#ifndef JADE_H
#define JADE_H


#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Jade : public AbstractMap
    {
        Q_OBJECT
    public:
        Jade();
        void generate();
    };
}

#endif // JADE_H
