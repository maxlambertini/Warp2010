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


#ifndef PLANETARYINSPECTOR_H
#define PLANETARYINSPECTOR_H

#include <QWidget>
#include <QtGui>
#include <QLineEdit>
#include <QFrame>
#include <QDoubleSpinBox>
#include <QLabel>
#include "planet.h"
#include "helpers/planetrenderer.h"

class PlanetaryInspector : public QWidget
{
Q_OBJECT

    QWidget *centralWidget;
    QLineEdit *txt_name;
    QDoubleSpinBox *spn_diameter;
    QDoubleSpinBox *spn_density;
    QFrame *frm_6;
    QDoubleSpinBox *spn_distance;
    QLabel *lbl_short_description;

    Planet* _planet;

    void createControls();
    void layoutControls();
    void fillControls();
    void connectSignalSlots();
public:
    explicit PlanetaryInspector(QWidget *parent = 0);
    void setPlanet(Planet* p) { _planet = p; fillControls();}
    Planet* planet() { return _planet; }

signals:
    void planetDataLoaded();
    void planetDataChanged();

public slots:
    void onPlanetNameChanged();
    void onPlanetDensityChanged(double d);
    void onPlanetDiameterChanged(double d);
    void onDistanceChanged(double d);


};

#endif // PLANETARYINSPECTOR_H
