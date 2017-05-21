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

#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QtCore>
#include <math.h>
#include "orbit.h"
#include <QDir>

namespace NSPlanet {
    enum CoreType {
        ctRocky = 0,
        ctIcy = 1
    };

    enum PlanetType {
        ptNone = 0,
        ptChunk = 1,
        ptRockball = 2,
        ptDesert = 3,
        ptHotHouse = 4,
        ptGlacier = 5,
        ptGarden = 6,
        ptPreGarden = 7,
        ptPostGarden = 8,
        ptGasGiant = 9,
        ptSuperJovian = 10,
        ptFailedCore = 11,
        ptIceball = 12
    };



    enum HydrosphereType {
        htNone = 0,
        htShards = 1,
        htLiquid = 2,
        htIce = 3,
        htVapor = 4
    };

   enum Atmosphere {
       atMassive = 0,
       atDense = 1,
       atStandard = 2,
       atThin = 3,
       atVeryThin = 4,
       atVacuum = 5
   };


}

using namespace NSPlanet;

class Planet;

class Planet : public QObject
{
    Q_OBJECT

private:

    // Serializable members
    //
    QString _name;
    QString _texture;
    double _diameter;
    double _density;
    double _temperature;
    double _mmwr;
    double _waterPercentage;
    bool    _satellite;
    CoreType _coreType;
    HydrosphereType _hydrosphereType;
    PlanetType      _planetType;
    Atmosphere      _atmosphere;
    Orbit _orbit;
    int _numGardens;
    int _numMarginals;
    int _currentSatellite;
    double _tidalForce;
    QVector<Planet> _satellites;

    QDir _dir;


public:

    Planet();
    Planet(const QString& name) : _name(name), _numGardens(0),_numMarginals(0) {}
    virtual ~Planet();

    Planet( const Planet & other );
    Planet& operator=( const Planet & other );
    bool operator==( const Planet & other ) const;
    bool operator!=( const Planet & other ) const;

    //getter & setter

    Orbit& orbit () { return _orbit; }
    Orbit* orbitPtr () { return &_orbit; }
    void setOrbit (const Orbit&  item) { _orbit = item; }

    const QString& name()  { return _name; }
    void setName(QString name) { _name = name; }

    double diameter() { return  _diameter;}
    void setDiameter(double dm) { _diameter = dm;}

    double density() { return _density;}
    double densityEarth() { return _density / 5520;}
    void setDensity(double dens) { _density = dens;}

    double radius() { return _diameter / 2; }
    double radiusEarth() { return radius() / 6378.0;}

    double massEarth() { return pow(radiusEarth(),3) * densityEarth(); }
    double gravEarth() { return massEarth() / (pow (radiusEarth(),2)); }

    double temperature() { return _temperature; }
    void setTemperature(double t) { _temperature = t; }

    double mmwr() { return _mmwr; }
    void setMmwr(double d) { _mmwr = d; }

    double waterPercentage() {return _waterPercentage; }
    void setWaterPercentage(double d) { _waterPercentage = d; }

    double oxygenPercentage() {
        if (this->_planetType == ptGarden || this->_planetType == ptGlacier
            || this->_planetType == ptPostGarden || this->_planetType == ptPreGarden)
            return (21.0 / (this->_waterPercentage/78.0));
        else
            return 0.0;

    }

    CoreType coreType() { return _coreType; }
    void setCoreType(CoreType ctype) { _coreType = ctype; }

    HydrosphereType hydrosphereType() { return _hydrosphereType; }
    void setHydrosphereType(HydrosphereType ht) { _hydrosphereType = ht; }

    PlanetType planetType() { return _planetType; }
    void setPlanetType(PlanetType pl);

    Atmosphere atmosphere() { return _atmosphere; }
    void setAtmosphere(Atmosphere atm) { _atmosphere = atm; }

    bool isSatellite() {return _satellite; }
    void setSatelliteFlag() {_satellite = true; }
    void setPlanetFlag() {_satellite = false; }

    QVector<Planet>& satellites() { return _satellites;}

    int satellitesCount() { return _satellites.count(); }
    void appendSatellite(const Planet& sat) { _satellites.append(sat); }

    QString toHtml();

    void toJson(QJsonObject& json) ;
    void fromJson(const QJsonObject& json) ;

    QString getPlanetTypeDesc();
    QString getHydrosphereDesc();
    QString getAtmosphereDesc();
    QString getCoreTypeDesc();

    const QString& texture() { return _texture; }
    void setTexture(QString& texture) {_texture = texture; }
    QString fullTexturePath();

    QString getPlanetTexture();
    QString getCloudTexture();


    inline int numGardens() { return _numGardens; }
    inline int numMarginals() { return _numMarginals; }

    void setNumGardens() ;
    void setNumMarginals();


    static void checkForTexturePath() ;

    friend QDataStream & operator >> (QDataStream &in, Planet &m);
    friend QDataStream & operator << (QDataStream &out, const Planet &m);

    inline Planet *firstSat() {
        if (_satellites.count() == 0)
            return 0;
        else {
            _currentSatellite =0;
            Planet *p =  const_cast<Planet *>( _satellites.data());
            return &(p[_currentSatellite]);
        }
    }

    inline Planet *lastSat() {
        if (_satellites.count() == 0)
            return 0;
        else {
            _currentSatellite = _satellites.count()-1;
            Planet *p =  const_cast<Planet *>( _satellites.data());
            return &(p[_currentSatellite]);
        }
    }


    inline Planet *nextSat() {
        if (_satellites.count() == 0)
            return 0;
        else {
            _currentSatellite++;
            if (_currentSatellite >= _satellites.count())
                return 0;
            Planet *p =  const_cast<Planet *>( _satellites.data());
            return &(p[_currentSatellite]);
        }
    }

    inline Planet *prevSat() {
        if (_satellites.count() == 0)
            return 0;
        else {
            _currentSatellite--;
            if (_currentSatellite < 0)
                return 0;
            Planet *p =  const_cast<Planet *>( _satellites.data());
            return &(p[_currentSatellite]);
        }
    }

    double tidalForce() { return _tidalForce; }
    void setTidalForce(double d) { _tidalForce = d; }
    bool isTidallyLocked() { return _tidalForce > 1.0; }

};
#endif // PLANET_H
