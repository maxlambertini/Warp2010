/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#include "warpmainwindowform.h"
#include <QListWidget>
#include <QtSvg>
#include <math.h>
#include <QPen>
#include <QObject>
#include <QDialog>
#include <QPrintDialog>
#include <stdlib.h>
#include <time.h>
#include "star.h"
#include "starwidgetitem.h"
#include "stargraphicsitem.h"
#include "dialogs/createtraderoutedialog.h"
#include "mainscenehandler.h"
#include "solarsystemcreator.h"
#include "dialogs/traderoutedialog.h"
#include "traderoutewidgetitem.h"
#include "warpexception.h"
#include "traderoutereportwriter.h"
#include "dialogs/newsectordialog.h"
#include "celestiaexporter.h"
#include "dialogs/preferencesdialog.h"
#include "cluster/cluster.h"
#include "cluster/clusteritem.h"
#include "diasporaclusterdialog.h"
#include "cluster/aspect.h"
#include "cluster/aspectlist.h"
#include "sceneimageexporter.h"
#include "appmessage.h"
#include "helpers/progressbarhelper.h"
#include "helpers/preferences.h"
#include "helpers/apppaths.h"
#include "dialogs/printingsetup.h"
#include "helpers/splashscreen.h"
#include "starlist.h"
#include "widgets/planetaryinspector.h"
#include "helpers/pixmaphelper.h"
#include "dialogs/createbetweenstarsdlg.h"
#include "dialogs/createnewstardlg.h"
#include <QEvent>
#include <noise/noise.h>
#include <noiseutils.h>
#include <exporters/starsectorjsonexporter.h>

void WarpMainWindowForm::on_actionLoad_Sector_triggered()
{
    //qDebug() << "Loading sector...";
    QString filename =
            QFileDialog::getOpenFileName(this,
                                         tr("Open Star Map"),
                                         AppPaths::appDir(),
                                         tr("Star sector files (*.star *.str *.STR, *.starx)"));
    if (!filename.isEmpty()) {
        SplashScreen::screenPtr()->show();
        SplashScreen::screenPtr()->setMessage("Acquired filename");
        QSharedPointer<Star> p;
        ui->solsysView->setStar(p);
        performMapProcessing(false, filename);
        SplashScreen::screenPtr()->setMessage("Processed map");
        if (!filename.endsWith(".starx")) {
            bool bCreateTradeRoutes = AppMessage::Question(
                    "Do you want me to create solar systems and trade routes?",
                    "You can always create them later. This will speed up star loading\n"
                    "and jump matrix rebuilding.");
            if (bCreateTradeRoutes) {
                SplashScreen::screenPtr()->setMessage("Creating solar system for all stars");
                SplashScreen::screenPtr()->show();
                //qApp->processEvents();
                this->performCreateSolSysForAllStars();

                //create trade routes, too
                //qApp->processEvents();
                SplashScreen::screenPtr()->setMessage("Creating trade routes...");
                //qApp->processEvents();
                this->on_action_TradeRoute_to_all_GardenPlanets_triggered();
            }
            //qApp->processEvents();
        }
        else {
            SplashScreen::screenPtr()->setMessage("Creating trade routes...");
            //qApp->processEvents();
            this->on_action_TradeRoute_to_all_GardenPlanets_triggered();
            //qApp->processEvents();
        }
        SplashScreen::screenPtr()->hide();
        ui->txtSectorName->setText(StarList::StarListPtr()->listName());
    }
}

void WarpMainWindowForm::on_action_Load_Whole_Sector_triggered()
{
    QString filename =
            QFileDialog::getOpenFileName(this,
                                         tr("Open Star Map"),
                                         AppPaths::appDir(),
                                         tr("Whole star sector files (*.json)"));
    if (!filename.isEmpty()) {
        this->clearSolarSystem();
        StarSectorJsonExporter jsonExp(_starList, _tradeRouteMediator);
        jsonExp.loadFromJson(filename);
        //this->_starList->loadFromJson(filename);
        this->_currentStarListIndex = 0;
        this->rebuildMatrix(0);
        this->fillListWithCalculatedData(0);
        _sceneMediator->setTradeRoute(_tradeRouteMediator->tradeRoutes());
        _sceneMediator->redrawScene();

        ui->txtSectorName->setText(StarList::StarListPtr()->listName());
    }
}

void WarpMainWindowForm::on_actionZoomIn_triggered()
{
    ui->sliderZoom->setValue(
            ui->sliderZoom->value() +
            ui->sliderZoom->pageStep());

}

void WarpMainWindowForm::on_actionRotateRight_triggered()
{
    ui->sliderRotate->setValue(
            ui->sliderRotate->value() +
            ui->sliderRotate->pageStep());

}

void WarpMainWindowForm::on_actionZoomOut_triggered()
{
    ui->sliderZoom->setValue(
            ui->sliderZoom->value() -
            ui->sliderZoom->pageStep());

}

void WarpMainWindowForm::on_actionRotateLeft_triggered()
{
    this->on_btnRotateLeft_clicked();
}

void WarpMainWindowForm::on_actionPrint_Sector_Map_triggered()
{
     QPrinter printer;

     QPrintDialog dialog (&printer, this);
     dialog.setWindowTitle(tr("Print Sector Map"));
     if (dialog.exec() != QDialog::Accepted)
         return;
     _sceneMediator->printSectors(printer);
 }

void WarpMainWindowForm::on_actionExit_triggered()
{
    if (AppMessage::Question(
            "<big><b>This action will close Warp2010.</b></big>",
            "Are you sure you want to do that?")) {
        QApplication::exit();
    }
}

void WarpMainWindowForm::on_action_CreateTradeRoute_triggered()
{
    CreateTradeRouteDialog *dialog = _createTradeRouteDlg;
    QListWidget     *list = ui->listWidget;
    if (list->currentItem() != 0)
    {
        StarWidgetItem *swi = (StarWidgetItem *)list->currentItem();
        if (swi->star()->path().count() > 1) {

            int nMax = swi->star()->path().count();
            int nFrom = swi->star()->path().at(0);
            int nTo = swi->star()->path().at(nMax -1);

            QSharedPointer<Star> stFrom = _starList->stars().at(nFrom);
            QSharedPointer<Star> stTo = _starList->stars().at(nTo);

            QString routeName = QString("From %1 to %2").arg(stFrom->starName).arg(stTo->starName);
            dialog->setTradeRouteName(routeName);

            if (dialog->exec() == QDialog::Accepted)
            {
                QColor color = dialog->selectedColor();
                QString tradeRouteName = dialog->tradeRouteName();
                QColor bgColor = dialog->selectedColor();
                QVector<int> path = swi->star()->path();

                int iol = swi->indexOnList();
                AddToTradeRoute (tradeRouteName, bgColor, path,iol);

                _sceneMediator->redrawScene();

            }
        } else {
            AppMessage::Information(tr("You must select a reachable star to add a trade route!"),"");
        }
    }
    else {
        AppMessage::Information(tr("You must select a  star to add a trade route!"),"");
    }
}

void WarpMainWindowForm::on_action_ShowNeighbors_routes_triggered()
{
    _sceneMediator->setShowNeighborsRoute( ui->action_ShowNeighbors_routes->isChecked());
    _sceneMediator->redrawScene();
}

void WarpMainWindowForm::on_action_ShowOptimalPath_triggered()
{
    _sceneMediator->setShowOptimalPath(  ui->action_ShowOptimalPath->isChecked() );
    _sceneMediator->redrawScene();
}

void WarpMainWindowForm::on_action_ShowTradeRoutes_triggered()
{
    _sceneMediator->setShowTradeRoute(  ui->action_ShowTradeRoutes->isChecked() ) ;
    _sceneMediator->redrawScene();
}

void WarpMainWindowForm::on_action_ShowOnlyStarsInTradeRoutes_triggered()
{

    _sceneMediator->setShowOnlyWorldOnRoutes(  ui->action_ShowOnlyStarsInTradeRoutes->isChecked() ) ;
    _sceneMediator->redrawScene();
    // qDebug() << "Setting ShowOnlyWorldOnRoutes ";
}


void WarpMainWindowForm::on_action_ExportMapToImage_triggered()
{
    QString defaultFilename = _starList->listName();
     QString fileName =
             QFileDialog::getSaveFileName(this, tr("Save File"),
                                          AppPaths::appDir()+"/"+ defaultFilename,
                            tr( "PDF Document (*.pdf);;SVG Drawing (*.svg)"));
    _sceneMediator->exportToImage(fileName);
}

void WarpMainWindowForm::on_action_SaveTradeRoutes_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("Save trade route"),
                                                    AppPaths::appDir()+ "/trade.route",tr("Trade Routes (*.route)"));
    if (!filename.isNull()) {
        TradeRoute::WriteTradeRoutesToFile(*_tradeRouteMediator->tradeRoutePtr(),filename);
    }
}



void WarpMainWindowForm::on_action_LoadTradeRoutes_triggered()
{
    QString filename = QFileDialog::getOpenFileName(
            this,
            "Open trade route",
            AppPaths::appDir(),
            tr("Trade Routes (*.route)"));
    if (!filename.isNull())
    {
        _tradeRouteMediator->setTableWidget(ui->gridTradeRoutes);
        _tradeRouteMediator->loadTradeRouteFromFile(filename);
        _sceneMediator->setTradeRoute(_tradeRouteMediator->tradeRoutes());

        _sceneMediator->redrawScene();

    }

}


void WarpMainWindowForm::on_action_CreateSolarSystem_triggered()
{
    if (_currentStar != 0)
    {
        _currentStar->clearPlanets();
        _currentStar->calcStarValue();

        srand (time(NULL));
        SolarSystemCreator *creator = new SolarSystemCreator(_currentStar);
        creator->createSolarSystem();
        delete creator;

        ui->solsysView->setStar(_currentStar);
    }
    else {
        AppMessage::Error("<b>No star selected</b>", "Create or load a star sector and select a star\nto create a solar system.");
    }

    QSharedPointer<Star> star = _currentStar;
    StarWidgetItem *swi = (StarWidgetItem *)ui->listWidget->currentItem();
    if (swi != 0) {
        if (star->path().count() > 0) {
            QPixmap pixmap (":/pics/ledred.png");
            QIcon icon(pixmap);
            swi->setIcon(icon);
        }

        if (star->hasGarden()) {
            if (star->path().count() > 0 )
            {
                QPixmap pixmap (":/pics/reachable_earth.png");
                QIcon icon(pixmap);
                swi->setIcon(icon);
            }
            else
            {
                QPixmap pixmap (":/pics/unreachable_earth.png");
                QIcon icon(pixmap);
                swi->setIcon(icon);
            }
        }
        ui->listWidget->repaint();
    }

}

void WarpMainWindowForm::on_action_TradeRoute_to_all_GardenPlanets_triggered()
{
    if (_starList->count() > 0) {
        _bUpdateTradeRoute = false;
        _tradeRouteMediator->setProgressBar(this->progressBar);
        _tradeRouteMediator->setTableWidget(ui->gridTradeRoutes);
        _tradeRouteMediator->searchTradeRouteToGardenPlanets();
        _sceneMediator->setTradeRoute(_tradeRouteMediator->tradeRoutes());
        _sceneMediator->redrawScene();
        _bUpdateTradeRoute = true;

        //TradeRouteReportWriter trrw = TradeRouteReportWriter(&_starList, _tradeRouteMediator);
        //trrw.createDocument();
        //trrw.write("demo.odf");

    }
    else {
        this->messageCannotCreateTradeRoute();
    }
}

void WarpMainWindowForm::on_action_NewSector_triggered()
{
    bool bCanCreateSector = true;
    if (StarList::StarListPtr()->stars().count() > 0) {
        if (AppMessage::Question("Do you want to clear current sector and create a new one?","Create Sector")) {
            this->clearSolarSystem();
            bCanCreateSector = true;
        }
        else
            bCanCreateSector = false;
    }

    if (bCanCreateSector) {
        _newSectorDialog = new NewSectorDialog(this);
        int res = _newSectorDialog->exec();
        //// qDebug() << res;
        if (res == QDialog::Accepted)
        {
            try {
                //qApp->processEvents();
                SplashScreen::screenPtr()->setMessage("Creating new sector: "+_newSectorDialog->sectorName());
                SplashScreen::screenPtr()->show();
                //qApp->processEvents();
                this->performMapProcessing(true,"");
                if (_newSectorDialog->createSolarSystems() ) {
                    //qApp->processEvents();
                    SplashScreen::screenPtr()->setMessage("Creating solar system for all stars");
                    //qApp->processEvents();
                    this->performCreateSolSysForAllStars();

                    //create trade routes, too
                    //qApp->processEvents();
                    SplashScreen::screenPtr()->setMessage("Creating trade routes...");
                    //qApp->processEvents();
                    this->on_action_TradeRoute_to_all_GardenPlanets_triggered();
                }
                //qApp->processEvents();
                SplashScreen::screenPtr()->hide();
            }
            catch (WarpException exc) {
                SplashScreen::screenPtr()->hide();
                QString errorText = "Error loading sector";
                QString errorInfo = QString(exc.what());
                AppMessage::Error(errorText,errorInfo);
                _sceneMediator->scene()->clear();
            }

        }
   }
}

void WarpMainWindowForm::on_action_SolarSystemForAllStars_triggered()
{
    QSharedPointer<Star> pt;
    ui->solsysView->setStar(pt);
    SplashScreen::screenPtr()->setMessage("Creating solar system for all stars");
    SplashScreen::screenPtr()->show();
    this->performCreateSolSysForAllStars();
    SplashScreen::screenPtr()->hide();
    //ui->solsysView->setStar(_currentStar);
}

void WarpMainWindowForm::on_action_CopySolarSystem_triggered()
{
    //ui->solSysWidget->copyToClipboard();
}

void WarpMainWindowForm::on_action_ExportSolarSystemToImage_triggered()
{
    /*
     QString fileName =
             QFileDialog::getSaveFileName(this, tr("Save File"),
                                          AppPaths::appDir()+ "/solarsystem.png",
                            tr("Png Image (*.png)"));
     if (!fileName.isEmpty() && !fileName.isNull())
        ui->solSysWidget->exportToImage(fileName,1024,512);
    */
}

void WarpMainWindowForm::on_action_Preferences_triggered()
{
    PreferencesDialog pd(this);
    int res = pd.exec();
    if (res == 1) {
        // qDebug() << "Preferences accepted, processing";
    }
    else {
        // qDebug() << "Preferences not processed";
    }
}

void WarpMainWindowForm::on_actionSave_Sector_triggered()
{
    QString defaultFilename = QString("./"+_starList->listName()+".str");
    QString filename =
            QFileDialog::getSaveFileName(this,
                                         tr("Save star Map"),
                                         AppPaths::appDir()+ "/"+defaultFilename,
                                         tr("Star sector files (*.star *.str *.STR);;Star matrix file (*.starx)"));
    if (!filename.isEmpty()) {
        if (filename.endsWith(".starx"))
            _starList->saveMatrix(filename);
        else
            _starList->saveMap(filename);
    }
}

void WarpMainWindowForm::on_action_AboutWarp2010_triggered()
{

    QPixmap pm;
    pm.load(AppPaths::appDir()+ "/pics/about_box.jpg");

    QDialog *dlg = new QDialog(this);
    QLabel *label = new QLabel(dlg);
    QGridLayout *layout = new QGridLayout(dlg);
    QPushButton *btnOk = new QPushButton(dlg);
    btnOk->setText("Close");
    btnOk->setMaximumSize(150,40);
    label->setPixmap(pm);
    layout->addWidget(label,0,0);
    layout->addWidget(btnOk,1,0,1,1,Qt::AlignHCenter);

    layout->setMargin(0);

    QObject::connect(btnOk, SIGNAL(clicked()), dlg, SLOT(close()));

    dlg->setLayout(layout);
    dlg->setWindowTitle("About Warp2010");
    dlg->exec();
    delete dlg;
}

void WarpMainWindowForm::on_action_ShowAsHexMap_triggered()
{

    _sceneMediator->setShowHexMap(  ui->action_ShowAsHexMap->isChecked() );
    ui->action_ShowOnlyReachableStars->setChecked(false);
    ui->action_ShowOnlyStarsInTradeRoutes->setChecked(true);
    _sceneMediator->redrawScene();


}

void WarpMainWindowForm::on_action_ExportMapToGraphVizFile_triggered()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Export file as Graphviz Graph"),
                                         AppPaths::appDir()+ "/" + _starList->listName() + ".graphml",
                           tr("GraphML yED File (*.graphml);;GML File (*.gml);;Graphviz File (*.dot);;Json File (*.json);;Celestia STC files (*.stc)"));

    if (!fileName.isEmpty() && !fileName.isNull()){
        if (fileName.endsWith(".gml"))
            _sceneMediator->drawToGML(fileName);
        if (fileName.endsWith(".graphml"))
            _sceneMediator->drawToGraphML(fileName);
        if (fileName.endsWith(".dot"))
            _sceneMediator->drawToGraphViz(fileName);
        if (fileName.endsWith(".json")) {
            StarSectorJsonExporter jsonExp(this->_starList, this->_tradeRouteMediator);
            jsonExp.saveToJson(fileName);
            //this->_starList->saveToJson(fileName);
        }
        if (fileName.endsWith(".stc")) {
            if (this->pCexp.data() != nullptr)
                this->pCexp.clear();
            this->pCexp = QSharedPointer<CelestiaExporter>(new CelestiaExporter (this->_currentStar.data()));

            connect(pCexp.data(),SIGNAL(startExporting()),this,SLOT(on_celestia_export_started()) );
            connect(pCexp.data(),SIGNAL(doneExporting()),this,SLOT(on_celestia_export_done()) );
            connect(pCexp.data(),SIGNAL(exported(int)),this, SLOT(on_celestia_system_exported(int)) );

            connect(pCexp.data(),SIGNAL(textureExportStarting(int)),this, SLOT(on_celestia_texture_starting(int)));
            connect(pCexp.data(),SIGNAL(textureChunkExported(int)), this, SLOT(on_celestia_texture_chunk(int)));
            connect(pCexp.data(),SIGNAL(textureDoneExported()),this,SLOT(on_celestia_texture_done()));

            pCexp.data()->setStarList(this->_starList);

            QFileInfo fileInfo(fileName);
            QString path = fileInfo.absolutePath();
            pCexp.data()->setFilePath(path);

            pCexp.data()->saveStarListToCelestiaFile(fileName);
        }
    }
}


void WarpMainWindowForm::on_celestia_export_started()
{

}

void WarpMainWindowForm::on_celestia_export_done()
{

}

void WarpMainWindowForm::on_celestia_system_exported(int exp)
{
    this->setWindowTitle(QString("System %1 of %2 exported").arg(exp).arg(this->_starList->count()));
    qApp->processEvents();
}

void WarpMainWindowForm::on_celestia_texture_chunk(int exp)
{
    progressBar->setValue(progressBar->value()+exp);
    qApp->processEvents();
}

void WarpMainWindowForm::on_celestia_texture_starting(int exp) {

    progressBar->setMinimum(0);
    progressBar->setValue(0);
    progressBar->setMaximum(exp);
    progressBar->setVisible(true);
    qApp->processEvents();
}

void WarpMainWindowForm::on_celestia_texture_done() {
    progressBar->setVisible(false);
}

void WarpMainWindowForm::on_action_ViewOnlyTradeRoutes_triggered()
{

    bool bChecked = ui->action_ShowOnlyStarsInTradeRoutes->isChecked() ;
    _sceneMediator->setShowOnlyWorldOnRoutes(  bChecked ) ;
    _sceneMediator->redrawScene();
    // qDebug() << "Setting ShowOnlyWorldOnRoutes " << bChecked;


}


void WarpMainWindowForm::on_action_Save_Diaspora_Cluster_triggered()
{
    ui->clusterCreator->saveCluster();
}

void WarpMainWindowForm::on_action_Load_Diaspora_Cluster_triggered()
{
    ui->clusterCreator->loadCluster();

}

void WarpMainWindowForm::on_action_Export_Diaspora_Cluster_To_SVG_triggered()
{
    ui->clusterCreator->exportClusterToSvg();
}

void WarpMainWindowForm::on_action_Export_Diaspora_Cluster_To_HTML_triggered()
{
    ui->clusterCreator->exportClusterToHtml();
}

void WarpMainWindowForm::on_action_Generate_New_Cluster_triggered()
{
    ui->clusterCreator->generateNewCluster();

}

void WarpMainWindowForm::on_action_Save_Solar_System_to_HTML_triggered()
{
    //on_btnSaveHtml_clicked();
    ui->solsysView->exportSolSysToHtml();
}

void WarpMainWindowForm::on_action_Save_Solar_System_to_Celestia_file_triggered()
{
    on_btnSaveCelestia_clicked();
}


void WarpMainWindowForm::on_action_ShowOnlyReachableStars_triggered()
{

    bool bChecked = ui->action_ShowOnlyReachableStars->isChecked() ;
    _sceneMediator->setShowOnlyReachableWorlds(  bChecked ) ;
    _sceneMediator->redrawScene();
    // qDebug() << "Setting setShowOnlyReachableWorlds " << bChecked;

}

void WarpMainWindowForm::on_action_Export_Cluster_To_PDF_triggered()
{

    ui->clusterCreator->exportClusterToPDF();

}

void WarpMainWindowForm::on_action_Print_Cluster_triggered()
{

    ui->clusterCreator->printCluster();

}

void WarpMainWindowForm::on_action_Page_Setup_triggered()
{
    PrintingSetup printingSetup(this);
    printingSetup.exec();
}

void WarpMainWindowForm::on_action_map_Show_Hexmap_With_Reachable_Stars_triggered()
{
    _sceneMediator->setShowHexOnHexMap(true);
    _sceneMediator->setShowOnlyWorldOnRoutes(false);
    _sceneMediator->setShowHexMap(true);
    _sceneMediator->setShowOnlyReachableWorlds(true);
    _sceneMediator->setShowTradeRoute(false);
    _sceneMediator->setShowOptimalPath(true);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_Show_Hexmap_with_Trade_Route_Only_triggered()
{
    _sceneMediator->setShowHexOnHexMap(true);
    _sceneMediator->setShowOnlyWorldOnRoutes(true);
    _sceneMediator->setShowHexMap(true);
    _sceneMediator->setShowOnlyReachableWorlds(false);
    _sceneMediator->setShowTradeRoute(true);
    _sceneMediator->setShowOptimalPath(false);
    _sceneMediator->redrawScene();
}

void WarpMainWindowForm::on_action_map_Show_All_Stars_triggered()
{
    _sceneMediator->setShowHexOnHexMap(true);
    _sceneMediator->setShowOnlyWorldOnRoutes(false);
    _sceneMediator->setShowHexMap(false);
    _sceneMediator->setShowOnlyReachableWorlds(false);
    _sceneMediator->setShowTradeRoute(false);
    _sceneMediator->setShowOptimalPath(true);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_Show_Reachable_Stars_triggered()
{
    _sceneMediator->setShowHexOnHexMap(true);
    _sceneMediator->setShowHexMap(false);
    _sceneMediator->setShowOnlyWorldOnRoutes(false);
    _sceneMediator->setShowOnlyReachableWorlds(true);
    _sceneMediator->setShowTradeRoute(false);
    _sceneMediator->setShowOptimalPath(true);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_Show_Stars_on_Trade_Routes_only_triggered()
{
    _sceneMediator->setShowHexOnHexMap(true);
    _sceneMediator->setShowHexMap(false);
    _sceneMediator->setShowOptimalPath(false);
    _sceneMediator->setShowOnlyWorldOnRoutes(true);
    _sceneMediator->setShowOnlyReachableWorlds(false);
    _sceneMediator->setShowTradeRoute(true);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_Show_Metro_Map_With_Reachable_Stars_triggered()
{
    _sceneMediator->setShowHexOnHexMap(false);
    _sceneMediator->setShowOnlyWorldOnRoutes(false);
    _sceneMediator->setShowHexMap(true);
    _sceneMediator->setShowOnlyReachableWorlds(true);
    _sceneMediator->setShowTradeRoute(false);
    _sceneMediator->setShowOptimalPath(true);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_Show_Metro_Map_With_Trade_Routes_triggered()
{
    _sceneMediator->setShowHexOnHexMap(false);
    _sceneMediator->setShowOnlyWorldOnRoutes(true);
    _sceneMediator->setShowHexMap(true);
    _sceneMediator->setShowOnlyReachableWorlds(false);
    _sceneMediator->setShowTradeRoute(true);
    _sceneMediator->setShowOptimalPath(false);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_Star_Sector_View_triggered(bool checked)
{
    this->on_tabSubprograms_currentChanged(TAB_STAR_SECTOR);
    this->ui->menuStar_Sector_Operations->setEnabled(true);
    this->ui->menuCluster_Operations->setEnabled(false);
    this->ui->menuSolar_System_Operations->setEnabled(false);
}

void WarpMainWindowForm::on_action_Solar_System_View_triggered(bool checked)
{
    this->on_tabSubprograms_currentChanged(TAB_SOLAR_SYSTEM);
    this->ui->menuStar_Sector_Operations->setEnabled(false);
    this->ui->menuCluster_Operations->setEnabled(false);
    this->ui->menuSolar_System_Operations->setEnabled(true);

}

void WarpMainWindowForm::on_action_Diaspora_Cluster_View_triggered(bool checked)
{
    this->on_tabSubprograms_currentChanged(TAB_CLUSTER_MAP);
    this->ui->menuStar_Sector_Operations->setEnabled(false);
    this->ui->menuCluster_Operations->setEnabled(true);
    this->ui->menuSolar_System_Operations->setEnabled(false);

}

void WarpMainWindowForm::on_action_Export_Diaspora_Cluster_To_Graphviz_triggered()
{
    ui->clusterCreator->exportClusterToGraphViz();
}

void WarpMainWindowForm::on_action_solsys_export_to_pdf() {
    ui->solsysView->exportSolSysToPDF();

}

void WarpMainWindowForm::on_action_solsys_export_to_svg() {
    ui->solsysView->exportSolSysToSvg();

}

void WarpMainWindowForm::on_action_solsys_print() {

}

void WarpMainWindowForm::on_action_Add_New_Star_triggered()
{
    QDialog dlg(this);
    CreateNewStarDlg *widget = new CreateNewStarDlg(&dlg);
    QVBoxLayout *layout = new QVBoxLayout(&dlg);
    layout->addWidget(widget);

    dlg.setLayout(layout);
    QObject::connect(widget, SIGNAL(accept()), &dlg, SLOT(accept()));
    QObject::connect(widget, SIGNAL(reject()), &dlg, SLOT(reject()));
    if (dlg.exec() == QDialog::Accepted) {
        widget->createStars();
        if (widget->starsToCreate().count()  > 0) {
            QSharedPointer<Star>  newStar;
            foreach (newStar, widget->starsToCreate()) {
                StarList::StarListPtr()->stars().append(newStar);
            }
            ui->listWidget->clear();
            this->rebuildMatrix(0, this->distance());
            fillListWithCalculatedData(0);

        }
    }

}

void WarpMainWindowForm::on_actionAdd_Stars_Between_Two_Stars_triggered()
{
    if (ui->listWidget->count() > 0) {
        CreateBetweenStarsDlg dlg(this);
        for (int h = 0; h < ui->listWidget->count();  h++)
        {
            dlg.addWidgetItemToStarFrom(ui->listWidget->item(h));
            dlg.addWidgetItemToStarTo(ui->listWidget->item(h));
        }
        if (dlg.exec() == QDialog::Accepted) {
            dlg.createStars();
            if (dlg.starsToCreate().count() > 0) {
                QSharedPointer<Star>  newStar;
                foreach (newStar, dlg.starsToCreate()) {
                    StarList::StarListPtr()->stars().append(newStar);
                }
                ui->listWidget->clear();
                this->rebuildMatrix(0, this->distance());
                fillListWithCalculatedData(0);

            }
        }
    }
}



void WarpMainWindowForm::on_action_Clear_Star_Sector_Data_triggered()
{
    if (StarList::StarListPtr()->stars().count() > 0) {
        if (AppMessage::Question(tr("Do you really want to clear solar system data?",
                                    ""))) {
            this->clearSolarSystem();
        }
    }
}

void WarpMainWindowForm::on_action_map_set_xy_mode_triggered() {
    _sceneMediator->setDrawMode(SceneMediatorDrawMode::XY);
    _sceneMediator->redrawScene();
}

void WarpMainWindowForm::on_action_map_set_xz_mode_triggered() {
    _sceneMediator->setDrawMode(SceneMediatorDrawMode::XZ);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_map_set_yz_mode_triggered() {
    _sceneMediator->setDrawMode(SceneMediatorDrawMode::YZ);
    _sceneMediator->redrawScene();

}

void WarpMainWindowForm::on_action_Export_Map_to_JSON_triggered()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Export file as Graphviz Graph"),
                                         AppPaths::appDir()+ "/"+this->_starList->listName() +".json",
                           tr("JSON File (*.json)"));
    if (!fileName.isEmpty() && !fileName.isNull())
       this->_starList->saveToJson(fileName);

}

