/********************************************************************************
** Form generated from reading UI file 'diasporaclusterdialog.ui'
**
** Created: Tue 21. Feb 18:44:04 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIASPORACLUSTERDIALOG_H
#define UI_DIASPORACLUSTERDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <clusteritemeditor.h>

QT_BEGIN_NAMESPACE

class Ui_DiasporaClusterDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinNumSolSys;
    QLabel *label_2;
    QLineEdit *lblClusterName;
    QSpacerItem *horizontalSpacer_2;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *clusterView;
    QVBoxLayout *verticalLayout_6;
    QToolButton *btnZoomIn;
    QSlider *sliderZoom;
    QToolButton *btnZoomOut;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *btnRotateLeft;
    QSlider *sliderRotate;
    QToolButton *btnRotateRight;
    ClusterItemEditor *cliEditor;

    void setupUi(QWidget *DiasporaClusterDialog)
    {
        if (DiasporaClusterDialog->objectName().isEmpty())
            DiasporaClusterDialog->setObjectName(QString::fromUtf8("DiasporaClusterDialog"));
        DiasporaClusterDialog->resize(593, 475);
        DiasporaClusterDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(DiasporaClusterDialog);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DiasporaClusterDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinNumSolSys = new QSpinBox(DiasporaClusterDialog);
        spinNumSolSys->setObjectName(QString::fromUtf8("spinNumSolSys"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        spinNumSolSys->setFont(font);
        spinNumSolSys->setStyleSheet(QString::fromUtf8(""));
        spinNumSolSys->setMinimum(6);
        spinNumSolSys->setMaximum(18);

        horizontalLayout->addWidget(spinNumSolSys);

        label_2 = new QLabel(DiasporaClusterDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        lblClusterName = new QLineEdit(DiasporaClusterDialog);
        lblClusterName->setObjectName(QString::fromUtf8("lblClusterName"));
        lblClusterName->setMinimumSize(QSize(200, 0));
        lblClusterName->setFont(font);
        lblClusterName->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(lblClusterName);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(4, 10);

        verticalLayout->addLayout(horizontalLayout);

        splitter_2 = new QSplitter(DiasporaClusterDialog);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        clusterView = new QGraphicsView(layoutWidget);
        clusterView->setObjectName(QString::fromUtf8("clusterView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clusterView->sizePolicy().hasHeightForWidth());
        clusterView->setSizePolicy(sizePolicy);
        clusterView->setStyleSheet(QString::fromUtf8(""));
        QBrush brush(QColor(227, 227, 227, 255));
        brush.setStyle(Qt::NoBrush);
        clusterView->setBackgroundBrush(brush);

        horizontalLayout_4->addWidget(clusterView);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        btnZoomIn = new QToolButton(layoutWidget);
        btnZoomIn->setObjectName(QString::fromUtf8("btnZoomIn"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomIn->setIcon(icon);
        btnZoomIn->setAutoRaise(true);

        verticalLayout_6->addWidget(btnZoomIn);

        sliderZoom = new QSlider(layoutWidget);
        sliderZoom->setObjectName(QString::fromUtf8("sliderZoom"));
        sliderZoom->setMinimum(1);
        sliderZoom->setMaximum(500);
        sliderZoom->setValue(250);
        sliderZoom->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(sliderZoom);

        btnZoomOut = new QToolButton(layoutWidget);
        btnZoomOut->setObjectName(QString::fromUtf8("btnZoomOut"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/Bitmaps/pics/zoomout.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnZoomOut->setIcon(icon1);
        btnZoomOut->setAutoRaise(true);

        verticalLayout_6->addWidget(btnZoomOut);


        horizontalLayout_4->addLayout(verticalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        btnRotateLeft = new QToolButton(layoutWidget);
        btnRotateLeft->setObjectName(QString::fromUtf8("btnRotateLeft"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateleft.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRotateLeft->setIcon(icon2);
        btnRotateLeft->setAutoRaise(true);

        horizontalLayout_6->addWidget(btnRotateLeft);

        sliderRotate = new QSlider(layoutWidget);
        sliderRotate->setObjectName(QString::fromUtf8("sliderRotate"));
        sliderRotate->setMinimum(-350);
        sliderRotate->setMaximum(360);
        sliderRotate->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(sliderRotate);

        btnRotateRight = new QToolButton(layoutWidget);
        btnRotateRight->setObjectName(QString::fromUtf8("btnRotateRight"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/Bitmaps/pics/rotateright.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRotateRight->setIcon(icon3);
        btnRotateRight->setAutoRaise(true);

        horizontalLayout_6->addWidget(btnRotateRight);


        verticalLayout_2->addLayout(horizontalLayout_6);

        splitter_2->addWidget(layoutWidget);
        cliEditor = new ClusterItemEditor(splitter_2);
        cliEditor->setObjectName(QString::fromUtf8("cliEditor"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cliEditor->sizePolicy().hasHeightForWidth());
        cliEditor->setSizePolicy(sizePolicy1);
        cliEditor->setMinimumSize(QSize(180, 0));
        cliEditor->setMaximumSize(QSize(300, 16777215));
        splitter_2->addWidget(cliEditor);

        verticalLayout->addWidget(splitter_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(DiasporaClusterDialog);

        QMetaObject::connectSlotsByName(DiasporaClusterDialog);
    } // setupUi

    void retranslateUi(QWidget *DiasporaClusterDialog)
    {
        DiasporaClusterDialog->setWindowTitle(QApplication::translate("DiasporaClusterDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DiasporaClusterDialog", "# of Solar Systems", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DiasporaClusterDialog", "    Cluster name: ", 0, QApplication::UnicodeUTF8));
        btnZoomIn->setText(QApplication::translate("DiasporaClusterDialog", "...", 0, QApplication::UnicodeUTF8));
        btnZoomOut->setText(QApplication::translate("DiasporaClusterDialog", "...", 0, QApplication::UnicodeUTF8));
        btnRotateLeft->setText(QApplication::translate("DiasporaClusterDialog", "...", 0, QApplication::UnicodeUTF8));
        btnRotateRight->setText(QApplication::translate("DiasporaClusterDialog", "...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DiasporaClusterDialog: public Ui_DiasporaClusterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIASPORACLUSTERDIALOG_H
