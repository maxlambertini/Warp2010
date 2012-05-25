/********************************************************************************
** Form generated from reading UI file 'clusteritemeditor.ui'
**
** Created: Wed 15. Sep 22:48:39 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTERITEMEDITOR_H
#define UI_CLUSTERITEMEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClusterItemEditor
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtSystemName;
    QLabel *label_2;
    QPlainTextEdit *txtAspect1;
    QLabel *label_3;
    QPlainTextEdit *txtAspect2;
    QLabel *label_4;
    QPlainTextEdit *txtAspect3;
    QFrame *line;
    QLabel *Technology;
    QSpinBox *spnTech;
    QLabel *label_7;
    QSpinBox *spnRes;
    QLabel *label_8;
    QSpinBox *spnEnv;
    QFrame *line_2;
    QLabel *label_5;
    QPlainTextEdit *txtSystemDescription;
    QLabel *label_6;
    QListWidget *lstReachability;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnConfirmEditing;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *ClusterItemEditor)
    {
        if (ClusterItemEditor->objectName().isEmpty())
            ClusterItemEditor->setObjectName(QString::fromUtf8("ClusterItemEditor"));
        ClusterItemEditor->resize(412, 611);
        ClusterItemEditor->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(ClusterItemEditor);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(12);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ClusterItemEditor);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtSystemName = new QLineEdit(ClusterItemEditor);
        txtSystemName->setObjectName(QString::fromUtf8("txtSystemName"));
        txtSystemName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtSystemName, 0, 1, 1, 1);

        label_2 = new QLabel(ClusterItemEditor);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtAspect1 = new QPlainTextEdit(ClusterItemEditor);
        txtAspect1->setObjectName(QString::fromUtf8("txtAspect1"));
        txtAspect1->setMinimumSize(QSize(50, 40));

        gridLayout->addWidget(txtAspect1, 1, 1, 1, 1);

        label_3 = new QLabel(ClusterItemEditor);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtAspect2 = new QPlainTextEdit(ClusterItemEditor);
        txtAspect2->setObjectName(QString::fromUtf8("txtAspect2"));
        txtAspect2->setMinimumSize(QSize(50, 40));

        gridLayout->addWidget(txtAspect2, 2, 1, 1, 1);

        label_4 = new QLabel(ClusterItemEditor);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        txtAspect3 = new QPlainTextEdit(ClusterItemEditor);
        txtAspect3->setObjectName(QString::fromUtf8("txtAspect3"));
        txtAspect3->setMinimumSize(QSize(50, 40));

        gridLayout->addWidget(txtAspect3, 3, 1, 1, 1);

        line = new QFrame(ClusterItemEditor);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

        Technology = new QLabel(ClusterItemEditor);
        Technology->setObjectName(QString::fromUtf8("Technology"));
        Technology->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Technology, 5, 0, 1, 1);

        spnTech = new QSpinBox(ClusterItemEditor);
        spnTech->setObjectName(QString::fromUtf8("spnTech"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(spnTech->sizePolicy().hasHeightForWidth());
        spnTech->setSizePolicy(sizePolicy);
        spnTech->setMinimum(-4);
        spnTech->setMaximum(4);

        gridLayout->addWidget(spnTech, 5, 1, 1, 1);

        label_7 = new QLabel(ClusterItemEditor);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        spnRes = new QSpinBox(ClusterItemEditor);
        spnRes->setObjectName(QString::fromUtf8("spnRes"));
        sizePolicy.setHeightForWidth(spnRes->sizePolicy().hasHeightForWidth());
        spnRes->setSizePolicy(sizePolicy);
        spnRes->setMinimum(-4);
        spnRes->setMaximum(4);

        gridLayout->addWidget(spnRes, 6, 1, 1, 1);

        label_8 = new QLabel(ClusterItemEditor);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        spnEnv = new QSpinBox(ClusterItemEditor);
        spnEnv->setObjectName(QString::fromUtf8("spnEnv"));
        sizePolicy.setHeightForWidth(spnEnv->sizePolicy().hasHeightForWidth());
        spnEnv->setSizePolicy(sizePolicy);
        spnEnv->setMinimum(-4);
        spnEnv->setMaximum(4);

        gridLayout->addWidget(spnEnv, 7, 1, 1, 1);

        line_2 = new QFrame(ClusterItemEditor);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 9, 0, 1, 2);

        label_5 = new QLabel(ClusterItemEditor);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setWordWrap(true);

        gridLayout->addWidget(label_5, 10, 0, 1, 1);

        txtSystemDescription = new QPlainTextEdit(ClusterItemEditor);
        txtSystemDescription->setObjectName(QString::fromUtf8("txtSystemDescription"));
        txtSystemDescription->setMinimumSize(QSize(0, 80));

        gridLayout->addWidget(txtSystemDescription, 10, 1, 1, 1);

        label_6 = new QLabel(ClusterItemEditor);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        lstReachability = new QListWidget(ClusterItemEditor);
        lstReachability->setObjectName(QString::fromUtf8("lstReachability"));

        gridLayout->addWidget(lstReachability, 8, 1, 1, 1);

        gridLayout->setRowStretch(0, 1);

        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnConfirmEditing = new QPushButton(ClusterItemEditor);
        btnConfirmEditing->setObjectName(QString::fromUtf8("btnConfirmEditing"));
        btnConfirmEditing->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnConfirmEditing->sizePolicy().hasHeightForWidth());
        btnConfirmEditing->setSizePolicy(sizePolicy1);
        btnConfirmEditing->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(btnConfirmEditing);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(ClusterItemEditor);

        QMetaObject::connectSlotsByName(ClusterItemEditor);
    } // setupUi

    void retranslateUi(QWidget *ClusterItemEditor)
    {
        ClusterItemEditor->setWindowTitle(QApplication::translate("ClusterItemEditor", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ClusterItemEditor", "System Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ClusterItemEditor", "Aspect #1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ClusterItemEditor", "Aspect #2", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ClusterItemEditor", "Aspect #3", 0, QApplication::UnicodeUTF8));
        Technology->setText(QApplication::translate("ClusterItemEditor", "Technology", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ClusterItemEditor", "Resources", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ClusterItemEditor", "Environment", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ClusterItemEditor", "System Description", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ClusterItemEditor", "Linked to:", 0, QApplication::UnicodeUTF8));
        btnConfirmEditing->setText(QApplication::translate("ClusterItemEditor", "&Confirm System Editing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClusterItemEditor: public Ui_ClusterItemEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTERITEMEDITOR_H
