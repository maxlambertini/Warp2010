#ifndef EARTHLIKE2_H
#define EARTHLIKE2_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Earthlike2 : public AbstractMap
    {
    public:
        Earthlike2();
        virtual void generate();
    };
}

#endif // EARTHLIKE2_H
