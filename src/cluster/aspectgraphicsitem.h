#ifndef ASPECTGRAPHICSITEM_H
#define ASPECTGRAPHICSITEM_H

#include <QtGui>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include "cluster/clusteritem.h"
#include "cluster/aspect.h"

namespace AGIAlign {
    enum Alignment {
        ALTopLeft,
        ALTopCenter,
        ALTopRight,
        ALCenterLeft,
        ALCenter,
        ALCenterRight,
        ALBottomLeft,
        ALBottomCenter,
        ALBottomRight

    };
}

class AspectGraphicsItem : public QGraphicsItem
{
    ClusterItem _clusterItem;
    QRectF _boundingRect;
    QString _aspectText;
    float _fLettersInWords;
    float _x;
    float _y;
    void calcBoundingRect();
    AGIAlign::Alignment _alignment;
    
    void recalcBoundingRect();

public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline ClusterItem&  clusterItem()  { return _clusterItem; }
    inline void setClusterItem(const ClusterItem& item) { _clusterItem = item; }

    inline AGIAlign::Alignment alignment () { return _alignment; }
    inline void setAlignment(AGIAlign::Alignment align = AGIAlign::ALTopLeft) {
        _alignment = align;
        this->recalcBoundingRect();
    }

    AspectGraphicsItem();
    AspectGraphicsItem(float x, float y, float fLettersInWords,  ClusterItem& item);
};

#endif // ASPECTGRAPHICSITEM_H
