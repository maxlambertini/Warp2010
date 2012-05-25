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


#ifndef SOLARSYSTEMTOSCENE_H
#define SOLARSYSTEMTOSCENE_H

#include <QGraphicsScene>
#include "star.h"
#include "gfx_items/planetgraphicsitem.h"


class SolarSystemToScene: public QObject
{
    Q_OBJECT

    QGraphicsScene _scene;
    Star *_star;
public:
    QGraphicsScene& scene() { return _scene; }
    QGraphicsScene* scenePtr() { return &_scene; }

    explicit SolarSystemToScene(QObject *parent = 0);
    void PopulateStarScene();

    void setStar(Star* s) { _star = s; this->PopulateStarScene();}
    Star* star() { return _star; }

signals:
    void planetSelected (Planet *p);

public slots:
    void handlePlanetSelected(Planet *p);

};

#endif // SOLARSYSTEMTOSCENE_H
