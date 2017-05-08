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

#ifndef ORBIT_H
#define ORBIT_H

#include <QObject>
#include <math.h>
#include <stdlib.h>
#include <QJsonDocument>
#include <QJsonObject>

namespace NSOrbit {
    enum OrbitType {
        otPlanet,
        otSatellite
    };
}

using namespace NSOrbit;

class Orbit
{

private:
    double _distance;
    double _eccentricity;
    double _inclination;
    double _year;
    double _day;
    double _obliquity;

public:
    void fromJson(const QJsonObject &json);
    void toJson (QJsonObject& json) const;


    inline double obliquity() { return _obliquity; }
    inline double distance() { return _distance;}
    inline double eccentricity() { return _eccentricity;}
    inline double inclination() { return _inclination;}
    inline double year() { return _year; }
    inline double day() { return _day; }
    inline double localYear() { return (_year*365.25*23.94888) / _day; }

    inline void setDay(double d) { _day = d; }
    inline void setObliquity(double d) { _obliquity = d; }
    inline void setDistance (double d) {_distance = d;}
    inline void setEccentricity (double d) {_eccentricity = d;}
    inline void setInclination (double d) {_inclination = d;}
    inline void setYear (double starMass) { _year = sqrt( pow(_distance,3)/starMass);}
    inline void setFixedYear(double dYear) { _year = dYear; }

    inline void setShortDay() { _day = 5+ rand() % 10 + ((double)(rand() % 1000))/1000.0; }
    inline void setNormalDay() { _day = 10+ rand() % 36 + ((double)(rand() % 1000))/1000.0; }
    inline void setLongDay() { _day = 30+ rand() % 80 + ((double)(rand() % 1000))/1000.0; }
    inline void setVeryLongDay() { _day = 100+ rand() % 500 + ((double)(rand() % 1000))/1000.0; }


    Orbit() :
            _distance(1.0),
            _eccentricity(0.0),
            _inclination(0.0),
            _year(365.25),
            _day(23.56),
            _obliquity(0.0)
    {}
    Orbit(double dist, double ecc=0.02, double incl=0.02, double starMass=1.0)
        :
            _distance(dist),
            _eccentricity(ecc),
            _inclination(incl),
            _year(sqrt( pow(_distance,3)/starMass)),
            _day(23.56),
            _obliquity(0.0)
    {
    }
    Orbit(const Orbit& that);
    Orbit  NextOrbit();



    friend QDataStream & operator >> (QDataStream &in, Orbit &model);
    friend QDataStream & operator << (QDataStream &out, const Orbit &model);

};

#endif // ORBIT_H
