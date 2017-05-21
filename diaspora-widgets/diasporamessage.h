#ifndef DIASPORAMESSAGE_H
#define DIASPORAMESSAGE_H

#include <QMessageBox>
#include "diaspora-widgets_global.h"

class  DIASPORAWIDGETSSHARED_EXPORT DiasporaMessage
{
public:
    DiasporaMessage();
    static inline void Error(QString errorText, QString errorInfo) {
         QMessageBox msgBox;
         msgBox.setIcon(QMessageBox::Critical);
         msgBox.setText("<big>"+errorText+"</big>");
         msgBox.setInformativeText(errorInfo);
         msgBox.setStandardButtons(QMessageBox::Ok );
         msgBox.setDefaultButton(QMessageBox::Ok);
         msgBox.exec();
    }

    static inline void Information(QString errorText, QString errorInfo) {
         QMessageBox msgBox;
         msgBox.setIcon(QMessageBox::Information);
         msgBox.setText("<big>"+errorText+"</big>");
         msgBox.setInformativeText(errorInfo);
         msgBox.setStandardButtons(QMessageBox::Ok );
         msgBox.setDefaultButton(QMessageBox::Ok);
         msgBox.exec();
    }

    static inline bool Question(QString questionText, QString questionInfo="") {
         QMessageBox msgBox;
         msgBox.setIcon(QMessageBox::Question);
         msgBox.setText("<big>"+questionText+"</big>");
         msgBox.setInformativeText(questionInfo);
         msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Yes);
         int code = msgBox.exec();
         return (code == QMessageBox::Yes);
    }
};

#endif // DIASPORAMESSAGE_H
