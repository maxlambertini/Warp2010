#ifndef GG2_H
#define GG2_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class GG2 : public AbstractMap
    {
        Q_OBJECT
    public:
        GG2();
        void generate();
    };
}

#endif // GG2_H
