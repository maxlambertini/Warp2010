#include "texturebuilder.h"
#include <QFile>
#include <QImage>
#include <memory>

TextureBuilder::TextureBuilder()
{

}

void TextureBuilder::fromJson(const QJsonObject &json) {
    QJsonArray aModules = json["modules"].toArray();
    QJsonArray aHeightMaps = json["heightMaps"].toArray();
    QJsonArray aHMBuilders = json["heightMapBuilders"].toArray();
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

    createAll();
    connectAll();
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
    QMapIterator<QString, QSharedPointer<RendererDescriptor>>  it(_rndDesc);
    while (it.hasNext()) {
        hmd = it.next().value();
        hmd.data()->setImages(_images);
        hmd.data()->setNoiseMaps(_heightMaps);
        QSharedPointer<utils::RendererImage> ptr
                = hmd.data()->makeRenderer();
        _renderers.insert(hmd.data()->name(), ptr);
        _lstRenderers.append(ptr);
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
        m.value().data()->setModules(_modules);
        m.value().data()->connectSrcModule();
    }
}

void TextureBuilder::connectRenderers() {
    QMapIterator<QString,QSharedPointer<RendererDescriptor>> iter(_rndDesc);
    while (iter.hasNext())
    {
        auto m = iter.next();
        auto ptr = m.value().data();
        ptr->setRenderers(_renderers);
        ptr->connectImagesAndMap();
    }

}


void TextureBuilder::buildNoiseMaps()
{
    QMapIterator<QString,QSharedPointer<utils::NoiseMapBuilder>> iter(_noiseMapBuilders);
    while(iter.hasNext()) {
        auto ptr = iter.next().value().data();
        ptr->Build();
    }

}

void TextureBuilder::renderRenderers()
{
    QSharedPointer<utils::RendererImage> r;
    foreach (r,_lstRenderers) {
        r.data()->Render();
    }
}

void TextureBuilder::buildTextureFromJson(const QString &filename) {
    QFile data (filename);
     if (data.open(QFile::ReadOnly | QFile::Text)) {
         QByteArray json = data.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(json);
        auto oStuff = doc.object();

        qDebug() << "Loading raw json data";
        //load raw data
        this->fromJson(oStuff);

        qDebug() << "Creating libnoise stuff";
        this->createAll();

        qDebug() << "Connecting modules and stuff";
        this->connectAll();

        qDebug() << "Building images...";
        QSharedPointer<utils::Image> imgPtr = this->buildImages();

        QString imgFile = filename+".png";
        qDebug() << "Saving image...";
        utils::WriterBMP writer;
        writer.SetSourceImage (*imgPtr.data());
        std::unique_ptr<noise::uint8[]> buff(writer.GetBRGABuffer());
        auto sizeX = _nmbDesc.first().data()->getSizeX();
        auto sizeY = _nmbDesc.first().data()->getSizeY();
        QImage img((uchar *)buff.get() ,sizeX, sizeY,sizeX*4,QImage::Format_ARGB32);
        img.save(imgFile,"PNG");


     }
     data.close();

}
