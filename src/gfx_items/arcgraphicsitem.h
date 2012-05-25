#ifndef ARCGRAPHICSITEM_H
#define ARCGRAPHICSITEM_H

#include <QtGui>



namespace NSArc {
    const double PI =  3.14159265;
    const int CHORD_ANGLE = 30 * 16;
    const double TO_GRAD = 57.2957795;
    const double SQ_ROOT_3 = 1.7320508075688772935274463415059;
    const double ANGLE_DELTA = 27.0/57.2957795;
    const double ANGLE_SWEEP = 54.0;
}

class ArcGraphicsItem : public QGraphicsItem
{
private:
    QPointF _p1;
    QPointF _p2;
    QPointF _pCenter;
    QPointF _halfway;
    QRectF  _boundingRect;
    QPen    _pen;
    double  _angleStart;
    double  _angleSweep;
    bool    _drawAsArc;

    void customDrawArc(QPointF p1, QPointF p2, QPen pOrange);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                    QWidget *widget);
public:
    ArcGraphicsItem(double x1, double y1, double x2, double y2, QPen& pen, bool bDrawAsArc = true);
    ArcGraphicsItem(const QPointF& p1, const QPointF& p2, QPen& pen, bool bDrawAsArc = true);
    QRectF boundingRect() const;
    QPointF& halfway() { return _halfway; }
    bool drawAsArc() { return _drawAsArc; }
    void setDrawAsArc(bool b) { _drawAsArc = b; }
};


#endif // ARCGRAPHICSITEM_H
