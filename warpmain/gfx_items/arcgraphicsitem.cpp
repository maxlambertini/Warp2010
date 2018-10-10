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

#include "gfx_items/arcgraphicsitem.h"
#include "helpers/preferences.h"

ArcGraphicsItem::ArcGraphicsItem(double x1, double y1, double x2, double y2, QPen &pen, bool bDrawAsArc __attribute__((unused)) )
{
    _p1 = QPointF(x1,y1);
    _p2 = QPointF(x2,y2);
    _pen = pen;
    _drawAsArc = Preferences::prefsPtr()->drawRoutesAsArcs();
    this->customDrawArc(_p1,_p2,_pen);
}


ArcGraphicsItem::ArcGraphicsItem(const QPointF & p1, const QPointF &p2, QPen &pen, bool bDrawAsArc __attribute__((unused)))
{
    _p1 = p1;
    _p2 = p2;
    _pen = pen;
    _drawAsArc = Preferences::prefsPtr()->drawRoutesAsArcs();
    this->customDrawArc(_p1,_p2,_pen);
}

QRectF ArcGraphicsItem::boundingRect() const
{
    return _boundingRect;
}

void ArcGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option __attribute__((unused)),
                            QWidget *widget __attribute__((unused)))
{
    painter->setPen(_pen);
    if (_drawAsArc) {
        QBrush brush;
        QPainterPath path;
        painter->setBrush(brush);
        path.moveTo(_pCenter.x(),_pCenter.y());
        path.arcMoveTo(_boundingRect,_angleStart);
        path.arcTo(_boundingRect,_angleStart,_angleSweep);
        painter->drawPath(path);
    }
    else {
        painter->drawLine(_p1,_p2);
    }
}

void ArcGraphicsItem::customDrawArc(QPointF p1, QPointF p2, QPen pOrange)
{
    if (_drawAsArc) {
        double dist = sqrt( (p2.x()-p1.x()) * (p2.x()-p1.x()) + (p2.y()-p1.y()) * (p2.y()-p1.y()));
        double radius = dist;
        QPointF pm( (p2.x()+p1.x()) /2, (p2.y()+p1.y())/2);
        double dx = p2.x()-p1.x();
        double dy = p2.y()-p1.y();
        double phi = atan2(dy,dx);
        phi -= NSArc::PI/2.0;

        double ellipseBaseAngle = (NSArc::PI + (2.0*NSArc::PI - phi)) ;
        double ellipseStartAngle = ellipseBaseAngle - NSArc::ANGLE_DELTA;

        _angleStart = ellipseStartAngle * NSArc::TO_GRAD;
        _angleSweep = NSArc::ANGLE_SWEEP;
        _pen = pOrange;

        double cx = pm.x()+radius*cos(phi);
        double cy = pm.y()+radius*sin(phi);

        radius = sqrt( (p2.x()-cx)*(p2.x()-cx) + (p2.y()-cy) * (p2.y()-cy));

        _halfway.setX(cx- radius * cos(phi));
        _halfway.setY(cy- radius * sin(phi));


        _pCenter = QPointF(cx,cy);
        QRectF rect(cx-radius, cy-radius, radius*2, radius*2);
        _boundingRect = rect;

    }
    else  {
        QRectF rect(p1,p2);
        _boundingRect = rect;
        _pCenter = QPointF( (p2.x()+p1.x()) /2, (p2.y()+p1.y())/2);
        _halfway = _pCenter;
    }
}

