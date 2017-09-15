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
    void makeSatellite(Planet &planet, double &dSatDistance, double currentDistance);
    void makePlanet(bool advanceNextPlanet, const double MIN_PLANET_DISTANCE_GG, double currentDistance, double prevSatDistance, Planet& px);
    void setPlanetTypeInner(Planet& planet);
    void setPlanetTypeOuter(Planet& planet);
    void setPlanetTypeLifeZone(Planet& planet);
    void setPtRockball(Planet& planet);
    void setPtDesert(Planet& planet);
    void setPtHotHouse(Planet& planet);
    void setPtPreGarden(Planet& planet);
    void setPtGasGiant(Planet& planet);
    void setPtIceball(Planet& planet);
    void setPtFailedCore(Planet& planet);
    void makeDiameterAndDensity(int d, double currentDistance, Planet planet, bool isSatellite, Planet& planetTop);
    void makeOrbit(Orbit &orbit);
    void makeDiameterAndDensity(bool isSatellite, Planet &planet, double currentDistance, Planet& planetTop);
};

#endif // SOLARSYSTEMCREATOR_H
