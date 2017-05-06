#ifndef CLOUDY_H
#define CLOUDY_H

#include <helpers/planetmaps/maps.h>

namespace maps {
    class Cloudy : public AbstractMap
    {
        Q_OBJECT
    public:
        Cloudy();
        void generate();
    };
}

#endif // CLOUDY_H
