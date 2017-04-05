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

#include "planet.h"
#include <QtCore>
#include <QCoreApplication>
#include <QDir>
#include <QFileInfoList>
#include "ssg_structures.h"
#include "helpers/apppaths.h"
#include "helpers/planetrenderer.h"

QString hydrosphereDesc[] = {
    "None",
    "Shards",
    "Liquid",
    "Ice",
    "Vapor"
};

QString atmosphereDesc[] = {
   "Massive",
   "Dense",
   "Standard",
   "Thin",
   "Very thin",
   "Vacuum"
};

QString coreDesc[] = {
   "Rocky",
   "Icy"
};


QString planetTypeDesc[] =
{
    "None",
    "Chunk",
    "Rockball",
    "Desert",
    "Hot house",
    "Glacier",
    "Garden",
    "Pregarden",
    "Postgarden",
    "Gas giant",
    "Superjovian",
    "Failed core",
    "Iceball"
};


Planet::Planet() : QObject()
{
    _coreType = NSPlanet::ctRocky;
    _atmosphere = NSPlanet::atVacuum;
    _hydrosphereType = NSPlanet::htNone;
    _planetType = NSPlanet::ptNone;
    _satellite = false;


    _numGardens = 0;
    _numMarginals = 0;

}


/*** For dynamic memory management (can be removed if it isn't necessary) ***/
Planet::Planet( const Planet& other ) : QObject ()
{
    this->_name = other._name;
    this->_atmosphere = other._atmosphere;
    this->_coreType = other._coreType;
    this->_density = other._density;
    this->_diameter = other._diameter;
    this->_hydrosphereType = other._hydrosphereType;
    this->_orbit = other._orbit;
    this->_planetType = other._planetType;
    this->_mmwr = other._mmwr;
    this->_waterPercentage = other._waterPercentage;
    this->_temperature = other._temperature;
    this->_satellite = other._satellite;
    this->_numGardens = other._numGardens;
    this->_numMarginals = other._numMarginals;
    this->_satellites = other._satellites;
    this->_tidalForce = other._tidalForce;
}

Planet& Planet::operator=( const Planet& other )
{
    if( *this != other )
    {
        this->_name = other._name;
        this->_atmosphere = other._atmosphere;
        this->_coreType = other._coreType;
        this->_density = other._density;
        this->_diameter = other._diameter;
        this->_hydrosphereType = other._hydrosphereType;
        this->_orbit = other._orbit;
        this->_planetType = other._planetType;
        this->_mmwr = other._mmwr;
        this->_waterPercentage = other._waterPercentage;
        this->_temperature = other._temperature;
        this->_satellite = other._satellite;
        this->_numGardens = other._numGardens;
        this->_numMarginals = other._numMarginals;
        this->_satellites = other._satellites;
        this->_tidalForce = other._tidalForce;
    }

    return *this;
}

bool Planet::operator==( const Planet& other ) const
{
    // Comparaison of datas here

    return false;	// Change it
}

bool Planet::operator!=( const Planet& other ) const
{
    return !operator==( other );
}

Planet::~Planet() {
    // qDebug() << "Deleting planet...";
    //delete _orbit;
    //Planet p;
    //foreach (p, _satellites)
    //    delete p;
    _satellites.clear();
}

QString Planet::toHtml()  {
    PlanetRenderer::current()->setPlanet(this);
    return PlanetRenderer::current()->description();
}

void Planet::toJson(QJsonObject& json)  {
    /*
                     .arg(p->massEarth())
                     .arg(p->gravEarth())
                     .arg(p->temperature())
                     .arg(p->mmwr())
                     .arg(p->waterPercentage())
                     .arg(p->orbit().distance())
                     .arg(p->orbit().eccentricity())
                     .arg(p->orbit().inclination())
                     .arg(p->orbit().obliquity())
                     .arg(p->orbit().year()*365.25)
                     .arg(p->orbit().day())
                     .arg(p->isSatellite() ? "Yes" : "No")
                     .arg(p->getCoreTypeDesc())
                     .arg(p->getPlanetTypeDesc())
                     .arg(p->getHydrosphereDesc())
                     .arg(p->getAtmosphereDesc())
                     .arg(p->tidalForce() > 1.0 ? "Yes" : "No");
    */
    json["name"]           = this->name();
    json["diameter"]       = this->diameter();
    json["density"]        = this->density();
    json["massEarth"]      = this->massEarth();
    json["gravEarth"]      = this->gravEarth();
    json["temperature"]    = this->temperature();
    json["mmwr"]           = this->mmwr();
    json["distance"]       = this->orbit().distance();
    json["eccentricity"]   = this->orbit().eccentricity();
    json["inclination"]    = this->orbit().inclination();
    json["obliquity"]      = this->orbit().obliquity();
    json["year"]           = this->orbit().year();
    json["day"]            = this->orbit().day();
    json["core"]           = this->getCoreTypeDesc();
    json["hydrosphere"]    = this->getHydrosphereDesc();
    json["atmosphere"]     = this->getAtmosphereDesc();
    json["planetType"]     = this->getPlanetTypeDesc();
    json["tidalforce"]     = this->tidalForce();
    json["tidally_locked"] = this->tidalForce() > 1.0 ? "Yes": "No";
    if (!this->isSatellite() && this->satellitesCount() > 0) {
        QJsonArray jsonSats;
        Planet sat;
        foreach (sat, this->satellites()) {
            QJsonObject oSat;
            sat.toJson(oSat);
            jsonSats.append(oSat);
        }
        json["satellites"] = jsonSats;
    }
    json["isSatellite"]    = this->isSatellite();
}

QString Planet::getPlanetTypeDesc()
{
    int i = (int)this->planetType();
    if (i < 0 || i > 12)
        return "";
    else
        return planetTypeDesc[i];
}

QString Planet::getHydrosphereDesc() {
    int i = (int)this->hydrosphereType();
    if (i < 0 || i > 4)
        return "";
    else
        return hydrosphereDesc[i];
}
QString Planet::getAtmosphereDesc() {
    int i = (int)this->atmosphere();
    if (i < 0 || i > 5)
        return "";
    else
        return atmosphereDesc[i];
}
QString Planet::getCoreTypeDesc() {
    int i = (int)this->coreType();
    if (i < 0 || i > 1)
        return "";
    else
        return coreDesc[(int)this->coreType()];
}


QString Planet::fullTexturePath() {
    return AppPaths::appDir() + "/"+this->getPlanetTypeDesc()+"/";
}

void Planet::checkForTexturePath()
{
    QDir dir(AppPaths::appDir());
    qDebug() << "checking " << AppPaths::appDir();
    for (int h = 0; h < 13; h++)
    {
        qDebug() << "-- checking for " << planetTypeDesc[h];
        if (!dir.exists(planetTypeDesc[h])) {
            qDebug() << "-- creating " << planetTypeDesc[h] << " on "  << AppPaths::appDir();
            dir.mkdir(planetTypeDesc[h]);
        }
    }
    if (!dir.exists("Clouds"))
        dir.mkdir("Clouds");
}

void Planet::setPlanetType(PlanetType pl) {
    _planetType = pl;

}


QString Planet::getPlanetTexture()
{
    QString res = "";
    dir.setPath(this->fullTexturePath());
    QStringList filter;
    filter << "*.png" << "*.jpg";
    dir.setFilter(QDir::Files);
    dir.setNameFilters(filter);
    QFileInfoList lst = dir.entryInfoList();
    if (lst.count() > 0) {
        int h = lst.count();
        QFileInfo fi = lst.at(rand() % h);
        return fi.fileName();
    }
    return res;
}

QString Planet::getCloudTexture()
{
    QDir dir2;
    QStringList filter;

    dir2.setPath(AppPaths::appDir()+"/clouds");
    filter << "*.png" << "*.jpg";
    dir2.setFilter(QDir::Files);
    dir2.setNameFilters(filter);
    QString res = "";
    QFileInfoList lst = dir2.entryInfoList();
    if (lst.count() > 0) {
        int h = lst.count();
        QFileInfo fi = lst.at(rand() % h);
        return fi.fileName();
    }
    return res;
}

QDataStream & operator >> (QDataStream &in, Planet &m) {
    in >> m._name;
    in >> m._texture;
    in >> m._diameter;
    in >> m._density;
    in >> m._temperature;
    in >> m._mmwr;
    in >> m._waterPercentage;
    in >> m._satellite;
    qint32 q;
    in >> q; m._coreType = (NSPlanet::CoreType)q;
    in >> q; m._hydrosphereType = (NSPlanet::HydrosphereType)q;
    in >> q; m._planetType  = (NSPlanet::PlanetType)q;
    in >> q; m._atmosphere =  (NSPlanet::Atmosphere)q;
    in >> m._orbit;
    in >> m._satellites;
    m.setNumGardens();
    m.setNumMarginals();
    return in;
}

QDataStream & operator << (QDataStream &out, const Planet &m) {
    out << m._name;
    out << m._texture;
    out << m._diameter;
    out << m._density;
    out << m._temperature;
    out << m._mmwr;
    out << m._waterPercentage;
    out << m._satellite;
    out << (qint32)m._coreType;
    out << (qint32)m._hydrosphereType;
    out << (qint32)m._planetType;
    out << (qint32)m._atmosphere;
    out << m._orbit;
    out << m._satellites;
    //out << m.dir;

    return out;
}

void Planet::setNumGardens() {
    int res = 0;
    QVector<Planet>::iterator ci;
    for (ci = _satellites.begin(); ci != _satellites.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptGarden || p->planetType() == ptGlacier)
            res++;
    }
    _numGardens =  res;

}

void Planet::setNumMarginals() {
    int res = 0;
    QVector<Planet>::iterator  ci;
    for (ci = _satellites.begin(); ci != _satellites.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptPreGarden || p->planetType() == ptPostGarden)
            res++;
    }
    _numMarginals = res;

}


