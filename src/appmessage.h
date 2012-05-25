/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/

#ifndef APPMESSAGE_H
#define APPMESSAGE_H

#include <QtGui>

class AppMessage
{
public:
    AppMessage();
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

#endif // APPMESSAGE_H
