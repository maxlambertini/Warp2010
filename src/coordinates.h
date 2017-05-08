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

#ifndef COORDINATES_H
#define COORDINATES_H

#include <QObject>

class Coordinates : public QObject
{

private:
    double _x;
    double _y;
    double _z;

public:
    inline Coordinates() : QObject() {}
    inline Coordinates (double nx, double ny, double nz) { _x = nx; _y = ny; _z = nz;}
    Coordinates(const Coordinates & c): QObject() { _x = c._x; _y = c._y; _z = c._z;}
    Coordinates& operator=(const Coordinates & c) { _x = c._x; _y = c._y; _z = c._z; return *this;}

    inline double x() { return _x;}
    inline void setX(double x) { _x = x;}

    inline double y() { return _y;}
    inline void setY(double y) { _y = y;}

    inline double z() { return _z; }
    inline void setZ(double z) { _z = z;}

    double distance(Coordinates &);
    void setCoordinates (double nx, double ny, double nz) { _x = nx; _y = ny; _z = nz;}

};

#endif // COORDINATES_H
