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
#include "basicstarinfowidget.h"

BasicStarInfoWidget::BasicStarInfoWidget(QWidget *parent) :
    QWidget(parent)
{
    _star = 0;
}

void BasicStarInfoWidget::paintEvent(QPaintEvent *event __attribute__((unused))) {
    int width = this->width();
    int height = this->height();
    QPalette::ColorRole role = this->backgroundRole();
    QPalette p = qApp->palette();
    QColor c = p.color(role);
    QPen pen;
    QBrush brush(QColor(255,255,255));
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.fillRect(QRect(0,0,width,height),c);
    if (_star != 0) {
        switch (_star->starType())
        {
        case NSStar::stO:
            brush.setColor(QColor(0,0,192));
            break;
        case NSStar::stB:
            brush.setColor(QColor(112,112,255));
            break;
        case NSStar::stA:
            brush.setColor(QColor(224,224,255));
            break;
        case NSStar::stF:
            brush.setColor(QColor(255,255,255));
            break;
        case NSStar::stG:
            brush.setColor(QColor(255,255,0));
            break;
        case NSStar::stK:
            brush.setColor(QColor(255,192,0));
            break;
        case NSStar::stM:
            brush.setColor(QColor(255,0,0));
            break;
        default:
            brush.setColor(QColor(128,64,0));
            break;
        }

        pen.setColor(QColor(0,0,0));
        pen.setWidthF(3.0);
        int mx = width/2;
        int my = height/2;
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawEllipse(QPoint(mx,my),my-3,my-3);
        pen.setWidthF(2.0);
        if (_star->numGardens() > 0) {
            pen.setColor(QColor (64,128,255));
            brush.setColor(QColor (0,0,255));
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint (12,12),9,9);
        }

        if (_star->numMarginals() > 0) {
            pen.setColor(QColor (64,128,255));
            brush.setColor(QColor (255,224,46));
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawEllipse(QPoint (12,height-12),9,9);

        }
    }
}
