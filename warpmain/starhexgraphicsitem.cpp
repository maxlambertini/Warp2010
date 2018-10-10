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

#include <QtGui>
#include "starhexgraphicsitem.h"
#include "dialogs/preferencesdialog.h"
#include "helpers/preferences.h"
#include <QStyleOptionGraphicsItem>

QPolygonF StarHexGraphicsItem::initializeHexPolygon()
{
    //double halfHeight = _hexHeight;
    double dy = ( _nx % 2 == 0) ? 0 : _hexHeight;
    double x = _size*1.5*(double)_nx;
    double y = -  (dy + (_size*1.73205*(double)_ny));

    QPolygonF polygon = QPolygonF();
    polygon.append(QPointF(x- _size/2, y-_hexHeight ));
    polygon.append(QPointF(x+ _size/2, y-_hexHeight ));
    polygon.append(QPointF(x+ _size, y));
    polygon.append(QPointF(x+ _size/2, y+_hexHeight ));
    polygon.append(QPointF(x- _size/2, y+_hexHeight ));
    polygon.append(QPointF(x- _size, y));
    return polygon;
}


QRectF StarHexGraphicsItem::boundingRect() const
{
    return _polygon.boundingRect();
}

void StarHexGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget  __attribute__ ((unused)) )
{
    if  (_nx == 0 && _ny == 0) {
        // qDebug() << "this hex has a level of detail of " << item->levelOfDetail;
        // qDebug() << "this hex has a level of detail of " << item->levelOfDetailFromTransform(this->transform());
    }
    const qreal lod = item->levelOfDetailFromTransform(painter->worldTransform());
    if (lod > 0.15) {

        //double halfHeight = _hexHeight;
        double dy = ( _nx % 2 == 0) ? 0 : _hexHeight;
        double x = _size*1.5*(double)_nx;
        double y = -  (dy + (_size*1.73205*(double)_ny));

        QPen pen = QPen(_penColor);
        QBrush brush = QBrush(Qt::transparent);
        pen.setWidthF(1);
        painter->setPen(pen);
        painter->setBrush(brush);
        painter->drawPolygon(_polygon, Qt::WindingFill);

        QFont f = Preferences::prefs().fontBody();
        painter->setFont(f);
        QString sgo = QString().sprintf("[%d, %d]",_nx,_ny);
        QPointF pt = QPointF(x- _size/2, y-(_hexHeight-16));
        painter->drawText(pt,sgo);

    }
}
