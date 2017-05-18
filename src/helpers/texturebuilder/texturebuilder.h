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

typedef QVector<QSharedPointer<utils::RendererImage>> ListRenderers;

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

    ListRenderers _lstRenderers;
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
        connectNoiseMapBuilders();
        connectRenderers();
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
};

#endif // TEXTUREBUILDER_H
