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

#include <stdio.h>
#include <stdlib.h>
#include <QtGui>
#include <QFileDialog>
#include <QPrintDialog>
#include "diasporaclusterdialog.h"
#include "ui_diasporaclusterdialog.h"
#include "sceneimageexporter.h"
#include "appmessage.h"
#include "cluster/cluster.h"
#include "cluster/diasporaclusterscene.h"
#include "cluster/diasporaclustergraphicsitem.h"
#include "cluster/aspect.h"
#include "cluster/aspectgraphicsitem.h"
#include "dialogs/preferencesdialog.h"
#include "exporters/clusterhtmlexporter.h"
#include "helpers/preferences.h"
#include "helpers/splashscreen.h"

DiasporaClusterDialog::DiasporaClusterDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiasporaClusterDialog)
{
    ui->setupUi(this);
    ui->clusterView->setRenderHint(QPainter::Antialiasing,true);
    this->doGenerateCluster();

    connect(ui->cliEditor,SIGNAL(clusterItemChanged()), this,SLOT(on_clusterItemChanged()));
    connect(&_scene,SIGNAL(clickedOnClusterItem(ClusterItem,int)),this, SLOT(on_clusterItemClicked(ClusterItem,int)));

    _selectedRow = -1;

    //qDebug() << "Cluster generated.";
    ui->btnRotateLeft->setVisible(false);
    ui->btnRotateRight->setVisible(false);
    ui->sliderRotate->setVisible(false);
}

DiasporaClusterDialog::~DiasporaClusterDialog()
{
    delete ui;
}

void DiasporaClusterDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void DiasporaClusterDialog::doGenerateCluster() {
    if (_cluster.isDirty()) {
        if (AppMessage::Question(
                tr("This cluster has been modified and not saved yet.\nDo you want to save it?"),
                tr("Cluster not saved"))) {
            this->saveCluster();
        }
    }
    bool closeCluster = ui->chkCloseCluster->isChecked();
    int nClusterItems = ui->spinNumSolSys->value();
    _cluster.create(nClusterItems,closeCluster);
    doFillClusterControls();
    //qDebug() << "did Cluster generated.";

}

void DiasporaClusterDialog::doFillListBox()
{

}

void DiasporaClusterDialog::doFillClusterControls()
{
    //qDebug() << "filling cluster controls";

    this->doFillListBox();
    ui->cliEditor->setCluster(&_cluster);
    ui->lblClusterName->setText(_cluster.name());
    _cluster.setIsDirty(false);
}

void DiasporaClusterDialog::doDrawCluster()
{
    QGraphicsScene *ctlScene = ui->clusterView->scene();
    QVector<DiasporaClusterGraphicsItem *> items;
    QBrush qbTransparent(Qt::transparent);

    float nStep = 0;
    int nCount = _cluster.clusterItems().count();
    for (int h = 0; h < nCount; h++) {
        ClusterItem cli = _cluster.clusterItems()[h];

        DiasporaClusterGraphicsItem* dcgi =
                new DiasporaClusterGraphicsItem(nStep,0,cli);
        dcgi->setCurrentScene(&_scene);
        dcgi->setIndexItem(h);
        dcgi->setZValue(100);
        nStep += (1.5* dcgi->size().width());
        items.append(dcgi);
    }

    if (ctlScene != 0) {
        ui->clusterView->scene()->clear();
        ui->clusterView->scene()->invalidate();
    }

    int nTot = 0;

    QPen pen = QPen(QColor(0,0,0));
    QColor colorDL = Preferences::prefsPtr()->colorDiasporaLink();
    colorDL.setAlpha(128);
    QPen penGray = QPen(colorDL);
    QPen penCyan = QPen(Preferences::prefsPtr()->colorStarOtherLink());
    penGray.setWidthF(8);
    penCyan.setWidthF(5.0);

    float minYCoord = 9999;

    for (int h = 0; h < nCount; h++) {
        _scene.ptrScene()->addItem(items[h]);
        int links = items[h]->clusterItem().links().count();
        //qDebug() << "Links are " << links;
        QSizeF size1 = items[h]->size();
        //QPointF corner1 = items[h]->corner();
        float x1 = items[h]->x();
        float y1 = items[h]->y();
        for (int w2 = 0; w2 < links; w2++) {
            int w = items[h]->clusterItem().links()[w2];
            //QPointF corner2 = items[w]->corner();
            QSizeF size2 = items[w]->size();
            float x2 = items[w]->x();
            float y2 = items[w]->y();

            if (w2 == 0)
            {
                _scene.scene().addLine(x1,y1,x2,y2,penGray);
            }
            else  {
                nTot = h+w2;
                float dx = x2-x1;
                QPainterPath path;

                if (nTot  % 2 == 0)
                    dx = -(dx+ size1.height());
                else
                    dx = ( dx+size1.height());
                QPointF ptStart(x1,y1);
                QPointF ptEnd(x2,y2);
                QPointF pt1(x1, (y2+dx)/2.5);
                QPointF pt2(x2, (y2+dx)/2.5);
                path.moveTo(x1,y1);
                path.cubicTo(pt1.x(),pt1.y(),pt2.x(),pt2.y(),ptEnd.x(),ptEnd.y());

                _scene.scene().addPath(path,penGray, qbTransparent);
            }
        }
        AGIAlign::Alignment align = AGIAlign::ALTopCenter;
        float dxBox = 2.5*size1.height();
        if (h % 2 == 1) {
            dxBox = -dxBox;
            align = AGIAlign::ALBottomCenter;
        }
        AspectGraphicsItem * agi = new AspectGraphicsItem(
                x1,dxBox,30,items[h]->clusterItem());

        agi->setAlignment(align);
        agi->setZValue(200);
        _scene.scene().addItem(agi);

        if (agi->boundingRect().top() < minYCoord)
            minYCoord = agi->boundingRect().top();

        QGraphicsLineItem *li = _scene.scene().addLine(x1,y1,x1,dxBox,penCyan);
        li->setZValue(-100);
    }

    QFont titleFont = Preferences::prefs().fontTitle();
    QString clusterName = _cluster.name()+" Cluster";
    QFontMetricsF metricsTitle(titleFont);
    float titleW = metricsTitle.width(clusterName);
    float fTitleX = (nStep -titleW)/2;
    float fTitleY = minYCoord- metricsTitle.height()*1.75;

    QGraphicsTextItem* title = _scene.scene().addText(clusterName,titleFont);
    title->setDefaultTextColor(QColor(192,0,0));

    title->setX(fTitleX);
    title->setY(fTitleY);

    QGraphicsScene* pScene = _scene.ptrScene();
    ui->clusterView->setScene(pScene);

}

void DiasporaClusterDialog::on_btnGenerate_clicked()
{
}

void DiasporaClusterDialog::on_btnRandomizeAspects_clicked()
{

}

void DiasporaClusterDialog::on_btnAddAspect_clicked()
{

}

void DiasporaClusterDialog::on_btnSaveCluster_clicked()
{

}

void DiasporaClusterDialog::on_btnExit_clicked()
{
    this->close();
}

void DiasporaClusterDialog::showClusterItemInfo(int ciIdx)
{
    //qDebug() << "showClusterItemInfo ";

    ui->cliEditor->setSelectedClusterIndex(ciIdx);
    //qDebug() << "shown cluster";

}

void DiasporaClusterDialog::doProcessClusterListModelItem(QModelIndex index) {
    _selectedRow = index.row();
    QString starName = _clusterNames[_selectedRow];
    showClusterItemInfo(_selectedRow);
}



void DiasporaClusterDialog::on_lstCluster_clicked(QModelIndex index)
{
    this->doProcessClusterListModelItem(index);

}

void DiasporaClusterDialog::on_lstCluster_entered(QModelIndex index)
{
    this->doProcessClusterListModelItem(index);

}

void DiasporaClusterDialog::on_spinNumSolSys_valueChanged(int )
{
    //doGenerateCluster();
}

void DiasporaClusterDialog::performSliderZoomRotation()
{
    qreal scale = 0.7*qPow(qreal(2), (ui->sliderZoom->value() - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);
    matrix.rotate(ui->sliderRotate->value());

    ui->clusterView->setMatrix(matrix);
}

void DiasporaClusterDialog::on_sliderRotate_valueChanged(int value)
{
    performSliderZoomRotation();
}

void DiasporaClusterDialog::on_sliderZoom_valueChanged(int value)
{
    performSliderZoomRotation();
}

void DiasporaClusterDialog::on_clusterItemChanged()
{
    ClusterItem* cli = ui->cliEditor->clusterItemPtr();

    //qDebug() << "Selected row is: " << _selectedRow;

    if (_selectedRow != -1) {
        int row = _selectedRow;
        _cluster.setClusterItem(*cli,row);
        _cluster.setIsDirty(true);
    }
    this->doDrawCluster();
}

void DiasporaClusterDialog::on_clusterItemClicked(const ClusterItem &cli2, int idx)
{
    ClusterItem cli = cli2;
    //qDebug() << "clicked on " << idx << " cluster item";
    _selectedRow = idx;
    int row = idx;
    //ui->cliEditor->setClusterItem(&cli);
    ui->cliEditor->setSelectedClusterIndex(row);
}


void DiasporaClusterDialog::on_btnZoomIn_clicked()
{
    int val = ui->sliderZoom->value();
    int step = ui->sliderZoom->pageStep();
    ui->sliderZoom->setValue(step+val);
}

void DiasporaClusterDialog::on_btnZoomOut_clicked()
{
    int val = ui->sliderZoom->value();
    int step = ui->sliderZoom->pageStep();
    ui->sliderZoom->setValue(val-step);

}

void DiasporaClusterDialog::on_btnRotateLeft_clicked()
{
    int val = ui->sliderRotate->value();
    int step = ui->sliderRotate->pageStep();
    ui->sliderRotate->setValue(val-step);

}

void DiasporaClusterDialog::on_btnRotateRight_clicked()
{
    int val = ui->sliderRotate->value();
    int step = ui->sliderRotate->pageStep();
    ui->sliderRotate->setValue(step+val);

}

void DiasporaClusterDialog::saveCluster()
{
    QString fileName =
            QFileDialog::getSaveFileName(this, tr("Export file as Cluster binary data"),
                                         AppPaths::appDir()+"/"+ _cluster.name()+".cluster",
                           tr("CLUSTER File (*.cluster)"));
    if (!fileName.isEmpty() && !fileName.isNull())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite))
        {
            QDataStream stream (&file);
            stream << _cluster;

        }
    }

}

void DiasporaClusterDialog::loadCluster()
{
    QString fileName =
            QFileDialog::getOpenFileName(
                    this,
                    tr("Load Cluster File"),
                    AppPaths::appDir(),
                    tr("CLUSTER File (*.cluster)"));
    if (!fileName.isEmpty() && !fileName.isNull())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::ReadWrite))
        {
            QDataStream stream(&file);
            Cluster cluster;
            stream >> cluster;
            this->setCluster(cluster);

        }
    }

}

void DiasporaClusterDialog::exportCluster() {
    QString fileName =
            QFileDialog::getSaveFileName(
                this,
                tr("Export file as Graphviz Graph"),
                AppPaths::appDir()+ "/" + _cluster.name() + ".svg",
                tr("SVG Image (*.svg);;PDF Doc  ument (*.pdf);;Graphviz File (*.dot);;HTML Page (*.html)"));
    if (!fileName.isEmpty() && !fileName.isNull()){
        if (fileName.endsWith(".svg"))
            this->exportClusterToSvg(fileName);
        if (fileName.endsWith(".pdf"))
            this->exportClusterToPDF(fileName);
        if (fileName.endsWith(".dot"))
            this->exportClusterToGraphViz(fileName);
        if (fileName.endsWith(".html"))
            this->exportClusterToHtml(fileName);
    }
}

void DiasporaClusterDialog::exportClusterToSvg(QString expFilename )
{
    QString fileName = expFilename != "" ? expFilename :
            QFileDialog::getSaveFileName(
                    this,
                    tr("Export cluster as SVG"),
                    AppPaths::appDir()+"/"+_cluster.name()+".svg",
                    tr("SVG Image (*.svg)"));
    if (!fileName.isEmpty() && !fileName.isNull()) {
        SceneImageExporter::ExportToSVG(this->clusterScene().ptrScene(),fileName);
    }

}

void DiasporaClusterDialog::exportClusterToGraphViz(QString expFilename )
{
    QString fileName = expFilename != "" ? expFilename :
            QFileDialog::getSaveFileName(
                    this,
                    tr("Export cluster as Graphviz file"),
                    AppPaths::appDir()+"/"+_cluster.name()+".dot",
                    tr("Graphviz file (*.dot)"));
    if (!fileName.isEmpty() && !fileName.isNull()) {
        _cluster.exportClusterToGraphViz(fileName);
    }

}

void DiasporaClusterDialog::exportClusterToPDF(QString expFilename ) {
    QString fileName = expFilename != "" ? expFilename :
            QFileDialog::getSaveFileName(
                    this,
                    tr("Export cluster as PDF"),
                    AppPaths::appDir()+"/"+_cluster.name()+".pdf",
                    tr("PDF Document (*.pdf)"));
    if (!fileName.isEmpty() && !fileName.isNull()) {
        qApp->processEvents();
        SplashScreen::screenPtr()->setMessage("Exporting "+_cluster.name() + " to PDF");
        SplashScreen::screenPtr()->show();
        qApp->processEvents();

        QPrinter printer;
        SceneImageExporter sci;
        sci.GraphicsSceneToPrinter(
                this->clusterScene().ptrScene(),
                printer,fileName,_cluster.name(),true);

        SplashScreen::screenPtr()->hide();
    }

}

void DiasporaClusterDialog::printCluster() {
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Current Diaspora Cluster"));
    if (dialog.exec() != QDialog::Accepted)
        return;
    qApp->processEvents();
    SplashScreen::screenPtr()->setMessage("Printing Cluster "+_cluster.name());
    SplashScreen::screenPtr()->show();
    qApp->processEvents();

    SceneImageExporter sci;
    sci.GraphicsSceneToPrinter(this->clusterScene().ptrScene(), printer);

    SplashScreen::screenPtr()->hide();

}

void DiasporaClusterDialog::exportClusterToHtml(QString expFilename)
{
    QString fileName = expFilename != "" ? expFilename :
            QFileDialog::getSaveFileName(
                    this,
                    tr("Export cluster as HTML"),
                    AppPaths::appDir()+"/"+_cluster.name()+".html",
                    tr("HTML Page (*.html)"));
    if (!fileName.isEmpty() && !fileName.isNull()) {
        //1 - Create directory
        QString filePath = fileName.replace(".","_");
        QDir dir(filePath);
        if (dir.exists()) {
            AppMessage::Error("Directory <tt>" + filePath + "</tt>\nhas already been created","Directory Creation Error");
        }
        else {
            dir.mkpath(filePath);
            QString svgFile = filePath+"/cluster.svg";
            SceneImageExporter::ExportToSVG(this->_scene.ptrScene(),svgFile);
            QString indexFile = filePath+"/index.html";
            QFile file(indexFile);
            if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream <<
                        "<html><head><title>" + _cluster.name() + " Cluster</title>"
                        "<style>"
                        "BODY { font-family: Corbel, lucida grande, verdana, sans-serif; font-size: 12pt; }"
                        ".cluster_table TR { vertical-align:top; }"
                        ".cluster_table { border: 1px dotted silver; }"
                        ".cluster_table TH { color: white; background-color: navy; }"
                        ".row_0 { background-color: #FFC;  }"
                        "</style>"
                        "<head>"
                        "\n<body>"
                        "\n<h1>" + _cluster.name() + "</h1>"
                        "\n<div id='image_cluster'>"
                        "\n<img src='cluster.svg' alt='cluster'>\n</div>"
                        "\n<div id='cluster_data'>" +
                        ClusterHTMLExporter::ToHTML(_cluster) +
                        "\n</div>"
                        "\n</body>";

            }
            file.flush();
            file.close();
        }

    }
}

void DiasporaClusterDialog::on_lblClusterName_textChanged(QString name)
{
    _cluster.setIsDirty(true);
    _cluster.setName(name);
}

void DiasporaClusterDialog::generateNewCluster() {
    doGenerateCluster();
    doDrawCluster();
}

void DiasporaClusterDialog::on_lblClusterName_returnPressed()
{
    doDrawCluster();
}
