#ifndef DIASPORACLUSTERSCENE_H
#define DIASPORACLUSTERSCENE_H

#include <QtGui>
#include <QtCore>
#include "cluster/cluster.h"
#include "clusteritem.h"

class DiasporaClusterScene : public QObject
{
    Q_OBJECT

    QGraphicsScene _scene;
    Cluster* _cluster;
public:
    QGraphicsScene& scene() { return _scene; }
    QGraphicsScene *ptrScene() { return &_scene; }
    void setCluster(Cluster* cluster) { _cluster = cluster; }
    Cluster* cluster() { return _cluster; }

    DiasporaClusterScene();
    void doClickedOnClusterItem (const ClusterItem& ci, int indexItem) {
        emit clickedOnClusterItem(ci,indexItem);
    }

signals:
    void clickedOnClusterItem (const ClusterItem& ci, int indexItem);

};

#endif // DIASPORACLUSTERSCENE_H
