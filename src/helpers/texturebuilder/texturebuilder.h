#ifndef TEXTUREBUILDER_H
#define TEXTUREBUILDER_H

#include <helpers/texturebuilder/heightmapdescriptor.h>
#include <helpers/texturebuilder/imagedescriptor.h>
#include <helpers/texturebuilder/moduledescriptor.h>
#include <helpers/texturebuilder/noisemapbuilderdescriptor.h>
#include <helpers/texturebuilder/rendererdescriptor.h>

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


class TextureBuilder
{
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
public:
    TextureBuilder();

    void fromJson(const QJsonObject& json);
    void toJson(QJsonObject& json);

    // these routines create libnoise's objects and store them into
    // appropriate maps, to be referenced where needed.
    void createModules();
    void createHeightMaps();
    void createHeightMapBuilders();
    void createRenderers();
    void createImages();

};

#endif // TEXTUREBUILDER_H
