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
