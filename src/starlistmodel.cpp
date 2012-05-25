#include "starlistmodel.h"
#include <QtCore>
#include <QtGui>


QVariant StarListModel::data (const QModelIndex &index, int role) const
{
    int nCount = _stars.stars().count();
    if (!index.isValid())
        return QVariant();
    if (index.row() >= nCount)
        return QVariant();
    if (role == Qt::DisplayRole)
        return _stars.stars().at(index.row());
    else
        return QVariant();
}

QVariant StarListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

int StarListModel::rowCount(const QModelIndex& parent) const
{
    return _stars.count();
}
