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
    noiserunner::RunType _runType = noiserunner::RunType::EARTHLIKE;
    //constructors
    static NoiseImageRunner CreateEarthlike(
            int    __seed = SSGX::dn(20000),
            int    __octave = 6,
            double __persistence = 0.29,
            double __lacunarity  = 2.98,
            double __frequency   = 3.31
            ) {
        NoiseImageRunner nir;
        nir._seed = __seed;
        nir._octave = __octave;
        nir._frequency = __frequency;
        nir._lacunarity = __lacunarity;
        nir._persistence = __persistence;
        return nir;
    }

    void setSeed (int v) {_seed = v; }
    int  seed() { return _seed; }

protected:
    NoiseImageRunner();
    //interface
    void run();

};

#endif // NOISEIMAGERUNNER_H
