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


#include "apppaths.h"
#include <memory>

AppPaths::AppPaths()
{
}

QString itemsToCheck[6] =
{
    QString("pics/about_box.jpg"),
    QString("pics/rex_orbiting_horza.jpg"),
    QString("aspectlist.aspect"),
    //QString("warp.preferences"),
    QString("50ly.str"),
    QString("100LY.STR"),
    QString("2300AD.STR")
};

QString dirToCheck[2] =
{
    QString("pics"),
    QString("themes")
};


void AppPaths::checkForDirectoriesAndFiles() {

    //char * buffer;

    //prima, creiamo le directory
    for (int h = 0; h < DIR_ITEMS; h++ ) {
        QString sPath = AppPaths::appDir() + "/" + dirToCheck[h];
        QDir dir(sPath);
        if (!dir.exists()) {
            dir.mkpath(sPath);
        }
        checkOrCreate(rockballTexDir());
        checkOrCreate(hotHouseTexDir());
        checkOrCreate(gardenTexDir());
        checkOrCreate(glacierTexDir());
        checkOrCreate(postgardenTexDir());
        checkOrCreate(pregardenTexDir());
        checkOrCreate(iceballTexDir());
        checkOrCreate(gasgiantTexDir());
        checkOrCreate(failedCoreTexDir());
        checkOrCreate(iceballTexDir());
        checkOrCreate(chunkTexDir());
        checkOrCreate(desertTexDir());
    }

    //poi,  creiamo i files
    for (int h = 0; h < FILE_ITEMS; h++) {
        QFile inFile(":/"+itemsToCheck[h]);
        QFile outFile (AppPaths::appDir()+"/"+ itemsToCheck[h]);
        if (!outFile.exists()) {
            //qDebug() << "creating "+ AppPaths::appDir()+"/"+ itemsToCheck[h];
            if (inFile.open(QIODevice::ReadOnly)) {
                if (outFile.open(QIODevice::WriteOnly | QIODevice::ReadWrite))
                {
                    char _buffer[8192];
                    qint64 rb = 1;
                    while (rb > 0) {
                        rb = inFile.read (_buffer,8192);
                        if (rb > 0)
                            outFile.write(_buffer,rb);
                    }
                    outFile.close();
                    inFile.close();
                    //delete buffer;
                }
            }
        }
    }
}

QString AppPaths::provideTexture(QString texturePath) {
    QDir myPath(texturePath);
    QStringList filters; filters << "*.texjson";
    myPath.setNameFilters(filters);
    QStringList entries = myPath.entryList();
    QString res;
    if (entries.count() > 0) {
        auto h = rand() % entries.count();
        res = entries[h];
    }
    return res;
}
