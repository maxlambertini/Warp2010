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


#ifndef APPPATHS_H
#define APPPATHS_H

#include <QtCore/QString>
#include <QtCore/QDir>
#include <QtCore>
#include <QStringList>

const int FILE_ITEMS = 6;
const int DIR_ITEMS = 2;


class AppPaths
{
public:
    AppPaths();
    inline static QString appDir() {
    #if defined(Q_WS_WIN)
        QString appDirPath = QCoreApplication::applicationDirPath()+"/Warp2010_Data";
        //qDebug() << appDirPath;
        return appDirPath;
    #else
        QString warpPath =  QDir::homePath()+"/.local/share/Warp2010_Data";
        QDir dir(warpPath);
        if (!dir.exists(warpPath)) {
            dir.mkpath(warpPath);

        }
        return warpPath;
    #endif
    }

    static void checkForDirectoriesAndFiles() ;


    inline static QString pluginsDir() {
        QString pluginPath = appDir()+"/plugins";
        QDir dir(pluginPath);
        if (!dir.exists(pluginPath)) {
            dir.mkpath(pluginPath);

        }
        return pluginPath;
    }

    inline static QString themesDir()  {
        QString pluginPath = appDir()+"/themes/default";
        QDir dir(pluginPath);
        if (!dir.exists(pluginPath)) {
            dir.mkpath(pluginPath);

        }
        return pluginPath;
    }

    inline static void checkOrCreate(QString path) {
        QDir dir(path);
        if (!dir.exists(path))
            dir.mkpath(path);
    }


    static QString provideTexture(QString texturePath);

    inline static QString preferencesFile() {
        return appDir()+"/warp.preferences";
    }

    inline static QString aspectsFile() {
        return appDir()+"/aspectlist.aspect";
    }

    inline static QString textureDir() {
        return appDir()+"/jstexture";
    }

    inline static QString rockballTexDir() {
        return appDir()+"/jstexture/rockball";
    }

    inline static QString hotHouseTexDir() {
        return appDir()+"/jstexture/hothouse";
    }

    inline static QString gardenTexDir() {
        return appDir()+"/jstexture/garden";
    }

    inline static QString pregardenTexDir() {
        return appDir()+"/jstexture/pregarden";
    }

    inline static QString postgardenTexDir() {
        return appDir()+"/jstexture/postgarden";
    }

    inline static QString glacierTexDir() {
        return appDir()+"/jstexture/glacier";
    }

    inline static QString gasgiantTexDir() {
        return appDir()+"/jstexture/gasgiant";
    }

    inline static QString iceballTexDir() {
        return appDir()+"/jstexture/iceball";
    }

    inline static QString failedCoreTexDir() {
        return appDir()+"/jstexture/failedcore";
    }
    inline static QString chunkTexDir() {
        return appDir()+"/jstexture/chunk";
    }

    inline static QString desertTexDir() {
        return appDir()+"/jstexture/desert";
    }
};

#endif // APPPATHS_H
