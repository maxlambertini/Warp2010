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

#include <QApplication>
#include <QtCore>
#include "scenemediator.h"
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
    //Planet::checkForTexturePath();

    //initialize files
    AppPaths::checkForDirectoriesAndFiles();

    //setuptextures
    AppPaths::initializeTextureDir();

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
