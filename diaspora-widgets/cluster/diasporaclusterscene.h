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

#ifndef DIASPORACLUSTERSCENE_H
#define DIASPORACLUSTERSCENE_H

#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include "diaspora-widgets_global.h"
#include <cluster/cluster.h>
#include <cluster/diasporaclusterscene.h>
#include <cluster/clusteritem.h>
#include <diaspora-widgets_global.h>


class DIASPORAWIDGETSSHARED_EXPORT  DiasporaClusterScene : public QObject
{
    Q_OBJECT

    QGraphicsScene _scene;
    Cluster* _cluster;
public:
    QGraphicsScene& scene() { return _scene; }
    QGraphicsScene *ptrScene() { return &_scene; }
    void setCluster(Cluster* cluster) { _cluster = cluster; }
    Cluster* cluster() { return _cluster; }

    DiasporaClusterScene();
    void doClickedOnClusterItem (const ClusterItem& ci, int indexItem) {
        emit clickedOnClusterItem(ci,indexItem);
    }

signals:
    void clickedOnClusterItem (const ClusterItem& ci, int indexItem);

};

#endif // DIASPORACLUSTERSCENE_H
