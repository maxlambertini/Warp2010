#ifndef EARTHCLOUDS_H
#define EARTHCLOUDS_H

#include <helpers/planetmaps/abstractmap.h>

namespace maps {

class EarthClouds : public AbstractMap
{
public:
    EarthClouds();
    void generate();
};

}
#endif // EARTHCLOUDS_H
