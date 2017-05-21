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

#ifndef ASPECTGRAPHICSITEM_H
#define ASPECTGRAPHICSITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include "cluster/clusteritem.h"
#include "cluster/aspect.h"
#include <diaspora-widgets_global.h>


namespace AGIAlign {
    enum Alignment {
        ALTopLeft,
        ALTopCenter,
        ALTopRight,
        ALCenterLeft,
        ALCenter,
        ALCenterRight,
        ALBottomLeft,
        ALBottomCenter,
        ALBottomRight

    };
}

class  DIASPORAWIDGETSSHARED_EXPORT AspectGraphicsItem : public QGraphicsItem
{
    ClusterItem _clusterItem;
    QRectF _boundingRect;
    QString _aspectText;
    float _fLettersInWords;
    float _x;
    float _y;
    void calcBoundingRect();
    AGIAlign::Alignment _alignment;
    
    void recalcBoundingRect();

public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline ClusterItem&  clusterItem()  { return _clusterItem; }
    inline void setClusterItem(const ClusterItem& item) { _clusterItem = item; }

    inline AGIAlign::Alignment alignment () { return _alignment; }
    inline void setAlignment(AGIAlign::Alignment align = AGIAlign::ALTopLeft) {
        _alignment = align;
        this->recalcBoundingRect();
    }

    AspectGraphicsItem();
    AspectGraphicsItem(float x, float y, float fLettersInWords,  ClusterItem& item);
};

#endif // ASPECTGRAPHICSITEM_H
