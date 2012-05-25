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
