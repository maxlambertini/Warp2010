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
#include <QApplication>
#include <math.h>
#include "solarsystemwidget.h"


const char* planetPixmap[] = {
        "",
        ":/Solsys/pics/Planets/Chunk.png",
        ":/Solsys/pics/Planets/Rockball.png",
        ":/Solsys/pics/Planets/Desert.png",
        ":/Solsys/pics/Planets/HotHouse.png",
        ":/Solsys/pics/Planets/Glacier.png",
        ":/Solsys/pics/Planets/Terrestrial.png",
        ":/Solsys/pics/Planets/Marginal.png",
        ":/Solsys/pics/Planets/Marginal.png",
        ":/Solsys/pics/Planets/GasGiant.png",
        ":/Solsys/pics/Planets/SuperJovian.png",
        ":/Solsys/pics/Planets/SmallPlanet.png",
        ":/Solsys/pics/Planets/Iceball.png"
    };


SolarSystemWidget::SolarSystemWidget(QWidget *parent = 0) : QWidget(parent)
{
    _star = 0;
}

void SolarSystemWidget::paintEvent(QPaintEvent *event)       
{
    _customWidth = this->width();
    _customHeight = this->height();
    QPainter painter(this);
    paintSolSys(painter);
}

void SolarSystemWidget::copyToClipboard()
{
    _customWidth = 1024;
    _customHeight = 512;
    QPixmap pixmap(_customWidth,_customHeight);
    QPainter painter(&pixmap);
    paintSolSys(painter);
    painter.save();
    QImage img = pixmap.toImage();
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setImage(img);
    _customWidth = this->width();
    _customHeight = this->height();

}

void SolarSystemWidget::exportToImage(QString& filename, int imgWidth = 1024, int imgHeight=512)
{
    _customWidth = imgWidth;
    _customHeight = imgHeight;
    QPixmap *pixmap = new QPixmap(_customWidth, _customHeight);
    QPainter painter(pixmap);
    paintSolSys(painter);
    painter.end();
    pixmap->save(filename);
    delete pixmap;
    _customWidth = this->width();
    _customHeight = this->height();
}

void SolarSystemWidget::paintSolSys(QPainter& painter)
{
    painter.setRenderHint(QPainter::Antialiasing);
    if (_star != 0 && _star->planetCount() > 0)
    {
        //Planet *pFirst = _star->planets().first();
        Planet pLast = _star->planets().last();
        //double dFirst = log2( pFirst->orbit()->distance());
        double dLast = log2(pLast.orbit().distance());
        int dDiv = (int)(trunc(dLast)+9);

        paintDivisions(painter, dDiv);
        paintPlanets(painter);

    }
    else
    {
        //// qDebug() << "empty widget";
        QLinearGradient linearGrad(QPointF(0, 0), QPointF(_customWidth, _customHeight));
        linearGrad.setColorAt(0, Qt::gray);
        linearGrad.setColorAt(1, Qt::white);
        painter.fillRect(rect(), linearGrad);
    }

}

void SolarSystemWidget::paintDivisions(QPainter& painter, int iDiv)
{
    int iStepWidth = _customWidth/iDiv;
    _iStepWidth = iStepWidth;
    QColor colorOdd = QColor (255,255,224);
    QColor colorEven = QColor (255,255,255);
    QBrush brushOdd = QBrush(colorOdd);
    QBrush brushEven = QBrush(colorEven);
    QBrush brushBlack = QBrush(QColor("black"));
    QPen myPen = QPen (colorEven);
    myPen.setWidth(0);

    painter.setRenderHint(QPainter::Antialiasing);

    for (int x = 0; x < iDiv; x++) {
        QRect r = QRect(iStepWidth *x, 0, iStepWidth, _customHeight);
        if (x % 2 == 0)
            painter.setBrush(brushEven);
        else
            painter.setBrush(brushOdd);
        painter.setPen(myPen);
        painter.drawRect(r);
        QString dist = QString().sprintf("%4.3f UA",pow(2,x-7));
        painter.setBrush(brushBlack);
        painter.setPen(QColor("black"));
        painter.drawText ((iStepWidth*x)+3,15,dist);
    }
}

void SolarSystemWidget::paintPlanets(QPainter& painter )
{
    painter.setRenderHint(QPainter::Antialiasing);

    Planet *planet;
    int idx = 0;
    if (_star->planetCount() > 0) {
        Planet *pArr = const_cast<Planet *>(_star->planetsPtr()->data());
        for (int ix = 0; ix < _star->planetCount(); ix++) {
            planet = &(pArr[ix]);
            double dx = planet->orbit().distance();
            dx = (int) ( ((double)_iStepWidth) *(7 + log2(dx)));

            double radius = 10.0;
            if (planet->diameter() < 12000)
                radius = planet->diameter()/1000.0;
            else {
                radius = 12.0 * (1+log(planet->diameter()/12000.0));
            }
            if (radius < 1.5)
                radius = 1.5;


            int nType = (int)planet->planetType();
            QString pixmapPath = QString(planetPixmap[nType]);
            QPixmap* icon = &(PixmapHelper::instancePtr()->pixHash()[pixmapPath]);
            QImage img = icon->toImage();
            int nSize = (int)(radius *2);
            QImage result = img.scaled(nSize, nSize, Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
            QPoint pt = QPoint((int)dx,(_customHeight /2) - (int)radius);

            if (idx++ == _currentPlanetIndex) {
                QPoint pt2 = QPoint((int)(dx-2),(_customHeight /2) - ((int)radius+2));
                painter.drawEllipse(pt2.x(),pt2.y(),nSize+4, nSize+4);
            }
            painter.drawImage(pt, result);
        }
    }
    else {
    }
}
