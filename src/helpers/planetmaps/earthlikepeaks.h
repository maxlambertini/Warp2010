#ifndef EARTHLIKEPEAKS_H
#define EARTHLIKEPEAKS_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {

static maps::GradientItem preGardenSteps[7] = {
    {-1.0000, 29, 94,128,255},
    {-0.2500, 35, 115, 141, 255},
    { 0.0000,232, 164, 123, 255},
    { 0.0625,171, 193,  85, 255},
    { 0.1250, 153, 160,   0, 255},
    { 0.3750, 93, 122, 149, 255},
    { 0.7500, 69,  65,  26, 255}
};

static maps::GradientItem postGardenSteps[7] = {
    {-1.0000, 19, 74,98,255},
    {-0.2500, 25, 95, 111, 255},
    { 0.0000,182, 124, 93, 255},
    { 0.0625,151, 143,  65, 255},
    { 0.1250, 123, 120,   0, 255},
    { 0.3750, 63, 102, 119, 255},
    { 0.7500, 49,  45,  16, 255}
};

enum GardenType {
    GARDEN,
    GLACIER,
    POSTGARDEN,
    PREGARDEN
};

class EarthlikePeaks : public AbstractMap
{
    Q_OBJECT
    double _seaRatio = 0.0;
    double _iceRatio = 0.125;

    GardenType _gardenType;

public:

    double iceRatio() { return _iceRatio; }
    void setIceRatio (double v) { _iceRatio = v; }
    double seaRatio() { return _seaRatio; }
    void setSeaRatio (double v) { _seaRatio = v; }

    GardenType gardenType() { return _gardenType;  }
    void setGardenType(GardenType v) { _gardenType = v; }

    void setupGlacier() {_iceRatio = 0.88; _gardenType = GLACIER; }
    void setupPostGarden() { _gardenType = POSTGARDEN; }
    void setupPreGarden() { _gardenType = PREGARDEN; }

    EarthlikePeaks();
    virtual void generate();


};

}
#endif // EARTHLIKEPEAKS_H
