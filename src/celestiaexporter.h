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


#ifndef CELESTIAEXPORTER_H
#define CELESTIAEXPORTER_H

#include <QtCore>
#include "star.h" _
#include "starlist.h"
#include "planet.h"
#include <helpers/noiseimageutils.h>
#include <QObject>
#include <QDir>
#include <QUuid>

class CelestiaExporter : public QObject
{
    Q_OBJECT

    QString _filePath;
    QString _texturePath;

public:
    CelestiaExporter() {}

    CelestiaExporter(Star *star) : _star(star)
    {
    }

    void setFilePath(QString& filePath) {
        _filePath = filePath;
        _texturePath = _filePath+"/textures/medres";
        QDir textureDir(_texturePath);
        if (!textureDir.exists())
            textureDir.mkpath(".");
    }
    QString& filePath() { return _filePath; }

    inline void setStarList (StarList * sl) { _starList = sl; }

    void saveCelestiaDataToFile(QString &filename);
    void saveStarListToCelestiaFile (QString &filename);
    void saveSolarSystemsToCelestiaFile (QString &filename);

    int zz = 1;

    QString getUid() {
        QString uid = QUuid::createUuid().toString().split('-')[1];
        return uid;
    }

    QString getCloudTexture(Planet& p, int i) {
        QString res = "";
        auto pt = p.planetType();
        if (pt == ptGarden || pt == ptGlacier ) {
            niu.CreateEarthClouds(SSGX::dn(999999));
            res = QString("clouds_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
        }
        else {
            niu.CreateFunkyClouds(SSGX::dn(999999));
            res = QString("f_clouds_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;

        }

    }

    QString getPlanetTexture(Planet& p, int i) {
        QString res = "";
        switch (p.planetType()) {
        case ptGarden:
            if (p.waterPercentage() > 80)
                niu.CreateEarthlike2(SSGX::dn(999999));
            else if (p.waterPercentage() < 30)
                niu.CreateEarthlike3(SSGX::dn(999999));
            else
                niu.CreateEarthlike(SSGX::dn(999999));
            res = QString("earthlike_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptGlacier:
            niu.CreateEarthlike3(SSGX::dn(999999));
            res = QString("glacier_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptPostGarden:
            if (p.waterPercentage() > 80)
                niu.CreateEarthlike2(SSGX::dn(999999));
            else if (p.waterPercentage() < 30)
                niu.CreateEarthlike3(SSGX::dn(999999));
            else
                niu.CreateEarthlike(SSGX::dn(999999));
            res = QString("postgarden_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptPreGarden:
            niu.CreatePregarden(SSGX::dn(999999));
            res = QString("pregarden_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptHotHouse:
            niu.CreateJade2Planet(SSGX::dn(999999));
            res = QString("hot_house_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptGasGiant:
            niu.CreateGGPlanet(SSGX::dn(999999));
            res = QString("gasgiant_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptDesert:
            zz = SSGX::d10();
            if (zz > 8)
                niu.CreateDesertG(SSGX::dn(999999));
            else if (zz  > 6)
                niu.CreateDesert(SSGX::dn(999999));
            else if (zz  > 4)
                niu.CreateComplexDesert2(SSGX::dn(999999));
            else
                niu.CreateComplexDesert(SSGX::dn(999999));
            res = QString("desert_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptFailedCore:
            niu.CreateJadePlanet(SSGX::dn(999999));
            res = QString("failedcore_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptRockball:
            niu.CreateGranitePlanet(SSGX::dn(999999));
            res = QString("rockball_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptIceball:
            niu.CreateIcePlanet(SSGX::dn(999999));
            res = QString("rockball_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        case ptChunk:
            niu.CreateGranitePlanet(SSGX::dn(999999));
            res = QString("rockball_%1.png").arg(getUid());
            niu.SaveImage(_texturePath+"/"+res);
            return res;
            break;
        default:
            return "";
        }
    }

signals:
    void exported(int idx);
    void startExporting();
    void doneExporting();

private:
    Star *_star;
    StarList * _starList;
    NoiseImageUtils niu;

    QString planetToCelestia(Planet& planet, QString starName, QString planetFatherName, int i);


};


#endif // CELESTIAEXPORTER_H


