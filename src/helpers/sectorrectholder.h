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


#ifndef SECTORRECTHOLDER_H
#define SECTORRECTHOLDER_H

#include <QtGui>

class SectorRectHolder
{
    QRectF _rectOuter;
    QRectF _rectInner;
    int _x;
    int _y;
    bool _bCanDrawRect;
public:
    SectorRectHolder();

    SectorRectHolder(const QRectF& ro, const QRectF& ri, int nx, int ny, bool canDraw = true) :
            _rectOuter(ro), _rectInner(ri), _x(nx), _y(ny), _bCanDrawRect(canDraw)
    {}

    ~SectorRectHolder() { }

    inline QRectF& rectOuter() { return _rectOuter; }
    inline QRectF& rectInner() { return _rectInner; }
    inline int x() { return _x; }
    inline int y() { return _y; }
    inline bool canDrawRect() { return _bCanDrawRect; }

    void setRectOuter (QRectF& r) { _rectOuter = r; }
    void setRectInner (QRectF& r) { _rectInner = r; }
    void setX(int i) { _x = i; }
    void setY(int i) { _y = i; }
    void setCanDrawRect (bool b) { _bCanDrawRect = b; }


};

#endif // SECTORRECTHOLDER_H
