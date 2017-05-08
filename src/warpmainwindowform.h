/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/

#ifndef WARPMAINWINDOWFORM_H
#define WARPMAINWINDOWFORM_H

const int TAB_STAR_SECTOR =  0;
const int TAB_SOLAR_SYSTEM = 1;
const int TAB_CLUSTER_MAP = 2;



#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <QListWidget>
#include <QProgressBar>
#include <QMainWindow>
#include "ui_warpmainwindow.h"
#include "starlist.h"
#include "dialogs/createtraderoutedialog.h"
#include "traderoute.h"
#include "mainscenehandler.h"
#include "traderoutemediator.h"
#include "dialogs/traderoutedialog.h"
#include "traderoutewidgetitem.h"
#include "dialogs/newsectordialog.h"
#include "appmessage.h"
#include "helpers/solarsystemtoscene.h"
#include <QSharedPointer>
#include <celestiaexporter.h>

namespace Ui
{
    class WarpMainWindow;
}

class WarpMainWindowForm : public QMainWindow
{
    Q_OBJECT
private:
    StarList *_starList;
    Ui::WarpMainWindow *ui;
    int _referenceIdx;
    QGraphicsScene *scene;
    QProgressBar *progressBar;
    bool bReloading;
    CreateTradeRouteDialog *_createTradeRouteDlg;
    QVector<QSharedPointer<TradeRoute> > _tradeRoutes;
    NewSectorDialog *_newSectorDialog;

    void populateScene();
    void fillListWithCalculatedData(int idx);
    void setupMatrix();


    SceneMediator *       _sceneMediator;
    QSharedPointer<Star>  _currentStar;
    TradeRouteMediator *  _tradeRouteMediator;
    TradeRouteDialog *    _tradeRouteDialog;
    TradeRoute*           _currentTradeRoute;
    int                   _currentStarListIndex;
    QVector<int>          _currentPath;
    TradeRouteWidgetItem  *_currentTwi;

    bool _bUpdateTradeRoute;
    QSplashScreen splash;
    QPixmap pixmap;

    QMenu *menuSectorOptions;
    QMenu *menuProjections;
    QActionGroup *agMapActions;
    QActionGroup *agViews;
    QActionGroup *agDrawMode;
    SolarSystemToScene solsysScene;

    QSharedPointer<CelestiaExporter> pCexp;

public slots:
    void sliderValueChanged(int value);
    void tradeRouteCreated(QString& routeName);
    void agMapActions_triggered (QAction* action);

public:
    inline void loadStarList(const QString& filename = "/home/maxl/2300AD.STR") { _starList->loadMap(filename);}
    inline void calculateNeighbors(double dist) { _starList->calculateNeighbors(dist);}
    inline void rebuildMatrix (int idx) { _starList->rebuildMatrix(idx); }
    inline void rebuildMatrix (int idx, double distance)
    {        
        // qDebug() << "Calculating neighbors... " << distance;
        this->calculateNeighbors(distance);
        // qDebug() << "actual rebuilding ";
        this->rebuildMatrix(idx);
    }

    double distance() { return this->ui->spinDistance->value();}
    void setDistance(double val) { return this->ui->spinDistance->setValue(val);}
    void AddToTradeRoute (QString & tradeRouteName, QColor & bgColor, QVector<int> & path, int &indexOnList);
    void performMapProcessing(bool bCreateNewMap, QString filename);
    void performCreateSolSysForAllStars();

    WarpMainWindowForm( QWidget *parent = 0);
    ~WarpMainWindowForm();

    inline void messageCannotCreateTradeRoute() {
        AppMessage::Error("<b>You cannot create trade routes</b>","A sector must be loaded\nbefore creating any trade route");
    }


    inline void splash_showMessage(QString message) {
        ui->statusbar->showMessage(message);
    }

    void clearSectorMap();
    void clearSolarSystem();
    void clearDiasporaCluster();

public slots:
    void on_btnRotateLeft_clicked();
    void on_btnRotateRight_clicked();
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
    void on_listWidget_itemSelectionChanged();
    void on_star_name_changed(QString &newStarName);
    void on_neighbor_selected(int i);

private slots:
    void on_txtSectorName_returnPressed();
    void on_stackWidget_currentChanged(int );
    void on_btnRotateLeft_triggered(QAction* );
    void on_tabSubprograms_currentChanged(int index);
    void on_btnDeleteAllRoutes_clicked();    
    void on_btnSaveCelestia_clicked();
    void on_btnSaveHtml_clicked();
    void on_btnDeleteRoute_clicked();
    void on_sliderZoom_valueChanged(int value);
    void on_action_NewSector_triggered();
    void on_btnConfirmRoute_clicked();
    void on_gridTradeRoutes_itemSelectionChanged();
    void on_gridTradeRoutes_itemChanged(QListWidgetItem* item);
    void on_gridTradeRoutes_itemClicked(QListWidgetItem* item);    
    void on_btnZoomUp_clicked();
    void on_btnZoomDown_clicked();
    void on_sliderRotate_valueChanged(int value);

    // GENERAL ACTIONS
    void on_action_Page_Setup_triggered();
    void on_action_ShowOnlyReachableStars_triggered();
    void on_action_ShowOnlyStarsInTradeRoutes_triggered();
    void on_actionRotateLeft_triggered();
    void on_actionZoomOut_triggered();
    void on_actionRotateRight_triggered();
    void on_actionZoomIn_triggered();
    void on_actionExit_triggered();


    // STAR SECTOR ACTIONS
    void on_action_Star_Sector_View_triggered(bool checked);
    void on_action_ViewOnlyTradeRoutes_triggered();
    void on_action_ShowAsHexMap_triggered();
    void on_action_AboutWarp2010_triggered();
    void on_action_Preferences_triggered();
    void on_actionSave_Sector_triggered();
    void on_actionLoad_Sector_triggered();
    void on_actionPrint_Sector_Map_triggered();
    void on_actionAdd_Stars_Between_Two_Stars_triggered();
    void on_action_Add_New_Star_triggered();

    //STAR MAP ACTIONS
    void on_action_map_Show_Metro_Map_With_Trade_Routes_triggered();
    void on_action_map_Show_Metro_Map_With_Reachable_Stars_triggered();
    void on_action_map_Show_Stars_on_Trade_Routes_only_triggered();
    void on_action_map_Show_Reachable_Stars_triggered();
    void on_action_map_Show_All_Stars_triggered();
    void on_action_map_Show_Hexmap_with_Trade_Route_Only_triggered();
    void on_action_map_Show_Hexmap_With_Reachable_Stars_triggered();
    void on_action_LoadTradeRoutes_triggered();
    void on_action_ExportMapToImage_triggered();
    void on_action_ExportMapToGraphVizFile_triggered();
    void on_action_SaveTradeRoutes_triggered();
    void on_action_ShowTradeRoutes_triggered();
    void on_action_ShowOptimalPath_triggered();
    void on_action_ShowNeighbors_routes_triggered();
    void on_action_CreateTradeRoute_triggered();

    void on_action_map_set_xy_mode_triggered();
    void on_action_map_set_xz_mode_triggered();
    void on_action_map_set_yz_mode_triggered();

    // SOLAR SYSTEM ACTIONS
    void on_action_Solar_System_View_triggered(bool checked);
    void on_action_Save_Solar_System_to_Celestia_file_triggered();
    void on_action_Save_Solar_System_to_HTML_triggered();
    void on_action_ExportSolarSystemToImage_triggered();
    void on_action_CopySolarSystem_triggered();
    void on_action_SolarSystemForAllStars_triggered();
    void on_action_TradeRoute_to_all_GardenPlanets_triggered();
    void on_action_CreateSolarSystem_triggered();
    void on_action_solsys_export_to_pdf();
    void on_action_solsys_export_to_svg();
    void on_action_solsys_print();

    //DIASPORA CLUSTER ACTIONS
    void on_action_Generate_New_Cluster_triggered();
    void on_action_Export_Diaspora_Cluster_To_HTML_triggered();
    void on_action_Export_Diaspora_Cluster_To_Graphviz_triggered();
    void on_action_Diaspora_Cluster_View_triggered(bool checked);
    void on_action_Print_Cluster_triggered();
    void on_action_Export_Cluster_To_PDF_triggered();
    void on_action_Export_Diaspora_Cluster_To_SVG_triggered();
    void on_action_Load_Diaspora_Cluster_triggered();
    void on_action_Save_Diaspora_Cluster_triggered();

    void on_action_Clear_Star_Sector_Data_triggered();
    void on_action_Export_Map_to_JSON_triggered();

    //GRAPHICS SCENE MOUSE EVENT

    void on_actionCreate_map_triggered();
    void on_actionCreate_map_2_triggered();

    //CELESTIA EXPORTER
    void on_celestia_export_started();
    void on_celestia_export_done();
    void on_celestia_system_exported(int exp);
    void on_celestia_texture_starting(int exp);
    void on_celestia_texture_done();
    void on_celestia_texture_chunk(int exp);
    void on_action_Load_Whole_Sector_triggered();
};

#endif // WARPMAINWINDOWFORM_H
