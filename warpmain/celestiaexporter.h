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

#ifndef CELESTIAEXPORTER_H
#define CELESTIAEXPORTER_H

#include <QtCore>
#include "star.h"
#include "starlist.h"
#include "planet.h"
#include <noiseimageutils.h>
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
        QString uid = QUuid::createUuid().toString().left(12);
        return uid;
    }

    QString getCloudTexture(Planet& p, int i);
    QString getPlanetTexture(Planet& p, int i);


    QString runGardenEarthlike(Planet& p, QString res);
    QString runGarden(Planet& p, QString res);
    QString runGlacier(Planet &p, QString res);
    QString runPostGarden(Planet& p, QString res);
    QString runPreGarden(Planet& p, QString res);
    QString runHotHouse(Planet& p, QString res);
    QString runGasGiant(Planet& p, QString res);
    QString runDesert(Planet& p, QString res);
    QString runFailedCore(Planet& p, QString res);
    QString runRockball(Planet& p, QString res);
    QString runIceball(Planet& p, QString res);
    QString runChunk(Planet& p, QString res);

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


