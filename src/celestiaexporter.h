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
#include <helpers/noiseimagerunner.h>
#include <QObject>
#include <QDir>
#include <QUuid>
#include <QThread>
#include <QSharedPointer>

class CelestiaExporter : public QObject
{
    Q_OBJECT

    QString _filePath;
    QString _texturePath;
    QVector<QSharedPointer<NoiseImageRunner>> vTextures;
    QVector<QFuture<void>> _futures;

public:
    CelestiaExporter() {}

    QVector<QFuture<void>>& getFutures() { return _futures; }

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
            res = QString("clouds_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Clouds,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
        }
        else {
            res = QString("f_clouds_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::FunkyClouds,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
        }

    }

    QString getPlanetTexture(Planet& p, int i) {
        QString res = "";
        switch (p.planetType()) {
        case ptGarden:
            res = QString("earthlike_%1.png").arg(getUid());
            if (p.waterPercentage() > 80)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999))));
            else if (p.waterPercentage() < 30)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike2,_texturePath+"/"+res, SSGX::dn(999999))));
            else
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike3,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptGlacier:
            res = QString("glacier_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike3,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptPostGarden:
            res = QString("postgarden_%1.png").arg(getUid());
            if (p.waterPercentage() > 80)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike2,_texturePath+"/"+res, SSGX::dn(999999))));
            else if (p.waterPercentage() < 30)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike3,_texturePath+"/"+res, SSGX::dn(999999))));
            else
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptPreGarden:
            res = QString("pregarden_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Pregarden,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptHotHouse:
            res = QString("hot_house_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Jade2,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptGasGiant:
            res = QString("gasgiant_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::GG,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptDesert:
            res = QString("desert_%1.png").arg(getUid());
            zz = SSGX::d10();
            if (zz > 8)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::DesertG,_texturePath+"/"+res,
                                                                                       SSGX::dn(999999),
                                                                                       6,2.5,0.2,1.5)));
            else if (zz  > 6)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Desert,_texturePath+"/"+res, SSGX::dn(999999),6,2.5,0.2,1.5)));
            else if (zz  > 4)
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::ComplexDesert2,_texturePath+"/"+res, SSGX::dn(999999),6,2.5,0.2,1.5)));
            else
                vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::ComplexDesert,_texturePath+"/"+res, SSGX::dn(999999),6,2.5,0.2,1.5)));
            return res;
            break;
        case ptFailedCore:
            res = QString("failedcore_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Jade,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptRockball:
            res = QString("rockball_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptIceball:
            res = QString("iceball_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Ice,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        case ptChunk:
            res = QString("chunk_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        default:
            res = QString("chunk_%1.png").arg(getUid());
            vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
            return res;
            break;
        }
    }

signals:
    void exported(int idx);
    void startExporting();
    void doneExporting();
    void textureExportStarting(int nToExport);
    void textureDoneExported();
    void textureChunkExported(int nExported);

public slots:
    void doneRendering(QString filename);

private:
    Star *_star;
    StarList * _starList;
    NoiseImageUtils niu;

    QString planetToCelestia(Planet& planet, QString starName, QString planetFatherName, int i);
    int _numTextures;
    int _curTexture;

};


#endif // CELESTIAEXPORTER_H


