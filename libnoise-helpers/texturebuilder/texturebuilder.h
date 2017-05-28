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
public:
    TextureBuilder();

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

    void buildTextureFromJson(const QString& filename);

    const QVector<QString>& generatedMaps() {
        return _generatedMaps;
    }
};

#endif // TEXTUREBUILDER_H
