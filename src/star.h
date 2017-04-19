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

#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QtCore>
#include "coordinates.h"
#include "planet.h"
#include "math.h"

namespace NSStar {
    enum StarType {
        stO=0,
        stB=1,
        stA=2,
        stF=3,
        stG=4,
        stK=5,
        stM=6,
        stDWARF = 7

    };

    enum StarClass {
        scI = 1,
        scII = 2,
        scIII = 3,
        scIV = 4,
        scV = 5,
        scVI = 6,
        scVII = 7,
        scXX = 999
    };

    typedef struct _STARCOORD {
        int x;
        int y;
        int idx;
        QString starName;
    } STARCOORD;

    typedef struct _STARVALUE {
        qint32 numGarden;
        qint32 numGlacier;
        qint32 numPostGarden;
        qint32 numPreGarden;
        qint32 numGasGiant;
        qint32 numRockball;
        qint32 numIceball;
        qint32 numFailedCore;
        qint32 numDesert;
        qint32 numHotHouse;
        qint32 numChunk;
    } STARVALUE;

}


class Star : public QObject
{
    Q_OBJECT

private:
    double              _starSize;
    double          _luminosity;
    double          _magnitude;
    double          _solarMass;
    double          _solarAge;
    double          _temperature;
    double          _diameter;
    double          _mass;
    double          _distance;
    double          _innerLifeZone;
    double          _idealLifeZone;
    double          _outerLifeZone;
    double _x;
    double _y;
    double _z;
    long _nx;
    long _ny;
    long _nz;
    bool _visited;
    bool _sister;
    bool _isReference;
    QString _starFullType;
    NSStar::StarClass   _starClass;
    NSStar::StarType    _starType;

    QVector<Planet> _planets;
    QVector<int>    _neighbors;
    QVector<int>    _path;
    QVector<Star *> _sisters;

    int _numGardens;
    int _numMarginals;
    int _numGasGiant;
    int _numDesert;
    int _numIce ;
    int _currentPlanet;

    NSStar::STARVALUE _starValue;

public:
    QString         starName;

    inline double x() { return _x;}
    inline double y() { return _y;}
    inline double z() { return _z;}
    inline void setX(double v) { _x = v;}
    inline void setY(double v) { _y = v;}
    inline void setZ(double v) { _z = v;}

    bool isReference() { return _isReference; }
    void setReference () { _isReference = true; }
    void clearReference() { _isReference = false; }

    inline NSStar::StarClass starClass() { return _starClass;}
    inline void setStarClass(NSStar::StarClass sc) { _starClass = sc;}

    inline NSStar::StarType starType() { return _starType;}
    inline void setStarType (NSStar::StarType st) {_starType = st;}

    inline double starSize() { return _starSize; }
    inline void setStarSize(double sz) { _starSize = sz; }

    inline double luminosity() { return _luminosity;}
    inline void setLuminosity(double lum) { _luminosity = lum;}

    inline double magnitude() { return _magnitude;}
    inline void setMagnitude(double magn)  { _magnitude = magn;}

    inline double solarMass() { return _solarMass;}
    inline void setSolarMass(double sm) { _solarMass = sm;}

    inline double solarAge() { return _solarAge;}
    inline void setSolarAge(double sa) { _solarAge = sa;}

    inline double temperature() { return _temperature;}
    inline void setTemperature(double tm) { _temperature = tm;}

    inline double diameter() { return _diameter;}
    inline void setDiameter(double dm) { _diameter = dm;}

    inline double mass() { return _mass; }
    inline void setMass(double m) { _mass = m;}

    inline double distance() { return _distance;}
    inline void setDistance(double d) { _distance = d;}


    inline void setLifeZones()
    {
        _innerLifeZone = .72* sqrt(_luminosity);
        _idealLifeZone = sqrt(_luminosity);
        _outerLifeZone = 1.45* sqrt(_luminosity);
    }

    inline NSStar::STARCOORD getStarCoord() {
        NSStar::STARCOORD starCoord;
        starCoord.x = (int)_x;
        starCoord.y = (int)_y;
        starCoord.starName = starName;
        return starCoord;
    }

    inline NSStar::STARVALUE starValue() { return _starValue; }

    inline double innerLifeZone() { return _innerLifeZone; }
    inline double idealLifeZone() { return _idealLifeZone; }
    inline double outerLifeZone() { return _outerLifeZone; }

    inline QPointF pointF() {return  QPointF(this->_x, this->_y); }

    inline double distance(Star* star) {
        double dx = pow((this->_x - star->_x),2);
        double dy = pow((this->_y - star->_y),2);
        double dz = pow((this->_z - star->_z),2);
        return sqrt (dx+dy+dz);
    }
    
    inline int distance2(Star* star) {
        long dx = (this->_nx - star->_nx)*(this->_nx - star->_nx);
        long dy = (this->_ny - star->_ny)*(this->_ny - star->_ny);
        long dz = (this->_nz - star->_nz)*(this->_nz - star->_nz);
        return dx+dy+dz;
    }

    inline const QVector<Planet> & planets() { return _planets;}
    inline const QVector<Planet> *planetsPtr() { return &_planets;}
    inline const QVector<int> & neighbors() { return _neighbors;}
    inline const QVector<int> & path() { return _path;}

    inline bool visited() { return _visited;}
    inline void visit() { _visited = true;}
    inline void leave() { _visited = false;}
    inline void setVisited(bool v=true) { _visited = v;}

    inline bool connectedToReference() { return (_path.count() > 0);}

    inline void clearNeighbors() {
        // qDebug() << "clearing... " << starName;
        _neighbors.clear();
    }
    inline void clearPath() { if (_path.count() > 0) {
            // qDebug() << "path clearing... " << starName;
            _path.clear();
        }
    }
    inline void clearPlanets() { _planets.clear(); }

    inline void appendToNeighbors(int i) { _neighbors.append(i); }
    inline void appendToPath(int i) { _path.append(i); }
    inline void appendToSisters(Star *s) { _sisters.append(s); }
    inline void appendToPlanets(Planet& p) { _planets.append(p); }

    inline int planetCount() {return _planets.count(); }

    inline bool hasGarden() { return (_starValue.numPostGarden
                                      +_starValue.numPreGarden
                                      +_starValue.numGlacier
                                      +_starValue.numGarden) > 0; }
    inline int habitabilityIndex() { return (_starValue.numPostGarden * 2
                                             +_starValue.numPreGarden * 1
                                             +_starValue.numGlacier * 4
                                             +_starValue.numGarden * 8); }
    inline int numMarginals() { return (_starValue.numPostGarden+_starValue.numPreGarden); }
    inline int numGardens() { return _starValue.numGarden; }
    inline void numMarginals( int i ) { _numMarginals = i; }
    inline void numGardens (int i ) { _numGardens = i; }
    inline int numDesert() { return _numDesert; }
    inline int numGasGiant() { return _numGasGiant; }
    inline void numGasGiant(int i) { _numGasGiant = i;}
    inline void numDesert(int i) { _numDesert = i; }

    inline int numPreGarden() { return _starValue.numPreGarden; }
    inline int numPostGarden() { return _starValue.numPostGarden; }


    void setNumGardens();
    void setNumMarginals();
    void setNumDesert();
    void setNumGasGiant();
    bool isSister() { return _sister; }
    void  setIsSister(bool b) { _sister = b; }

    Star();
    ~Star();
    Star(double radius);
    Star(const Star & that);
    Star& operator=(const Star & that);

    void deleteSolarSystem();
    void changeStartingPath(QVector<int>& subPath);
    void setStarFullType(const QString& type);
    QString starFullType() { return _starFullType; }
    QString toHtml();
    void toJson(QJsonObject& json);

    void setStarData();

    static void serializePtr(QDataStream& out, Star* p);
    static Star * deserializeToPtr(QDataStream& in);

    NSStar::STARVALUE calcStarValue();
    int diasporaEnvironment();
    int diasporaResources();

    inline Planet *firstPlanet() {
        if (_planets.count() == 0)
            return 0;
        else {
            _currentPlanet =0;
            Planet *p =  const_cast<Planet *>( _planets.data());
            return &(p[0]);
        }
    }

    inline Planet *lastPlanet() {
        if (_planets.count() == 0)
            return 0;
        else {
            _currentPlanet =_planets.count()-1;
            Planet *p =  const_cast<Planet *>( _planets.data());
            return &(p[_currentPlanet]);
        }
    }


    inline Planet *nextPlanet() {
        if (_planets.count() == 0)
            return 0;
        else {
            _currentPlanet++;
            if (_currentPlanet >= _planets.count())
                return 0;
            Planet *p =  const_cast<Planet *>( _planets.data());
            return &(p[_currentPlanet]);
        }
    }

    inline Planet *prevPlanet() {
        if (_planets.count() == 0)
            return 0;
        else {
            _currentPlanet--;
            if (_currentPlanet < 0)
                return 0;
            Planet *p =  const_cast<Planet *>( _planets.data());
            return &(p[_currentPlanet]);
        }
    }


};

#endif // STAR_H
