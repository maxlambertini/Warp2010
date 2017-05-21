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

#include <QtGui>
#include "cluster/diasporaclustergraphicsitem.h"
//#include "dialogs/preferencesdialog.h"
//#include "helpers/preferences.h"
#include <cluster/clusteritem.h>
#include <diasporadefaultfonts.h>

//DiasporaClusterGraphicsItem::DiasporaClusterGraphicsItem()
//{
//}

DiasporaClusterGraphicsItem::DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item) :
        _corner(QPointF(fx,fy)),
        _x(fx), _y(fy),
        _clusterItem(item),
        _referenceSize(DiasporaDefaultFonts::TitleFont().pointSizeF())
{
    _size = QSizeF(200,200);
    _itemName = _clusterItem.name();
    _rect = getBoundingRect();
    _currentScene = 0;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    //this->setFlag(QGraphicsItem::ItemIsMovable,true);
}



DiasporaClusterGraphicsItem::DiasporaClusterGraphicsItem(float fx, float fy, ClusterItem &item, Cluster &cluster) :
        _corner(QPointF(fx,fy)),
        _x(fx), _y(fy),
        _clusterItem(item),
        _cluster(&cluster),
        _referenceSize(DiasporaDefaultFonts::TitleFont().pointSizeF())
{
    _size = QSizeF(200,200);
    _itemName = _clusterItem.name();
    _rect = getBoundingRect();
    _currentScene = 0;
    this->setFlag(QGraphicsItem::ItemIsSelectable,true);
    //this->setFlag(QGraphicsItem::ItemIsMovable,true);
}


void DiasporaClusterGraphicsItem::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    this->setSelected(!this->isSelected());
    if (_currentScene != 0)
        _currentScene->doClickedOnClusterItem(_clusterItem, _indexItem);

}

QRectF DiasporaClusterGraphicsItem::getBoundingRect()
{

    QFont fontMain = DiasporaDefaultFonts::TitleFont(); // Preferences::prefs().fontAspectTitle();
    QFont fontStat = DiasporaDefaultFonts::BodyFont(); //Preferences::prefs().fontBody();

    QFontMetricsF fmMain = QFontMetrics(fontMain);
    QFontMetricsF fmStat = QFontMetrics(fontStat);

    float hMain = fmMain.height();
    float wMain = fmMain.width("AEIOUjZ");

    float hStat = fmStat.height();

    _initials = _clusterItem.name().left(3);

    float fTotHeight = (hMain + hStat *3) * 1.2;
    float fReference = wMain > fTotHeight ? wMain : fTotHeight;

    _size.setWidth(fReference);
    _size.setHeight(fReference);

    _corner.setX (_corner.x()-fReference/2);
    _corner.setY (_corner.y()-fReference/2);

    return QRectF (_corner, _size);

}

void DiasporaClusterGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor borderColor = QColor(192,192,192);
    QColor starColor = QColor (255,255,192);
    QColor techColor = QColor (255,255,0);
    QColor textColor = QColor(0,0,0);
    QColor borderSelectedColor = QColor(255,0,0);

    QBrush starBrush = QBrush(starColor,Qt::SolidPattern);
    QBrush techBrush = QBrush(techColor,Qt::SolidPattern);
    QBrush textBrush = QBrush(textColor, Qt::SolidPattern);

    QPen borderPen;

    if (!this->isSelected()) {
        borderPen= QPen(borderColor);
        borderPen.setWidthF(2.0);
    } else {
        borderPen= QPen(borderSelectedColor);
        borderPen.setWidthF(2.0);

    }

    QPen textPen = QPen(textColor);

    painter->setPen(borderPen);
    painter->setBrush(_clusterItem.technology() >= 2 ? techBrush : starBrush);

    QRectF boundingRect = this->boundingRect();

    painter->drawEllipse(boundingRect);

    QFont fontMain = DiasporaDefaultFonts::TitleFont(); //Preferences::prefs().fontAspectTitle();
    QFont fontStat = DiasporaDefaultFonts::BodyFont();// Preferences::prefs().fontBody();

    QFontMetricsF fmMain = QFontMetrics(fontMain);
    QFontMetricsF fmStat = QFontMetrics(fontStat);

    float hMain = fmMain.height() * 1.1;
    float wMain = fmMain.width(_initials);

    QString t1 = QString("Env: %1")
                 .arg(_clusterItem.environment());
    QString t2 = QString("Tech: %1").arg(_clusterItem.technology());
    QString t3 = QString("Res: %1").arg(_clusterItem.resources());


    float hStat = fmStat.height() * 1.1;
    float w1 = fmStat.width(t1);
    float w2 = fmStat.width(t2);
    float w3 = fmStat.width(t3);

    float wRect = boundingRect.width();

    wMain = (wRect- wMain)/2;
    w1 = (wRect- w1)/2;
    w2 = (wRect- w2)/2;
    w3 = (wRect- w3)/2;


    QPoint p1 = QPoint (_corner.x()+wMain, boundingRect.top()+hMain);
    QPoint p2 = QPoint (_corner.x()+w1, _corner.y()+hMain+hStat);
    QPoint p3 = QPoint (_corner.x()+w2, _corner.y()+hMain+2*hStat);
    QPoint p4 = QPoint (_corner.x()+w3, _corner.y()+hStat*3+hMain);

    painter->setFont(fontMain);
    painter->setBrush(textBrush);
    painter->setPen(textPen);
    painter->drawText(p1,_initials );
    painter->setFont(fontStat);
    painter->drawText(p2,t1 );
    painter->drawText(p3,t2 );
    painter->drawText(p4,t3 );

    //painter->setPen(borderPen);
    //painter->drawPoint(QPointF(_x,_y));

}
