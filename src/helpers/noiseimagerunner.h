#ifndef NOISEIMAGERUNNER_H
#define NOISEIMAGERUNNER_H

#include <QRunnable>
#include <helpers/noiseimageutils.h>
#include <ssg_structures.h>
#include <QString>
#include <QThread>
#include <helpers/planetmaps/maps.h>

namespace RT {
enum RType {
    GG2,
    GG ,
    Cloudy,
    Earthlike,
    Earthlike2,
    Earthlike3 ,
    Glacier,
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

    double _seaRatio = 0.0;
    double _iceRatio = 0.125;


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
    double iceRatio() { return _iceRatio; }
    void setIceRatio (double v) { _iceRatio = v; }
    double seaRatio() { return _seaRatio; }
    void setSeaRatio (double v) { _seaRatio = v; }


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

    void run()  ;

signals:
    void imageSaved(QString f);

};

#endif // NOISEIMAGERUNNER_H
