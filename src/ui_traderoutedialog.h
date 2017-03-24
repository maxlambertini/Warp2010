/********************************************************************************
** Form generated from reading UI file 'traderoutedialog.ui'
**
** Created: Sun 22. Jan 22:02:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRADEROUTEDIALOG_H
#define UI_TRADEROUTEDIALOG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QSpacerItem>
#include <QSplitter>
#include <QStackedWidget>
#include <QTextEdit>
#include <QToolBar>
#include <QVBoxLayout>
#include <QWidget>
#include "qtcolorpicker.h"

QT_BEGIN_NAMESPACE

class Ui_TradeRouteDialog
{
public:
    QAction *action_NewTradeRoute;
    QAction *action_DeleteTradeRoute;
    QAction *action_EditTradeRoute;
    QAction *action_SaveTradeRoutes;
    QAction *action_LoadTradeRoutes;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *txtRouteName;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QtColorPicker *colorpicker;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAddRoute;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QListWidget *listWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QTextEdit *webView;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TradeRouteDialog)
    {
        if (TradeRouteDialog->objectName().isEmpty())
            TradeRouteDialog->setObjectName(QString::fromUtf8("TradeRouteDialog"));
        TradeRouteDialog->resize(352, 278);
        QFont font;
        font.setPointSize(8);
        TradeRouteDialog->setFont(font);
        TradeRouteDialog->setStyleSheet(QString::fromUtf8(""));
        action_NewTradeRoute = new QAction(TradeRouteDialog);
        action_NewTradeRoute->setObjectName(QString::fromUtf8("action_NewTradeRoute"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Bitmaps/pics/gtk-add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_NewTradeRoute->setIcon(icon);
        action_DeleteTradeRoute = new QAction(TradeRouteDialog);
        action_DeleteTradeRoute->setObjectName(QString::fromUtf8("action_DeleteTradeRoute"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Bitmaps/pics/list-remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_DeleteTradeRoute->setIcon(icon1);
        action_EditTradeRoute = new QAction(TradeRouteDialog);
        action_EditTradeRoute->setObjectName(QString::fromUtf8("action_EditTradeRoute"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Bitmaps/pics/applications-development.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_EditTradeRoute->setIcon(icon2);
        action_SaveTradeRoutes = new QAction(TradeRouteDialog);
        action_SaveTradeRoutes->setObjectName(QString::fromUtf8("action_SaveTradeRoutes"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Bitmaps/pics/document-save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveTradeRoutes->setIcon(icon3);
        action_LoadTradeRoutes = new QAction(TradeRouteDialog);
        action_LoadTradeRoutes->setObjectName(QString::fromUtf8("action_LoadTradeRoutes"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/Bitmaps/pics/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_LoadTradeRoutes->setIcon(icon4);
        centralwidget = new QWidget(TradeRouteDialog);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        txtRouteName = new QLineEdit(page);
        txtRouteName->setObjectName(QString::fromUtf8("txtRouteName"));

        verticalLayout->addWidget(txtRouteName);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        colorpicker = new QtColorPicker(page);
        colorpicker->setObjectName(QString::fromUtf8("colorpicker"));

        verticalLayout_2->addWidget(colorpicker);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnAddRoute = new QPushButton(page);
        btnAddRoute->setObjectName(QString::fromUtf8("btnAddRoute"));

        horizontalLayout_2->addWidget(btnAddRoute);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        verticalLayout_7 = new QVBoxLayout(page_2);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        splitter = new QSplitter(page_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_5->addWidget(listWidget);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_6->addWidget(label_4);

        webView = new QTextEdit(layoutWidget1);
        webView->setObjectName(QString::fromUtf8("webView"));

        verticalLayout_6->addWidget(webView);

        splitter->addWidget(layoutWidget1);

        verticalLayout_7->addWidget(splitter);

        stackedWidget->addWidget(page_2);

        horizontalLayout->addWidget(stackedWidget);

        TradeRouteDialog->setCentralWidget(centralwidget);
        toolBar = new QToolBar(TradeRouteDialog);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setFloatable(false);
        TradeRouteDialog->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action_NewTradeRoute);
        toolBar->addAction(action_DeleteTradeRoute);
        toolBar->addAction(action_EditTradeRoute);
        toolBar->addAction(action_SaveTradeRoutes);
        toolBar->addAction(action_LoadTradeRoutes);

        retranslateUi(TradeRouteDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(TradeRouteDialog);
    } // setupUi

    void retranslateUi(QMainWindow *TradeRouteDialog)
    {
        TradeRouteDialog->setWindowTitle(QApplication::translate("TradeRouteDialog", "Trade Route Editor", 0));
        action_NewTradeRoute->setText(QApplication::translate("TradeRouteDialog", "New Trade Route", 0));
#ifndef QT_NO_TOOLTIP
        action_NewTradeRoute->setToolTip(QApplication::translate("TradeRouteDialog", "Creates a new Trade Route", 0));
#endif // QT_NO_TOOLTIP
        action_DeleteTradeRoute->setText(QApplication::translate("TradeRouteDialog", "Delete Trade Route", 0));
#ifndef QT_NO_TOOLTIP
        action_DeleteTradeRoute->setToolTip(QApplication::translate("TradeRouteDialog", "Deletes a Trade Route", 0));
#endif // QT_NO_TOOLTIP
        action_EditTradeRoute->setText(QApplication::translate("TradeRouteDialog", "Edit Trade Route", 0));
#ifndef QT_NO_TOOLTIP
        action_EditTradeRoute->setToolTip(QApplication::translate("TradeRouteDialog", "Modifies a Trade Route", 0));
#endif // QT_NO_TOOLTIP
        action_SaveTradeRoutes->setText(QApplication::translate("TradeRouteDialog", "Save Trade Routes", 0));
        action_LoadTradeRoutes->setText(QApplication::translate("TradeRouteDialog", "Load Trade Routes", 0));
        label->setText(QApplication::translate("TradeRouteDialog", "Route Name", 0));
        label_2->setText(QApplication::translate("TradeRouteDialog", "Route Color", 0));
        btnAddRoute->setText(QApplication::translate("TradeRouteDialog", "Add Route", 0));
        label_3->setText(QApplication::translate("TradeRouteDialog", "Route List", 0));
        label_4->setText(QApplication::translate("TradeRouteDialog", "Route Description", 0));
        toolBar->setWindowTitle(QApplication::translate("TradeRouteDialog", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class TradeRouteDialog: public Ui_TradeRouteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRADEROUTEDIALOG_H
