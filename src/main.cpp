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

#include <QApplication>
#include <QtCore>
#include "mainscenehandler.h"
#include "warpmainwindowform.h"
#include "starmapwidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include "planet.h"
#include <QtPlugin>
#include <stdlib.h>
#include <time.h>
#include "helpers/splashscreen.h"
#include "helpers/graphmlexporter.h"

#ifdef WIN32
//Q_IMPORT_PLUGIN(qjpeg)
//Q_IMPORT_PLUGIN(qgif)
//Q_IMPORT_PLUGIN(qmng)
#endif

int main(int argc, char *argv[])
{
    srand(time(0)); //randomize everything!
    Q_INIT_RESOURCE(Resources);

    QApplication a(argc, argv);

    a.addLibraryPath(QCoreApplication::applicationDirPath()+"/plugins");


    //check if texture paths are present
    Planet::checkForTexturePath();

    //initialize files
    AppPaths::checkForDirectoriesAndFiles();

    WarpMainWindowForm window;
    window.resize(800,600);
    window.show();

    QString themePath = QApplication::applicationDirPath()+"/themes/default/";
    qDebug() << "checking in " << themePath;
    QDir dir(themePath);
    if (dir.exists("default.qss")) {
        qDebug() << "CSS existing....";
        QString buffer;
        QFile data(themePath+"default.qss");
        if  (data.open(QFile::ReadOnly | QFile::ReadWrite)) {
            qDebug() << "qss opened";
            QTextStream stream(&data);
            buffer = stream.readAll();
            a.setStyleSheet(buffer);
            qDebug() << "buffer: " << buffer;
         }
    }
    return a.exec();

}
