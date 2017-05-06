#ifndef DESERT_H
#define DESERT_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Desert : public AbstractMap
    {
    public:
        Desert();
        virtual void generate();
    };
}

#endif // DESERT_H
