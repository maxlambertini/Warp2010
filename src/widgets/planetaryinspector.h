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


#ifndef PLANETARYINSPECTOR_H
#define PLANETARYINSPECTOR_H

#include <QWidget>
#include <QtGui>
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
