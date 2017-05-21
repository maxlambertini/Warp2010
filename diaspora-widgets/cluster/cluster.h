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

#ifndef CLUSTER_H
#define CLUSTER_H

#include <QtGui>
#include <QObject>
#include "clusteritem.h"
#include "ssg_structures.h"
#include "onomastikon.h"
#include "aspectlist.h"

class Cluster
{
    Onomastikon *_onomastikon;
    QVector<ClusterItem> _clusterItems;
    QMap<QString, ClusterItem> _clusterMap;
    QString _name;
    AspectList _aspects;
    bool _isDirty;
public:
    const QMap<QString, ClusterItem> clusterMap() { return _clusterMap; }
    const QVector<ClusterItem>& clusterItems() { return _clusterItems; }
    QVector<ClusterItem>& mutableClusterItems() { return _clusterItems; }
    void addClusterItem(const ClusterItem& item) { _clusterItems.append(item); }
    int count() { return _clusterItems.count(); }
    void clear() { _clusterItems.clear(); }
    Cluster();
    ~Cluster() {
        //qDebug() << "destroying cluster";
    }

    inline void setAspectList (AspectList& aspectlist) { _aspects = aspectlist; }
    inline AspectList& aspectList() { return _aspects; }

    inline bool isDirty() const { return _isDirty; }
    void setIsDirty(bool b) { _isDirty = b; }

    void setName (QString& name) { _name = name; }
    const QString& name() { return _name; }

    inline void setClusterItem(ClusterItem& ci, int h) {
        if (h >= 0 && h < _clusterItems.count())
            _clusterItems[h] = ci;
    }

    bool _closeCluster ;

    void exportClusterToGraphViz(QString filename = "");

    void create(int nCluster = 0, bool closeCluster = false);

    friend QDataStream & operator << (QDataStream &in, const Cluster &model);
    friend QDataStream & operator >> (QDataStream &out, Cluster &model);


    QString clusterItemName() ;

    void addLink (int idx, int idxToLink);
    void removeLink (int idx, int idxToLink);

};

#endif // CLUSTER_H
