#ifndef RENDERERDESCRIPTOR_H
#define RENDERERDESCRIPTOR_H

#include <QObject>

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>

using namespace utils;

//position, r, g, b, a
typedef std::tuple<double,int,int,int,int> GradientInfo;

class RendererDescriptor
{
    QString _name = "renderer1";
    QString _noiseMap = "heightmap1";
    QString _backgroundImage = "";
    QString _destImage = "";
    bool _enabledLight = false;
    bool _lightContrast = 1.0;
    bool _lightBrightness = 1.0;


    QVector<GradientInfo> _gradientInfo;
    QMap<QString, QSharedPointer<utils::NoiseMap>> _noiseMaps;
    QMap<QString, QSharedPointer<utils::Image>> _images;

public:
    RendererDescriptor();

    QString& name() { return _name; }
    QString& destImage() { return _destImage; }
    QString& backgroundImage() { return _backgroundImage; }
    QString& noiseMap() { return _noiseMap; }
    bool enabledLight() { return _enabledLight; }
    bool lightContrast() { return _lightContrast; }
    bool lightBrightness() { return _lightBrightness; }

    const QMap<QString, QSharedPointer<utils::NoiseMap>>& noiseMaps() { return _noiseMaps; }
    const QMap<QString, QSharedPointer<utils::Image>>& images() { return _images; }

    void setName(const QString& v) { _name = v ; }
    void setDestImage(const QString& v) { _destImage = v ; }
    void setBackgroundImage(const QString& v) { _backgroundImage = v ; }
    void setNoisemap(const QString& v) { _noiseMap = v ; }
    void setEnabledlight(bool v) { _enabledLight = v ; }
    void setLightcontrast(bool v) { _lightContrast = v ; }
    void setLightbrightness(bool v) { _lightBrightness = v ; }
    void setNoisemap(const QMap<QString, QSharedPointer<utils::NoiseMap>>& v) { _noiseMaps = v; }
    void setImages(const QMap<QString, QSharedPointer<utils::Image>>& v) { _images = v; }

    QSharedPointer<utils::RendererImage> makeRenderer();

    void toJson(QJsonObject& json);
    void fromJson(const QJsonObject& json);
};

#endif // RENDERERDESCRIPTOR_H
