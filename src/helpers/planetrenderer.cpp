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


#include "planetrenderer.h"
#include "planet.h"
#include <QtCore>

PlanetRenderer PlanetRenderer::_current;

PlanetRenderer::PlanetRenderer()
{
}

PlanetRenderer::~PlanetRenderer() {}

QString PlanetRenderer::smallDescription()
{
    QString planet_tpl = QString(
            "<table width='100%' border='0' cellpadding='2' cellspacing='0'>"
            "   <tr>"
            "       <td align='right'>Earth Mass</td>"
            "       <td><b>%1</b></td>"
            "       <td align='right'>Gravity (G)</td>"
            "       <td><b>%2</b></td>"
            "       <td align='right'><nobr>Temperature (K)</nobr></td>"
            "       <td><b>%3</b></td>"
            "       <td align='right'>MMWR</td>"
            "       <td><b>%4</b></td>"
            "       <td align='right'>Water</td>"
            "       <td><b>%5</b></td>"
            "       <td align='right'>Distance</td>"
            "       <td><b>%6</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'>Eccentricity</td>"
            "       <td><b>%7</b></td>"
            "       <td align='right'>Inclination</td>"
            "       <td><b>%8</b></td>"
            "       <td align='right'>Obliquity</td>"
            "       <td><b>%9</b></td>"
            "       <td align='right'>Year</td>"
            "       <td><b>%10</b></td>"
            "       <td align='right'>Day</td>"
            "       <td><b>%11</b></td>"
            "       <td align='right'>Satellite</td>"
            "       <td><b>%12</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'><nobr>Core Type</nobr></td>"
            "       <td><b>%13</b></td>"
            "       <td align='right'><nobr>Planet Type</nobr></td>"
            "       <td><b>%14</b></td>"
            "       <td align='right'>Hydrosphere</td>"
            "       <td><b>%15</b></td>"
            "       <td align='right'>Atmosphere</td>"
            "       <td><b>%16</b></td>"
            "       <td align='right'><nobr>Tidal Lock</nobr></td>"
            "       <td><b>%17</b></td>"
            "   </tr>"
            "</table>");

    if (!_planet.isNull()) {
        Planet *p = _planet;
        planet_tpl = planet_tpl
                     .arg(p->massEarth())
                     .arg(p->gravEarth())
                     .arg(p->temperature())
                     .arg(p->mmwr())
                     .arg(p->waterPercentage())
                     .arg(p->orbit().distance())
                     .arg(p->orbit().eccentricity())
                     .arg(p->orbit().inclination())
                     .arg(p->orbit().obliquity())
                     .arg(p->orbit().year()*365.25)
                     .arg(p->orbit().day())
                     .arg(p->isSatellite() ? "Yes" : "No")
                     .arg(p->getCoreTypeDesc())
                     .arg(p->getPlanetTypeDesc())
                     .arg(p->getHydrosphereDesc())
                     .arg(p->getAtmosphereDesc())
                     .arg(p->tidalForce() > 1.0 ? "Yes" : "No");

        return planet_tpl;
    }
    else
        return "";

}

QString PlanetRenderer::description() {

    QString planet_tpl = QString(
            "<h3>%1</h3>"
            "<table border='0' cellpadding='2' cellspacing='0'>"
            "   <tr>"
            "       <td align='right'>Diameter</td>"
            "       <td><b>%2</b></td>"
            "       <td align='right'>Density</td>"
            "       <td><b>%3</b></td>"
            "       <td align='right'>Earth Mass</td>"
            "       <td><b>%4</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'>Gravity (G)</td>"
            "       <td><b>%5</b></td>"
            "       <td align='right'><nobr>Temperature (K)</nobr></td>"
            "       <td><b>%6</b></td>"
            "       <td align='right'>MMWR</td>"
            "       <td><b>%7</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'>Water</td>"
            "       <td><b>%8</b></td>"
            "       <td align='right'>Distance</td>"
            "       <td><b>%9</b></td>"
            "       <td align='right'>Eccentricity</td>"
            "       <td><b>%10</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'>Inclination</td>"
            "       <td><b>%11</b></td>"
            "       <td align='right'>Obliquity</td>"
            "       <td><b>%12</b></td>"
            "       <td align='right'>Year</td>"
            "       <td><b>%13</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'>Day</td>"
            "       <td><b>%14</b></td>"
            "       <td align='right'>Satellite</td>"
            "       <td><b>%15</b></td>"
            "       <td align='right'><nobr>Core Type</nobr></td>"
            "       <td><b>%16</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'><nobr>Planet Type</nobr></td>"
            "       <td><b>%17</b></td>"
            "       <td align='right'>Hydrosphere</td>"
            "       <td><b>%18</b></td>"
            "       <td align='right'>Atmosphere</td>"
            "       <td><b>%19</b></td>"
            "   </tr>"
            "   <tr>"
            "       <td align='right'><nobr>Tidal Lock</nobr></td>"
            "       <td><b>%20</b></td>"
            "   </tr>"
            "</table>");

    if (!_planet.isNull()) {
        Planet *p = _planet;
        planet_tpl = planet_tpl
                     .arg(p->name())
                     .arg(p->diameter())
                     .arg(p->density())
                     .arg(p->massEarth())
                     .arg(p->gravEarth())
                     .arg(p->temperature())
                     .arg(p->mmwr())
                     .arg(p->waterPercentage())
                     .arg(p->orbit().distance())
                     .arg(p->orbit().eccentricity())
                     .arg(p->orbit().inclination())
                     .arg(p->orbit().obliquity())
                     .arg(p->orbit().year()*365.25)
                     .arg(p->orbit().day())
                     .arg(p->isSatellite() ? "Yes" : "No")
                     .arg(p->getCoreTypeDesc())
                     .arg(p->getPlanetTypeDesc())
                     .arg(p->getHydrosphereDesc())
                     .arg(p->getAtmosphereDesc())
                     .arg(p->tidalForce() > 1.0 ? "Yes" : "No");

        return planet_tpl;
    }
    else
        return "";
}

