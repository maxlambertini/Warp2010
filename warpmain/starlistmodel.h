#ifndef STARLISTMODEL_H
#define STARLISTMODEL_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include "star.h"
#include "starlist.h"

class StarListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    StarListModel (const StarList &stars,QObject *parent = 0) :
            QAbstractListModel(parent), _stars(stars) {}

    //needed by QAbstractListModel
    int rowCount  (const QModelIndex &parent =QModelIndex()) const;
    QVariant data (const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    StarList _stars;

}


#endif // STARLISTMODEL_H
