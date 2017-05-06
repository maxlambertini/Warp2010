#ifndef ALIENPEAKS_H
#define ALIENPEAKS_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class AlienPeaks : public AbstractMap
    {
        Q_OBJECT
    public:
        AlienPeaks();
        virtual void generate();
    };
}

#endif // ALIENPEAKS_H
