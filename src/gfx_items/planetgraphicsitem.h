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
# packaging of this file#.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/


#ifndef PLANETGRAPHICSITEM_H
#define PLANETGRAPHICSITEM_H

#include <QGraphicsItem>
#include "planet.h"
#include "helpers/planetselector.h"


class PlanetGraphicsItem : public QGraphicsItem
{
    QRectF _boundingRect;
    QRectF _planetRect;
    QRectF _textRect;
    QPointer<Planet> _planet;
    QPointer<PlanetSelector> _selector;
    double _scaleFactor;
public:
    PlanetGraphicsItem(double x , double y, Planet *planet, double scaleFactor = 10.0);
    ~PlanetGraphicsItem();
    QRectF boundingRect() const;
    QRectF planetRect() const;
    QRectF textRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    Planet * planet() { return _planet; }
    PlanetSelector * selector() { return _selector; }

protected:
    virtual void mousePressEvent ( QGraphicsSceneMouseEvent * event ) ;
};

#endif // PLANETGRAPHICSITEM_H
