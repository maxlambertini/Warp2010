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

#include "celestiaexporter.h"
#include <QtCore>
#include "star.h"
#include "starlist.h"
#include "planet.h"
#include "ssg_structures.h"
#include <QObject>
#include <QtConcurrent/QtConcurrent>
#include <helpers/apppaths.h>

void CelestiaExporter::saveStarListToCelestiaFile (QString &filename) {
    QString sOutput;
    QTextStream stream(&sOutput);

    QSharedPointer<Star> star;
    int iHip = 500002 + SSGX::dx(699999);
   foreach (star, _starList->stars()) {
        stream << star.data()->getCelestiaStcEntry(iHip++);
    }

    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QTextStream out(&data);
         out << sOutput;
         out.flush();
     }
     data.close();
     QString filenamessc = filename+".ssc";


     this->saveSolarSystemsToCelestiaFile(filenamessc);
}

void CelestiaExporter::saveSolarSystemsToCelestiaFile (QString &filename) {
    emit this->startExporting();
    QString sOutput;
    QTextStream stream(&sOutput);


    QSharedPointer<Star> star;
    Planet planet, sat;
    int i = 10000;
    int nCount = 0;
    foreach (star, _starList->stars()) {
        i += 10;
        this->_star = star.data();
        foreach (planet, _star->planets()) {
            i += 10;
            QString starName = _star->starName;
            stream << this->planetToCelestia(planet,starName,"",i);
            // qDebug() << "celestia exporting " << planet.name();
            foreach (sat, planet.satellites()) {
                i += 10;
                stream << this->planetToCelestia(sat,_star->starName,planet.name(),i);
                // qDebug() << "celestia exporting sat " << sat.name();
            }
        }
        emit this->exported(nCount++);
    }

    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QTextStream out(&data);
         out << sOutput;
         out.flush();
     }
     data.close();
     emit this->doneExporting();

    emit this->textureExportStarting(vTextures.count());

    QFuture<void> pt;
    _futures.clear();

    _numTextures = vTextures.count();
    _curTexture = _numTextures;

    QVectorIterator<QSharedPointer<NoiseImageRunner>>  vi(vTextures);
    while(vi.hasNext()) {
        NoiseImageRunner* nir = vi.next().data();
        connect (nir,SIGNAL(imageSaved(QString)),this,SLOT(doneRendering(QString)));
    }
    vi.toFront();
    while (vi.hasNext()) {
        auto nir = vi.next();
        auto res = QtConcurrent::run (nir.data(), &NoiseImageRunner::run);

        _futures.append(res);
        if (_futures.count()== 8) {
            //for (auto x = 0; x < 8; x++)
            //    _futures[x].waitForFinished();
            //_futures.clear();
            emit this->textureChunkExported(8);
        }
    }
    /*
    foreach (pt, _futures) {
        pt.waitForFinished();
    }
    emit this->textureChunkExported(_futures.count());
    */
    //_futures.clear();

}

void CelestiaExporter::doneRendering(QString filename) {
    emit this->textureChunkExported(1);
    _curTexture--;
    if (_curTexture == 0)
        emit this->textureDoneExported();

}

QString CelestiaExporter::planetToCelestia(Planet& planet, QString starName, QString planetFatherName = "", int i = 1)
{
    QString sOutput;
    QTextStream stream(&sOutput);

    if (planetFatherName != "")
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "/" << planetFatherName << "\" {\n";
    else
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "\" {\n";

    // qDebug() << "step 1";

    stream << "\tTexture \"" << this->getPlanetTexture(planet,i) << "\"\n";
    stream << "\tMass " << planet.massEarth() << "\n";
    stream << "\tRadius " << planet.radius() << "\n";
    stream << "\tRotationPeriod " << planet.orbit().day() << "\n";
    stream << "\tEllipticalOrbit { \n";
    stream << "\t\tPeriod " << planet.orbit().year() << "\n";
    stream << "\t\tEccentricity " << planet.orbit().eccentricity() << "\n";

    // qDebug() << "step 2";


    if (!planet.isSatellite())
        stream << "\t\tSemiMajorAxis " << planet.orbit().distance() << "\n";
    else
        stream << "\t\tSemiMajorAxis " << (planet.orbit().distance() ) << "\n";

    // qDebug() << "step 3";


    stream << "\t\tInclination " << planet.orbit().inclination() << "\n";
    stream << "\t\tObliquity " << planet.orbit().obliquity() << "\n";
    stream << "\t\tEpoch " << SSGX::dn(1000000) << "." << SSGX::dn(1000000) << "\n";
    stream << "\t}\n";

    // qDebug() << "step 4";


    if ( (int)planet.atmosphere() <= 3 && (
             planet.planetType() == ptDesert ||
             planet.planetType() == ptGarden ||
             planet.planetType() == ptPreGarden ||
             planet.planetType() == ptPostGarden ||
             planet.planetType() == ptGlacier ||
             planet.planetType() == ptFailedCore )) {

        int type = (int)planet.atmosphere();
        if (type < 1) type = 1;
        stream << "\tAtmosphere { \n";
        stream << "\t\tHeight " << (SSGX::dn(40)+ SSGX::dn(40)+60)  << "\n";
        stream << "\t\tLower [" << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 6 << " " << SSGX::floatRand() << "]\n ";
        stream << "\t\tUpper [" << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 2 << "]\n ";
        stream << "\t\tSky [" << SSGX::floatRand() / 3 << " " << SSGX::floatRand() / 3 << " " << SSGX::floatRand() / 2 << "]\n ";
        stream << "\t\tCloudHeight " << (SSGX::d10()+ SSGX::d10()+30) / type << "\n";
        stream << "\t\tCloudSpeed " << (SSGX::d10()+ SSGX::d10()+30) / type << "\n";
        stream << "\t\tCloudMap \"" << this->getCloudTexture(planet,i) << "\"\n";
        stream << "}\n";
        // qDebug() << "step 4.2";

    }

    // qDebug() << "step 5";

    stream << "}\n\n";
    stream.flush();

    // qDebug() << "step 6";


    return sOutput;

}

void CelestiaExporter::saveCelestiaDataToFile(QString &filename)
{
    emit this->startExporting();

    // qDebug() << "starting celestia export ";
    QString sOutput;
    QTextStream stream(&sOutput);

    Planet planet, sat;
    int i = 100000;
    int nCount = 0;
    foreach (planet, _star->planets()) {
        i += 10;
        stream << this->planetToCelestia(planet,_star->starName,"",i);
        // qDebug() << "celestia exporting " << planet.name();
        foreach (sat, planet.satellites()) {
            i += 1;
            stream << this->planetToCelestia(sat,_star->starName,planet.name(),i);
            // qDebug() << "celestia exporting sat " << sat.name();
        }
        emit this->exported(nCount++);
    }
    // qDebug() << "flushing ";
    stream.flush();

    // qDebug() << "writing file... " << _star->starName << ".ssc";


    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QTextStream out(&data);
         out << sOutput;
         out.flush();
     }
     data.close();
     emit this->doneExporting();
    // qDebug() << "ended celestia export ";
}

QString CelestiaExporter::getCloudTexture(Planet& p, int i) {
    QString res = "";
    auto pt = p.planetType();
    if (pt == ptGarden || pt == ptGlacier ) {
        res = QString("clouds_%1.png").arg(getUid());
        auto ptr = NoiseImageRunner::UseTextureBuilder("Cloud.OK.texjson", _texturePath+"/"+res);
        vTextures.append(ptr);
        return res;
    }
    else {
        res = QString("f_clouds_%1.png").arg(getUid());
        auto ptr = NoiseImageRunner::UseTextureBuilder("FunkyCloud.OK.texjson", _texturePath+"/"+res);
        vTextures.append(ptr);
        return res;
    }

}

QString CelestiaExporter::runGarden(Planet& p, QString res)
{
    res = QString("earthlike_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideGarden(true), _texturePath+"/"+res);
    //QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999)));
    ptr.data()->setSeaRatio(p.waterPercentage());
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runGlacier(QString res)
{
    res = QString("glacier_%1.png").arg(getUid());
    vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Glacier,_texturePath+"/"+res, SSGX::dn(999999))));
    return res;
}

QString CelestiaExporter::runPostGarden(Planet& p, QString res)
{
    res = QString("postgarden_%1.png").arg(getUid());
    QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Postgarden,_texturePath+"/"+res, SSGX::dn(999999)));
    ptr.data()->setSeaRatio(p.waterPercentage());
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runPreGarden(QString res, Planet& p)
{
    res = QString("pregarden_%1.png").arg(getUid());
    QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Pregarden,_texturePath+"/"+res, SSGX::dn(999999)));
    ptr.data()->setSeaRatio(p.waterPercentage());
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runHotHouse(QString res)
{
    res = QString("hot_house_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder("Hothouse.OK.texjson", _texturePath+"/"+res);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Ice,_texturePath+"/"+res, SSGX::dn(999999))));
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runGasGiant(QString res)
{
    res = QString("gasgiant_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder("GasGiantOriginalOK.texjson", _texturePath+"/"+res);
    vTextures.append(ptr);
    return res;
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::GG,_texturePath+"/"+res, SSGX::dn(999999))));
    //return res;
}

QString CelestiaExporter::runDesert(QString res)
{
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
}

QString CelestiaExporter::runFailedCore(QString res)
{
    res = QString("failedcore_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideFailedCore(true), _texturePath+"/"+res);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Jade2,_texturePath+"/"+res, SSGX::dn(999999))));
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runRockball(QString res)
{
    res = QString("rockball_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder("Chunk.OK.texjson", _texturePath+"/"+res);
    //auto ptr = NoiseImageRunner::UseTextureBuilder("alienpeaksvoronoi.texjson", _texturePath+"/"+res);
    //QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999)));
    //ptr.data()->setSeaRatio(p.waterPercentage());
    vTextures.append(ptr);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
    return res;
}

QString CelestiaExporter::runIceball(QString res)
{
    res = QString("rockball_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder("Iceball.OK.texjson", _texturePath+"/"+res);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Ice,_texturePath+"/"+res, SSGX::dn(999999))));
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runChunk(QString res)
{
    res = QString("chunk_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder("Chunk.OK.texjson", _texturePath+"/"+res);
    //QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999)));
    //ptr.data()->setSeaRatio(p.waterPercentage());
    vTextures.append(ptr);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
    return res;
}

QString CelestiaExporter::getPlanetTexture(Planet& p, int i) {
    QString res = "";
    switch (p.planetType()) {
    case ptGarden:
    {
        return runGarden(p, res);
    }
    break;
    case ptGlacier:
    {
        return runGlacier(res);
    }
    break;
    case ptPostGarden:
    {
        return runPostGarden(p, res);
    }
    break;
    case ptPreGarden:
    {
        return runPreGarden(res, p);
    }
    case ptHotHouse:
        return runHotHouse(res);
        break;
    case ptGasGiant:
        return runGasGiant(res);
        break;
    case ptDesert:
        runDesert(res);
        return res;
        break;
    case ptFailedCore:
        return runFailedCore(res);
        break;
    case ptRockball:
        return runRockball(res);
        break;
    case ptIceball:
        return runIceball(res);
        break;
    case ptChunk:
        return runChunk(res);
        break;
    default:
        return runChunk(res);
        break;
    }
}


