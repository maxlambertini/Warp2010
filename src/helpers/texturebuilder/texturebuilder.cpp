#include "texturebuilder.h"


TextureBuilder::TextureBuilder()
{

}

void TextureBuilder::fromJson(const QJsonObject &json) {
    QJsonArray aModules = json["modules"].toArray();
    QJsonArray aHeightMaps = json["heightMaps"].toArray();
    QJsonArray aHMBuilders = json["heightMapsBuilders"].toArray();
    QJsonArray aRenderers = json["renderers"].toArray();
    QJsonArray aImages = json["images"].toArray();

    for (auto h = 0; h < aModules.size(); ++h) {
        ModuleDescriptor *m = new ModuleDescriptor();
        QJsonObject o = aModules[h].toObject();
        m->fromJson(o);
        QString name = m->name();
        QSharedPointer<ModuleDescriptor> p; p.reset(m);
        _modDesc.insert(name,p);
    }

    for (auto h = 0; h < aModules.size(); ++h) {
        NoiseMapBuilderDescriptor *m = new NoiseMapBuilderDescriptor();
        QJsonObject o = aModules[h].toObject();
        m->fromJson(o);
        QString name = m->name();
        QSharedPointer<NoiseMapBuilderDescriptor> p; p.reset(m);
        _nmbDesc.insert(name,p);
    }

    for (auto h = 0; h < aHeightMaps.size(); ++h) {
        HeightMapDescriptor *m = new HeightMapDescriptor();
        QString o = aHeightMaps[h].toString();
        m->setName(o);
        QSharedPointer<HeightMapDescriptor> p; p.reset(m);
        _hmDesc.insert(o,p);
    }

    for (auto h = 0; h < aImages.size(); ++h) {
        ImageDescriptor *m = new ImageDescriptor();
        QString o = aImages[h].toString();
        m->setName(o);
        QSharedPointer<ImageDescriptor> p; p.reset(m);
        __imDesc.insert(o,p);
    }

}

void TextureBuilder::toJson(QJsonObject &json) {

}

void TextureBuilder::createModules() {

}

void TextureBuilder::createImages() {

}

void TextureBuilder::createRenderers() {

}

void TextureBuilder::createHeightMaps() {

}

void TextureBuilder::createHeightMapBuilders() {

}
