/********************************************************************************
** Form generated from reading UI file 'diasporaclusterformdlg.ui'
**
** Created: Mon 10. May 11:02:00 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIASPORACLUSTERFORMDLG_H
#define UI_DIASPORACLUSTERFORMDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinNumSolSys;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnGenerate;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_6;
    QGraphicsView *clusterView;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblName;
    QLabel *lblEnv;
    QLabel *lblTech;
    QLabel *lblRes;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QListView *lstCluster;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnRandomizeAspects;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineAspect;
    QPushButton *btnAddAspect;
    QListWidget *lstAspects;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QPlainTextEdit *txtSolSysDescription;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnSaveCluster;
    QPushButton *btnExit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(674, 485);
        verticalLayout_5 = new QVBoxLayout(Dialog);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinNumSolSys = new QSpinBox(Dialog);
        spinNumSolSys->setObjectName(QString::fromUtf8("spinNumSolSys"));
        spinNumSolSys->setMinimum(6);
        spinNumSolSys->setMaximum(14);

        horizontalLayout->addWidget(spinNumSolSys);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnGenerate = new QPushButton(Dialog);
        btnGenerate->setObjectName(QString::fromUtf8("btnGenerate"));

        horizontalLayout->addWidget(btnGenerate);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 10);
        horizontalLayout->setStretch(3, 3);

        verticalLayout_5->addLayout(horizontalLayout);

        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_6 = new QHBoxLayout(tab);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        clusterView = new QGraphicsView(tab);
        clusterView->setObjectName(QString::fromUtf8("clusterView"));

        horizontalLayout_6->addWidget(clusterView);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_5 = new QHBoxLayout(tab_2);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(-1, -1, -1, 0);
        lblName = new QLabel(tab_2);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblName->sizePolicy().hasHeightForWidth());
        lblName->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        lblName->setFont(font);
        lblName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(lblName);

        lblEnv = new QLabel(tab_2);
        lblEnv->setObjectName(QString::fromUtf8("lblEnv"));
        lblEnv->setFont(font);
        lblEnv->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(lblEnv);

        lblTech = new QLabel(tab_2);
        lblTech->setObjectName(QString::fromUtf8("lblTech"));
        lblTech->setFont(font);
        lblTech->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(lblTech);

        lblRes = new QLabel(tab_2);
        lblRes->setObjectName(QString::fromUtf8("lblRes"));
        lblRes->setFont(font);
        lblRes->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_2->addWidget(lblRes);

        horizontalLayout_2->setStretch(0, 17);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 2);

        verticalLayout_4->addLayout(horizontalLayout_2);

        splitter = new QSplitter(tab_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(5);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lstCluster = new QListView(layoutWidget);
        lstCluster->setObjectName(QString::fromUtf8("lstCluster"));

        verticalLayout->addWidget(lstCluster);

        splitter->addWidget(layoutWidget);
        layoutWidget_2 = new QWidget(splitter);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnRandomizeAspects = new QPushButton(layoutWidget_2);
        btnRandomizeAspects->setObjectName(QString::fromUtf8("btnRandomizeAspects"));

        horizontalLayout_3->addWidget(btnRandomizeAspects);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineAspect = new QLineEdit(layoutWidget_2);
        lineAspect->setObjectName(QString::fromUtf8("lineAspect"));

        horizontalLayout_4->addWidget(lineAspect);

        btnAddAspect = new QPushButton(layoutWidget_2);
        btnAddAspect->setObjectName(QString::fromUtf8("btnAddAspect"));

        horizontalLayout_4->addWidget(btnAddAspect);


        verticalLayout_3->addLayout(horizontalLayout_4);

        lstAspects = new QListWidget(layoutWidget_2);
        lstAspects->setObjectName(QString::fromUtf8("lstAspects"));

        verticalLayout_3->addWidget(lstAspects);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_5 = new QLabel(layoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);

        txtSolSysDescription = new QPlainTextEdit(layoutWidget_2);
        txtSolSysDescription->setObjectName(QString::fromUtf8("txtSolSysDescription"));

        verticalLayout_2->addWidget(txtSolSysDescription);


        verticalLayout_3->addLayout(verticalLayout_2);

        splitter->addWidget(layoutWidget_2);

        verticalLayout_4->addWidget(splitter);

        verticalLayout_4->setStretch(0, 1);

        horizontalLayout_5->addLayout(verticalLayout_4);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_5->addWidget(tabWidget);

        line = new QFrame(Dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(218, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        btnSaveCluster = new QPushButton(Dialog);
        btnSaveCluster->setObjectName(QString::fromUtf8("btnSaveCluster"));

        horizontalLayout_7->addWidget(btnSaveCluster);

        btnExit = new QPushButton(Dialog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_7->addWidget(btnExit);


        verticalLayout_5->addLayout(horizontalLayout_7);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "# of Solar Systems", 0, QApplication::UnicodeUTF8));
        btnGenerate->setText(QApplication::translate("Dialog", "&Generate Cluster", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Cluster Map", 0, QApplication::UnicodeUTF8));
        lblName->setText(QApplication::translate("Dialog", "TextLabel", 0, QApplication::UnicodeUTF8));
        lblEnv->setText(QApplication::translate("Dialog", "Env", 0, QApplication::UnicodeUTF8));
        lblTech->setText(QApplication::translate("Dialog", "Tech", 0, QApplication::UnicodeUTF8));
        lblRes->setText(QApplication::translate("Dialog", "Res", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Cluster Items", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Solar System Aspects", 0, QApplication::UnicodeUTF8));
        btnRandomizeAspects->setText(QApplication::translate("Dialog", "Randomize Aspects", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Edit Aspect", 0, QApplication::UnicodeUTF8));
        btnAddAspect->setText(QApplication::translate("Dialog", "&Add/Confirm Aspect", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "Solar system description", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Cluster Details", 0, QApplication::UnicodeUTF8));
        btnSaveCluster->setText(QApplication::translate("Dialog", "&Save Cluster", 0, QApplication::UnicodeUTF8));
        btnExit->setText(QApplication::translate("Dialog", "&Exit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIASPORACLUSTERFORMDLG_H
