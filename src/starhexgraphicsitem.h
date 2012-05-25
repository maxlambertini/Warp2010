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
