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

#ifndef STARMAPWIDGET_H
#define STARMAPWIDGET_H

#include <QWidget>
#include <QtCore>
#include "starlist.h"
#include "star.h"

class StarMapWidget : public QWidget
{
    Q_OBJECT

private:

    StarList*    _starList;
    double      _scaleFactor;
    double      _rotationAngle;
    QFont       _font;

public slots:
    void setMapToStar();


public:
    StarMapWidget(QWidget *parent = 0);

    const StarList* starList() { return _starList;}
    double scaleFactor() { return _scaleFactor;}
    double rotationAngle() { return _rotationAngle;}

    void setScaleFactor(double d) { _scaleFactor = d;}
    void setRotationAngle(double d) { _rotationAngle = d;}

    void loadMap(const QString& filename);
    void createSVG(const QString& filename);
};

#endif // STARMAPWIDGET_H
