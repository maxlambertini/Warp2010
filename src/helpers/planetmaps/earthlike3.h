#ifndef EARTHLIKE3_H
#define EARTHLIKE3_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Earthlike3 : public AbstractMap
    {
        Q_OBJECT
    public:
        Earthlike3();
        virtual void generate();
    };
}
#endif // EARTHLIKE3_H
