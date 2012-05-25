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
