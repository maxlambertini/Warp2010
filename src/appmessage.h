/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#ifndef APPMESSAGE_H
#define APPMESSAGE_H

#include <QtGui>
#include <QMessageBox>

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
