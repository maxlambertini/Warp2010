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
