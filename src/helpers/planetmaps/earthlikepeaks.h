#ifndef EARTHLIKEPEAKS_H
#define EARTHLIKEPEAKS_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
class EarthlikePeaks : public AbstractMap
{
    Q_OBJECT
    double _seaRatio = 0.0;
    double _iceRatio = 0.125;
public:

    double iceRatio() { return _iceRatio; }
    void setIceRatio (double v) { _iceRatio = v; }
    double seaRatio() { return _seaRatio; }
    void setSeaRatio (double v) { _seaRatio = v; }

    EarthlikePeaks();
    virtual void generate();
};

}
#endif // EARTHLIKEPEAKS_H
