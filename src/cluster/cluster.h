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
