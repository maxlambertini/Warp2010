#ifndef NOISEIMAGERUNNER_H
#define NOISEIMAGERUNNER_H

#include <QRunnable>
#include <helpers/noiseimageutils.h>
#include <ssg_structures.h>

namespace noiserunner {
    enum RunType {
        CLOUD,
        EARTHLIKE,
        EARTHLIKE_RMF,
        DESERT,
        COMPLEX_DESERT,
        COMPLEX_DESERT_2,
        JADE_PLANET,
        GAS_GIANT,
        HOTHOUSE
    };
}

class NoiseImageRunner : public QRunnable
{
    int    _seed;
    int    _octave;
    double _persistence;
    double _lacunarity;
    double _frequency;
public:
    NoiseImageRunner();

    //interface
    void run();

};

#endif // NOISEIMAGERUNNER_H
