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

#ifndef STARGRAPHICSITEM_H
#define STARGRAPHICSITEM_H

#include <QtGui/QColor>
#include <QtGui/QGraphicsItem>
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
    Star * _star;
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
    inline Star * star() { return _star;}
    inline double x() { return _x;}
    inline double y() { return _y;}
    inline double starWidth()  { return _starWidth; }
    inline double fontSize()  { return _fontSize; }
    inline int position()  { return _position; }

    //setter
    inline void setStar(Star *star) { _star = star; }
    inline void setX(double v) { _x = v;}
    inline void setY(double v) { _y = v;}
    inline void setStarWidth(double v) { _starWidth = v;}
    inline void setFontSize(double v) { _fontSize = v;}
    inline void setPosition(int p) { _position = p; }
    inline void setStarBrush(QBrush &b) { _brush = b; }



    StarGraphicsItem(Star *star, double x, double y, double width);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget);

//protected:
//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // STARGRAPHICSITEM_H
