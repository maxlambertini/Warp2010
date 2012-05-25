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
