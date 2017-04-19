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
