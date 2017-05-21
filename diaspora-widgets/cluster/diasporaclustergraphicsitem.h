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

#ifndef DIASPORACLUSTERGRAPHICSITEM_H
#define DIASPORACLUSTERGRAPHICSITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include "cluster/cluster.h"
#include "cluster/clusteritem.h"
#include "cluster/diasporaclusterscene.h"
#include <diaspora-widgets_global.h>


class DIASPORAWIDGETSSHARED_EXPORT  DiasporaClusterGraphicsItem : public QGraphicsItem
{
private:

    QSizeF  _size;
    QPointF _corner;
    float _x, _y;
    QRectF _rect;
    QRectF getBoundingRect();
    ClusterItem _clusterItem;
    Cluster* _cluster;
    float _referenceSize;
    QString _itemName;
    QString _initials;
    DiasporaClusterScene* _currentScene;
    int _indexItem;

    DiasporaClusterScene *containingScene;


protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

public:
    Cluster* cluster() { return _cluster; }
    void setCluster (Cluster* c) { _cluster = c; }
    QPointF& corner() { return _corner; }
    QSizeF& size() { return _size; }
    float x() { return _x; }
    float y() { return _y; }

    ClusterItem& clusterItem() { return _clusterItem; }
    void setClusterItem(ClusterItem& c) { _clusterItem = c; }
    void setContainingScene(DiasporaClusterScene* scene) { containingScene = scene; }

    void setCurrentScene (DiasporaClusterScene* scene) { _currentScene = scene; }
    void setIndexItem (int i) { _indexItem = i; }

    float referenceSize() { return _referenceSize; }
    void setReferenceSize(float f) { _referenceSize = f; }

    DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item);
    DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item, Cluster& cluster);



    QRectF boundingRect() const
    {
        return _rect;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);


};


#endif // DIASPORACLUSTERGRAPHICSITEM_H
