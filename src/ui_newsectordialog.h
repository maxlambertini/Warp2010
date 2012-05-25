/********************************************************************************
** Form generated from reading UI file 'newsectordialog.ui'
**
** Created: Sun 22. Jan 22:02:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSECTORDIALOG_H
#define UI_NEWSECTORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewSectorDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *txtSectorName;
    QLabel *label_4;
    QCheckBox *chkCreateSolSys;
    QSpinBox *spnStarDensity;
    QSpinBox *spnRadiusInLY;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewSectorDialog)
    {
        if (NewSectorDialog->objectName().isEmpty())
            NewSectorDialog->setObjectName(QString::fromUtf8("NewSectorDialog"));
        NewSectorDialog->resize(320, 173);
        QFont font;
        font.setPointSize(8);
        NewSectorDialog->setFont(font);
        NewSectorDialog->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(NewSectorDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NewSectorDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(NewSectorDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(NewSectorDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        txtSectorName = new QLineEdit(NewSectorDialog);
        txtSectorName->setObjectName(QString::fromUtf8("txtSectorName"));
        txtSectorName->setMinimumSize(QSize(130, 0));

        gridLayout->addWidget(txtSectorName, 0, 1, 1, 2);

        label_4 = new QLabel(NewSectorDialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        chkCreateSolSys = new QCheckBox(NewSectorDialog);
        chkCreateSolSys->setObjectName(QString::fromUtf8("chkCreateSolSys"));

        gridLayout->addWidget(chkCreateSolSys, 3, 1, 1, 1);

        spnStarDensity = new QSpinBox(NewSectorDialog);
        spnStarDensity->setObjectName(QString::fromUtf8("spnStarDensity"));
        spnStarDensity->setMinimumSize(QSize(70, 0));
        spnStarDensity->setMaximumSize(QSize(80, 16777215));
        spnStarDensity->setMinimum(500);
        spnStarDensity->setMaximum(1400);
        spnStarDensity->setSingleStep(50);
        spnStarDensity->setValue(750);

        gridLayout->addWidget(spnStarDensity, 2, 1, 1, 1);

        spnRadiusInLY = new QSpinBox(NewSectorDialog);
        spnRadiusInLY->setObjectName(QString::fromUtf8("spnRadiusInLY"));
        spnRadiusInLY->setMinimumSize(QSize(70, 0));
        spnRadiusInLY->setMaximumSize(QSize(80, 16777215));
        spnRadiusInLY->setMinimum(20);
        spnRadiusInLY->setMaximum(120);
        spnRadiusInLY->setSingleStep(5);
        spnRadiusInLY->setValue(50);

        gridLayout->addWidget(spnRadiusInLY, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(NewSectorDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewSectorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewSectorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewSectorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewSectorDialog);
    } // setupUi

    void retranslateUi(QDialog *NewSectorDialog)
    {
        NewSectorDialog->setWindowTitle(QApplication::translate("NewSectorDialog", "New Sector", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewSectorDialog", "New Sector Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewSectorDialog", "Radius in LY", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewSectorDialog", "Star Density", 0, QApplication::UnicodeUTF8));
        txtSectorName->setText(QApplication::translate("NewSectorDialog", "Solomani Rim Sector", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewSectorDialog", "Create Solar Systems", 0, QApplication::UnicodeUTF8));
        chkCreateSolSys->setText(QApplication::translate("NewSectorDialog", "Yes", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewSectorDialog: public Ui_NewSectorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSECTORDIALOG_H
