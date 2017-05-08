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

#ifndef STARGRAPHICSITEM_H
#define STARGRAPHICSITEM_H

#include <QColor>
#include <QGraphicsItem>
#include <QtGui>
#include "star.h"

namespace NSStarGraphicsItem {
    const int PositionTop = 0;
    const int PositionRight = 1;
    const int PositionBottom = 2;
    const int PositionLeft = 3;
}


class StarGraphicsItem : public QGraphicsItem
{
private:
    QSharedPointer<Star> _star;
    QColor  _starColor;
    QColor  _textColor;
    QString _fontName;
    QBrush  _brush;

    double  _x;
    double  _y;
    double _starWidth;
    double _fontSize;
    int _position;


public:
    //getter
    inline QSharedPointer<Star> star() { return _star;}
    inline double x() { return _x;}
    inline double y() { return _y;}
    inline double starWidth()  { return _starWidth; }
    inline double fontSize()  { return _fontSize; }
    inline int position()  { return _position; }

    //setter
    inline void setStar(QSharedPointer<Star> star) { _star = star; }
    inline void setX(double v) { _x = v;}
    inline void setY(double v) { _y = v;}
    inline void setStarWidth(double v) { _starWidth = v;}
    inline void setFontSize(double v) { _fontSize = v;}
    inline void setPosition(int p) { _position = p; }
    inline void setStarBrush(QBrush &b) { _brush = b; }



    StarGraphicsItem(QSharedPointer<Star> star, double x, double y, double width);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // STARGRAPHICSITEM_H
