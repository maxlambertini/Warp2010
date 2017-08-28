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
            stream << this->planetToCelestia(planet,"",i);
            // qDebug() << "celestia exporting " << planet.name();
            foreach (sat, planet.satellites()) {
                i += 10;
                stream << this->planetToCelestia(sat,planet.name(),i);
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

void CelestiaExporter::makeAtmosphere(int i, Planet& planet, QTextStream& stream)
{
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
}

void CelestiaExporter::makeMainCelestiaStats(int i, Planet& planet, QTextStream &stream)
{
    stream << "\tTexture \"" << this->getPlanetTexture(planet,i) << "\"\n";
    stream << "\tMass " << planet.massEarth() << "\n";
    stream << "\tRadius " << planet.radius() << "\n";
    stream << "\tRotationPeriod " << planet.orbit().day() << "\n";
    stream << "\tEllipticalOrbit { \n";
    stream << "\t\tPeriod " << planet.orbit().year() << "\n";
    stream << "\t\tEccentricity " << planet.orbit().eccentricity() << "\n";

    if (!planet.isSatellite())
        stream << "\t\tSemiMajorAxis " << planet.orbit().distance() << "\n";
    else
        stream << "\t\tSemiMajorAxis " << (planet.orbit().distance() ) << "\n";

    stream << "\t\tInclination " << planet.orbit().inclination() << "\n";
    stream << "\t\tObliquity " << planet.orbit().obliquity() << "\n";
    stream << "\t\tEpoch " << SSGX::dn(1000000) << "." << SSGX::dn(1000000) << "\n";
    stream << "\t}\n";
}

void CelestiaExporter::makeRings(int i, Planet& planet, QTextStream &stream)
{
    //TODO: build ring code. Planet has rings if:
    // 1. It's a gas giant. Usually it is a smallish ring, from 2* radius and 0.05 radius width.
    // 2. If it's a Saturn, it's 0.25-0.4 radius width
    // 3. Other planet types might have or not a ring, but it's extremely unlikely. Say 1 in 20 of earthlike planets or bigger
    QString res = QString("rings_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseRingBuilder( _texturePath+"/"+res);
    vTextures.append(ptr);

    double min_ring = planet.radius() * (1.35+1.85*SSGX::floatRand());
    double max_ring = min_ring * 1.02;
    if (SSGX::d100() > 90)
        max_ring = min_ring * (1.1+0.26*SSGX::floatRand());
   else
        max_ring = min_ring * (1.02+0.08*SSGX::floatRand());

    stream << "\t\t Rings { \n";
    stream << "\t\t\tInner " << (int)min_ring << " \n";
    stream << "\t\t\tOuter " << (int)max_ring << " \n";
    stream << "\t\t\Texture \"" << res << "\" \n\t\t}\n";

    return;
}

QString CelestiaExporter::planetToCelestia(Planet& planet, QString planetFatherName = "", int i = 1)
{
    QString sOutput;
    QTextStream stream(&sOutput);

    if (planetFatherName != "")
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "/" << planetFatherName << "\" {\n";
    else
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "\" {\n";

    makeMainCelestiaStats(i, planet, stream );
    makeAtmosphere(i, planet, stream);
    if (planet.planetType() == ptGasGiant ) {
        if (SSGX::d100() < 80) {
            makeRings(i, planet, stream);
        }
    }

    if (planet.planetType() == ptFailedCore ) {
        if (SSGX::d100() < 40) {
            makeRings(i, planet, stream);
        }
    }

    stream << "}\n\n";
    stream.flush();

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
        stream << this->planetToCelestia(planet,"",i);
        // qDebug() << "celestia exporting " << planet.name();
        foreach (sat, planet.satellites()) {
            i += 1;
            stream << this->planetToCelestia(sat,planet.name(),i);
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
        //auto ptr = NoiseImageRunner::UseTextureBuilder("Cloud.OK.texjson", _texturePath+"/"+res);
        auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideClouds(true), _texturePath+"/"+res);

        ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Clouds");
        vTextures.append(ptr);
        return res;
    }
    else {
        res = QString("f_clouds_%1.png").arg(getUid());
        auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideAlienClouds(true), _texturePath+"/"+res);
        ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Alien Clouds");
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
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Garden");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runGlacier(Planet& p, QString res)
{
    res = QString("glacier_%1.png").arg(getUid());
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Glacier,_texturePath+"/"+res, SSGX::dn(999999))));
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideGlacier(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Glacier");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runPostGarden(Planet& p, QString res)
{
    res = QString("postgarden_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::providePostgarden(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"PostGarden");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runPreGarden(Planet& p, QString res )
{
    res = QString("pregarden_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::providePregarden(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"PreGarden");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runHotHouse(Planet& p, QString res)
{
    res = QString("hot_house_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideHotHouse(true), _texturePath+"/"+res);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Ice,_texturePath+"/"+res, SSGX::dn(999999))));
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Hothouse");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runGasGiant(Planet& p, QString res)
{
    res = QString("gasgiant_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideGasgiant(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"GasGiant");
    vTextures.append(ptr);
    return res;
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::GG,_texturePath+"/"+res, SSGX::dn(999999))));
    //return res;
}

QString CelestiaExporter::runDesert(Planet& p, QString res)
{
    res = QString("desert_%1.png").arg(getUid());
    /*
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
    */
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideDesert(true), _texturePath+"/"+res);
    //QSharedPointer<NoiseImageRunner> ptr(new NoiseImageRunner(RT::Earthlike,_texturePath+"/"+res, SSGX::dn(999999)));
    qDebug() << "runDesert: " << res;
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Desert");
    vTextures.append(ptr);
    return res;

}

QString CelestiaExporter::runFailedCore(Planet& p, QString res)
{
    res = QString("failedcore_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideFailedCore(true), _texturePath+"/"+res);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Jade2,_texturePath+"/"+res, SSGX::dn(999999))));
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Failed Core");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runRockball(Planet& p, QString res)
{
    res = QString("rockball_%1.png").arg(getUid());
    //auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideRockball(true), _texturePath+"/"+res);
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideDesert(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Rockball");
    vTextures.append(ptr);
    //vTextures.append(QSharedPointer<NoiseImageRunner>(new NoiseImageRunner(RT::Granite,_texturePath+"/"+res, SSGX::dn(999999))));
    return res;
}

QString CelestiaExporter::runIceball(Planet& p, QString res)
{
    res = QString("rockball_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideIceball(true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Iceball");
    vTextures.append(ptr);
    return res;
}

QString CelestiaExporter::runChunk(Planet& p, QString res)
{
    res = QString("chunk_%1.png").arg(getUid());
    auto ptr = NoiseImageRunner::UseTextureBuilder(AppPaths::provideChunk(  true), _texturePath+"/"+res);
    ptr->setPlanetNameAndType(_star->starName+"-"+p.name(),"Chunk");
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
        return runGlacier(p,res);
    }
    break;
    case ptPostGarden:
    {
        return runPostGarden(p, res);
    }
    break;
    case ptPreGarden:
    {
        return runPreGarden(p,res);
    }
    case ptHotHouse:
        return runHotHouse(p,res);
        break;
    case ptGasGiant:
        return runGasGiant(p,res);
        break;
    case ptDesert:
        return runDesert(p,res);
        break;
    case ptFailedCore:
        return runFailedCore(p,res);
        break;
    case ptRockball:
        return runRockball(p,res);
        break;
    case ptIceball:
        return runIceball(p,res);
        break;
    case ptChunk:
        return runChunk(p,res);
        break;
    default:
        return runChunk(p,res);
        break;
    }
}


