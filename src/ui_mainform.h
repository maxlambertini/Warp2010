/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created: Mon 9. Aug 11:50:38 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFormClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainFormClass)
    {
        if (MainFormClass->objectName().isEmpty())
            MainFormClass->setObjectName(QString::fromUtf8("MainFormClass"));
        MainFormClass->resize(600, 400);
        centralWidget = new QWidget(MainFormClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        MainFormClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainFormClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        MainFormClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainFormClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainFormClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainFormClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainFormClass->setStatusBar(statusBar);

        retranslateUi(MainFormClass);
        QObject::connect(pushButton, SIGNAL(clicked(bool)), MainFormClass, SLOT(setStarList()));

        QMetaObject::connectSlotsByName(MainFormClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainFormClass)
    {
        MainFormClass->setWindowTitle(QApplication::translate("MainFormClass", "MainForm", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainFormClass", "PushButton", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainFormClass: public Ui_MainFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
