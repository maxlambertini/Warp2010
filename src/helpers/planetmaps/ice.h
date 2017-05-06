#ifndef ICE_H
#define ICE_H


#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Ice : public AbstractMap
    {
        Q_OBJECT
    public:
        Ice();
        void generate();
    };
}

#endif // ICE_H
