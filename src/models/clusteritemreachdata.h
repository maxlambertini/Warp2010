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


#ifndef CLUSTERITEMREACHDATA_H
#define CLUSTERITEMREACHDATA_H

#include "cluster/clusteritem.h"
#include <QtGui>
#include <QListWidgetItem>

class ClusterItemReachData : public QListWidgetItem
{
    int  _clusterIndex;
    bool _linked;
    ClusterItem _clusterItem;

public:
    inline bool linked() { return _linked; }
    inline int clusterIndex() { return _clusterIndex; }

    void setLinked(bool b) { _linked = b;
        if (b) this->setCheckState(Qt::Checked); else this->setCheckState(Qt::Unchecked);
    }
    void setClusterIndex (int i ) { _clusterIndex = i;}

    const QString& clusterItemName()  { return _clusterItem.name(); }

    ClusterItemReachData (const QString& name, int idx) :
            _clusterIndex(idx),
            _linked (false)
    {
        //qDebug () << "Initializ<ing ClusterItemReachData with " << name << "," << idx;
        this->setText(name);
        this->setFlags(this->flags() | Qt::ItemIsUserCheckable);
        this->setCheckState(Qt::Unchecked);
    }
};

#endif // CLUSTERITEMREACHDATA_H
