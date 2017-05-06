#ifndef DESERTG_H
#define DESERTG_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {

class DesertG : public AbstractMap
{
    Q_OBJECT
public:
    DesertG();
    virtual void generate();
};

}

#endif // DESERTG_H
