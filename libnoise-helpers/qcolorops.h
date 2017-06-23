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

#ifndef QCOLOROPS_H
#define QCOLOROPS_H

#include <QColor>
#include <QMap>
#include <ssg_structures.h>


namespace ColorOps {


    inline QColor randomColor() { return QColor(SSGX::dn(255), SSGX::dn(255),SSGX::dn(255)); }
    inline QColor irregularLightenColor(const QColor &clr, int step=25) {
        int dStep = step / 2;
        int rSrep = 1+dStep / 4;
        QColor res(clr);
        int newHue = (res.hslHue() + SSGX::dx(dStep) -rSrep) % 255;
        int newSat = (res.hslSaturation() + SSGX::dx(dStep) -rSrep) % 255;
        int newLt = (res.lightness() + SSGX::dx(step)) % 255;
        if (newLt < 144)
            newLt = 144 + SSGX::dx(110);
        res.setHsl ( newHue,newSat, newLt);
        return res;
    }
    inline QColor irregularDarkenColor(const QColor &clr, int step=25) {
        int dStep = step / 2;
        int rSrep = 1+dStep / 4;
        QColor res(clr);
        int newHue = (res.hslHue() + SSGX::dx(dStep) -rSrep) % 255;
        int newSat = (res.hslSaturation() + SSGX::dx(dStep) -rSrep) % 255;
        int newLt = (res.lightness() - SSGX::dx(step)) % 255;
        if (newLt < 144)
            newLt = 144 + SSGX::dx(110);
        res.setHsl ( newHue,newSat, newLt);
        return res;
    }

    inline QMap<double, QColor> lightningGradient (int nSteps = 7,int nColorStep = 14,
                                                   const QColor& startColor = randomColor(),
                                                   int randomFactor = -1,
                                                   bool randomAlpha = false)
    {
        QMap<double,QColor> colorMap;
        double dStart = -1.0;
        double dStep = (2.0 / (double)nSteps);
        QColor theColor = startColor;
        if (randomAlpha)
            theColor.setAlpha(32+SSGX::dn(192));
        for (auto h = 0; h < nSteps-1; h++) {
            colorMap.insert(dStart,theColor);
            auto x = SSGX::d100();
            if (x > randomFactor)
                theColor = irregularLightenColor(theColor, nColorStep);
            else {
                theColor.setHsl((theColor.hslHue() + SSGX::dn(50) -25 ) % 255
                                , theColor.hslSaturation(), theColor.lightness());
                int newLt = theColor.lightness();
                if (newLt < 144)
                    newLt = 144 + SSGX::dx(110);
                theColor.setHsl(theColor.hslHue(),theColor.hslSaturation(), newLt);
            }
            if (randomAlpha)
                theColor.setAlpha(32+SSGX::dn(192));
            dStart += dStep;
        }
        colorMap.insert(dStart,theColor);
        return colorMap;
    }

    inline QMap<double, QColor> darkeningGradient (int nSteps = 7,int nColorStep = 14,
                                                   const QColor& startColor = randomColor(),
                                                   int randomFactor = -1,
                                                   bool randomAlpha = false)
    {
        QMap<double,QColor> colorMap;
        double dStart = -1.0;
        double dStep = (2.0 / (double)nSteps);
        QColor theColor = startColor;
        if (randomAlpha)
            theColor.setAlpha(32+SSGX::dn(192));
        for (auto h = 0; h < nSteps-1; h++) {
            colorMap.insert(dStart,theColor);
            auto x = SSGX::d100();
            if (x > randomFactor)
                theColor = irregularLightenColor(theColor, nColorStep);
            else {
                theColor.setHsl((theColor.hslHue() + SSGX::dn(50) -25 ) % 255
                                , theColor.hslSaturation(), theColor.lightness());
                int newLt = theColor.lightness();
                if (newLt < 144)
                    newLt = 144 + SSGX::dx(110);
                theColor.setHsl(theColor.hslHue(),theColor.hslSaturation(), newLt);
            }
            if (randomAlpha)
                theColor.setAlpha(32+SSGX::dn(192));
            dStart += dStep;;
        }
        colorMap.insert(dStart,theColor);
        return colorMap;
    }

    inline QMap<double, QColor> randomGradient (int nSteps = 7, int nColorStep=14,
                                                const QColor& startColor = randomColor())
    {
        if (SSGX::d100() %2 == 0)
            return darkeningGradient(nSteps, nColorStep, startColor);
        else
            return lightningGradient(nSteps, nColorStep, startColor);
    }

}


#endif // QCOLOROPS_H
