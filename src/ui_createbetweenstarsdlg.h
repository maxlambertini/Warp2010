/********************************************************************************
** Form generated from reading UI file 'createbetweenstarsdlg.ui'
**
** Created: Sun 22. Jan 22:02:01 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBETWEENSTARSDLG_H
#define UI_CREATEBETWEENSTARSDLG_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QListWidget>
#include <QSpacerItem>
#include <QSpinBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CreateBetweenStarsDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QListWidget *lstFrom;
    QListWidget *lstTo;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateBetweenStarsDlg)
    {
        if (CreateBetweenStarsDlg->objectName().isEmpty())
            CreateBetweenStarsDlg->setObjectName(QString::fromUtf8("CreateBetweenStarsDlg"));
        CreateBetweenStarsDlg->resize(381, 280);
        verticalLayout = new QVBoxLayout(CreateBetweenStarsDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CreateBetweenStarsDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label->setMargin(6);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(CreateBetweenStarsDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_2->setMargin(6);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(CreateBetweenStarsDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_3->setMargin(6);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox = new QSpinBox(CreateBetweenStarsDlg);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(80, 16777215));
        spinBox->setMinimum(1);
        spinBox->setMaximum(20);

        gridLayout->addWidget(spinBox, 2, 1, 1, 1);

        lstFrom = new QListWidget(CreateBetweenStarsDlg);
        lstFrom->setObjectName(QString::fromUtf8("lstFrom"));

        gridLayout->addWidget(lstFrom, 0, 1, 1, 1);

        lstTo = new QListWidget(CreateBetweenStarsDlg);
        lstTo->setObjectName(QString::fromUtf8("lstTo"));

        gridLayout->addWidget(lstTo, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(CreateBetweenStarsDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(CreateBetweenStarsDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateBetweenStarsDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateBetweenStarsDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateBetweenStarsDlg);
    } // setupUi

    void retranslateUi(QDialog *CreateBetweenStarsDlg)
    {
        CreateBetweenStarsDlg->setWindowTitle(QApplication::translate("CreateBetweenStarsDlg", "Dialog", 0));
        label->setText(QApplication::translate("CreateBetweenStarsDlg", "From", 0));
        label_2->setText(QApplication::translate("CreateBetweenStarsDlg", "To", 0));
        label_3->setText(QApplication::translate("CreateBetweenStarsDlg", "Stars to add:", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateBetweenStarsDlg: public Ui_CreateBetweenStarsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBETWEENSTARSDLG_H
