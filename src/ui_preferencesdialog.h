/********************************************************************************
** Form generated from reading UI file 'preferencesdialog.ui'
**
** Created: Wed 15. Sep 22:48:39 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "qtcolorpicker.h"
#include "widgets/fontpreviewwidget.h"

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QAction *action_Title_Font;
    QAction *action_Aspect_Title_Font;
    QAction *action_Body_Font;
    QAction *action_Small_Font;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QtColorPicker *colorMainRoute;
    QtColorPicker *colorSecondary;
    QtColorPicker *colorDiasporaBox;
    QtColorPicker *colorDiasporaBoxBackground;
    QtColorPicker *colorDiasporaLinks;
    QRadioButton *rdoStraightLines;
    QRadioButton *rdoArcs;
    QCheckBox *chkShowSecondaryRoutes;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    FontPreviewWidget *fontSelector;
    QToolButton *btnTitleFont;
    QToolButton *btnAspectTitleFont;
    QToolButton *btnBodyFont;
    QToolButton *btnSmallFont;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QString::fromUtf8("PreferencesDialog"));
        PreferencesDialog->resize(499, 381);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreferencesDialog->sizePolicy().hasHeightForWidth());
        PreferencesDialog->setSizePolicy(sizePolicy);
        PreferencesDialog->setStyleSheet(QString::fromUtf8(""));
        action_Title_Font = new QAction(PreferencesDialog);
        action_Title_Font->setObjectName(QString::fromUtf8("action_Title_Font"));
        action_Title_Font->setCheckable(true);
        action_Aspect_Title_Font = new QAction(PreferencesDialog);
        action_Aspect_Title_Font->setObjectName(QString::fromUtf8("action_Aspect_Title_Font"));
        action_Aspect_Title_Font->setCheckable(true);
        action_Body_Font = new QAction(PreferencesDialog);
        action_Body_Font->setObjectName(QString::fromUtf8("action_Body_Font"));
        action_Body_Font->setCheckable(true);
        action_Small_Font = new QAction(PreferencesDialog);
        action_Small_Font->setObjectName(QString::fromUtf8("action_Small_Font"));
        action_Small_Font->setCheckable(true);
        verticalLayout_3 = new QVBoxLayout(PreferencesDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tabWidget = new QTabWidget(PreferencesDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        colorMainRoute = new QtColorPicker(tab);
        colorMainRoute->setObjectName(QString::fromUtf8("colorMainRoute"));
        colorMainRoute->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(colorMainRoute, 0, 2, 1, 1);

        colorSecondary = new QtColorPicker(tab);
        colorSecondary->setObjectName(QString::fromUtf8("colorSecondary"));
        colorSecondary->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(colorSecondary, 1, 2, 1, 1);

        colorDiasporaBox = new QtColorPicker(tab);
        colorDiasporaBox->setObjectName(QString::fromUtf8("colorDiasporaBox"));
        colorDiasporaBox->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(colorDiasporaBox, 2, 2, 1, 1);

        colorDiasporaBoxBackground = new QtColorPicker(tab);
        colorDiasporaBoxBackground->setObjectName(QString::fromUtf8("colorDiasporaBoxBackground"));
        colorDiasporaBoxBackground->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(colorDiasporaBoxBackground, 3, 2, 1, 1);

        colorDiasporaLinks = new QtColorPicker(tab);
        colorDiasporaLinks->setObjectName(QString::fromUtf8("colorDiasporaLinks"));
        colorDiasporaLinks->setMinimumSize(QSize(100, 30));

        gridLayout->addWidget(colorDiasporaLinks, 4, 2, 1, 1);

        rdoStraightLines = new QRadioButton(tab);
        rdoStraightLines->setObjectName(QString::fromUtf8("rdoStraightLines"));

        gridLayout->addWidget(rdoStraightLines, 6, 2, 1, 1);

        rdoArcs = new QRadioButton(tab);
        rdoArcs->setObjectName(QString::fromUtf8("rdoArcs"));
        rdoArcs->setChecked(true);

        gridLayout->addWidget(rdoArcs, 7, 2, 1, 1);

        chkShowSecondaryRoutes = new QCheckBox(tab);
        chkShowSecondaryRoutes->setObjectName(QString::fromUtf8("chkShowSecondaryRoutes"));

        gridLayout->addWidget(chkShowSecondaryRoutes, 8, 2, 1, 1);

        line = new QFrame(tab);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 5, 1, 1, 2);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 1, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 1, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 6, 1, 1, 1);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 8, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_5->addLayout(verticalLayout_4);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_6 = new QVBoxLayout(tab_2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        fontSelector = new FontPreviewWidget(tab_2);
        fontSelector->setObjectName(QString::fromUtf8("fontSelector"));
        fontSelector->setMinimumSize(QSize(0, 150));

        gridLayout_2->addWidget(fontSelector, 1, 1, 5, 2);

        btnTitleFont = new QToolButton(tab_2);
        btnTitleFont->setObjectName(QString::fromUtf8("btnTitleFont"));
        btnTitleFont->setMinimumSize(QSize(170, 0));
        btnTitleFont->setCheckable(true);

        gridLayout_2->addWidget(btnTitleFont, 1, 0, 1, 1);

        btnAspectTitleFont = new QToolButton(tab_2);
        btnAspectTitleFont->setObjectName(QString::fromUtf8("btnAspectTitleFont"));
        btnAspectTitleFont->setMinimumSize(QSize(170, 0));
        btnAspectTitleFont->setCheckable(true);

        gridLayout_2->addWidget(btnAspectTitleFont, 2, 0, 1, 1);

        btnBodyFont = new QToolButton(tab_2);
        btnBodyFont->setObjectName(QString::fromUtf8("btnBodyFont"));
        btnBodyFont->setMinimumSize(QSize(170, 0));
        btnBodyFont->setCheckable(true);

        gridLayout_2->addWidget(btnBodyFont, 3, 0, 1, 1);

        btnSmallFont = new QToolButton(tab_2);
        btnSmallFont->setObjectName(QString::fromUtf8("btnSmallFont"));
        btnSmallFont->setMinimumSize(QSize(170, 0));
        btnSmallFont->setCheckable(true);

        gridLayout_2->addWidget(btnSmallFont, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_6->addLayout(verticalLayout);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_3->addWidget(tabWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        buttonBox = new QDialogButtonBox(PreferencesDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(PreferencesDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PreferencesDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PreferencesDialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QApplication::translate("PreferencesDialog", "Preferen ces", 0, QApplication::UnicodeUTF8));
        action_Title_Font->setText(QApplication::translate("PreferencesDialog", "Title Font", 0, QApplication::UnicodeUTF8));
        action_Aspect_Title_Font->setText(QApplication::translate("PreferencesDialog", "Aspect Title Font", 0, QApplication::UnicodeUTF8));
        action_Body_Font->setText(QApplication::translate("PreferencesDialog", "Body Font", 0, QApplication::UnicodeUTF8));
        action_Small_Font->setText(QApplication::translate("PreferencesDialog", "Small Font", 0, QApplication::UnicodeUTF8));
        colorMainRoute->setText(QApplication::translate("PreferencesDialog", "color", 0, QApplication::UnicodeUTF8));
        colorSecondary->setText(QApplication::translate("PreferencesDialog", "color", 0, QApplication::UnicodeUTF8));
        colorDiasporaBox->setText(QApplication::translate("PreferencesDialog", "color", 0, QApplication::UnicodeUTF8));
        colorDiasporaBoxBackground->setText(QApplication::translate("PreferencesDialog", "color", 0, QApplication::UnicodeUTF8));
        colorDiasporaLinks->setText(QApplication::translate("PreferencesDialog", "color", 0, QApplication::UnicodeUTF8));
        rdoStraightLines->setText(QApplication::translate("PreferencesDialog", "Straight Lines", 0, QApplication::UnicodeUTF8));
        rdoArcs->setText(QApplication::translate("PreferencesDialog", "Arcs", 0, QApplication::UnicodeUTF8));
        chkShowSecondaryRoutes->setText(QApplication::translate("PreferencesDialog", "Yes", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreferencesDialog", "Main Route Default Color", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PreferencesDialog", "Secondary Route Default Color", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PreferencesDialog", "Diaspora Box Color", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PreferencesDialog", "Diaspora Box Background", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PreferencesDialog", "Diaspora Links", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PreferencesDialog", "On Star Map, draw routes as...", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PreferencesDialog", "Show secondary, non direct routes", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("PreferencesDialog", "Colors and Map Options", 0, QApplication::UnicodeUTF8));
        btnTitleFont->setText(QApplication::translate("PreferencesDialog", "Title Font", 0, QApplication::UnicodeUTF8));
        btnAspectTitleFont->setText(QApplication::translate("PreferencesDialog", "Aspect Title Font", 0, QApplication::UnicodeUTF8));
        btnBodyFont->setText(QApplication::translate("PreferencesDialog", "Body Font", 0, QApplication::UnicodeUTF8));
        btnSmallFont->setText(QApplication::translate("PreferencesDialog", "Small Font", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("PreferencesDialog", "Fonts", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H
