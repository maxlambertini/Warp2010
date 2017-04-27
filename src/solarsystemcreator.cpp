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

#include "solarsystemcreator.h"
#include "ssg_structures.h"
#include "planet.h"

void SolarSystemCreator::createOrbits()
{
    _star->numGardens(0);
    _star->numMarginals(0);
    int nSize = (int)_star->starSize();

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


void SolarSystemCreator::createWorlds()
{
    double currentDistance;
    _star->numDesert(0);
    _star->numGasGiant(0);


    _star->calcStarValue();
    for (int h = 0; h < _orbits; h++) {
        bool advanceNextPlanet = true;
        do {
            Planet px;
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
            else
                currentDistance *= (1.2+ (double)(rand() % 900)/1000.0);
            int chance = SSGX::d10();
            if (chance < 8) {

                Planet planet = this->createPlanet(currentDistance, false,px);
                this->setPlanetType(planet, currentDistance);

                int numSat = 0;
                if (planet.planetType() == ptGasGiant)
                    numSat = SSGX::d6()+SSGX::d6()+SSGX::d6();
                else if (planet.planetType() != ptChunk)
                    numSat = SSGX::d6()-3;

                if (numSat > 0)
                {
                    double dSatDistance = 0;
                    for (int idxSat = 0; idxSat < numSat; idxSat++)
                    {
                        Planet sat = this->createPlanet( currentDistance, true, planet, &dSatDistance);
                        this->setPlanetType(sat, currentDistance);
                        if (sat.massEarth() < 0.6)
                            sat.setTidalForce(1.1);
                        else
                            sat.setTidalForce(0.2);
                        planet.appendSatellite(sat);

                    }
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

void SolarSystemCreator::setPlanetType(Planet& planet, double currentDistance)
{
    if (currentDistance < _star->innerLifeZone())
    {
        int die = SSGX::d10()+SSGX::d10();
        int die1 = SSGX::d10()+SSGX::d10();
        switch (planet.atmosphere())
        {
            case atVacuum:
                planet.setPlanetType(ptRockball);
                planet.setWaterPercentage(0);
                planet.orbit().setLongDay();
                break;
            case atVeryThin:
                planet.setPlanetType(ptRockball);
                planet.setWaterPercentage(0);
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atThin:
                planet.setPlanetType(ptDesert);
                planet.setHydrosphereType(NSPlanet::htVapor);
                planet.setWaterPercentage(SSGX::floatRand());
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atStandard:
                planet.setPlanetType(ptHotHouse);
                planet.setHydrosphereType(NSPlanet::htVapor);
                planet.setWaterPercentage(SSGX::floatRand());
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atDense:
                planet.setHydrosphereType(NSPlanet::htVapor);
                planet.setWaterPercentage(SSGX::floatRand());
                planet.setPlanetType(ptHotHouse);
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                if (die1 == 7 && planet.temperature() < 333) {
                    planet.setPlanetType(ptPreGarden);
                    planet.setHydrosphereType(NSPlanet::htLiquid);
                    planet.setWaterPercentage(SSGX::d100()/4);
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
    else if (currentDistance > _star->outerLifeZone())
    {
        double die = SSGX::d10()+SSGX::d10();
        switch (planet.atmosphere())
        {
            case atVacuum:
                planet.setPlanetType(ptIceball);
                planet.setHydrosphereType(NSPlanet::htIce);
                planet.setWaterPercentage(SSGX::d100());
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atVeryThin:
                planet.setPlanetType(ptIceball);
                planet.setHydrosphereType(NSPlanet::htIce);
                planet.setWaterPercentage(SSGX::d100());
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atThin:
                planet.setPlanetType(ptFailedCore);
                planet.setHydrosphereType(NSPlanet::htIce);
                planet.setWaterPercentage(SSGX::d10());
                if (die == 2)
                    planet.orbit().setNormalDay();
                else if (die == 20)
                    planet.orbit().setVeryLongDay();
                else
                    planet.orbit().setLongDay();
                break;
            case atStandard:
                planet.setPlanetType(ptFailedCore);
                planet.setHydrosphereType(NSPlanet::htIce);
                planet.setWaterPercentage(SSGX::d10());
                if (die == 2)
                    planet.orbit().setShortDay();
                else if (die == 20)
                    planet.orbit().setLongDay();
                else
                    planet.orbit().setNormalDay();
                break;
            case atDense:
                planet.setPlanetType(ptFailedCore);
                planet.setHydrosphereType(NSPlanet::htIce);
                planet.setWaterPercentage(SSGX::d10());
                if (die == 2)
                    planet.orbit().setShortDay();
                else if (die == 20)
                    planet.orbit().setLongDay();
                else
                    planet.orbit().setNormalDay();
                break;
            case atMassive:
                planet.setPlanetType(ptGasGiant);
                planet.setHydrosphereType(NSPlanet::htShards);
                planet.setWaterPercentage(SSGX::floatRand());
                planet.orbit().setShortDay();
                break;
        }
    }
    else
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
}

Planet SolarSystemCreator::createPlanet(
        double currentDistance,
        bool isSatellite,
        Planet& planetTop,
        double *prevDistance)
{
    Planet planet;

    Orbit orbit;
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

    d = SSGX::d6();

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



    while (isSatellite && planet.diameter() > planetTop.diameter() / 3)
        planet.setDiameter(planet.diameter()/2);


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
            sSatDist = 105000+(double)((SSGX::dn(40)+5) * planetTop.diameter());
        else
            sSatDist += 80000.0+(double)((SSGX::dn(20)+15) * planet.diameter());
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
