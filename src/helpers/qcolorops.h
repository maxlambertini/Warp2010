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
        res.setHsl ( (res.hslHue() + SSGX::dx(dStep) -rSrep) % 255,
                     (res.hslSaturation() + SSGX::dx(dStep) -rSrep) % 255,
                     (res.lightness() + SSGX::dx(step)) % 255);
        return res;
    }
    inline QColor irregularDarkenColor(const QColor &clr, int step=25) {
        int dStep = step / 2;
        int rSrep = 1+dStep / 4;
        QColor res(clr);
        res.setHsl ( (res.hslHue() + SSGX::dx(dStep) -rSrep) % 255,
                     (res.hslSaturation() + SSGX::dx(dStep) -rSrep) % 255,
                     (res.lightness() - SSGX::dx(step)) % 255);
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
            else
                theColor.setHsl((theColor.hslHue() + SSGX::dn(50) -25 ) % 255
                                , theColor.hslSaturation(), theColor.lightness());
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
            else
                theColor.setHsl((theColor.hslHue() + SSGX::dn(50) -25 ) % 255
                                , theColor.hslSaturation(), theColor.lightness());
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
