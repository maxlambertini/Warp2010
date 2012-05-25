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
