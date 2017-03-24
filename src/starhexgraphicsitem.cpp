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

void StarHexGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
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
