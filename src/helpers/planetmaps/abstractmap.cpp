#include "abstractmap.h"

using namespace maps;


AbstractMap::AbstractMap()
{
    //sensible defaults
    _seed = 1;
    _octave = 5;
    _lacunarity = 2.50;
    _frequency = 2.0;
    _persistence = 0.43;
}
