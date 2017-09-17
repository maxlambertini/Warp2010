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
    static bool copyDir(const QString source, const QString destination, const bool override);

    static void initializeTextureDir(bool override = false) {
        QDir dir(textureDir());

        //if (!dir.exists(textureDir())) {
            copyDir(QCoreApplication::applicationDirPath()+"/textures/",textureDir(), override);
        //}
    }

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


    static QString provideTexture(QString texturePath, bool returnFullPath = false);

    static QStringList provideTextures(QString texturePath, bool returnFullPath = false);

    static QStringList provideAllTextures (bool returnFullPath = false);

    inline static QString preferencesFile() {
        return appDir()+"/warp.preferences";
    }

    inline static QString aspectsFile() {
        return appDir()+"/aspectlist.aspect";
    }

    inline static QString textureDir() {
        return appDir()+"/textures";
    }

    inline static QString rockballTexDir() {
        return textureDir()+"/rockball";
    }
    inline static QString provideRockball(bool returnFullPath=false) { return provideTexture(rockballTexDir() ,returnFullPath); }

    inline static QString hotHouseTexDir() {
        return textureDir()+"/hothouse";
    }
    inline static QString provideHotHouse(bool returnFullPath=false) { return provideTexture(hotHouseTexDir() ,returnFullPath); }

    inline static QString gardenTexDir() {
        return textureDir()+"/garden";
    }

    inline static QString provideGarden(bool returnFullPath=false) { return provideTexture(gardenTexDir(),returnFullPath); }

    inline static QString pregardenTexDir() {
        return textureDir()+"/pregarden";
    }
    inline static QString providePregarden(bool returnFullPath=false) { return provideTexture(pregardenTexDir() ,returnFullPath); }

    inline static QString postgardenTexDir() {
        return textureDir()+"/postgarden";
    }
    inline static QString providePostgarden(bool returnFullPath=false) { return provideTexture(postgardenTexDir() ,returnFullPath); }

    inline static QString glacierTexDir() {
        return textureDir()+"/glacier";
    }
    inline static QString provideGlacier(bool returnFullPath=false) { return provideTexture(glacierTexDir() ,returnFullPath); }

    inline static QString gasgiantTexDir() {
        return textureDir()+"/gasgiant";
    }
    inline static QString provideGasgiant(bool returnFullPath=false) { return provideTexture(gasgiantTexDir() ,returnFullPath); }

    inline static QString iceballTexDir() {
        return textureDir()+"/iceball";
    }
    inline static QString provideIceball(bool returnFullPath=false) { return provideTexture(iceballTexDir() ,returnFullPath); }

    inline static QString failedCoreTexDir() {
        return textureDir()+"/failedcore";
    }

    inline static QString provideFailedCore(bool returnFullPath=false) { return provideTexture(failedCoreTexDir() ,returnFullPath); }


    inline static QString chunkTexDir() {
        return textureDir()+"/chunk";
    }
    inline static QString provideChunk(bool returnFullPath=false) { return provideTexture(chunkTexDir() ,returnFullPath); }

    inline static QString desertTexDir() {
        return textureDir()+"/desert";
    }
    inline static QString provideDesert(bool returnFullPath=false) { return provideTexture(desertTexDir() ,returnFullPath); }


    inline static QString cloudsTexDir() {
        return textureDir()+"/clouds";
    }
    inline static QString provideClouds(bool returnFullPath=false) { return provideTexture(cloudsTexDir() ,returnFullPath); }

    inline static QString alienCloudsTexDir() {
        return textureDir()+"/clouds-alien";
    }
    inline static QString provideAlienClouds(bool returnFullPath=false) { return provideTexture(alienCloudsTexDir() ,returnFullPath); }
};

#endif // APPPATHS_H
