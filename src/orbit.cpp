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

#include <QtCore>
#include <stdlib.h>
#include "orbit.h"


Orbit::Orbit(const Orbit &that) {
    this->_distance = that._distance;
    this->_eccentricity = that._eccentricity;
    this->_inclination = that._inclination;
    this->_year = that._year;
    this->_day = that._day;
    this->_obliquity = that._obliquity;
}

Orbit Orbit::NextOrbit()
{
    double d = ((double)(rand() % 1000) / 1000.0)+0.35;
    Orbit orbit(this->_distance*d);
    return orbit;
}

void Orbit::fromJson(const QJsonObject &json)
{
    _distance = json["distance"].toDouble();
    _eccentricity = json["eccentricity"].toDouble();
    _inclination = json["inclination"].toDouble();
    _year = json["year"].toDouble();
    _day = json["day"].toDouble();
    _obliquity = json["obliquity"].toDouble();
}

void Orbit::toJson(QJsonObject &json) const
{
    json["distance"] = _distance;
    json["eccentricity"] = _eccentricity;
    json["inclination"] = _inclination;
    json["year"] = _year;
    json["day"] = _day;
    json["obliquity"] = _obliquity;
}

QDataStream & operator >> (QDataStream &in,  Orbit &model) {
    in >> model._day >> model._distance  >> model._eccentricity
            >> model._inclination >> model._obliquity >> model._year;
    return in;

}

QDataStream & operator << (QDataStream &out, const Orbit &model) {
    out << model._day << model._distance  << model._eccentricity
            << model._inclination << model._obliquity << model._year;
    return out;
}
