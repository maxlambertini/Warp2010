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


#ifndef TEXTUREBUILDER_H
#define TEXTUREBUILDER_H

#include <libnoise-helpers_global.h>
#include <texturebuilder/heightmapdescriptor.h>
#include <texturebuilder/imagedescriptor.h>
#include <texturebuilder/moduledescriptor.h>
#include <texturebuilder/noisemapbuilderdescriptor.h>
#include <texturebuilder/rendererdescriptor.h>
#include "ssg_structures.h"

typedef QMap<QString, QSharedPointer<HeightMapDescriptor>> MapHeightMapDescriptors;
typedef QMap<QString, QSharedPointer<ImageDescriptor>> MapImageDescriptors;
typedef QMap<QString, QSharedPointer<ModuleDescriptor>> MapModuleDescriptors;
typedef QMap<QString, QSharedPointer<NoiseMapBuilderDescriptor>> MapNoiseMapBuilderDescriptors;
typedef QMap<QString, QSharedPointer<RendererDescriptor>> MapRendererDescriptors;

typedef QMap<QString, QSharedPointer<utils::NoiseMap>> MapHeightMaps;
typedef QMap<QString, QSharedPointer<utils::Image>> MapImages;
typedef QMap<QString, QSharedPointer<noise::module::Module>> MapModules;
typedef QMap<QString, QSharedPointer<utils::NoiseMapBuilder>> MapNoiseMapBuilders;
typedef QMap<QString, QSharedPointer<utils::RendererImage>> MapRenderers;

typedef QVector<QSharedPointer<utils::RendererImage>> ListRenderers;

typedef QVector<double> RandomFactors;

class LIBNOISEHELPERSSHARED_EXPORT TextureBuilder : public QObject
{
    Q_OBJECT

    MapHeightMapDescriptors _hmDesc;
    MapImageDescriptors __imDesc;
    MapModuleDescriptors _modDesc;
    MapNoiseMapBuilderDescriptors _nmbDesc;
    MapRendererDescriptors _rndDesc;

    MapHeightMaps  _heightMaps;
    MapImages _images;
    MapModules _modules;
    MapNoiseMapBuilders _noiseMapBuilders;
    MapRenderers _renderers;

    ListRenderers _lstRenderers;

    QVector<QString> _generatedMaps;

    QString _cloudMap;
    QString _colorMap;
    QString _bumpMap;
    QString _reflectionMap;
    RandomFactors _randomFactors;

    QString _outputFolder;

public:
    TextureBuilder();

    inline const QString& cloudMap() { return _cloudMap; }
    inline const QString& colorMap() { return _colorMap; }
    inline const QString& reflectionMap() { return _reflectionMap; }
    inline const QString& bumpMap() { return _bumpMap; }
    inline const RandomFactors& randomFactors() { return _randomFactors; }
    inline bool useRandomFactors() {
       return _randomFactors.count() > 0 && _randomFactors.first() > 0.0;
    }
    inline double pickRandomFactor() {
        return useRandomFactors() ?
                    _randomFactors[SSGX::dx(_randomFactors.count())] : 0.0;
    }

    double variateDouble(double origin, double rndFactor) {
        double d1 = SSGX::floatRand() * (2*rndFactor) - rndFactor;
        return origin + d1;
    }


    inline double applyRandomFactor (double v) { return useRandomFactors() ? variateDouble(v, pickRandomFactor()) : v; }

    inline const QString& outputFolder() { return _outputFolder; }
    inline void setOutputFolder(const QString& f) { _outputFolder = f; }

    void fromJson(const QJsonObject& json);
    void toJson(QJsonObject& json);

    // these routines create libnoise's objects and store them into
    // appropriate maps, to be referenced where needed.

    void createModules();
    void createHeightMaps();
    void createNoiseMapBuilders();
    void createRenderers();
    void createImages();

    const MapNoiseMapBuilders& noiseMapBuilders() { return _noiseMapBuilders; }
    const MapHeightMaps& heightMaps() { return _heightMaps; }
    const MapImages& images() { return _images; }
    const MapRenderers& renderers() { return _renderers; }
    const MapModules& modules() { return _modules; }

    MapHeightMapDescriptors& hmDesc() { return _hmDesc; }
    MapImageDescriptors& imDesc() { return __imDesc;}
    MapModuleDescriptors& modDesc() { return _modDesc;  }
    MapNoiseMapBuilderDescriptors& nmbDesc() { return _nmbDesc; }
    MapRendererDescriptors& rndDesc() { return _rndDesc; }

    void createAll() {
        qDebug() << "Creating modules";
        createModules();
        qDebug() << "Creating height maps";
        createHeightMaps();
        qDebug() << "Creating map builders";
        createNoiseMapBuilders();
        qDebug() << "Creating images";
        createImages();
        qDebug() << "Creating renderers";
        createRenderers();
    }

    void connectModules();
    void connectRenderers();
    void connectNoiseMapBuilders();

    void connectAll() {
        connectModules();
        connectRenderers();
        connectNoiseMapBuilders();
        qDebug() << "Build noisemaps";
        buildNoiseMaps();
    }

    void buildNoiseMaps();
    void renderRenderers();

    QSharedPointer<utils::Image> buildImages() {
        renderRenderers();
        return _images.first();
    }


    void buildTextureFromJson(const QString& filename, QString path="");

    const QVector<QString>& generatedMaps() {
        return _generatedMaps;
    }

    void prepareObjectFromJsonFile (const QString& filename);
    void prepareObjectFromJsonString(const QString& jsonData);
    void saveRenderedImageToFile (const QString& imageName, const QString& destFileName);

    bool hasColorMap() { return _colorMap != ""; }
    bool hasBumpMap() { return _bumpMap != ""; }
    bool hasCloudMap() { return _cloudMap != ""; }
    bool hasReflectionMap() { return _reflectionMap != ""; }

signals:
    void textureGenerationStarting();
    void textureGenerated(QString texture);
    void allTextureGenerated();
    void noTextureGenerated();
    void builderReady();
};

#endif // TEXTUREBUILDER_H
