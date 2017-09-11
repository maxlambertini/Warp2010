/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#ifndef RENDERERDESCRIPTOR_H
#define RENDERERDESCRIPTOR_H

#include <QObject>

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>
#include "libnoise-helpers_global.h"

using namespace utils;

//position, r, g, b, a
typedef std::tuple<double,int,int,int,int> GradientInfo;
typedef std::tuple<int, utils::Color> RandomGradientRow;


class LIBNOISEHELPERSSHARED_EXPORT RendererDescriptor : public QObject
{
    Q_OBJECT

    QString _name = "renderer0001";
    QString _heightMap = "heightmap1";
    QString _backgroundImage = "";
    QString _alphaImage = "";
    QString _destImage = "";
    bool _enabledLight = false;
    double _lightContrast = 1.0;
    double _lightBrightness = 1.0;
    bool _randomGradient = false;

    int _rndHue        = 0;
    int _rndSaturation = 0;
    int _rndValue      = 0;
    bool applyRandomFactor() { return _rndHue != 0 || _rndSaturation != 0 || _rndValue != 0; }


    QVector<GradientInfo> _gradientInfo;
    QMap<QString, QSharedPointer<utils::NoiseMap>> _noiseMaps;
    QMap<QString, QSharedPointer<utils::Image>> _images;
    QMap<QString, QSharedPointer<utils::RendererImage>> _renderers;

public:
    RendererDescriptor();

    QString& name() { return _name; }
    QString& destImage() { return _destImage; }
    QString& backgroundImage() { return _backgroundImage; }
    QString& alphaImage() { return _alphaImage; }
    QString& heightMap() { return _heightMap; }
    bool enabledLight() { return _enabledLight; }
    double lightContrast() { return _lightContrast; }
    double lightBrightness() { return _lightBrightness; }
    bool randomGradient() { return _randomGradient; }
    int rndHue() { return _rndHue; }
    int rndSaturation() { return _rndSaturation; }
    int rndValue() { return _rndValue; }
    void setRandomFactor (int h, int s, int v )  { _rndHue = h; _rndSaturation = s; _rndValue = v; }


    const QMap<QString, QSharedPointer<utils::NoiseMap>>& noiseMaps() { return _noiseMaps; }
    const QMap<QString, QSharedPointer<utils::Image>>& images() { return _images; }
    const QMap<QString, QSharedPointer<utils::RendererImage>>& renderers() { return _renderers; }

    void setName(const QString& v) { _name = v ; }
    void setDestImage(const QString& v) { _destImage = v ; }
    void setBackgroundImage(const QString& v) { _backgroundImage = v ; }
    void setAlphaImage(const QString& v) { _alphaImage = v ; }
    void setHeightmap(const QString& v) { _heightMap = v ; }
    void setEnabledlight(bool v) { _enabledLight = v ; }
    void setLightcontrast(double v) { _lightContrast = v ; }
    void setLightbrightness(double v) { _lightBrightness = v ; }
    void setRandomGradient (bool b ) { _randomGradient = b; }

    void setNoiseMaps(const QMap<QString, QSharedPointer<utils::NoiseMap>>& v) { _noiseMaps = v; }
    void setImages(const QMap<QString, QSharedPointer<utils::Image>>& v) { _images = v; }
    void setRenderers(const QMap<QString, QSharedPointer<utils::RendererImage>>& v) { _renderers = v; }

    QSharedPointer<utils::RendererImage> makeRenderer();

    RendererDescriptor& connectImagesAndMap();

    void toJson(QJsonObject& json);
    void fromJson(const QJsonObject& json);

    QVector<GradientInfo>& gradientInfo() { return _gradientInfo; }
    void readGradientInfo(const QJsonObject& json);
    void randomizeGradientInfo();
};

#endif // RENDERERDESCRIPTOR_H
