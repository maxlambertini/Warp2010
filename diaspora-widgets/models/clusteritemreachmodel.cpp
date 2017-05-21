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


#include "clusteritemreachmodel.h"
#include <QtGui>


int ClusterItemReachModel::rowCount(const QModelIndex &parent) const
{
    return _reachData.count();
}

QVariant ClusterItemReachModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _reachData.size())
        return QVariant();

    if (role == Qt::DisplayRole) {
        ClusterItemReachData cri = _reachData[index.row()];
        QString name = cri.clusterItemName();
        return name;
    }
    else
        return QVariant();
}

QVariant ClusterItemReachModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("System %1").arg(section);
    else
        return QString("System %1").arg(section);
}
