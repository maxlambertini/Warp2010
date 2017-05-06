#ifndef EARTHLIKE_H
#define EARTHLIKE_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class Earthlike : public AbstractMap
    {
        Q_OBJECT
    public:
        Earthlike();
        virtual void generate();
    };
}



#endif // EARTHLIKE_H
