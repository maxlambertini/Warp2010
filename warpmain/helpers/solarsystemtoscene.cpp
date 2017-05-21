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


#include "solarsystemtoscene.h"

SolarSystemToScene::SolarSystemToScene(QObject *parent) : QObject(parent)
{
}

void SolarSystemToScene::PopulateStarScene() {
    if (_star != 0) {
        _scene.clear();
        Planet *p, *s;
        if (_star->planetCount() > 0) 
        {
            float fStepX = 0;
            p = _star->firstPlanet();            
            while (p != 0) {                
                PlanetGraphicsItem *pgi = new PlanetGraphicsItem(fStepX,0,p);
                connect (pgi->selector(),SIGNAL(planetSelected(Planet*)), this, SLOT(handlePlanetSelected(Planet*)));
                pgi->setY(pgi->y()-pgi->boundingRect().height() / 2);
                _scene.addItem(pgi);
                if (p->satellitesCount() > 0) {
                    float fStepY = pgi->boundingRect().height()*0.6;
                    float fStartY = pgi->boundingRect().top() - fStepY;
                    float midStepX = pgi->boundingRect().width()/2;
                    s = p->firstSat();
                    int nCount = 0;
                    while (s != 0) {
                        PlanetGraphicsItem *sgi;
                        if (nCount % 2 == 0) {
                            sgi = new PlanetGraphicsItem(fStepX+midStepX,fStepY,s);
                            sgi->setX(sgi->x() -sgi->boundingRect().width()/2);
                            fStepY += sgi->boundingRect().height()*1.2;
                        }
                        else {
                            sgi = new PlanetGraphicsItem(fStepX+midStepX,fStartY,s);
                            sgi->setX(sgi->x() -sgi->boundingRect().width()/2);
                            sgi->setY(sgi->y() - sgi->boundingRect().height());
                            fStartY -= sgi->boundingRect().height()*1.2;
                        }
                        nCount++;
                        connect (sgi->selector(),SIGNAL(planetSelected(Planet*)), this, SLOT(handlePlanetSelected(Planet*)));
                        _scene.addItem(sgi);
                        s = p->nextSat();
                    }
                }
                fStepX += pgi->boundingRect().width() * 1.2;
                p = _star->nextPlanet();
            }
        }
    } else {
        _scene.clear();
    }

}

void SolarSystemToScene::handlePlanetSelected(Planet *p) {
    emit planetSelected(p);
}
