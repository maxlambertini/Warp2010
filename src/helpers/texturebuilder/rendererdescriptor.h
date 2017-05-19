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
    double _lightContrast = 1.0;
    double _lightBrightness = 1.0;


    QVector<GradientInfo> _gradientInfo;
    QMap<QString, QSharedPointer<utils::NoiseMap>> _noiseMaps;
    QMap<QString, QSharedPointer<utils::Image>> _images;
    QMap<QString, QSharedPointer<utils::RendererImage>> _renderers;

public:
    RendererDescriptor();

    QString& name() { return _name; }
    QString& destImage() { return _destImage; }
    QString& backgroundImage() { return _backgroundImage; }
    QString& noiseMap() { return _noiseMap; }
    bool enabledLight() { return _enabledLight; }
    double lightContrast() { return _lightContrast; }
    double lightBrightness() { return _lightBrightness; }

    const QMap<QString, QSharedPointer<utils::NoiseMap>>& noiseMaps() { return _noiseMaps; }
    const QMap<QString, QSharedPointer<utils::Image>>& images() { return _images; }
    const QMap<QString, QSharedPointer<utils::RendererImage>>& renderers() { return _renderers; }

    void setName(const QString& v) { _name = v ; }
    void setDestImage(const QString& v) { _destImage = v ; }
    void setBackgroundImage(const QString& v) { _backgroundImage = v ; }
    void setNoisemap(const QString& v) { _noiseMap = v ; }
    void setEnabledlight(bool v) { _enabledLight = v ; }
    void setLightcontrast(double v) { _lightContrast = v ; }
    void setLightbrightness(double v) { _lightBrightness = v ; }

    void setNoiseMaps(const QMap<QString, QSharedPointer<utils::NoiseMap>>& v) { _noiseMaps = v; }
    void setImages(const QMap<QString, QSharedPointer<utils::Image>>& v) { _images = v; }
    void setRenderers(const QMap<QString, QSharedPointer<utils::RendererImage>>& v) { _renderers = v; }

    QSharedPointer<utils::RendererImage> makeRenderer();

    RendererDescriptor& connectImagesAndMap();

    void toJson(QJsonObject& json);
    void fromJson(const QJsonObject& json);
};

#endif // RENDERERDESCRIPTOR_H
