/********************************************************************************
** Form generated from reading UI file 'warpmainwindow.ui'
**
** Created: Wed 22. Feb 08:44:28 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARPMAINWINDOW_H
#define UI_WARPMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <diasporaclusterdialog.h>
#include "qtcolorpicker.h"
#include "widgets/solarsystemviewwidget.h"

QT_BEGIN_NAMESPACE

class Ui_WarpMainWindow
{
public:
    QAction *action_NewSector;
    QAction *actionLoad_Sector;
    QAction *actionSave_Sector;
    QAction *actionPrint_Sector_Map;
    QAction *actionPrint_Trade_Route;
    QAction *actionPrint_Solar_System;
    QAction *action_ExportMapToImage;
    QAction *action_ExportSolarSystemToImage;
    QAction *actionExit;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionRotateLeft;
    QAction *actionRotateRight;
    QAction *action_ViewStarList;
    QAction *action_ViewRouteTo;
    QAction *action_ViewTradeRoutes;
    QAction *action_ViewSolarSystem;
    QAction *action_CreateSolarSystem;
    QAction *action_CreateTradeRoute;
    QAction *actionCreate_a_Solar_System_for_all_stars;
    QAction *actionCreate_trade_routes_for_interesting_stars;
    QAction *action_AboutWarp2010;
    QAction *action_ShowNeighbors_routes;
    QAction *action_ShowOptimalPath;
    QAction *action_ShowTradeRoutes;
    QAction *action_SaveTradeRoutes;
    QAction *action_LoadTradeRoutes;
    QAction *action_ShowOnlyStarsInTradeRoutes;
    QAction *action_TradeRoute_to_all_GardenPlanets;
    QAction *action_SolarSystemForAllStars;
    QAction *action_CopySolarSystem;
    QAction *action_Preferences;
    QAction *action_ShowAsHexMap;
    QAction *action_ExportMapToGraphVizFile;
    QAction *action_ViewOnlyTradeRoutes;
    QAction *action_Diaspora_Creation_Form;
    QAction *action_Export_Diaspora_Cluster_To_Graphviz;
    QAction *action_Export_Diaspora_Cluster_To_HTML;
    QAction *action_Export_Diaspora_Cluster_To_SVG;
    QAction *action_Save_Diaspora_Cluster;
    QAction *action_Load_Diaspora_Cluster;
    QAction *action_Generate_New_Cluster;
    QAction *action_Print_Cluster;
    QAction *actionExport_Solar_System_Data_to_HTML;
    QAction *actionExport_to_Celestia;
    QAction *action_Save_Solar_System_to_HTML;
    QAction *action_Save_Solar_System_to_Celestia_file;
    QAction *actionGu;
    QAction *action_ShowOnlyReachableStars;
    QAction *action_Export_Cluster_To_PDF;
    QAction *action_Page_Setup;
    QAction *action_map_Show_Hexmap_With_Reachable_Stars;
    QAction *action_map_Show_Hexmap_with_Trade_Route_Only;
    QAction *action_map_Show_All_Stars;
    QAction *action_map_Show_Reachable_Stars;
    QAction *action_map_Show_Stars_on_Trade_Routes_only;
    QAction *action_map_Sector_Map_Options;
    QAction *action_map_Show_Metro_Map_With_Reachable_Stars;
    QAction *action_map_Show_Metro_Map_With_Trade_Routes;
    QAction *action_Star_Sector_View;
    QAction *action_Solar_System_View;
    QAction *action_Diaspora_Cluster_View;
    QAction *action_Export_Solar_System_To_PDF;
    QAction *action_Export_Solar_System_To_SVG;
    QAction *action_Print_Solar_System;
    QAction *action_Add_New_Star;
    QAction *actionAdd_Stars_Between_Two_Stars;
    QAction *action_Clear_Star_Sector_Data;
    QAction *action_Set_XY_Mode;
    QAction *action_Set_XZ_Mode;
    QAction *action_Set_YZ_Mode;
    QAction *action_Planar_Projection_Modes;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_10;
    QSplitter *splitter_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *txtSectorName;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayout_4;
    QToolButton *btnZoomUp;
    QSlider *sliderZoom;
    QToolButton *btnZoomDown;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *btnRotateLeft;
    QSlider *sliderRotate;
    QToolButton *btnRotateRight;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    SolarSystemViewWidget *solsysView;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_8;
    DiasporaClusterDialog *clusterCreator;
    QSplitter *splitterStarInfo;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QDoubleSpinBox *spinDistance;
    QListWidget *listWidget;
    QTabWidget *tabInspectorWidget;
    QWidget *tabStarList;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblRouteTo;
    QTableWidget *routeTable;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_19;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QtColorPicker *colorPicker;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *txtRouteName;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnConfirmRoute;
    QPushButton *btnDeleteRoute;
    QPushButton *btnDeleteAllRoutes;
    QSplitter *splitter_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QListWidget *gridTradeRoutes;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLabel *lblRouteDistance;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_6;
    QTextEdit *webTradeRouteView;
    QMenuBar *menubar;
    QMenu *menuFileSector;
    QMenu *menuStar_Sector_Operations;
    QMenu *menuSolar_System_Operations;
    QMenu *menuCluster_Operations;
    QMenu *menu_Edit;
    QMenu *menu_View;
    QMenu *menu;
    QStatusBar *statusbar;
    QToolBar *toolbarStarMap;
    QToolBar *toolbarSolarSystem;
    QToolBar *toolbarCluster;
    QToolBar *toolbarSystem;
    QToolBar *toolBar;

    void setupUi(QMainWindow *WarpMainWindow)
    {
        if (WarpMainWindow->objectName().isEmpty())
            WarpMainWindow->setObjectName(QString::fromUtf8("WarpMainWindow"));
        WarpMainWindow->resize(819, 670);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Bitmaps/pics/shjp02_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        WarpMainWindow->setWindowIcon(icon);
        WarpMainWindow->setStyleSheet(QString::fromUtf8(""));
        WarpMainWindow->setTabShape(QTabWidget::Rounded);
        WarpMainWindow->setDockNestingEnabled(true);
        WarpMainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        WarpMainWindow->setUnifiedTitleAndToolBarOnMac(true);
        action_NewSector = new QAction(WarpMainWindow);
        action_NewSector->setObjectName(QString::fromUtf8("action_NewSector"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Bitmaps/pics/document-new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_NewSector->setIcon(icon1);
        action_NewSector->setVisible(true);
        actionLoad_Sector = new QAction(WarpMainWindow);
        actionLoad_Sector->setObjectName(QString::fromUtf8("actionLoad_Sector"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Bitmaps/pics/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_Sector->setIcon(icon2);
        actionSave_Sector = new QAction(WarpMainWindow);
        actionSave_Sector->setObjectName(QString::fromUtf8("actionSave_Sector"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Bitmaps/pics/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_Sector->setIcon(icon3);
        actionPrint_Sector_Map = new QAction(WarpMainWindow);
        actionPrint_Sector_Map->setObjectName(QString::fromUtf8("actionPrint_Sector_Map"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/Bitmaps/pics/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint_Sector_Map->setIcon(icon4);
        actionPrint_Trade_Route = new QAction(WarpMainWindow);
        actionPrint_Trade_Route->setObjectName(QString::fromUtf8("actionPrint_Trade_Route"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/Bitmaps/pics/document-print.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint_Trade_Route->setIcon(icon5);
        actionPrint_Solar_System = new QAction(WarpMainWindow);
        actionPrint_Solar_System->setObjectName(QString::fromUtf8("actionPrint_Solar_System"));
        actionPrint_Solar_System->setIcon(icon5);
        action_ExportMapToImage = new QAction(WarpMainWindow);
        action_ExportMapToImage->setObjectName(QString::fromUtf8("action_ExportMapToImage"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/Bitmaps/pics/mozilla_doc.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ExportMapToImage->setIcon(icon6);
        action_ExportSolarSystemToImage = new QAction(WarpMainWindow);
        action_ExportSolarSystemToImage->setObjectName(QString::fromUtf8("action_ExportSolarSystemToImage"));
        actionExit = new QAction(WarpMainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/Bitmaps/pics/system-log-out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon7);
        actionZoomIn = new QAction(WarpMainWindow);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomin.png"), QSize(), QIcon::Normal, QIcon::On);
        actionZoomIn->setIcon(icon8);
        actionZoomOut = new QAction(WarpMainWindow);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon9);
        actionRotateLeft = new QAction(WarpMainWindow);
        actionRotateLeft->setObjectName(QString::fromUtf8("actionRotateLeft"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateLeft->setIcon(icon10);
        actionRotateRight = new QAction(WarpMainWindow);
        actionRotateRight->setObjectName(QString::fromUtf8("actionRotateRight"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateright.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateRight->setIcon(icon11);
        action_ViewStarList = new QAction(WarpMainWindow);
        action_ViewStarList->setObjectName(QString::fromUtf8("action_ViewStarList"));
        action_ViewStarList->setCheckable(true);
        action_ViewStarList->setChecked(true);
        action_ViewRouteTo = new QAction(WarpMainWindow);
        action_ViewRouteTo->setObjectName(QString::fromUtf8("action_ViewRouteTo"));
        action_ViewRouteTo->setCheckable(true);
        action_ViewRouteTo->setChecked(true);
        action_ViewTradeRoutes = new QAction(WarpMainWindow);
        action_ViewTradeRoutes->setObjectName(QString::fromUtf8("action_ViewTradeRoutes"));
        action_ViewTradeRoutes->setCheckable(true);
        action_ViewTradeRoutes->setChecked(true);
        action_ViewSolarSystem = new QAction(WarpMainWindow);
        action_ViewSolarSystem->setObjectName(QString::fromUtf8("action_ViewSolarSystem"));
        action_ViewSolarSystem->setCheckable(true);
        action_CreateSolarSystem = new QAction(WarpMainWindow);
        action_CreateSolarSystem->setObjectName(QString::fromUtf8("action_CreateSolarSystem"));
        action_CreateSolarSystem->setIcon(icon1);
        action_CreateTradeRoute = new QAction(WarpMainWindow);
        action_CreateTradeRoute->setObjectName(QString::fromUtf8("action_CreateTradeRoute"));
        action_CreateTradeRoute->setIcon(icon);
        actionCreate_a_Solar_System_for_all_stars = new QAction(WarpMainWindow);
        actionCreate_a_Solar_System_for_all_stars->setObjectName(QString::fromUtf8("actionCreate_a_Solar_System_for_all_stars"));
        actionCreate_a_Solar_System_for_all_stars->setIcon(icon);
        actionCreate_trade_routes_for_interesting_stars = new QAction(WarpMainWindow);
        actionCreate_trade_routes_for_interesting_stars->setObjectName(QString::fromUtf8("actionCreate_trade_routes_for_interesting_stars"));
        action_AboutWarp2010 = new QAction(WarpMainWindow);
        action_AboutWarp2010->setObjectName(QString::fromUtf8("action_AboutWarp2010"));
        action_ShowNeighbors_routes = new QAction(WarpMainWindow);
        action_ShowNeighbors_routes->setObjectName(QString::fromUtf8("action_ShowNeighbors_routes"));
        action_ShowNeighbors_routes->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/new/Bitmaps/pics/AllTradeRoutes32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowNeighbors_routes->setIcon(icon12);
        action_ShowOptimalPath = new QAction(WarpMainWindow);
        action_ShowOptimalPath->setObjectName(QString::fromUtf8("action_ShowOptimalPath"));
        action_ShowOptimalPath->setCheckable(true);
        action_ShowOptimalPath->setChecked(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/new/Bitmaps/pics/optimalpath32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowOptimalPath->setIcon(icon13);
        action_ShowTradeRoutes = new QAction(WarpMainWindow);
        action_ShowTradeRoutes->setObjectName(QString::fromUtf8("action_ShowTradeRoutes"));
        action_ShowTradeRoutes->setCheckable(true);
        action_ShowTradeRoutes->setChecked(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/new/Bitmaps/pics/traderoute32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowTradeRoutes->setIcon(icon14);
        action_SaveTradeRoutes = new QAction(WarpMainWindow);
        action_SaveTradeRoutes->setObjectName(QString::fromUtf8("action_SaveTradeRoutes"));
        action_LoadTradeRoutes = new QAction(WarpMainWindow);
        action_LoadTradeRoutes->setObjectName(QString::fromUtf8("action_LoadTradeRoutes"));
        action_ShowOnlyStarsInTradeRoutes = new QAction(WarpMainWindow);
        action_ShowOnlyStarsInTradeRoutes->setObjectName(QString::fromUtf8("action_ShowOnlyStarsInTradeRoutes"));
        action_ShowOnlyStarsInTradeRoutes->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/new/Bitmaps/pics/nopath32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowOnlyStarsInTradeRoutes->setIcon(icon15);
        action_TradeRoute_to_all_GardenPlanets = new QAction(WarpMainWindow);
        action_TradeRoute_to_all_GardenPlanets->setObjectName(QString::fromUtf8("action_TradeRoute_to_all_GardenPlanets"));
        action_TradeRoute_to_all_GardenPlanets->setIcon(icon);
        action_SolarSystemForAllStars = new QAction(WarpMainWindow);
        action_SolarSystemForAllStars->setObjectName(QString::fromUtf8("action_SolarSystemForAllStars"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Solsys/pics/Planets/Marginal.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SolarSystemForAllStars->setIcon(icon16);
        action_CopySolarSystem = new QAction(WarpMainWindow);
        action_CopySolarSystem->setObjectName(QString::fromUtf8("action_CopySolarSystem"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/new/Bitmaps/pics/gtk-copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_CopySolarSystem->setIcon(icon17);
        action_Preferences = new QAction(WarpMainWindow);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        action_ShowAsHexMap = new QAction(WarpMainWindow);
        action_ShowAsHexMap->setObjectName(QString::fromUtf8("action_ShowAsHexMap"));
        action_ShowAsHexMap->setCheckable(true);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/new/Bitmaps/pics/hex_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_ShowAsHexMap->setIcon(icon18);
        action_ExportMapToGraphVizFile = new QAction(WarpMainWindow);
        action_ExportMapToGraphVizFile->setObjectName(QString::fromUtf8("action_ExportMapToGraphVizFile"));
        action_ExportMapToGraphVizFile->setIcon(icon13);
        action_ViewOnlyTradeRoutes = new QAction(WarpMainWindow);
        action_ViewOnlyTradeRoutes->setObjectName(QString::fromUtf8("action_ViewOnlyTradeRoutes"));
        action_ViewOnlyTradeRoutes->setCheckable(true);
        action_ViewOnlyTradeRoutes->setIcon(icon14);
        action_Diaspora_Creation_Form = new QAction(WarpMainWindow);
        action_Diaspora_Creation_Form->setObjectName(QString::fromUtf8("action_Diaspora_Creation_Form"));
        action_Export_Diaspora_Cluster_To_Graphviz = new QAction(WarpMainWindow);
        action_Export_Diaspora_Cluster_To_Graphviz->setObjectName(QString::fromUtf8("action_Export_Diaspora_Cluster_To_Graphviz"));
        action_Export_Diaspora_Cluster_To_Graphviz->setIcon(icon13);
        action_Export_Diaspora_Cluster_To_HTML = new QAction(WarpMainWindow);
        action_Export_Diaspora_Cluster_To_HTML->setObjectName(QString::fromUtf8("action_Export_Diaspora_Cluster_To_HTML"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/new/Bitmaps/pics/html.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Export_Diaspora_Cluster_To_HTML->setIcon(icon19);
        action_Export_Diaspora_Cluster_To_SVG = new QAction(WarpMainWindow);
        action_Export_Diaspora_Cluster_To_SVG->setObjectName(QString::fromUtf8("action_Export_Diaspora_Cluster_To_SVG"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/new/Bitmaps/pics/inkscape.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Export_Diaspora_Cluster_To_SVG->setIcon(icon20);
        action_Save_Diaspora_Cluster = new QAction(WarpMainWindow);
        action_Save_Diaspora_Cluster->setObjectName(QString::fromUtf8("action_Save_Diaspora_Cluster"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/new/Bitmaps/pics/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Save_Diaspora_Cluster->setIcon(icon21);
        action_Load_Diaspora_Cluster = new QAction(WarpMainWindow);
        action_Load_Diaspora_Cluster->setObjectName(QString::fromUtf8("action_Load_Diaspora_Cluster"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/new/Bitmaps/pics/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Load_Diaspora_Cluster->setIcon(icon22);
        action_Generate_New_Cluster = new QAction(WarpMainWindow);
        action_Generate_New_Cluster->setObjectName(QString::fromUtf8("action_Generate_New_Cluster"));
        action_Generate_New_Cluster->setIcon(icon1);
        action_Print_Cluster = new QAction(WarpMainWindow);
        action_Print_Cluster->setObjectName(QString::fromUtf8("action_Print_Cluster"));
        action_Print_Cluster->setIcon(icon5);
        actionExport_Solar_System_Data_to_HTML = new QAction(WarpMainWindow);
        actionExport_Solar_System_Data_to_HTML->setObjectName(QString::fromUtf8("actionExport_Solar_System_Data_to_HTML"));
        actionExport_Solar_System_Data_to_HTML->setIcon(icon19);
        actionExport_to_Celestia = new QAction(WarpMainWindow);
        actionExport_to_Celestia->setObjectName(QString::fromUtf8("actionExport_to_Celestia"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/new/Bitmaps/pics/GasGiant.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_to_Celestia->setIcon(icon23);
        action_Save_Solar_System_to_HTML = new QAction(WarpMainWindow);
        action_Save_Solar_System_to_HTML->setObjectName(QString::fromUtf8("action_Save_Solar_System_to_HTML"));
        action_Save_Solar_System_to_HTML->setIcon(icon19);
        action_Save_Solar_System_to_Celestia_file = new QAction(WarpMainWindow);
        action_Save_Solar_System_to_Celestia_file->setObjectName(QString::fromUtf8("action_Save_Solar_System_to_Celestia_file"));
        action_Save_Solar_System_to_Celestia_file->setIcon(icon3);
        actionGu = new QAction(WarpMainWindow);
        actionGu->setObjectName(QString::fromUtf8("actionGu"));
        action_ShowOnlyReachableStars = new QAction(WarpMainWindow);
        action_ShowOnlyReachableStars->setObjectName(QString::fromUtf8("action_ShowOnlyReachableStars"));
        action_ShowOnlyReachableStars->setCheckable(true);
        action_ShowOnlyReachableStars->setIcon(icon15);
        action_Export_Cluster_To_PDF = new QAction(WarpMainWindow);
        action_Export_Cluster_To_PDF->setObjectName(QString::fromUtf8("action_Export_Cluster_To_PDF"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/new/Bitmaps/pics/gnome-mime-application-pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Export_Cluster_To_PDF->setIcon(icon24);
        action_Page_Setup = new QAction(WarpMainWindow);
        action_Page_Setup->setObjectName(QString::fromUtf8("action_Page_Setup"));
        action_map_Show_Hexmap_With_Reachable_Stars = new QAction(WarpMainWindow);
        action_map_Show_Hexmap_With_Reachable_Stars->setObjectName(QString::fromUtf8("action_map_Show_Hexmap_With_Reachable_Stars"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/hex_reachable_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Hexmap_With_Reachable_Stars->setIcon(icon25);
        action_map_Show_Hexmap_with_Trade_Route_Only = new QAction(WarpMainWindow);
        action_map_Show_Hexmap_with_Trade_Route_Only->setObjectName(QString::fromUtf8("action_map_Show_Hexmap_with_Trade_Route_Only"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/hex_traderoute_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Hexmap_with_Trade_Route_Only->setIcon(icon26);
        action_map_Show_All_Stars = new QAction(WarpMainWindow);
        action_map_Show_All_Stars->setObjectName(QString::fromUtf8("action_map_Show_All_Stars"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/normal_all_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_All_Stars->setIcon(icon27);
        action_map_Show_Reachable_Stars = new QAction(WarpMainWindow);
        action_map_Show_Reachable_Stars->setObjectName(QString::fromUtf8("action_map_Show_Reachable_Stars"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/normal_reachable_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Reachable_Stars->setIcon(icon28);
        action_map_Show_Stars_on_Trade_Routes_only = new QAction(WarpMainWindow);
        action_map_Show_Stars_on_Trade_Routes_only->setObjectName(QString::fromUtf8("action_map_Show_Stars_on_Trade_Routes_only"));
        action_map_Show_Stars_on_Trade_Routes_only->setCheckable(true);
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/normal_traderoute_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Stars_on_Trade_Routes_only->setIcon(icon29);
        action_map_Sector_Map_Options = new QAction(WarpMainWindow);
        action_map_Sector_Map_Options->setObjectName(QString::fromUtf8("action_map_Sector_Map_Options"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/hex_all_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Sector_Map_Options->setIcon(icon30);
        action_map_Show_Metro_Map_With_Reachable_Stars = new QAction(WarpMainWindow);
        action_map_Show_Metro_Map_With_Reachable_Stars->setObjectName(QString::fromUtf8("action_map_Show_Metro_Map_With_Reachable_Stars"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/metro_reachable_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Metro_Map_With_Reachable_Stars->setIcon(icon31);
        action_map_Show_Metro_Map_With_Trade_Routes = new QAction(WarpMainWindow);
        action_map_Show_Metro_Map_With_Trade_Routes->setObjectName(QString::fromUtf8("action_map_Show_Metro_Map_With_Trade_Routes"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/new/Bitmaps/pics/map_icons/metro_traderoute_32.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_map_Show_Metro_Map_With_Trade_Routes->setIcon(icon32);
        action_Star_Sector_View = new QAction(WarpMainWindow);
        action_Star_Sector_View->setObjectName(QString::fromUtf8("action_Star_Sector_View"));
        action_Star_Sector_View->setCheckable(true);
        action_Star_Sector_View->setChecked(true);
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/Icons/pics/newicons/mappa_tot_64.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Star_Sector_View->setIcon(icon33);
        action_Solar_System_View = new QAction(WarpMainWindow);
        action_Solar_System_View->setObjectName(QString::fromUtf8("action_Solar_System_View"));
        action_Solar_System_View->setCheckable(true);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/Icons/pics/newicons/64.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Solar_System_View->setIcon(icon34);
        action_Diaspora_Cluster_View = new QAction(WarpMainWindow);
        action_Diaspora_Cluster_View->setObjectName(QString::fromUtf8("action_Diaspora_Cluster_View"));
        action_Diaspora_Cluster_View->setCheckable(true);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/Icons/pics/newicons/diaspora64.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Diaspora_Cluster_View->setIcon(icon35);
        action_Export_Solar_System_To_PDF = new QAction(WarpMainWindow);
        action_Export_Solar_System_To_PDF->setObjectName(QString::fromUtf8("action_Export_Solar_System_To_PDF"));
        action_Export_Solar_System_To_PDF->setIcon(icon24);
        action_Export_Solar_System_To_SVG = new QAction(WarpMainWindow);
        action_Export_Solar_System_To_SVG->setObjectName(QString::fromUtf8("action_Export_Solar_System_To_SVG"));
        action_Export_Solar_System_To_SVG->setIcon(icon20);
        action_Print_Solar_System = new QAction(WarpMainWindow);
        action_Print_Solar_System->setObjectName(QString::fromUtf8("action_Print_Solar_System"));
        action_Print_Solar_System->setIcon(icon5);
        action_Add_New_Star = new QAction(WarpMainWindow);
        action_Add_New_Star->setObjectName(QString::fromUtf8("action_Add_New_Star"));
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/new/Bitmaps/pics/gtk-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Add_New_Star->setIcon(icon36);
        actionAdd_Stars_Between_Two_Stars = new QAction(WarpMainWindow);
        actionAdd_Stars_Between_Two_Stars->setObjectName(QString::fromUtf8("actionAdd_Stars_Between_Two_Stars"));
        actionAdd_Stars_Between_Two_Stars->setIcon(icon36);
        action_Clear_Star_Sector_Data = new QAction(WarpMainWindow);
        action_Clear_Star_Sector_Data->setObjectName(QString::fromUtf8("action_Clear_Star_Sector_Data"));
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/new/Bitmaps/pics/edit-clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Clear_Star_Sector_Data->setIcon(icon37);
        action_Set_XY_Mode = new QAction(WarpMainWindow);
        action_Set_XY_Mode->setObjectName(QString::fromUtf8("action_Set_XY_Mode"));
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/new/Bitmaps/pics/xy.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Set_XY_Mode->setIcon(icon38);
        action_Set_XZ_Mode = new QAction(WarpMainWindow);
        action_Set_XZ_Mode->setObjectName(QString::fromUtf8("action_Set_XZ_Mode"));
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/new/Bitmaps/pics/xz.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Set_XZ_Mode->setIcon(icon39);
        action_Set_YZ_Mode = new QAction(WarpMainWindow);
        action_Set_YZ_Mode->setObjectName(QString::fromUtf8("action_Set_YZ_Mode"));
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/new/Bitmaps/pics/yz.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Set_YZ_Mode->setIcon(icon40);
        action_Planar_Projection_Modes = new QAction(WarpMainWindow);
        action_Planar_Projection_Modes->setObjectName(QString::fromUtf8("action_Planar_Projection_Modes"));
        action_Planar_Projection_Modes->setIcon(icon38);
        centralwidget = new QWidget(WarpMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_10 = new QHBoxLayout(centralwidget);
        horizontalLayout_10->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        splitter_3 = new QSplitter(centralwidget);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        stackedWidget = new QStackedWidget(splitter_3);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout = new QVBoxLayout(page);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMargin(0);

        horizontalLayout_6->addWidget(label_7);

        txtSectorName = new QLineEdit(page);
        txtSectorName->setObjectName(QString::fromUtf8("txtSectorName"));
        txtSectorName->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_6->addWidget(txtSectorName);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        graphicsView = new QGraphicsView(page);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(300, 0));
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        QBrush brush(QColor(211, 234, 231, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush);

        horizontalLayout_3->addWidget(graphicsView);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        btnZoomUp = new QToolButton(page);
        btnZoomUp->setObjectName(QString::fromUtf8("btnZoomUp"));
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomUp->setIcon(icon41);
        btnZoomUp->setAutoRaise(true);

        verticalLayout_4->addWidget(btnZoomUp);

        sliderZoom = new QSlider(page);
        sliderZoom->setObjectName(QString::fromUtf8("sliderZoom"));
        sliderZoom->setMinimum(1);
        sliderZoom->setMaximum(500);
        sliderZoom->setValue(250);
        sliderZoom->setOrientation(Qt::Vertical);

        verticalLayout_4->addWidget(sliderZoom);

        btnZoomDown = new QToolButton(page);
        btnZoomDown->setObjectName(QString::fromUtf8("btnZoomDown"));
        btnZoomDown->setIcon(icon9);
        btnZoomDown->setAutoRaise(true);

        verticalLayout_4->addWidget(btnZoomDown);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnRotateLeft = new QToolButton(page);
        btnRotateLeft->setObjectName(QString::fromUtf8("btnRotateLeft"));
        btnRotateLeft->setIcon(icon10);
        btnRotateLeft->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnRotateLeft);

        sliderRotate = new QSlider(page);
        sliderRotate->setObjectName(QString::fromUtf8("sliderRotate"));
        sliderRotate->setMinimum(-360);
        sliderRotate->setMaximum(360);
        sliderRotate->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(sliderRotate);

        btnRotateRight = new QToolButton(page);
        btnRotateRight->setObjectName(QString::fromUtf8("btnRotateRight"));
        btnRotateRight->setIcon(icon11);
        btnRotateRight->setAutoRaise(true);

        horizontalLayout_2->addWidget(btnRotateRight);


        verticalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(verticalLayout_5);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_7 = new QVBoxLayout(page_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(1, 1, 1, 0);
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMaximumSize(QSize(16777215, 14));

        verticalLayout_7->addWidget(label_8);

        solsysView = new SolarSystemViewWidget(page_2);
        solsysView->setObjectName(QString::fromUtf8("solsysView"));

        verticalLayout_7->addWidget(solsysView);

        verticalLayout_7->setStretch(1, 1);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        horizontalLayout_8 = new QHBoxLayout(page_3);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        clusterCreator = new DiasporaClusterDialog(page_3);
        clusterCreator->setObjectName(QString::fromUtf8("clusterCreator"));
        clusterCreator->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout_8->addWidget(clusterCreator);

        stackedWidget->addWidget(page_3);
        splitter_3->addWidget(stackedWidget);
        splitterStarInfo = new QSplitter(splitter_3);
        splitterStarInfo->setObjectName(QString::fromUtf8("splitterStarInfo"));
        splitterStarInfo->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitterStarInfo);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 2, 2, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        horizontalLayout->addWidget(label_2);

        spinDistance = new QDoubleSpinBox(layoutWidget);
        spinDistance->setObjectName(QString::fromUtf8("spinDistance"));
        spinDistance->setMinimumSize(QSize(50, 0));
        spinDistance->setStyleSheet(QString::fromUtf8(""));
        spinDistance->setDecimals(4);
        spinDistance->setMinimum(0.005);
        spinDistance->setMaximum(20);
        spinDistance->setSingleStep(0.25);
        spinDistance->setValue(7.7);

        horizontalLayout->addWidget(spinDistance);


        verticalLayout_3->addLayout(horizontalLayout);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMinimumSize(QSize(200, 0));
        listWidget->setFocusPolicy(Qt::WheelFocus);
        listWidget->setStyleSheet(QString::fromUtf8(""));
        listWidget->setFrameShape(QFrame::StyledPanel);
        listWidget->setFrameShadow(QFrame::Sunken);
        listWidget->setAlternatingRowColors(true);

        verticalLayout_3->addWidget(listWidget);

        splitterStarInfo->addWidget(layoutWidget);
        tabInspectorWidget = new QTabWidget(splitterStarInfo);
        tabInspectorWidget->setObjectName(QString::fromUtf8("tabInspectorWidget"));
        tabInspectorWidget->setMinimumSize(QSize(200, 0));
        tabInspectorWidget->setMaximumSize(QSize(280, 16777215));
        tabInspectorWidget->setAutoFillBackground(true);
        tabInspectorWidget->setTabShape(QTabWidget::Rounded);
        tabStarList = new QWidget();
        tabStarList->setObjectName(QString::fromUtf8("tabStarList"));
        verticalLayout_6 = new QVBoxLayout(tabStarList);
        verticalLayout_6->setContentsMargins(3, 3, 3, 3);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lblRouteTo = new QLabel(tabStarList);
        lblRouteTo->setObjectName(QString::fromUtf8("lblRouteTo"));

        verticalLayout_2->addWidget(lblRouteTo);

        routeTable = new QTableWidget(tabStarList);
        routeTable->setObjectName(QString::fromUtf8("routeTable"));
        routeTable->setStyleSheet(QString::fromUtf8(""));
        routeTable->setAlternatingRowColors(true);

        verticalLayout_2->addWidget(routeTable);


        verticalLayout_6->addLayout(verticalLayout_2);

        tabInspectorWidget->addTab(tabStarList, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_19 = new QVBoxLayout(tab_3);
        verticalLayout_19->setContentsMargins(3, 3, 3, 3);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 4, -1, 0);
        label = new QLabel(tab_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        colorPicker = new QtColorPicker(tab_3);
        colorPicker->setObjectName(QString::fromUtf8("colorPicker"));
        colorPicker->setMinimumSize(QSize(100, 0));
        colorPicker->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(colorPicker, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        txtRouteName = new QLineEdit(tab_3);
        txtRouteName->setObjectName(QString::fromUtf8("txtRouteName"));
        txtRouteName->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        gridLayout->addWidget(txtRouteName, 0, 1, 1, 2);


        verticalLayout_19->addLayout(gridLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 0, -1, 2);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        btnConfirmRoute = new QPushButton(tab_3);
        btnConfirmRoute->setObjectName(QString::fromUtf8("btnConfirmRoute"));
        btnConfirmRoute->setMinimumSize(QSize(50, 0));
        btnConfirmRoute->setStyleSheet(QString::fromUtf8(""));
        btnConfirmRoute->setIcon(icon36);

        horizontalLayout_5->addWidget(btnConfirmRoute);

        btnDeleteRoute = new QPushButton(tab_3);
        btnDeleteRoute->setObjectName(QString::fromUtf8("btnDeleteRoute"));
        btnDeleteRoute->setMinimumSize(QSize(50, 0));
        btnDeleteRoute->setStyleSheet(QString::fromUtf8(""));
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/new/Bitmaps/pics/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleteRoute->setIcon(icon42);

        horizontalLayout_5->addWidget(btnDeleteRoute);

        btnDeleteAllRoutes = new QPushButton(tab_3);
        btnDeleteAllRoutes->setObjectName(QString::fromUtf8("btnDeleteAllRoutes"));
        btnDeleteAllRoutes->setMinimumSize(QSize(50, 0));
        btnDeleteAllRoutes->setStyleSheet(QString::fromUtf8(""));
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/new/Bitmaps/pics/delete_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnDeleteAllRoutes->setIcon(icon43);

        horizontalLayout_5->addWidget(btnDeleteAllRoutes);


        verticalLayout_19->addLayout(horizontalLayout_5);

        splitter_2 = new QSplitter(tab_3);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget1 = new QWidget(splitter_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_9 = new QVBoxLayout(layoutWidget1);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_9->addWidget(label_4);

        gridTradeRoutes = new QListWidget(layoutWidget1);
        gridTradeRoutes->setObjectName(QString::fromUtf8("gridTradeRoutes"));
        gridTradeRoutes->setMinimumSize(QSize(200, 0));
        gridTradeRoutes->setStyleSheet(QString::fromUtf8(""));
        gridTradeRoutes->setAlternatingRowColors(true);

        verticalLayout_9->addWidget(gridTradeRoutes);

        splitter_2->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_11 = new QVBoxLayout(layoutWidget2);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        lblRouteDistance = new QLabel(layoutWidget2);
        lblRouteDistance->setObjectName(QString::fromUtf8("lblRouteDistance"));

        gridLayout_2->addWidget(lblRouteDistance, 0, 1, 1, 1);


        verticalLayout_11->addLayout(gridLayout_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_10->addWidget(label_6);

        webTradeRouteView = new QTextEdit(layoutWidget2);
        webTradeRouteView->setObjectName(QString::fromUtf8("webTradeRouteView"));
        webTradeRouteView->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_10->addWidget(webTradeRouteView);


        verticalLayout_11->addLayout(verticalLayout_10);

        splitter_2->addWidget(layoutWidget2);

        verticalLayout_19->addWidget(splitter_2);

        tabInspectorWidget->addTab(tab_3, QString());
        splitterStarInfo->addWidget(tabInspectorWidget);
        splitter_3->addWidget(splitterStarInfo);

        horizontalLayout_10->addWidget(splitter_3);

        WarpMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(WarpMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 819, 21));
        menuFileSector = new QMenu(menubar);
        menuFileSector->setObjectName(QString::fromUtf8("menuFileSector"));
        menuStar_Sector_Operations = new QMenu(menuFileSector);
        menuStar_Sector_Operations->setObjectName(QString::fromUtf8("menuStar_Sector_Operations"));
        menuSolar_System_Operations = new QMenu(menuFileSector);
        menuSolar_System_Operations->setObjectName(QString::fromUtf8("menuSolar_System_Operations"));
        menuCluster_Operations = new QMenu(menuFileSector);
        menuCluster_Operations->setObjectName(QString::fromUtf8("menuCluster_Operations"));
        menu_Edit = new QMenu(menubar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_View = new QMenu(menubar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        WarpMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(WarpMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        WarpMainWindow->setStatusBar(statusbar);
        toolbarStarMap = new QToolBar(WarpMainWindow);
        toolbarStarMap->setObjectName(QString::fromUtf8("toolbarStarMap"));
        toolbarStarMap->setStyleSheet(QString::fromUtf8(""));
        toolbarStarMap->setIconSize(QSize(32, 32));
        toolbarStarMap->setToolButtonStyle(Qt::ToolButtonIconOnly);
        WarpMainWindow->addToolBar(Qt::TopToolBarArea, toolbarStarMap);
        toolbarSolarSystem = new QToolBar(WarpMainWindow);
        toolbarSolarSystem->setObjectName(QString::fromUtf8("toolbarSolarSystem"));
        toolbarSolarSystem->setStyleSheet(QString::fromUtf8(""));
        toolbarSolarSystem->setIconSize(QSize(32, 32));
        toolbarSolarSystem->setToolButtonStyle(Qt::ToolButtonIconOnly);
        WarpMainWindow->addToolBar(Qt::TopToolBarArea, toolbarSolarSystem);
        toolbarCluster = new QToolBar(WarpMainWindow);
        toolbarCluster->setObjectName(QString::fromUtf8("toolbarCluster"));
        toolbarCluster->setStyleSheet(QString::fromUtf8(""));
        toolbarCluster->setIconSize(QSize(32, 32));
        WarpMainWindow->addToolBar(Qt::TopToolBarArea, toolbarCluster);
        toolbarSystem = new QToolBar(WarpMainWindow);
        toolbarSystem->setObjectName(QString::fromUtf8("toolbarSystem"));
        toolbarSystem->setStyleSheet(QString::fromUtf8(""));
        toolbarSystem->setMovable(false);
        toolbarSystem->setIconSize(QSize(32, 32));
        toolbarSystem->setFloatable(false);
        WarpMainWindow->addToolBar(Qt::TopToolBarArea, toolbarSystem);
        toolBar = new QToolBar(WarpMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setFloatable(false);
        WarpMainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menubar->addAction(menuFileSector->menuAction());
        menubar->addAction(menu_Edit->menuAction());
        menubar->addAction(menu_View->menuAction());
        menubar->addAction(menu->menuAction());
        menuFileSector->addAction(menuStar_Sector_Operations->menuAction());
        menuFileSector->addAction(menuSolar_System_Operations->menuAction());
        menuFileSector->addAction(menuCluster_Operations->menuAction());
        menuFileSector->addSeparator();
        menuFileSector->addAction(action_Page_Setup);
        menuFileSector->addSeparator();
        menuFileSector->addAction(actionExit);
        menuStar_Sector_Operations->addAction(action_NewSector);
        menuStar_Sector_Operations->addAction(action_Add_New_Star);
        menuStar_Sector_Operations->addAction(actionAdd_Stars_Between_Two_Stars);
        menuStar_Sector_Operations->addAction(actionLoad_Sector);
        menuStar_Sector_Operations->addAction(action_LoadTradeRoutes);
        menuStar_Sector_Operations->addAction(action_TradeRoute_to_all_GardenPlanets);
        menuStar_Sector_Operations->addSeparator();
        menuStar_Sector_Operations->addAction(actionSave_Sector);
        menuStar_Sector_Operations->addAction(action_SaveTradeRoutes);
        menuStar_Sector_Operations->addSeparator();
        menuStar_Sector_Operations->addAction(action_ExportMapToImage);
        menuStar_Sector_Operations->addAction(action_ExportMapToGraphVizFile);
        menuStar_Sector_Operations->addSeparator();
        menuStar_Sector_Operations->addAction(actionPrint_Sector_Map);
        menuStar_Sector_Operations->addAction(actionPrint_Trade_Route);
        menuStar_Sector_Operations->addSeparator();
        menuStar_Sector_Operations->addAction(action_Clear_Star_Sector_Data);
        menuSolar_System_Operations->addAction(action_CreateSolarSystem);
        menuSolar_System_Operations->addAction(action_SolarSystemForAllStars);
        menuSolar_System_Operations->addSeparator();
        menuSolar_System_Operations->addAction(action_Save_Solar_System_to_HTML);
        menuSolar_System_Operations->addAction(action_Save_Solar_System_to_Celestia_file);
        menuSolar_System_Operations->addSeparator();
        menuSolar_System_Operations->addAction(actionPrint_Solar_System);
        menuCluster_Operations->addAction(action_Generate_New_Cluster);
        menuCluster_Operations->addAction(action_Load_Diaspora_Cluster);
        menuCluster_Operations->addAction(action_Save_Diaspora_Cluster);
        menuCluster_Operations->addSeparator();
        menuCluster_Operations->addAction(action_Export_Diaspora_Cluster_To_Graphviz);
        menuCluster_Operations->addAction(action_Export_Diaspora_Cluster_To_SVG);
        menuCluster_Operations->addAction(action_Export_Diaspora_Cluster_To_HTML);
        menuCluster_Operations->addAction(action_Export_Cluster_To_PDF);
        menuCluster_Operations->addSeparator();
        menuCluster_Operations->addAction(action_Print_Cluster);
        menu_Edit->addAction(action_CopySolarSystem);
        menu_Edit->addSeparator();
        menu_Edit->addAction(action_Preferences);
        menu_View->addAction(action_Star_Sector_View);
        menu_View->addAction(action_Solar_System_View);
        menu_View->addAction(action_Diaspora_Cluster_View);
        menu->addAction(action_AboutWarp2010);
        toolbarStarMap->addAction(action_NewSector);
        toolbarStarMap->addAction(action_Add_New_Star);
        toolbarStarMap->addAction(actionLoad_Sector);
        toolbarStarMap->addAction(actionSave_Sector);
        toolbarStarMap->addAction(action_Clear_Star_Sector_Data);
        toolbarStarMap->addAction(actionPrint_Sector_Map);
        toolbarStarMap->addSeparator();
        toolbarStarMap->addAction(action_map_Sector_Map_Options);
        toolbarStarMap->addAction(action_Planar_Projection_Modes);
        toolbarStarMap->addSeparator();
        toolbarStarMap->addAction(action_ExportMapToImage);
        toolbarStarMap->addSeparator();
        toolbarStarMap->addAction(action_ExportMapToGraphVizFile);
        toolbarStarMap->addSeparator();
        toolbarSolarSystem->addAction(action_CreateSolarSystem);
        toolbarSolarSystem->addAction(action_SolarSystemForAllStars);
        toolbarSolarSystem->addAction(action_TradeRoute_to_all_GardenPlanets);
        toolbarSolarSystem->addSeparator();
        toolbarSolarSystem->addAction(action_Save_Solar_System_to_Celestia_file);
        toolbarSolarSystem->addAction(action_Print_Solar_System);
        toolbarSolarSystem->addSeparator();
        toolbarSolarSystem->addAction(action_Save_Solar_System_to_HTML);
        toolbarSolarSystem->addAction(action_Export_Solar_System_To_PDF);
        toolbarSolarSystem->addAction(action_Export_Solar_System_To_SVG);
        toolbarSolarSystem->addSeparator();
        toolbarSolarSystem->addAction(action_CopySolarSystem);
        toolbarCluster->addAction(action_Generate_New_Cluster);
        toolbarCluster->addAction(action_Load_Diaspora_Cluster);
        toolbarCluster->addAction(action_Save_Diaspora_Cluster);
        toolbarCluster->addAction(action_Export_Diaspora_Cluster_To_HTML);
        toolbarCluster->addAction(action_Export_Diaspora_Cluster_To_SVG);
        toolbarCluster->addAction(action_Export_Cluster_To_PDF);
        toolbarCluster->addAction(action_Export_Diaspora_Cluster_To_Graphviz);
        toolbarSystem->addAction(actionExit);
        toolBar->addAction(action_Star_Sector_View);
        toolBar->addAction(action_Solar_System_View);
        toolBar->addAction(action_Diaspora_Cluster_View);

        retranslateUi(WarpMainWindow);
        QObject::connect(sliderZoom, SIGNAL(valueChanged(int)), WarpMainWindow, SLOT(sliderValueChanged(int)));
        QObject::connect(sliderRotate, SIGNAL(valueChanged(int)), WarpMainWindow, SLOT(sliderValueChanged(int)));
        QObject::connect(btnRotateLeft, SIGNAL(clicked()), WarpMainWindow, SLOT(on_btnRotateLeft_clicked()));
        QObject::connect(btnRotateRight, SIGNAL(clicked()), WarpMainWindow, SLOT(on_btnRotateRight_clicked()));

        stackedWidget->setCurrentIndex(0);
        tabInspectorWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WarpMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *WarpMainWindow)
    {
        WarpMainWindow->setWindowTitle(QApplication::translate("WarpMainWindow", "Warp 2010 -- Leonov Edition", 0, QApplication::UnicodeUTF8));
        action_NewSector->setText(QApplication::translate("WarpMainWindow", "New Sector", 0, QApplication::UnicodeUTF8));
        actionLoad_Sector->setText(QApplication::translate("WarpMainWindow", "Load Sector", 0, QApplication::UnicodeUTF8));
        actionSave_Sector->setText(QApplication::translate("WarpMainWindow", "Save Sector", 0, QApplication::UnicodeUTF8));
        actionPrint_Sector_Map->setText(QApplication::translate("WarpMainWindow", "Print Sector Map", 0, QApplication::UnicodeUTF8));
        actionPrint_Trade_Route->setText(QApplication::translate("WarpMainWindow", "Print Trade Route", 0, QApplication::UnicodeUTF8));
        actionPrint_Solar_System->setText(QApplication::translate("WarpMainWindow", "Print Solar System", 0, QApplication::UnicodeUTF8));
        action_ExportMapToImage->setText(QApplication::translate("WarpMainWindow", "Export Map to image", 0, QApplication::UnicodeUTF8));
        action_ExportSolarSystemToImage->setText(QApplication::translate("WarpMainWindow", "Export To Image", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("WarpMainWindow", "E&xit", 0, QApplication::UnicodeUTF8));
        actionZoomIn->setText(QApplication::translate("WarpMainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionZoomIn->setToolTip(QApplication::translate("WarpMainWindow", "Zoom In", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionZoomOut->setText(QApplication::translate("WarpMainWindow", "Zoom Out", 0, QApplication::UnicodeUTF8));
        actionRotateLeft->setText(QApplication::translate("WarpMainWindow", "Rotate Left", 0, QApplication::UnicodeUTF8));
        actionRotateRight->setText(QApplication::translate("WarpMainWindow", "Rotate Right", 0, QApplication::UnicodeUTF8));
        action_ViewStarList->setText(QApplication::translate("WarpMainWindow", "Star List", 0, QApplication::UnicodeUTF8));
        action_ViewRouteTo->setText(QApplication::translate("WarpMainWindow", "Route to...", 0, QApplication::UnicodeUTF8));
        action_ViewTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Trade Routes", 0, QApplication::UnicodeUTF8));
        action_ViewSolarSystem->setText(QApplication::translate("WarpMainWindow", "Solar System", 0, QApplication::UnicodeUTF8));
        action_CreateSolarSystem->setText(QApplication::translate("WarpMainWindow", "New Solar System", 0, QApplication::UnicodeUTF8));
        action_CreateTradeRoute->setText(QApplication::translate("WarpMainWindow", "Trade Route", 0, QApplication::UnicodeUTF8));
        actionCreate_a_Solar_System_for_all_stars->setText(QApplication::translate("WarpMainWindow", "Create a Solar System for all stars", 0, QApplication::UnicodeUTF8));
        actionCreate_trade_routes_for_interesting_stars->setText(QApplication::translate("WarpMainWindow", "Create trade routes for interesting stars", 0, QApplication::UnicodeUTF8));
        action_AboutWarp2010->setText(QApplication::translate("WarpMainWindow", "About Warp 2010", 0, QApplication::UnicodeUTF8));
        action_ShowNeighbors_routes->setText(QApplication::translate("WarpMainWindow", "Neighbors' routes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_ShowNeighbors_routes->setToolTip(QApplication::translate("WarpMainWindow", "Show Neighbors' routes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_ShowOptimalPath->setText(QApplication::translate("WarpMainWindow", "Optimal Path", 0, QApplication::UnicodeUTF8));
        action_ShowTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Trade Routes", 0, QApplication::UnicodeUTF8));
        action_SaveTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Save Trade Routes", 0, QApplication::UnicodeUTF8));
        action_LoadTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Load Trade Routes", 0, QApplication::UnicodeUTF8));
        action_ShowOnlyStarsInTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Stars In Trade", 0, QApplication::UnicodeUTF8));
        action_TradeRoute_to_all_GardenPlanets->setText(QApplication::translate("WarpMainWindow", "Trade Route to all Garden Planets", 0, QApplication::UnicodeUTF8));
        action_SolarSystemForAllStars->setText(QApplication::translate("WarpMainWindow", "Solar System For All Stars", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_SolarSystemForAllStars->setToolTip(QApplication::translate("WarpMainWindow", "Create a Solar System For Everyl Star In List", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_CopySolarSystem->setText(QApplication::translate("WarpMainWindow", "&Copy solar system", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_CopySolarSystem->setToolTip(QApplication::translate("WarpMainWindow", "Copy solar system image to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Preferences->setText(QApplication::translate("WarpMainWindow", "&Preferences", 0, QApplication::UnicodeUTF8));
        action_ShowAsHexMap->setText(QApplication::translate("WarpMainWindow", "Show as HexMap", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_ShowAsHexMap->setToolTip(QApplication::translate("WarpMainWindow", "Switch the map to hexmap mode (useful for Traveller)", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_ExportMapToGraphVizFile->setText(QApplication::translate("WarpMainWindow", "Export Map to Graphviz file", 0, QApplication::UnicodeUTF8));
        action_ViewOnlyTradeRoutes->setText(QApplication::translate("WarpMainWindow", "Only Trade Routes", 0, QApplication::UnicodeUTF8));
        action_Diaspora_Creation_Form->setText(QApplication::translate("WarpMainWindow", "Diaspora Creation Form", 0, QApplication::UnicodeUTF8));
        action_Export_Diaspora_Cluster_To_Graphviz->setText(QApplication::translate("WarpMainWindow", "Export Cluster To Graphviz", 0, QApplication::UnicodeUTF8));
        action_Export_Diaspora_Cluster_To_HTML->setText(QApplication::translate("WarpMainWindow", "Export Cluster To HTML", 0, QApplication::UnicodeUTF8));
        action_Export_Diaspora_Cluster_To_SVG->setText(QApplication::translate("WarpMainWindow", "Export Cluster To SVG", 0, QApplication::UnicodeUTF8));
        action_Save_Diaspora_Cluster->setText(QApplication::translate("WarpMainWindow", "Save Cluster", 0, QApplication::UnicodeUTF8));
        action_Load_Diaspora_Cluster->setText(QApplication::translate("WarpMainWindow", "Load Cluster", 0, QApplication::UnicodeUTF8));
        action_Generate_New_Cluster->setText(QApplication::translate("WarpMainWindow", "New Cluster", 0, QApplication::UnicodeUTF8));
        action_Print_Cluster->setText(QApplication::translate("WarpMainWindow", "Print Cluster", 0, QApplication::UnicodeUTF8));
        actionExport_Solar_System_Data_to_HTML->setText(QApplication::translate("WarpMainWindow", "Export to HTML", 0, QApplication::UnicodeUTF8));
        actionExport_to_Celestia->setText(QApplication::translate("WarpMainWindow", "Export to Celestia", 0, QApplication::UnicodeUTF8));
        action_Save_Solar_System_to_HTML->setText(QApplication::translate("WarpMainWindow", "Save Solar System to HTML", 0, QApplication::UnicodeUTF8));
        action_Save_Solar_System_to_Celestia_file->setText(QApplication::translate("WarpMainWindow", "Save Solar System to Celestia file", 0, QApplication::UnicodeUTF8));
        actionGu->setText(QApplication::translate("WarpMainWindow", "Gu", 0, QApplication::UnicodeUTF8));
        action_ShowOnlyReachableStars->setText(QApplication::translate("WarpMainWindow", "Reachable Stars", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_ShowOnlyReachableStars->setToolTip(QApplication::translate("WarpMainWindow", "Show Only Reachable Stars", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Export_Cluster_To_PDF->setText(QApplication::translate("WarpMainWindow", "Export Cluster To PDF", 0, QApplication::UnicodeUTF8));
        action_Page_Setup->setText(QApplication::translate("WarpMainWindow", "Page Setup", 0, QApplication::UnicodeUTF8));
        action_map_Show_Hexmap_With_Reachable_Stars->setText(QApplication::translate("WarpMainWindow", "Show Hexmap With Reachable Stars", 0, QApplication::UnicodeUTF8));
        action_map_Show_Hexmap_with_Trade_Route_Only->setText(QApplication::translate("WarpMainWindow", "Show Hexmap with Trade Route Only", 0, QApplication::UnicodeUTF8));
        action_map_Show_All_Stars->setText(QApplication::translate("WarpMainWindow", "Show All Stars", 0, QApplication::UnicodeUTF8));
        action_map_Show_Reachable_Stars->setText(QApplication::translate("WarpMainWindow", "Show Reachable Stars", 0, QApplication::UnicodeUTF8));
        action_map_Show_Stars_on_Trade_Routes_only->setText(QApplication::translate("WarpMainWindow", "Show Stars on Trade Routes only", 0, QApplication::UnicodeUTF8));
        action_map_Sector_Map_Options->setText(QApplication::translate("WarpMainWindow", "Sector Map Options", 0, QApplication::UnicodeUTF8));
        action_map_Show_Metro_Map_With_Reachable_Stars->setText(QApplication::translate("WarpMainWindow", "Show Metro Map With Reachable Stars", 0, QApplication::UnicodeUTF8));
        action_map_Show_Metro_Map_With_Trade_Routes->setText(QApplication::translate("WarpMainWindow", "Show Metro Map With Trade Routes", 0, QApplication::UnicodeUTF8));
        action_Star_Sector_View->setText(QApplication::translate("WarpMainWindow", "Star Sector View", 0, QApplication::UnicodeUTF8));
        action_Solar_System_View->setText(QApplication::translate("WarpMainWindow", "Solar System View", 0, QApplication::UnicodeUTF8));
        action_Diaspora_Cluster_View->setText(QApplication::translate("WarpMainWindow", "Diaspora Cluster View", 0, QApplication::UnicodeUTF8));
        action_Export_Solar_System_To_PDF->setText(QApplication::translate("WarpMainWindow", "Export Solar System To PDF", 0, QApplication::UnicodeUTF8));
        action_Export_Solar_System_To_SVG->setText(QApplication::translate("WarpMainWindow", "Export Solar System To SVG", 0, QApplication::UnicodeUTF8));
        action_Print_Solar_System->setText(QApplication::translate("WarpMainWindow", "Print Solar System", 0, QApplication::UnicodeUTF8));
        action_Add_New_Star->setText(QApplication::translate("WarpMainWindow", "Add New Star", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Add_New_Star->setToolTip(QApplication::translate("WarpMainWindow", "Add a new star to current sector", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAdd_Stars_Between_Two_Stars->setText(QApplication::translate("WarpMainWindow", "Add Stars Between Two Stars", 0, QApplication::UnicodeUTF8));
        action_Clear_Star_Sector_Data->setText(QApplication::translate("WarpMainWindow", "Clear Star Sector Data", 0, QApplication::UnicodeUTF8));
        action_Set_XY_Mode->setText(QApplication::translate("WarpMainWindow", "Set XY Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Set_XY_Mode->setToolTip(QApplication::translate("WarpMainWindow", "Set XY Mode projection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Set_XZ_Mode->setText(QApplication::translate("WarpMainWindow", "Set XZ Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Set_XZ_Mode->setToolTip(QApplication::translate("WarpMainWindow", "Set XZ Mode Projection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Set_YZ_Mode->setText(QApplication::translate("WarpMainWindow", "Set YZ Mode", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Set_YZ_Mode->setToolTip(QApplication::translate("WarpMainWindow", "Set YZ Mode Projection", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        action_Planar_Projection_Modes->setText(QApplication::translate("WarpMainWindow", "Planar Projection Modes", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        action_Planar_Projection_Modes->setToolTip(QApplication::translate("WarpMainWindow", "Planar Projection Modes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("WarpMainWindow", "Sector Name", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        graphicsView->setToolTip(QApplication::translate("WarpMainWindow", "Star map", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btnZoomUp->setToolTip(QApplication::translate("WarpMainWindow", "Zoom in", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnZoomUp->setText(QApplication::translate("WarpMainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sliderZoom->setToolTip(QApplication::translate("WarpMainWindow", "Zoom slider", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btnZoomDown->setToolTip(QApplication::translate("WarpMainWindow", "Zoom out", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnZoomDown->setText(QApplication::translate("WarpMainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnRotateLeft->setToolTip(QApplication::translate("WarpMainWindow", "Rotate left", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnRotateLeft->setText(QApplication::translate("WarpMainWindow", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sliderRotate->setToolTip(QApplication::translate("WarpMainWindow", "Rotate map using this slider", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        btnRotateRight->setToolTip(QApplication::translate("WarpMainWindow", "Rotate right", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnRotateRight->setText(QApplication::translate("WarpMainWindow", "...", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("WarpMainWindow", "Solar System Layout", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("WarpMainWindow", "Distance in LY", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinDistance->setToolTip(QApplication::translate("WarpMainWindow", "Set jump distance.\n"
"Double click on a star below to recalculate a new jumpweb centered on the selected star using the distance as the maximum jump limit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        listWidget->setToolTip(QApplication::translate("WarpMainWindow", "Stars of the current sector", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lblRouteTo->setText(QApplication::translate("WarpMainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        routeTable->setToolTip(QApplication::translate("WarpMainWindow", "Jumps to reach selected star", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tabInspectorWidget->setTabText(tabInspectorWidget->indexOf(tabStarList), QApplication::translate("WarpMainWindow", "Reachability Details", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("WarpMainWindow", "Route Name", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("WarpMainWindow", "Route Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        colorPicker->setToolTip(QApplication::translate("WarpMainWindow", "Click here to choose the trade route color", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        colorPicker->setText(QApplication::translate("WarpMainWindow", "Color", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        btnConfirmRoute->setToolTip(QApplication::translate("WarpMainWindow", "Confirm operation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnConfirmRoute->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteRoute->setToolTip(QApplication::translate("WarpMainWindow", "Delete selected trade route", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnDeleteRoute->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnDeleteAllRoutes->setToolTip(QApplication::translate("WarpMainWindow", "Delete all Trade Routes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        btnDeleteAllRoutes->setText(QString());
        label_4->setText(QApplication::translate("WarpMainWindow", "Route List", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        gridTradeRoutes->setToolTip(QApplication::translate("WarpMainWindow", "Trade route list", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("WarpMainWindow", "Route Distance", 0, QApplication::UnicodeUTF8));
        lblRouteDistance->setText(QApplication::translate("WarpMainWindow", "\"Distance\"", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("WarpMainWindow", "Route Info", 0, QApplication::UnicodeUTF8));
        tabInspectorWidget->setTabText(tabInspectorWidget->indexOf(tab_3), QApplication::translate("WarpMainWindow", "Trade Routes", 0, QApplication::UnicodeUTF8));
        menuFileSector->setTitle(QApplication::translate("WarpMainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menuStar_Sector_Operations->setTitle(QApplication::translate("WarpMainWindow", "Star Sector Operations", 0, QApplication::UnicodeUTF8));
        menuSolar_System_Operations->setTitle(QApplication::translate("WarpMainWindow", "Solar System Operations", 0, QApplication::UnicodeUTF8));
        menuCluster_Operations->setTitle(QApplication::translate("WarpMainWindow", "Cluster Operations", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("WarpMainWindow", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("WarpMainWindow", "&View", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("WarpMainWindow", "?", 0, QApplication::UnicodeUTF8));
        toolbarStarMap->setWindowTitle(QApplication::translate("WarpMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        toolbarStarMap->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        toolbarSolarSystem->setWindowTitle(QApplication::translate("WarpMainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolbarCluster->setWindowTitle(QApplication::translate("WarpMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolbarSystem->setWindowTitle(QApplication::translate("WarpMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("WarpMainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class WarpMainWindow: public Ui_WarpMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARPMAINWINDOW_H
