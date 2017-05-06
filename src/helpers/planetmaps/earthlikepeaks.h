#ifndef EARTHLIKEPEAKS_H
#define EARTHLIKEPEAKS_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
class EarthlikePeaks : public AbstractMap
{
    Q_OBJECT
public:
    EarthlikePeaks();
    virtual void generate();
};

}
#endif // EARTHLIKEPEAKS_H
