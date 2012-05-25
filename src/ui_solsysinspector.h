/********************************************************************************
** Form generated from reading UI file 'solsysinspector.ui'
**
** Created: Sun 22. Jan 22:02:00 2012
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOLSYSINSPECTOR_H
#define UI_SOLSYSINSPECTOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SolsysInspector
{
public:

    void setupUi(QWidget *SolsysInspector)
    {
        if (SolsysInspector->objectName().isEmpty())
            SolsysInspector->setObjectName(QString::fromUtf8("SolsysInspector"));
        SolsysInspector->resize(240, 320);
        QFont font;
        font.setPointSize(8);
        SolsysInspector->setFont(font);

        retranslateUi(SolsysInspector);

        QMetaObject::connectSlotsByName(SolsysInspector);
    } // setupUi

    void retranslateUi(QWidget *SolsysInspector)
    {
        SolsysInspector->setWindowTitle(QApplication::translate("SolsysInspector", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SolsysInspector: public Ui_SolsysInspector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOLSYSINSPECTOR_H
