#ifndef TEXTUREBUILDER_H
#define TEXTUREBUILDER_H

#include <helpers/texturebuilder/heightmapdescriptor.h>
#include <helpers/texturebuilder/imagedescriptor.h>
#include <helpers/texturebuilder/moduledescriptor.h>
#include <helpers/texturebuilder/noisemapbuilderdescriptor.h>
#include <helpers/texturebuilder/rendererdescriptor.h>

typedef QMap<QString, HeightMapDescriptor> MapHeightMapDescriptors;
typedef QMap<QString, ImageDescriptor> MapImageDescriptors;
typedef QMap<QString, ModuleDescriptor> MapModuleDescriptors;
typedef QMap<QString, NoiseMapBuilderDescriptor> MapNoiseMapBuilderDescriptors;
typedef QMap<QString, RendererDescriptor> MapRendererDescriptors;

typedef QMap<QString, QSharedPointer<utils::NoiseMap>> MapHeightMaps;
typedef QMap<QString, QSharedPointer<utils::Image>> MapImages;
typedef QMap<QString, QSharedPointer<noise::module::Module>> MapModules;
typedef QMap<QString, QSharedPointer<utils::NoiseMapBuilder>> MapNoiseMapBuilders;
typedef QMap<QString, QSharedPointer<utils::RendererImage>> MapRenderers;


class TextureBuilder
{
    MapHeightMapDescriptors _heightMapDescriptors;
    MapImageDescriptors _imageDescriptors;
    MapModuleDescriptors _moduleDescriptors;
    MapNoiseMapBuilderDescriptors _noiseMapBuilderDescriptors;
    MapRendererDescriptors _rendererDescriptors;

    MapHeightMaps  _heightMaps;
    MapImages _images;
    MapModules _modules;
    MapNoiseMapBuilders _noiseMapBuilders;
    MapRenderers _renderers;
public:
    TextureBuilder();
};

#endif // TEXTUREBUILDER_H
