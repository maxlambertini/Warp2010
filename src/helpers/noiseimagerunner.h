#ifndef NOISEIMAGERUNNER_H
#define NOISEIMAGERUNNER_H

#include <QRunnable>
#include <helpers/noiseimageutils.h>
#include <ssg_structures.h>
#include <QString>
#include <QThread>

namespace RT {
enum RType {
    GG2,
    GG ,
    Cloudy,
    Earthlike,
    Earthlike2,
    Earthlike3 ,
    Pregarden,
    Postgarden,
    Clouds,
    FunkyClouds,
    Desert,
    DesertG,
    ComplexDesert,
    ComplexDesert2,
    Jade,
    Jade2,
    Granite,
    Ice
};
}

using namespace RT;

class NoiseImageRunner : public QObject
{
    Q_OBJECT
    int    _seed;
    int    _octave;
    double _persistence;
    double _lacunarity;
    double _frequency;
    RType _runType = Earthlike;
    QString _filename = "";
    NoiseImageUtils imgUtils;
public:    
    void setSeed (int v) {_seed = v; }
    int  seed() { return _seed; }
    void setOctave (int v) {_octave = v; }
    int  octave() { return _octave; }
    void setPersistence(double v)  { _persistence = v; }
    double persistence() { return _persistence; }
    void setLacunarity(double v) { _lacunarity = v; }
    double lacunarity() { return _lacunarity; }
    void setFrequency(double v) {_frequency = v; }
    double frequency() { return _frequency; }
    void setFilename(const QString& str) { _filename = str; }
    const QString& filename() { return _filename; }
    void setRunType(RType str) { _runType = str; }
    const RType runType() { return _runType; }
    NoiseImageRunner();

    NoiseImageRunner(RType runType, const QString& filename, int seed) : _runType(runType), _filename(filename), _seed(seed) {}
    NoiseImageRunner(RType runType, const QString& filename, int seed, int octave) : _runType(runType),_filename(filename),_seed(seed), _octave(octave) {}
    NoiseImageRunner(RType runType, const QString& filename, int seed, int octave, double pers) :
        _runType(runType),_filename(filename),
        _seed(seed), _octave(octave),
        _persistence(pers){}
    NoiseImageRunner(RType runType, const QString& filename, int seed, int octave, double pers, double lac) :
        _runType(runType),_filename(filename),
        _seed(seed), _octave(octave),
        _persistence(pers),_lacunarity(lac){}
    NoiseImageRunner(RType runType, const QString& filename, int seed, int octave, double pers, double lac, double freq) :
        _runType(runType),_filename(filename),
        _seed(seed), _octave(octave),
        _persistence(pers),_lacunarity(lac), _frequency(freq){}

    void run()   {
        switch (_runType) {
            case GG2:
                //imgUtils.CreateGG2Planet(_seed);
                imgUtils.CreateGGPlayground(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Cloudy:
                imgUtils.CreateCloudyPlanet(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Earthlike:
                imgUtils.CreateEarthlike(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Earthlike2:
                imgUtils.CreateEarthlike2(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Earthlike3:
                imgUtils.CreateEarthlike3(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Pregarden:
                imgUtils.CreatePregarden(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Postgarden:
                imgUtils.CreatePostgarden(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Clouds:
                imgUtils.CreateEarthClouds(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case FunkyClouds:
                imgUtils.CreateFunkyClouds(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Desert:
                imgUtils.CreateDesert(_seed,
                                         _octave,
                                         _lacunarity,
                                         _frequency,
                                         _persistence,
                                         imgUtils.QColorToColor(ColorOps::randomColor()),
                                         imgUtils.QColorToColor(ColorOps::randomColor()),
                                         imgUtils.QColorToColor(ColorOps::randomColor()));
                imgUtils.SaveImage(_filename);
            break;
            case DesertG:
                imgUtils.CreateDesertG(_seed,
                                         _octave,
                                         _lacunarity,
                                         _frequency,
                                         _persistence);
                imgUtils.SaveImage(_filename);
            break;
            case ComplexDesert:
                imgUtils.CreateComplexDesert(_seed,
                                         _octave,
                                         _lacunarity,
                                         _frequency,
                                         _persistence);
                imgUtils.SaveImage(_filename);
            break;
            case ComplexDesert2:
                imgUtils.CreateComplexDesert2(_seed,
                                         _octave,
                                         _lacunarity,
                                         _frequency,
                                         _persistence);
                imgUtils.SaveImage(_filename);
            break;
            case GG:
                //imgUtils.CreateGGPlanet(_seed);
                imgUtils.CreateGGPlayground(_seed);
                imgUtils.SaveImage(_filename);
            break;
            case Jade:
                imgUtils.CreateJadePlanet(_seed, ColorOps::randomColor());
                imgUtils.SaveImage(_filename);
            break;
            case Jade2:
                imgUtils.CreateJade2Planet(_seed, ColorOps::randomColor());
                imgUtils.SaveImage(_filename);
            break;
            case Granite:
                imgUtils.CreateGranitePlanet(_seed, ColorOps::randomColor());
                imgUtils.SaveImage(_filename);
            break;
            case Ice:
                imgUtils.CreateIcePlanet(_seed);
                imgUtils.SaveImage(_filename);
            break;
            default:
                imgUtils.CreateEarthlike(_seed);
                imgUtils.SaveImage(_filename);
            break;
        }
        emit imageSaved(_filename);
    }

signals:
    void imageSaved(QString f);

};

#endif // NOISEIMAGERUNNER_H
