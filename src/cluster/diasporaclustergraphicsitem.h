#ifndef DIASPORACLUSTERGRAPHICSITEM_H
#define DIASPORACLUSTERGRAPHICSITEM_H

#include <QtGui>
#include "cluster/cluster.h"
#include "cluster/clusteritem.h"
#include "cluster/diasporaclusterscene.h"

class DiasporaClusterGraphicsItem : public QGraphicsItem
{
private:

    QSizeF  _size;
    QPointF _corner;
    float _x, _y;
    QRectF _rect;
    QRectF getBoundingRect();
    ClusterItem _clusterItem;
    Cluster* _cluster;
    float _referenceSize;
    QString _itemName;
    QString _initials;
    DiasporaClusterScene* _currentScene;
    int _indexItem;

    DiasporaClusterScene *containingScene;


protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

public:
    Cluster* cluster() { return _cluster; }
    void setCluster (Cluster* c) { _cluster = c; }
    QPointF& corner() { return _corner; }
    QSizeF& size() { return _size; }
    float x() { return _x; }
    float y() { return _y; }

    ClusterItem& clusterItem() { return _clusterItem; }
    void setClusterItem(ClusterItem& c) { _clusterItem = c; }
    void setContainingScene(DiasporaClusterScene* scene) { containingScene = scene; }

    void setCurrentScene (DiasporaClusterScene* scene) { _currentScene = scene; }
    void setIndexItem (int i) { _indexItem = i; }

    float referenceSize() { return _referenceSize; }
    void setReferenceSize(float f) { _referenceSize = f; }

    DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item);
    DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item, Cluster& cluster);



    QRectF boundingRect() const
    {
        return _rect;
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);


};


#endif // DIASPORACLUSTERGRAPHICSITEM_H
