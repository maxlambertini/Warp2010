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

#include "starmapwidget.h"
#include "coordinates.h"
#include <QtSvg>
#include <QtCore>
#include <QtGui>
#include <QtGlobal>
#include <stdlib.h>
#include "star.h"
#include "starlist.h"

StarMapWidget::StarMapWidget(QWidget *parent) : QWidget(parent)
{
    _starList = StarList::StarListPtr();
}

void StarMapWidget::loadMap(const QString& filename)
{
    _starList->loadMap(filename);
    _starList->calculateNeighbors(7.7);
    _starList->buildMatrix();

    QString data("On the road to Gamma Serpenti!\n");
    Star *gs = _starList->stars().at(477);

    int iStar;
    foreach (iStar, gs->path())
    {
        Star *step = _starList->stars().at(iStar);
        data.append( step->starName + "\n");
    }

    QMessageBox::information(this,"On The Road...",data);
}

void StarMapWidget::setMapToStar()
{
    _starList->rebuildMatrix(499);
    QString data("On the road to Gamma Serpenti from Kingsland!\n");
    Star *gs = _starList->stars().at(477);

    int iStar;
    foreach (iStar, gs->path())
    {
        Star *step = _starList->stars().at(iStar);
        data.append( step->starName + "\n");
    }

    QMessageBox::information(this,"On The Road...",data);
}

void StarMapWidget::createSVG(const QString& filename = "c:/starmap.svg")
{
    QSvgGenerator *generator = new QSvgGenerator();
    generator->setFileName(filename);
    QColor colorFill(255,128,0,128);
    QColor colorMap(255,255,0,128);
    QColor colorPen("black");

    QBrush brushStar(colorFill);
    QBrush brushText(colorPen);
    QPen   pen(colorPen);
    QPen   routepen(colorMap);
    QFont  font("Arial");
    font.setPointSizeF(0.2);

    QPainter painter(generator);
    painter.scale(70,70);

    QPointF ptPrev;

    Star *theStar;
    foreach (theStar, _starList->stars()) {
        theStar->leave();
    }

    Star *p1, *p2;
    painter.setPen(routepen);
    //int pathCount = 0;
    foreach (theStar, _starList->stars()) {
        int pathCount = theStar->path().count();
        if (pathCount > 1) {
            for (int w = 1; w < pathCount; w++)
            {
                p1 = _starList->stars().at(theStar->path().at(w-1));
                p2 = _starList->stars().at(theStar->path().at(w));
                QLineF line = QLineF(
                        p1->x(),
                        -p1->y(),
                        p2->x(),
                        -p2->y());
                painter.drawLine(line);
            }
        }
    }


    for (int h = 0; h < this->_starList->stars().count(); h++)
    {
        int nAngle = rand() % 360;

        painter.setFont(font);
        painter.setBrush(brushStar);
        painter.setPen(pen);
        pen.setWidthF(0.05);

        Star star = *(_starList->stars().at(h));

        QPointF pt = QPointF(star.x(), star.y());

        if (h > 0)
            painter.translate(-ptPrev.x(), ptPrev.y());
        ptPrev = pt;
        painter.translate(pt.x(), pt.y());

        QString name = star.starName;

        painter.drawEllipse(QPointF(0,0), 0.2,0.2);
        painter.rotate((qreal)nAngle);
        painter.drawText(QPointF(0.2,0.2),name);
        painter.rotate(-(qreal)nAngle);
    }
    painter.end();
    delete generator;

}

