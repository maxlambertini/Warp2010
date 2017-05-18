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
        m->setModules(_modules);
        QSharedPointer<ModuleDescriptor> p; p.reset(m);
        _modDesc.insert(name,p);
    }

    for (auto h = 0; h < aRenderers.size(); ++h) {
        RendererDescriptor *m = new RendererDescriptor();
        QJsonObject o = aRenderers[h].toObject();
        m->fromJson(o);
        QString name = m->name();

        m->setImages(_images);
        m->setNoiseMaps(_heightMaps);
        m->setRenderers(_renderers);

        QSharedPointer<RendererDescriptor> p; p.reset(m);
        _rndDesc.insert(name,p);
    }

    for (auto h = 0; h < aHMBuilders.size(); ++h) {
        NoiseMapBuilderDescriptor *m = new NoiseMapBuilderDescriptor();
        QJsonObject o = aHMBuilders[h].toObject();

        m->fromJson(o);
        m->setModules(_modules);

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
    QSharedPointer<ModuleDescriptor> mod;
    foreach (mod,_modDesc) {
        mod.data()->setModules(_modules);
        auto ptr = mod.data()->makeModule();
        _modules.insert(mod.data()->name(), ptr);
    }
}

void TextureBuilder::createImages() {
    QSharedPointer<ImageDescriptor> img;
    foreach (img,__imDesc) {
        auto ptr = img.data()->makeImage();
        _images.insert(img.data()->name(), ptr);
    }
}

void TextureBuilder::createRenderers() {
    QSharedPointer<RendererDescriptor> hmd;
    foreach (hmd,_rndDesc) {
        hmd.data()->setImages(_images);
        hmd.data()->setNoiseMaps(_heightMaps);
        auto ptr = hmd.data()->makeRenderer();
        _renderers.insert(hmd.data()->name(), ptr);
    }
}

void TextureBuilder::createHeightMaps() {
    QSharedPointer<HeightMapDescriptor> hmd;
    foreach (hmd,_hmDesc) {
        auto ptr = hmd.data()->makeNoiseMap();
        _heightMaps.insert(hmd.data()->name(), ptr);
    }

}

void TextureBuilder::createNoiseMapBuilders() {
    QSharedPointer<NoiseMapBuilderDescriptor> hmd;
    foreach (hmd,_nmbDesc) {
        hmd.data()->setModules(_modules);
        auto ptr = hmd.data()->makeBuilder();
        _noiseMapBuilders.insert(hmd.data()->name(), ptr);
    }

}

void TextureBuilder::connectModules()
{
    QMapIterator<QString,QSharedPointer<ModuleDescriptor>> iter(_modDesc);
    while (iter.hasNext())
    {
        auto m = iter.next();
        m.value().data()->connectModules();
    }
}

void TextureBuilder::connectNoiseMapBuilders() {
    QMapIterator<QString,QSharedPointer<NoiseMapBuilderDescriptor>> iter(_nmbDesc);
    while (iter.hasNext())
    {
        auto m = iter.next();
        m.value().data()->connectSrcModule();
    }
}

void TextureBuilder::connectRenderers() {
    QMapIterator<QString,QSharedPointer<RendererDescriptor>> iter(_rndDesc);
    while (iter.hasNext())
    {
        auto m = iter.next();
        auto ptr = m.value().data();
        ptr->connectImagesAndMap();
    }

}
