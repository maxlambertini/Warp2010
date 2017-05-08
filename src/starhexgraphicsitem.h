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

#ifndef STARHEXGRAPHICSITEM_H
#define STARHEXGRAPHICSITEM_H

#include <QGraphicsItem>
#include "star.h"

class StarHexGraphicsItem : public QGraphicsItem
{
private:
    Star *_star;
    double _size;
    int _nx;
    int _ny;
    QColor _penColor;
    QColor _brushColor;
    double _hexHeight;
    QPolygonF _polygon;
public:
    StarHexGraphicsItem(Star *star, int nDx, int nDy, double size = 50,
                        QColor penColor = QColor("black"), QColor brushColor = QColor("yellow")) :
            _star(star),
            _size(size),
            _nx(nDx),
            _ny(nDy),
            _penColor(penColor),
            _brushColor(brushColor)
    {
        _hexHeight = 0.866025 * _size;
        _polygon = this->initializeHexPolygon();
        //this->setCacheMode(QGraphicsItem::ItemCoordinateCache,QSize (size*10, size * 10));
    }

    inline Star* star() { return _star; }

    inline double size() { return _size; }
    inline double hexHeight() { return _hexHeight; }

    inline int nx() { return _nx; }
    inline int ny() { return _ny; }
    inline QColor& penColor() { return _penColor; }
    inline QColor& brushColor() { return _brushColor; }

    QPolygonF initializeHexPolygon();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);
};

#endif // STARHEXGRAPHICSITEM_H
