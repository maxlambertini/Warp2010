#ifndef JADE2_H
#define JADE2_H


#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Jade2 : public AbstractMap
    {
        Q_OBJECT
    public:
        Jade2();
        void generate();
    };
}

#endif // JADE2_H
