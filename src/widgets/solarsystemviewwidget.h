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

#ifndef SOLARSYSTEMVIEWWIDGET_H
#define SOLARSYSTEMVIEWWIDGET_H

#include <QWidget>
#include "star.h"
#include "planet.h"
#include "helpers/solarsystemtoscene.h"
#include "widgets/starinspector.h"
#include "widgets/planetaryinspector.h"
#include "helpers/solarsystemtoscene.h"

namespace Ui {
    class SolarSystemViewWidget;
}

class SolarSystemViewWidget : public QWidget {
    Q_OBJECT

    QSharedPointer<Star>  _star;
    SolarSystemToScene *_solsysToScene;


public:
    SolarSystemViewWidget(QWidget *parent = 0);
    ~SolarSystemViewWidget();
    void emitPlanetSelected(Planet *p);

    void setStar(QSharedPointer<Star> s);
    inline QSharedPointer<Star>  star() { return _star; }
    inline SolarSystemToScene * solsysToScene() { return _solsysToScene; }

    void exportSolSysToSvg();
    void exportSolSysToPDF();
    void printSolsys();
    void exportSolSysToHtml();


signals:
    void planetSelected(Planet *p);
    void starNameChanged(QString& s);
    void neighborSelected(int i);

public slots:
    void handlePlanetSelected(Planet *p);
    void onStarNameChanged (QString& s);
    void onPlanetDataChanged ();
    void starFullTypeChanged(QString& s);
    void onNeighborSelected(int i);

    //zoom & rotation
    void rotateLeft();
    void rotateRight();
    void zoomIn();
    void zoomOut();

    //slider
    void sliderValueChanged(int val);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SolarSystemViewWidget *ui;
};

#endif // SOLARSYSTEMVIEWWIDGET_H
