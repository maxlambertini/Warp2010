/********************************************************************************
** Form generated from reading UI file 'printingsetup.ui'
**
** Created: Sun 22. Jan 22:02:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINTINGSETUP_H
#define UI_PRINTINGSETUP_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QCheckBox>
#include <QComboBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QSpacerItem>
#include <QSpinBox>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PrintingSetup
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *cboPaperSizes;
    QLabel *label_2;
    QDoubleSpinBox *spnPaperHeight;
    QLabel *label_3;
    QFrame *line;
    QLabel *label_4;
    QDoubleSpinBox *spnPaperWidth;
    QDoubleSpinBox *spnLeftMargin;
    QDoubleSpinBox *spnTopMargin;
    QDoubleSpinBox *spnRightMargin;
    QDoubleSpinBox *spnBottomMargin;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spnVerticalDivisions;
    QFrame *line_2;
    QCheckBox *chkLandscape;
    QCheckBox *chkImperialSystem;
    QLabel *label_10;
    QLabel *label_7;
    QLabel *label_11;
    QSpinBox *spnHexPerSector;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PrintingSetup)
    {
        if (PrintingSetup->objectName().isEmpty())
            PrintingSetup->setObjectName(QString::fromUtf8("PrintingSetup"));
        PrintingSetup->setWindowModality(Qt::WindowModal);
        PrintingSetup->resize(270, 398);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PrintingSetup->sizePolicy().hasHeightForWidth());
        PrintingSetup->setSizePolicy(sizePolicy);
        PrintingSetup->setMaximumSize(QSize(270, 398));
        QFont font;
        font.setPointSize(8);
        PrintingSetup->setFont(font);
        PrintingSetup->setModal(true);
        verticalLayout = new QVBoxLayout(PrintingSetup);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(PrintingSetup);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label->setMargin(4);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        cboPaperSizes = new QComboBox(PrintingSetup);
        cboPaperSizes->setObjectName(QString::fromUtf8("cboPaperSizes"));
        cboPaperSizes->setMinimumSize(QSize(150, 0));

        gridLayout->addWidget(cboPaperSizes, 0, 1, 1, 1);

        label_2 = new QLabel(PrintingSetup);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_2->setMargin(4);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spnPaperHeight = new QDoubleSpinBox(PrintingSetup);
        spnPaperHeight->setObjectName(QString::fromUtf8("spnPaperHeight"));
        spnPaperHeight->setMaximumSize(QSize(90, 16777215));
        spnPaperHeight->setMaximum(2500);
        spnPaperHeight->setValue(297);

        gridLayout->addWidget(spnPaperHeight, 2, 1, 1, 1);

        label_3 = new QLabel(PrintingSetup);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_3->setMargin(4);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        line = new QFrame(PrintingSetup);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 4, 0, 1, 2);

        label_4 = new QLabel(PrintingSetup);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_4->setMargin(4);

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        spnPaperWidth = new QDoubleSpinBox(PrintingSetup);
        spnPaperWidth->setObjectName(QString::fromUtf8("spnPaperWidth"));
        spnPaperWidth->setMaximumSize(QSize(90, 16777215));
        spnPaperWidth->setMaximum(2500);
        spnPaperWidth->setValue(210);

        gridLayout->addWidget(spnPaperWidth, 1, 1, 1, 1);

        spnLeftMargin = new QDoubleSpinBox(PrintingSetup);
        spnLeftMargin->setObjectName(QString::fromUtf8("spnLeftMargin"));
        spnLeftMargin->setMaximumSize(QSize(90, 16777215));
        spnLeftMargin->setMaximum(100);
        spnLeftMargin->setValue(2);

        gridLayout->addWidget(spnLeftMargin, 5, 1, 1, 1);

        spnTopMargin = new QDoubleSpinBox(PrintingSetup);
        spnTopMargin->setObjectName(QString::fromUtf8("spnTopMargin"));
        spnTopMargin->setMaximumSize(QSize(90, 16777215));
        spnTopMargin->setMaximum(100);
        spnTopMargin->setValue(2);

        gridLayout->addWidget(spnTopMargin, 6, 1, 1, 1);

        spnRightMargin = new QDoubleSpinBox(PrintingSetup);
        spnRightMargin->setObjectName(QString::fromUtf8("spnRightMargin"));
        spnRightMargin->setMaximumSize(QSize(90, 16777215));
        spnRightMargin->setMaximum(100);
        spnRightMargin->setValue(2);

        gridLayout->addWidget(spnRightMargin, 7, 1, 1, 1);

        spnBottomMargin = new QDoubleSpinBox(PrintingSetup);
        spnBottomMargin->setObjectName(QString::fromUtf8("spnBottomMargin"));
        spnBottomMargin->setMaximumSize(QSize(90, 16777215));
        spnBottomMargin->setMaximum(100);
        spnBottomMargin->setValue(2);

        gridLayout->addWidget(spnBottomMargin, 8, 1, 1, 1);

        label_5 = new QLabel(PrintingSetup);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_5->setMargin(4);

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_6 = new QLabel(PrintingSetup);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_6->setMargin(4);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_8 = new QLabel(PrintingSetup);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_8->setMargin(4);

        gridLayout->addWidget(label_8, 10, 0, 1, 1);

        label_9 = new QLabel(PrintingSetup);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_9->setMargin(4);

        gridLayout->addWidget(label_9, 12, 0, 1, 1);

        spnVerticalDivisions = new QSpinBox(PrintingSetup);
        spnVerticalDivisions->setObjectName(QString::fromUtf8("spnVerticalDivisions"));
        spnVerticalDivisions->setMaximumSize(QSize(90, 16777215));
        spnVerticalDivisions->setMinimum(1);
        spnVerticalDivisions->setMaximum(10);
        spnVerticalDivisions->setValue(1);

        gridLayout->addWidget(spnVerticalDivisions, 10, 1, 1, 1);

        line_2 = new QFrame(PrintingSetup);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 9, 0, 1, 2);

        chkLandscape = new QCheckBox(PrintingSetup);
        chkLandscape->setObjectName(QString::fromUtf8("chkLandscape"));

        gridLayout->addWidget(chkLandscape, 12, 1, 1, 1);

        chkImperialSystem = new QCheckBox(PrintingSetup);
        chkImperialSystem->setObjectName(QString::fromUtf8("chkImperialSystem"));

        gridLayout->addWidget(chkImperialSystem, 13, 1, 1, 1);

        label_10 = new QLabel(PrintingSetup);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_10->setMargin(4);

        gridLayout->addWidget(label_10, 13, 0, 1, 1);

        label_7 = new QLabel(PrintingSetup);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_7->setMargin(4);

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        label_11 = new QLabel(PrintingSetup);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11->setMargin(4);

        gridLayout->addWidget(label_11, 11, 0, 1, 1);

        spnHexPerSector = new QSpinBox(PrintingSetup);
        spnHexPerSector->setObjectName(QString::fromUtf8("spnHexPerSector"));
        spnHexPerSector->setMinimumSize(QSize(0, 0));
        spnHexPerSector->setMaximumSize(QSize(90, 16777215));
        spnHexPerSector->setMinimum(10);
        spnHexPerSector->setMaximum(30);
        spnHexPerSector->setValue(14);

        gridLayout->addWidget(spnHexPerSector, 11, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 34, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(PrintingSetup);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PrintingSetup);
        QObject::connect(buttonBox, SIGNAL(accepted()), PrintingSetup, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PrintingSetup, SLOT(reject()));

        QMetaObject::connectSlotsByName(PrintingSetup);
    } // setupUi

    void retranslateUi(QDialog *PrintingSetup)
    {
        PrintingSetup->setWindowTitle(QApplication::translate("PrintingSetup", "Printing Setup", 0));
        label->setText(QApplication::translate("PrintingSetup", "Paper Formats", 0));
        label_2->setText(QApplication::translate("PrintingSetup", "Paper Width", 0));
        label_3->setText(QApplication::translate("PrintingSetup", "Paper Height", 0));
        label_4->setText(QApplication::translate("PrintingSetup", "Left Margin", 0));
        label_5->setText(QApplication::translate("PrintingSetup", "Top Margin", 0));
        label_6->setText(QApplication::translate("PrintingSetup", "Right Margin", 0));
        label_8->setText(QApplication::translate("PrintingSetup", "Vertical Divisions", 0));
        label_9->setText(QApplication::translate("PrintingSetup", "Landscape?", 0));
        chkLandscape->setText(QString());
        chkImperialSystem->setText(QString());
        label_10->setText(QApplication::translate("PrintingSetup", "Use Imperial Units", 0));
        label_7->setText(QApplication::translate("PrintingSetup", "Bottom Margin", 0));
        label_11->setText(QApplication::translate("PrintingSetup", "Sector side in hex", 0));
    } // retranslateUi

};

namespace Ui {
    class PrintingSetup: public Ui_PrintingSetup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINTINGSETUP_H
