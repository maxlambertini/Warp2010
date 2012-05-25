/********************************************************************************
** Form generated from reading UI file 'createtraderoutedialog.ui'
**
** Created: Wed 15. Sep 22:48:39 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETRADEROUTEDIALOG_H
#define UI_CREATETRADEROUTEDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTradeRouteDialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtTradeRouteName;
    QWidget *ctlSelectedColor;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QPushButton *btnChangeColor;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateTradeRouteDialog)
    {
        if (CreateTradeRouteDialog->objectName().isEmpty())
            CreateTradeRouteDialog->setObjectName(QString::fromUtf8("CreateTradeRouteDialog"));
        CreateTradeRouteDialog->setWindowModality(Qt::WindowModal);
        CreateTradeRouteDialog->resize(299, 180);
        CreateTradeRouteDialog->setStyleSheet(QString::fromUtf8(""));
        CreateTradeRouteDialog->setModal(true);
        verticalLayout_4 = new QVBoxLayout(CreateTradeRouteDialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CreateTradeRouteDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtTradeRouteName = new QLineEdit(CreateTradeRouteDialog);
        txtTradeRouteName->setObjectName(QString::fromUtf8("txtTradeRouteName"));

        gridLayout->addWidget(txtTradeRouteName, 0, 1, 1, 1);

        ctlSelectedColor = new QWidget(CreateTradeRouteDialog);
        ctlSelectedColor->setObjectName(QString::fromUtf8("ctlSelectedColor"));
        ctlSelectedColor->setMinimumSize(QSize(150, 50));
        ctlSelectedColor->setAutoFillBackground(false);
        ctlSelectedColor->setStyleSheet(QString::fromUtf8(""));

        gridLayout->addWidget(ctlSelectedColor, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(CreateTradeRouteDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label_2);

        btnChangeColor = new QPushButton(CreateTradeRouteDialog);
        btnChangeColor->setObjectName(QString::fromUtf8("btnChangeColor"));

        verticalLayout_2->addWidget(btnChangeColor);


        gridLayout->addLayout(verticalLayout_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(CreateTradeRouteDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_4->addLayout(verticalLayout);


        retranslateUi(CreateTradeRouteDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateTradeRouteDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateTradeRouteDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateTradeRouteDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateTradeRouteDialog)
    {
        CreateTradeRouteDialog->setWindowTitle(QApplication::translate("CreateTradeRouteDialog", "Create Trade Route", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateTradeRouteDialog", "Trade Route Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateTradeRouteDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Trade route color</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        btnChangeColor->setText(QApplication::translate("CreateTradeRouteDialog", "Change Color", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateTradeRouteDialog: public Ui_CreateTradeRouteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETRADEROUTEDIALOG_H
