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

#ifndef CLUSTERITEMREACHMODEL_H
#define CLUSTERITEMREACHMODEL_H

#include <QtGui>
#include "clusteritemreachdata.h"

class ClusterItemReachModel : public QAbstractListModel
{
    Q_OBJECT

public:
    ClusterItemReachModel(const QList<ClusterItemReachData> reachData,
                    QObject *parent = 0)
        : QAbstractListModel(parent), _reachData(reachData) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

private:
    QList<ClusterItemReachData> _reachData;
};

#endif // CLUSTERITEMREACHMODEL_H
