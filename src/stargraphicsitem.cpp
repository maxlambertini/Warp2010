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

#include "stargraphicsitem.h"
#include "star.h"
#include <QtGui>
#include <helpers/preferences.h>
#include <dialogs/preferencesdialog.h>


StarGraphicsItem::StarGraphicsItem(Star *star, double x, double y, double width)
{
    _star = star;
    _x = x;
    _y = y;
    _starWidth = width+5;
    _starColor = QColor("orange");
    _textColor = QColor("black");
    _position = NSStarGraphicsItem::PositionRight;
    _fontName = "Arial";
    _fontSize = 11.0;
}

QRectF StarGraphicsItem::boundingRect() const
{
    //QFont font ("Arial",11,100,false);
    //font.setFamily(_fontName);
    //font.setPointSizeF(_fontSize);
    QFont font = Preferences::prefs().fontBody();

    QFontMetricsF mf(font);
    double mfHeight = mf.height();
    double mfWidth = mf.width( _star->starName);

    QRectF rect(1,1,1,1);
    QRectF rect1 = mf.boundingRect(rect,Qt::AlignLeft | Qt::AlignTop,_star->starName);

    double mfMiddleW = rect1.width() / 2;
    double mfMiddleH = rect1.height() / 2;
    if (mfMiddleW < _starWidth)
        mfMiddleW = _starWidth+1;
    if (mfMiddleH < _starWidth)
        mfMiddleH = _starWidth+1;

    /*
    switch (_position) {
        case NSStarGraphicsItem::PositionTop:
            rect.setLeft( _x - mfMiddleW);
            rect.setRight(_x+ mfMiddleW);
            rect.setTop(_y-_starWidth/2);
            rect.setBottom(_y+_starWidth/2+2+mfHeight);
            break;
        case NSStarGraphicsItem::PositionBottom:
            rect.setLeft( _x - mfMiddleW);
            rect.setRight(_x+ mfMiddleW);
            rect.setTop(_y-_starWidth/2 -2 -mfHeight);
            rect.setBottom(_y+_starWidth/2+2);
            break;
        case NSStarGraphicsItem::PositionLeft:
            rect.setLeft( _x - mfMiddleW -2 -mfWidth);
            rect.setRight(_x+ mfMiddleW);
            rect.setTop(_y-_starWidth/2);
            rect.setBottom(_y+_starWidth/2);
            break;
        case NSStarGraphicsItem::PositionRight:
            rect.setLeft( _x - mfMiddleW);
            rect.setRight(_x+ mfMiddleW +2 + mfWidth);
            rect.setTop(_y-_starWidth/2);
            rect.setBottom(_y+_starWidth/2);
            break;
        default:
            break;
        }
        */
    rect.setLeft( _x - mfMiddleW);
    rect.setRight(_x+ mfMiddleW +2 + mfWidth);
    rect.setTop(_y-_starWidth/2);
    rect.setBottom(_y+_starWidth/2);

    return rect;
}

void StarGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    //QFont font("Arial",11,100,false);
    //font.setFamily(_fontName);
    //font.setPointSizeF(_fontSize);

    QFont font = Preferences::prefs().fontBody();

    QBrush fontBrush(_textColor, Qt::SolidPattern);
    QBrush starBrush(_starColor, Qt::SolidPattern);
    QPen starPen(_textColor);
    starPen.setWidthF(1.0);

    painter->setBrush(_brush);
    painter->setPen(starPen);
    painter->setFont(font);


    bool bCanDrawStar = (item->levelOfDetailFromTransform(painter->worldTransform())
                         > 0.25 || this->star()->isReference()
                         || this->star()->path().count() > 1);
    if (bCanDrawStar) {
        if (this->star()->hasGarden()) {
            QBrush greenBr = QBrush(QColor("green"));
            QPen greenPen = QPen(QColor("green"));
            painter->setPen(greenPen);
            painter->setBrush(greenBr);
            painter->drawEllipse(QPointF(_x,_y),_starWidth-1,_starWidth+1);
            painter->setBrush(_brush);
            painter->setPen(starPen);
        }
        painter->drawEllipse(QPointF(_x,_y),_starWidth-6,_starWidth-6);
    }

    QFontMetricsF mf(font);
    double mfHeight = mf.height();
    double mfWidth = mf.width( _star->starName);
    double mfMiddleW = mfWidth / 2;
    double mfMiddleH = mfHeight / 2;

    QPointF pt1(_x -mfMiddleW, _y + _starWidth/2 +2 );
    QPointF pt2(_x -mfMiddleW, _y - _starWidth - 2 -mfMiddleH);
    QPointF pt3(_x -mfWidth -2 -_starWidth / 2, _y);
    QPointF pt4(_x + _starWidth+2, _y );

    if (item->levelOfDetailFromTransform(painter->worldTransform()) > 0.1) {
        painter->drawText(pt4,_star->starName);
        /*
        switch (_position) {
            case NSStarGraphicsItem::PositionTop:
                painter->drawText(pt1,_star->starName);
                break;
            case NSStarGraphicsItem::PositionBottom:
                painter->drawText(pt2,_star->starName);
                break;
            case NSStarGraphicsItem::PositionLeft:
                painter->drawText(pt3,_star->starName);
                break;
            case NSStarGraphicsItem::PositionRight:
                painter->drawText(pt4,_star->starName);
                break;
            default:
                break;
            }
            */
    }
    return;
}
