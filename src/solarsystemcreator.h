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

#ifndef SOLARSYSTEMCREATOR_H
#define SOLARSYSTEMCREATOR_H

#include <QObject>
#include "star.h"
#include "planet.h"
#include "onomastikon.h"

class SolarSystemCreator
{

private:
    QSharedPointer<Star>    _star;
    int    _orbits;
    int    _nMod;
    Onomastikon *_onomastikon;

    void setPlanetType(Planet& p, double currentDistance);
    void setPlanetModifiers(Planet& p);

    Planet createPlanet (
            double currentDistance,
            bool isSatellite,
            Planet& planetTop,
            double *prevDistance = 0);

public:
    SolarSystemCreator() : _onomastikon(Onomastikon::instancePtr()) {}
    SolarSystemCreator(QSharedPointer<Star> star) : _onomastikon(Onomastikon::instancePtr()){ _star = star; }

    QSharedPointer<Star>  star() { return _star; }
    void setStar(QSharedPointer<Star> s) { _star = s; }

    void createOrbits();
    void createWorlds();
    void createSatellites();
    bool canCreateWorlds() {
        int sc = (int)_star->starClass();
        int st = (int)_star->starType();

        if (sc != 4 && sc != 5)
            return false;
        if (sc == 4 && (st != 3 && st != 4))
            return false;
        if (sc == 5 && (st < 3 && st > 6))
            return false;
        return true;
    }

    void createSolarSystem()
    {
        if (canCreateWorlds()) {
            _star->deleteSolarSystem();

            _star->calcStarValue();
            createOrbits();
            createWorlds();
            createSatellites();
            _star->calcStarValue();
        }
    }
};

#endif // SOLARSYSTEMCREATOR_H
