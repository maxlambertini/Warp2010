/********************************************************************************
** Form generated from reading UI file 'fontpreviewwidget.ui'
**
** Created: Sun 22. Jan 22:02:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FONTPREVIEWWIDGET_H
#define UI_FONTPREVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FontPreviewWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblFontSelected;
    QPushButton *btnSelectFont;
    QTextEdit *txtPrevirew;

    void setupUi(QWidget *FontPreviewWidget)
    {
        if (FontPreviewWidget->objectName().isEmpty())
            FontPreviewWidget->setObjectName(QString::fromUtf8("FontPreviewWidget"));
        FontPreviewWidget->resize(286, 141);
        verticalLayout = new QVBoxLayout(FontPreviewWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lblFontSelected = new QLabel(FontPreviewWidget);
        lblFontSelected->setObjectName(QString::fromUtf8("lblFontSelected"));

        horizontalLayout->addWidget(lblFontSelected);

        btnSelectFont = new QPushButton(FontPreviewWidget);
        btnSelectFont->setObjectName(QString::fromUtf8("btnSelectFont"));

        horizontalLayout->addWidget(btnSelectFont);

        horizontalLayout->setStretch(0, 4);

        verticalLayout->addLayout(horizontalLayout);

        txtPrevirew = new QTextEdit(FontPreviewWidget);
        txtPrevirew->setObjectName(QString::fromUtf8("txtPrevirew"));
        txtPrevirew->setReadOnly(true);

        verticalLayout->addWidget(txtPrevirew);

        verticalLayout->setStretch(1, 9);

        retranslateUi(FontPreviewWidget);

        QMetaObject::connectSlotsByName(FontPreviewWidget);
    } // setupUi

    void retranslateUi(QWidget *FontPreviewWidget)
    {
        FontPreviewWidget->setWindowTitle(QApplication::translate("FontPreviewWidget", "Form", 0, QApplication::UnicodeUTF8));
        lblFontSelected->setText(QApplication::translate("FontPreviewWidget", "TextLabel", 0, QApplication::UnicodeUTF8));
        btnSelectFont->setText(QApplication::translate("FontPreviewWidget", "Select &Font", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FontPreviewWidget: public Ui_FontPreviewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FONTPREVIEWWIDGET_H
