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
