/********************************************************************************
** Form generated from reading UI file 'createnewstardlg.ui'
**
** Created: Sun 22. Jan 22:02:01 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWSTARDLG_H
#define UI_CREATENEWSTARDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateNewStarDlg
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_9;
    QSpinBox *spinBox;
    QLabel *label_10;
    QCheckBox *chkTypes;
    QLineEdit *txtX;
    QLabel *label_11;
    QLabel *label_6;
    QLineEdit *txtRadius;
    QLabel *label_4;
    QLineEdit *txtY;
    QLineEdit *txtZ;
    QLabel *label_5;
    QLineEdit *txtStarName;
    QLineEdit *txtStarType;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_3;
    QLineEdit *txtDistanceFromCenter;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *CreateNewStarDlg)
    {
        if (CreateNewStarDlg->objectName().isEmpty())
            CreateNewStarDlg->setObjectName(QString::fromUtf8("CreateNewStarDlg"));
        CreateNewStarDlg->resize(298, 342);
        verticalLayout = new QVBoxLayout(CreateNewStarDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setContentsMargins(3, 3, 3, 3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(CreateNewStarDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label->setMargin(3);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(CreateNewStarDlg);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_2->setMargin(3);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_9 = new QLabel(CreateNewStarDlg);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_9->setMargin(3);

        gridLayout->addWidget(label_9, 10, 0, 1, 1);

        spinBox = new QSpinBox(CreateNewStarDlg);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMaximumSize(QSize(80, 16777215));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000);

        gridLayout->addWidget(spinBox, 10, 2, 1, 1);

        label_10 = new QLabel(CreateNewStarDlg);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMargin(3);

        gridLayout->addWidget(label_10, 11, 0, 1, 1);

        chkTypes = new QCheckBox(CreateNewStarDlg);
        chkTypes->setObjectName(QString::fromUtf8("chkTypes"));
        chkTypes->setChecked(true);

        gridLayout->addWidget(chkTypes, 11, 2, 1, 1);

        txtX = new QLineEdit(CreateNewStarDlg);
        txtX->setObjectName(QString::fromUtf8("txtX"));
        txtX->setMaximumSize(QSize(80, 16777215));
        txtX->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtX, 3, 2, 1, 1);

        label_11 = new QLabel(CreateNewStarDlg);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        label_6 = new QLabel(CreateNewStarDlg);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6->setMargin(3);

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        txtRadius = new QLineEdit(CreateNewStarDlg);
        txtRadius->setObjectName(QString::fromUtf8("txtRadius"));
        txtRadius->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(txtRadius, 8, 2, 1, 1);

        label_4 = new QLabel(CreateNewStarDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_4->setMargin(3);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        txtY = new QLineEdit(CreateNewStarDlg);
        txtY->setObjectName(QString::fromUtf8("txtY"));
        txtY->setMaximumSize(QSize(80, 16777215));
        txtY->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtY, 4, 2, 1, 1);

        txtZ = new QLineEdit(CreateNewStarDlg);
        txtZ->setObjectName(QString::fromUtf8("txtZ"));
        txtZ->setMaximumSize(QSize(80, 16777215));
        txtZ->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtZ, 5, 2, 1, 1);

        label_5 = new QLabel(CreateNewStarDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTop|Qt::AlignTrailing);
        label_5->setMargin(3);

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        txtStarName = new QLineEdit(CreateNewStarDlg);
        txtStarName->setObjectName(QString::fromUtf8("txtStarName"));
        txtStarName->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtStarName, 0, 2, 1, 1);

        txtStarType = new QLineEdit(CreateNewStarDlg);
        txtStarType->setObjectName(QString::fromUtf8("txtStarType"));
        txtStarType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(txtStarType, 1, 2, 1, 1);

        line = new QFrame(CreateNewStarDlg);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 0, 1, 3);

        line_2 = new QFrame(CreateNewStarDlg);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 7, 0, 1, 3);

        label_3 = new QLabel(CreateNewStarDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3->setMargin(3);

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        txtDistanceFromCenter = new QLineEdit(CreateNewStarDlg);
        txtDistanceFromCenter->setObjectName(QString::fromUtf8("txtDistanceFromCenter"));
        txtDistanceFromCenter->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(txtDistanceFromCenter, 9, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 22, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(CreateNewStarDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);

        QWidget::setTabOrder(txtStarName, txtStarType);
        QWidget::setTabOrder(txtStarType, txtX);
        QWidget::setTabOrder(txtX, txtY);
        QWidget::setTabOrder(txtY, txtZ);
        QWidget::setTabOrder(txtZ, txtRadius);
        QWidget::setTabOrder(txtRadius, txtDistanceFromCenter);
        QWidget::setTabOrder(txtDistanceFromCenter, spinBox);
        QWidget::setTabOrder(spinBox, chkTypes);
        QWidget::setTabOrder(chkTypes, buttonBox);

        retranslateUi(CreateNewStarDlg);

        QMetaObject::connectSlotsByName(CreateNewStarDlg);
    } // setupUi

    void retranslateUi(QWidget *CreateNewStarDlg)
    {
        CreateNewStarDlg->setWindowTitle(QApplication::translate("CreateNewStarDlg", "Create New Star", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CreateNewStarDlg", "Star Name", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CreateNewStarDlg", "Star Type", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("CreateNewStarDlg", "Num. to create:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("CreateNewStarDlg", "Randomize Star Types", 0, QApplication::UnicodeUTF8));
        chkTypes->setText(QApplication::translate("CreateNewStarDlg", "Yes", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("CreateNewStarDlg", "Center X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("CreateNewStarDlg", "Spread Radius", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("CreateNewStarDlg", "Y", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("CreateNewStarDlg", "Z", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CreateNewStarDlg", "Distance from center", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CreateNewStarDlg: public Ui_CreateNewStarDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWSTARDLG_H
