/********************************************************************************
** Form generated from reading UI file 'solarsystemviewwidget.ui'
**
** Created: Wed 22. Feb 08:44:28 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLARSYSTEMVIEWWIDGET_H
#define UI_SOLARSYSTEMVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QSlider>
#include <QSplitter>
#include <QTabWidget>
#include <QTextEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>
#include <solarsystemwidget.h>
#include <widgets/starinspector.h>
#include "widgets/planetaryinspector.h"

QT_BEGIN_NAMESPACE

class Ui_SolarSystemViewWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_3;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *solsysView;
    QVBoxLayout *verticalLayout;
    QToolButton *btnZoomUp;
    QSlider *zoomSlider;
    QToolButton *btnZoomDown;
    QHBoxLayout *horizontalLayout;
    QToolButton *btnRotateLeft;
    QSlider *rotateSlider;
    QToolButton *btnRotateRight;
    PlanetaryInspector *planetInspector;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_4;
    QSplitter *splitter_3;
    QSplitter *splitter;
    QTextEdit *txtSolSys;
    StarInspector *starInspector;
    SolarSystemWidget *solSysWidget;

    void setupUi(QWidget *SolarSystemViewWidget)
    {
        if (SolarSystemViewWidget->objectName().isEmpty())
            SolarSystemViewWidget->setObjectName(QString::fromUtf8("SolarSystemViewWidget"));
        SolarSystemViewWidget->resize(640, 480);
        horizontalLayout_5 = new QHBoxLayout(SolarSystemViewWidget);
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        tabWidget = new QTabWidget(SolarSystemViewWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMaximumSize(QSize(16777215, 1677215));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_3 = new QHBoxLayout(tab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        splitter_2 = new QSplitter(tab);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        solsysView = new QGraphicsView(layoutWidget);
        solsysView->setObjectName(QString::fromUtf8("solsysView"));

        horizontalLayout_2->addWidget(solsysView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnZoomUp = new QToolButton(layoutWidget);
        btnZoomUp->setObjectName(QString::fromUtf8("btnZoomUp"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomUp->setIcon(icon);

        verticalLayout->addWidget(btnZoomUp);

        zoomSlider = new QSlider(layoutWidget);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setMinimum(1);
        zoomSlider->setMaximum(500);
        zoomSlider->setValue(250);
        zoomSlider->setOrientation(Qt::Vertical);

        verticalLayout->addWidget(zoomSlider);

        btnZoomDown = new QToolButton(layoutWidget);
        btnZoomDown->setObjectName(QString::fromUtf8("btnZoomDown"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomDown->setIcon(icon1);

        verticalLayout->addWidget(btnZoomDown);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnRotateLeft = new QToolButton(layoutWidget);
        btnRotateLeft->setObjectName(QString::fromUtf8("btnRotateLeft"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRotateLeft->setIcon(icon2);

        horizontalLayout->addWidget(btnRotateLeft);

        rotateSlider = new QSlider(layoutWidget);
        rotateSlider->setObjectName(QString::fromUtf8("rotateSlider"));
        rotateSlider->setMinimum(-360);
        rotateSlider->setMaximum(360);
        rotateSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(rotateSlider);

        btnRotateRight = new QToolButton(layoutWidget);
        btnRotateRight->setObjectName(QString::fromUtf8("btnRotateRight"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateright.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRotateRight->setIcon(icon3);

        horizontalLayout->addWidget(btnRotateRight);


        verticalLayout_2->addLayout(horizontalLayout);

        splitter_2->addWidget(layoutWidget);
        planetInspector = new PlanetaryInspector(splitter_2);
        planetInspector->setObjectName(QString::fromUtf8("planetInspector"));
        splitter_2->addWidget(planetInspector);

        horizontalLayout_3->addWidget(splitter_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_4 = new QHBoxLayout(tab_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        splitter_3 = new QSplitter(tab_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        txtSolSys = new QTextEdit(splitter);
        txtSolSys->setObjectName(QString::fromUtf8("txtSolSys"));
        splitter->addWidget(txtSolSys);
        starInspector = new StarInspector(splitter);
        starInspector->setObjectName(QString::fromUtf8("starInspector"));
        starInspector->setMinimumSize(QSize(250, 0));
        starInspector->setMaximumSize(QSize(280, 16777215));
        splitter->addWidget(starInspector);
        splitter_3->addWidget(splitter);
        solSysWidget = new SolarSystemWidget(splitter_3);
        solSysWidget->setObjectName(QString::fromUtf8("solSysWidget"));
        solSysWidget->setMinimumSize(QSize(0, 120));
        solSysWidget->setMaximumSize(QSize(16777215, 300));
        splitter_3->addWidget(solSysWidget);

        horizontalLayout_4->addWidget(splitter_3);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_5->addWidget(tabWidget);


        retranslateUi(SolarSystemViewWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SolarSystemViewWidget);
    } // setupUi

    void retranslateUi(QWidget *SolarSystemViewWidget)
    {
        SolarSystemViewWidget->setWindowTitle(QApplication::translate("SolarSystemViewWidget", "Form", 0));
        btnZoomUp->setText(QApplication::translate("SolarSystemViewWidget", "...", 0));
        btnZoomDown->setText(QApplication::translate("SolarSystemViewWidget", "...", 0));
        btnRotateLeft->setText(QApplication::translate("SolarSystemViewWidget", "...", 0));
        btnRotateRight->setText(QApplication::translate("SolarSystemViewWidget", "...", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SolarSystemViewWidget", "Single Planet Data", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SolarSystemViewWidget", "Solar System Data", 0));
    } // retranslateUi

};

namespace Ui {
    class SolarSystemViewWidget: public Ui_SolarSystemViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLARSYSTEMVIEWWIDGET_H
