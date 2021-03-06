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

#include "solarsystemcreator.h"
#include "ssg_structures.h"
#include "planet.h"

void SolarSystemCreator::createOrbits()
{
    _star->numGardens(0);
    _star->numMarginals(0);
    int nSize  __attribute__((unused)) = (int)_star->starSize();

    _orbits = 0;
    _nMod = 0;

    switch (_star->starType())
    {
        case NSStar::stF:
            _nMod -= 2;
            _orbits = SSGX::d10();
            break;
        case NSStar::stG:
            _orbits = SSGX::d6() + SSGX::d6() + SSGX::d6();
            break;
        case NSStar::stK:
            _nMod += 1;
            _orbits = SSGX::d6() + SSGX::d6();
            break;
        case NSStar::stM:
            _nMod += 2;
            _orbits = SSGX::d6();
            break;
        default:
            _orbits = SSGX::d6();
            break;
    }

}


void SolarSystemCreator::makeSatellite(Planet& planet, double &dSatDistance, double currentDistance)
{
    Planet sat = this->createPlanet( currentDistance, true, planet, &dSatDistance);
    sat.setStar(_star.data());
    this->setPlanetType(sat, currentDistance);
    if (sat.massEarth() < 0.6)
        sat.setTidalForce(1.1);
    else
        sat.setTidalForce(0.2);
    planet.appendSatellite(sat);
}

void SolarSystemCreator::makePlanet(bool advanceNextPlanet __attribute__((unused)), const double MIN_PLANET_DISTANCE_GG, double currentDistance,
                                    double prevSatDistance __attribute__((unused)), Planet& px)
{
    Planet planet = this->createPlanet(currentDistance, false,px);
    planet.setStar(_star.data());
    this->setPlanetType(planet, currentDistance);

    int numSat = 0;
    if (planet.planetType() == ptGasGiant)
        numSat = SSGX::d6()+SSGX::d6()+SSGX::d6();
    else if (planet.planetType() != ptChunk)
        numSat = SSGX::d6()-3;


    if (numSat > 0)
    {
        prevSatDistance = 0;
        double dSatDistance = 0;
        for (int idxSat = 0; idxSat < numSat; idxSat++)
        {
            makeSatellite(planet, dSatDistance, currentDistance);
        }
        prevSatDistance = dSatDistance > MIN_PLANET_DISTANCE_GG ? MIN_PLANET_DISTANCE_GG : dSatDistance;
    }
    double T = (_star->mass()*266400.0 / pow((planet.orbitPtr()->distance() *400),3));
    double tf = (double)((0.83 + (double) SSGX::d10() *.03) *T * _star->solarAge() / 6.6);
    planet.setTidalForce(tf);
    //qDebug() << "Set Tidal Force. " << tf << planet.tidalForce();

    if (planet.planetType() == ptGasGiant && planet.tidalForce() > 1.0) {
        advanceNextPlanet = false;
    }
    else  {
        advanceNextPlanet = true;
        _star->appendToPlanets(planet);
    }
}

void SolarSystemCreator::createWorlds()
{
    double currentDistance;
    _star->numDesert(0);
    _star->numGasGiant(0);

    double prevSatDistance = 0.0;
    //double prevDistance = 0.0;

    const double MIN_PLANET_DISTANCE_GG = 4000000.0;
    const double MAX_OUTER_PLANET = 100.0;

    _star->calcStarValue();
    for (int h = 0; h < _orbits; h++) {
        bool advanceNextPlanet = true;
        do {
            Planet px;
            px.setStar(_star.data());
            if (h == 0) {
                double dModifier = 0.1;
                if (_star->starType() == NSStar::stM)
                    dModifier *= .33;
                if (_star->starType() == NSStar::stK)
                    dModifier *= .66;
                if (_star->starType() == NSStar::stF)
                    dModifier *= 1.25;
                currentDistance = dModifier + SSGX::floatRand() * dModifier;
            }
            else {
                prevSatDistance = currentDistance;
                auto minDistance = currentDistance + (prevSatDistance * 50.0 / 150000000.0);
                auto newDistance = (currentDistance * (1.05+ (double)(rand() % 900)/1000.0)) - currentDistance;
                if (minDistance > newDistance)
                    currentDistance += minDistance;
                else
                    currentDistance += newDistance;
            }
            int chance = SSGX::d10();
            if (chance < 8 && currentDistance < MAX_OUTER_PLANET) {
                makePlanet(advanceNextPlanet, MIN_PLANET_DISTANCE_GG, currentDistance, prevSatDistance, px);
            }
        } while (!advanceNextPlanet);

    }
    _star->calcStarValue();

}

void SolarSystemCreator::createSatellites()
{
}

void SolarSystemCreator::setPlanetModifiers(Planet& planet)
{
    if (planet.planetType() == ptGasGiant) {
        int nSize = SSGX::d6();
        if (nSize  <4)
            planet.setDiameter(planet.diameter()*2);
        if (nSize  <3)
            planet.setDiameter(planet.diameter()*2);
        if (nSize  <2)
            planet.setDiameter(planet.diameter()*2);
        if (planet.diameter() < 30000)
            planet.setDiameter(15000 +SSGX::d10()*10000+SSGX::dn(5000));
    }

    if (planet.planetType() == ptGarden) {
        int nSize = SSGX::d10() + _nMod;
        if ( nSize < 3)
            planet.setPlanetType(ptPreGarden);
        if ( nSize >=3 && nSize < 6)
            planet.setPlanetType(ptGlacier);
        if (nSize >= 10)
            planet.setPlanetType(ptPostGarden);
    }
}

void SolarSystemCreator::setPtRockball(Planet& planet)
{
    planet.setPlanetType(ptRockball);
    planet.setWaterPercentage(0);
}

void SolarSystemCreator::setPtDesert(Planet& planet)
{
    planet.setPlanetType(ptDesert);
    planet.setHydrosphereType(NSPlanet::htVapor);
    planet.setWaterPercentage(SSGX::floatRand());
}

void SolarSystemCreator::setPtHotHouse(Planet& planet)
{
    planet.setPlanetType(ptHotHouse);
    planet.setHydrosphereType(NSPlanet::htVapor);
    planet.setWaterPercentage(SSGX::floatRand());
}

void SolarSystemCreator::setPtPreGarden(Planet& planet)
{
    planet.setPlanetType(ptPreGarden);
    planet.setHydrosphereType(NSPlanet::htLiquid);
    planet.setWaterPercentage(SSGX::d100()/4);
}

void SolarSystemCreator::setPtGasGiant(Planet& planet)
{
    planet.setPlanetType(ptGasGiant);
    planet.setHydrosphereType(NSPlanet::htShards);
    planet.setWaterPercentage(SSGX::floatRand());
    planet.orbit().setShortDay();
}

void SolarSystemCreator::setPlanetTypeInner(Planet& planet)
{
    int die = SSGX::d10()+SSGX::d10();
    int die1 = SSGX::d10()+SSGX::d10();
    switch (planet.atmosphere())
    {
        case atVacuum:
            planet.orbit().setLongDay();
            setPtRockball(planet);
            break;
        case atVeryThin:
            setPtRockball(planet);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atThin:
            setPtDesert(planet);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atStandard:
            if (SSGX::d10() < 7) setPtHotHouse(planet); else setPtRockball(planet);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atDense:
        if (SSGX::d10() < 7) setPtHotHouse(planet); else setPtRockball(planet);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            if (die1 == 7 && planet.temperature() < 333) {
                setPtPreGarden(planet);
            }
            break;
        case atMassive:
            setPtGasGiant(planet);
            break;

    }
}

void SolarSystemCreator::setPtIceball(Planet& planet)
{
    planet.setPlanetType(ptIceball);
    planet.setWaterPercentage(SSGX::d100());
}

void SolarSystemCreator::setPtFailedCore(Planet& planet)
{
    planet.setPlanetType(ptFailedCore);
    planet.setHydrosphereType(NSPlanet::htIce);
    planet.setWaterPercentage(SSGX::d10());
}

void SolarSystemCreator::setPlanetTypeOuter(Planet& planet)
{
    double die = SSGX::d10()+SSGX::d10();
    switch (planet.atmosphere())
    {
        case atVacuum:
            if (SSGX::d10() < 7) setPtIceball(planet); else setPtRockball(planet);
            planet.setHydrosphereType(NSPlanet::htIce);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atVeryThin:
            if (SSGX::d10() < 7) setPtIceball(planet); else setPtRockball(planet);
            planet.setHydrosphereType(NSPlanet::htIce);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atThin:
            if (SSGX::d10() < 7) setPtRockball(planet); else setPtDesert(planet);
            planet.setHydrosphereType(NSPlanet::htIce);
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atStandard:
            if (SSGX::d10() < 7) setPtRockball(planet); else setPtDesert(planet);
            planet.setHydrosphereType(NSPlanet::htIce);
            if (die == 2)
                planet.orbit().setShortDay();
            else if (die == 20)
                planet.orbit().setLongDay();
            else
                planet.orbit().setNormalDay();
            break;
        case atDense:
        if (SSGX::d10() < 7) setPtDesert(planet); else setPtFailedCore(planet);
            if (die == 2)
                planet.orbit().setShortDay();
            else if (die == 20)
                planet.orbit().setLongDay();
            else
                planet.orbit().setNormalDay();
            break;
        case atMassive:
            setPtGasGiant(planet);
            break;
    }
}

void SolarSystemCreator::setPlanetTypeLifeZone(Planet& planet)
{
    double die = SSGX::d10()+SSGX::d10();
    double die1 = SSGX::d10()+SSGX::d10();
    switch (planet.atmosphere())
    {
        case atVacuum:
            planet.setPlanetType(ptRockball);
            planet.setHydrosphereType(NSPlanet::htIce);
            planet.setWaterPercentage(SSGX::floatRand());
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atVeryThin:
            planet.setPlanetType(ptRockball);
            planet.setHydrosphereType(NSPlanet::htIce);
            planet.setWaterPercentage(SSGX::floatRand());
            if (die == 2)
                planet.orbit().setNormalDay();
            else if (die == 20)
                planet.orbit().setVeryLongDay();
            else
                planet.orbit().setLongDay();
            break;
        case atThin:
            planet.setPlanetType(ptDesert);
            planet.setHydrosphereType(NSPlanet::htIce);
            planet.setWaterPercentage(SSGX::floatRand());
            if (die == 2)
                planet.orbit().setShortDay();
            else if (die == 20)
                planet.orbit().setLongDay();
            else
                planet.orbit().setNormalDay();
            break;
        case atStandard:
            planet.setPlanetType(ptDesert);
            planet.setHydrosphereType(NSPlanet::htIce);
            planet.setWaterPercentage(SSGX::floatRand());
            if (die == 2)
                planet.orbit().setShortDay();
            else if (die == 20)
                planet.orbit().setLongDay();
            else
                planet.orbit().setNormalDay();
            if (die1 == 7)
                planet.setPlanetType(ptPreGarden);
            break;
        case atDense:
            planet.setPlanetType(ptGarden);

            planet.setHydrosphereType(NSPlanet::htLiquid);
            planet.setWaterPercentage(SSGX::dn(90));
            if (die == 2)
                planet.orbit().setShortDay();
            else if (die == 20)
                planet.orbit().setLongDay();
            else
                planet.orbit().setNormalDay();
            if  ( planet.temperature() < 230)
                planet.setPlanetType(ptGlacier);

            switch (_star->starType()) {
            case NSStar::stF:
                die1--;
                break;
            case NSStar::stK:
                die1++;
                break;
            case NSStar::stM:
                die1+=2;
                break;
            default:
                break;
            }

            if (die1 < 3) {
                planet.setPlanetType(ptPreGarden);
                planet.setWaterPercentage(SSGX::dn(20));
            }
            if (die1 > 17) {
                planet.setPlanetType(ptPostGarden);
                planet.setWaterPercentage(SSGX::dn(20));
            }
            break;
        case atMassive:
            planet.setPlanetType(ptGasGiant);
            planet.setHydrosphereType(NSPlanet::htShards);
            planet.setWaterPercentage(SSGX::floatRand());
            planet.orbit().setShortDay();
            break;
    }
}

void SolarSystemCreator::setPlanetType(Planet& planet, double currentDistance)
{
    if (currentDistance < _star->innerLifeZone())
    {
        setPlanetTypeInner(planet);
    }
    else if (currentDistance > _star->outerLifeZone())
    {
        setPlanetTypeOuter(planet);
    }
    else
    {
        setPlanetTypeLifeZone(planet);
    }
}

void SolarSystemCreator::makeOrbit(Orbit& orbit)
{
    int d = SSGX::d6();

    if (d == 3)
        orbit.setEccentricity( (double)SSGX::dn(2000) / 10000.0);
    else
        orbit.setEccentricity( (double)SSGX::dn(200) / 10000.0);

    if (d == 4)
        orbit.setInclination( (double)(SSGX::d100() -50)/2.5);
    else
        orbit.setInclination( (double)(SSGX::d100() -50)/20);

    if (d == 6)
        orbit.setObliquity( (double)(SSGX::d100() -50)/2.5);
    else
        orbit.setObliquity( (double)(SSGX::d100() -50)/10);
}

void SolarSystemCreator::makeDiameterAndDensity(bool isSatellite, Planet& planet, double currentDistance, Planet& planetTop)
{
    int d = SSGX::d6();

    if (currentDistance > _star->outerLifeZone()) {
        if (d < 5) {
            planet.setCoreType(NSPlanet::ctIcy);
            planet.setDensity( ((double)(SSGX::dn(400)))/1000*5520.0);
            if (!isSatellite)
                planet.setDiameter(SSGX::icyDiameter());
            else
                planet.setDiameter(SSGX::satDiameter());

        }
        else {
            if (!isSatellite)
                planet.setDiameter(SSGX::rockyDiameter());
            else
                planet.setDiameter(SSGX::satDiameter());

            planet.setDensity( ((double)(400+SSGX::dn(600)))/1000*5520.0);
        }
    }
    else {
        if (!isSatellite)
            planet.setDiameter(SSGX::rockyDiameter());
        else
            planet.setDiameter(SSGX::satDiameter());
        planet.setDensity( ((double)(400+SSGX::dn(900)))/1000*5520.0);
    }

    int divFactor = (planetTop.planetType() == ptGasGiant) ? 6 : 3;

    while (isSatellite && (planet.diameter() > planetTop.diameter() / divFactor || planet.diameter() > 14000))
        planet.setDiameter(planet.diameter()/1.5);
}

Planet SolarSystemCreator::createPlanet(
        double currentDistance,
        bool isSatellite,
        Planet& planetTop,
        double *prevDistance)
{
    Planet planet;
    if (isSatellite)
        planet.setParent(&planetTop);

    Orbit orbit;

    makeOrbit(orbit);
    makeDiameterAndDensity(isSatellite, planet, currentDistance, planetTop);


    double dTemp = 255 / sqrt(( currentDistance / sqrt (_star->luminosity())));
    planet.setTemperature(dTemp);
    double dmmwr = (0.02783 * dTemp) / ( pow(planet.gravEarth(),2) );
    planet.setMmwr(dmmwr);
    if (dmmwr < 120)
        planet.setAtmosphere(atVeryThin);
    if (dmmwr < 80)
        planet.setAtmosphere(atThin);
    if (dmmwr < 40)
        planet.setAtmosphere(atStandard);
    if (dmmwr < 20)
        planet.setAtmosphere(atDense);
    if (dmmwr < 5) {
        if (planet.diameter() > 20000 )
            planet.setAtmosphere(atMassive);
        else
            planet.setAtmosphere(atDense);
    }

    this->setPlanetType(planet,currentDistance);

    if (!isSatellite) {
        this->setPlanetModifiers(planet);
        planet.setPlanetFlag();
    }
    else {
        planet.setSatelliteFlag();
        //qDebug() << "Satellite flag set: " << planet.isSatellite();
    }

    if (!isSatellite) {
        orbit.setDistance(currentDistance);
        orbit.setYear(_star->mass());
    }
    else {
        double sSatDist = *prevDistance;
        if (sSatDist <= 0)
            if (planetTop.planetType() != ptGasGiant)
                sSatDist = 105000+(double)((SSGX::dn(20)+10) * planetTop.diameter());
            else
                sSatDist = 105000+(double)((SSGX::floatRand()*1.8+2.0) * planetTop.diameter());
        else
            sSatDist += 80000.0+(double)((SSGX::dn(50)+25) * planet.diameter());
        *prevDistance = sSatDist;

        orbit.setDistance(sSatDist);  //in km

        double d1 = orbit.distance() / 40000.0;
        d1 = (pow(d1,3) * 793.64) / (planetTop.massEarth() + planet.massEarth());
        double dYear = sqrt(d1);

        orbit.setFixedYear(dYear);
    }

    planet.setOrbit(orbit);

    int w = rand() % 10;
    switch (w) {
    case 1:
        planet.setName(_onomastikon->fakeNomen());
        break;
    case 2:
        planet.setName(_onomastikon->fakeNomen());
        break;
    case 3:
        planet.setName(_onomastikon->nomen());
        break;
    case 4:
        planet.setName(_onomastikon->nomen());
        break;
    case 5:
        planet.setName(_onomastikon->sigla());
        break;
    default:
        planet.setName(_onomastikon->pseudoNomen());
        break;

    }


    return planet;
}
