#ifndef GRANITE_H
#define GRANITE_H


#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Granite : public AbstractMap
    {
        Q_OBJECT
    public:
        Granite();
        void generate();
    };
}

#endif // GRANITE_H
