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

#include "texturebuilder.h"
#include <QFile>
#include <QImage>
#include <memory>
#include <QMessageBox>
#include <QString>

TextureBuilder::TextureBuilder() :
    _outputFolder("."),
    _bumpMap(""),
    _reflectionMap(""),
    _cloudMap(""),
    _colorMap("image1")
{
    _randomFactors.append(0.0);
    QSharedPointer<ModuleDescriptor> p(new ModuleDescriptor());
    p.data()->setName("Module1");
    p.data()->setModuleType("Perlin");
    p.data()->setupPropertiesToExport(p.data()->moduleType());
    _modDesc.insert(p.data()->name(),p);
    QSharedPointer<HeightMapDescriptor> hmp(new HeightMapDescriptor());
    hmp.data()->setName("heightMap");
    _hmDesc.insert(hmp.data()->name(), hmp);
    QSharedPointer<ImageDescriptor> imp(new ImageDescriptor());
    imp.data()->setName("image1");
    __imDesc.insert(imp.data()->name(),imp);
    QSharedPointer<NoiseMapBuilderDescriptor> nmbd(new NoiseMapBuilderDescriptor());
    nmbd.data()->setName("noiseMapBuilder1");
    nmbd.data()->setSourceModule(p.data()->name());
    nmbd.data()->setSize(1024,512);
    nmbd.data()->setDest(hmp.data()->name());
    _nmbDesc.insert(nmbd.data()->name(),nmbd);
    QSharedPointer<RendererDescriptor> rdp(new RendererDescriptor());
    rdp.data()->setName("renderer1");
    rdp.data()->setDestImage(imp.data()->name());
    rdp.data()->setNoisemap(hmp.data()->name());
    rdp.data()->gradientInfo().clear();
    rdp.data()->gradientInfo().append(GradientInfo(-1.0,255,255,0  ,255));
    rdp.data()->gradientInfo().append(GradientInfo( 0.0,  0,255,255,255));
    rdp.data()->gradientInfo().append(GradientInfo( 1.0,255,  0,255,255));
    _rndDesc.insert(rdp.data()->name(),rdp);

}

void TextureBuilder::fromJson(const QJsonObject &json) {

    if (!json["colorMap"].isNull() && !json["colorMap"].isUndefined())
        _colorMap = json["colorMap"].toString();
    if (!json["cloudMap"].isNull() && !json["cloudMap"].isUndefined())
        _cloudMap = json["cloudMap"].toString();
    if (!json["reflectionMap"].isNull() && !json["reflectionMap"].isUndefined())
        _reflectionMap = json["reflectionMap"].toString();
    if (!json["bumpMap"].isNull() && !json["bumpMap"].isUndefined())
        _bumpMap = json["bumpMap"].toString();

    if (!json["randomFactors"].isNull() && !json["randomFactors"].isUndefined()) {
        auto jsRf = json["randomFactors"];
        if (jsRf.isDouble()) {
            _randomFactors.clear();
            _randomFactors.append(jsRf.toDouble());
        }
        if (jsRf.isArray()) {
            _randomFactors.clear();
            QJsonArray arr = jsRf.toArray();
            for (auto h = 0; h < arr.size(); ++h) {
                _randomFactors.append(arr[h].toDouble());
            }
        }
    }


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
        if (h == 0 && _colorMap == "") _colorMap = o;
        if (h == 1 && _cloudMap == "") _cloudMap = o;
        if (h == 2 && _bumpMap == "") _bumpMap =  o;
        if (h == 3 && _reflectionMap == "") _reflectionMap = o;

        QSharedPointer<ImageDescriptor> p; p.reset(m);
        __imDesc.insert(o,p);
    }

    /*
    createAll();
    connectAll();
    */
}

void TextureBuilder::toJson(QJsonObject &json) {
    json["colorMap"] = _colorMap;
    json["cloudMap"] = _cloudMap;
    json["reflectionMap"] = _reflectionMap;
    json["bumpMap"] = _bumpMap;

    if (_randomFactors.count() > 0) {
        QJsonArray rf;
        for (auto it = _randomFactors.begin(); it != _randomFactors.end(); ++it) {
            auto w = (*it);
            rf.append(w);
        }
        json["randomFactors"] = rf;
    }
    QJsonArray aModules;
    for (auto it = _modDesc.begin(); it != _modDesc.end(); ++it) {
        QJsonObject o;
        it.value().data()->toJson(o);
        aModules.append(o);
    }
    json["modules"] = aModules;

    QJsonArray aHMBuilders;
    for (auto it = _nmbDesc.begin(); it != _nmbDesc.end(); ++it) {
        QJsonObject o;
        it.value().data()->toJson(o);
        aHMBuilders.append(o);
    }
    json["heightMapBuilders"] = aHMBuilders;

    QJsonArray aRenderers;
    for (auto it = _rndDesc.begin(); it != _rndDesc.end(); ++it) {
        QJsonObject o;
        it.value().data()->toJson(o);
        aRenderers.append(o);
    }

    json["renderers"] = aRenderers;

    QJsonArray aImages;
    for (auto it = __imDesc.begin(); it != __imDesc.end(); ++it) {
        aImages.append(it.value().data()->name());
    }
    json["images"] = aImages;

    QJsonArray aHeightMaps;
    for (auto it = _hmDesc.begin(); it != _hmDesc.end(); ++it) {
        aHeightMaps.append(it.value().data()->name());
    }
    json["heightMaps"] = aHeightMaps;

}

void TextureBuilder::createModules() {
    QSharedPointer<ModuleDescriptor> mod;
    foreach (mod,_modDesc) {
        auto modPtr = mod.data();
        if (this->useRandomFactors() &&  modPtr->enableRandom() ) {
            modPtr->setBias(this->applyRandomFactor(modPtr->bias()) );
            modPtr->setDispl(this->applyRandomFactor(modPtr->displ()) );
            modPtr->setExp(this->applyRandomFactor(modPtr->exp()) );
            modPtr->setFreq(this->applyRandomFactor(modPtr->freq()) );
            modPtr->setLac(this->applyRandomFactor(modPtr->lac()) );
            modPtr->setLbound(this->applyRandomFactor(modPtr->lBound()) );
            modPtr->setPers(this->applyRandomFactor(modPtr->pers()) );
            modPtr->setPow(this->applyRandomFactor(modPtr->pow()) );
            modPtr->setRough(this->applyRandomFactor(modPtr->rough()) );
            modPtr->setScale(this->applyRandomFactor(modPtr->scale()) );
            modPtr->setValue(this->applyRandomFactor(modPtr->value()) );
            modPtr->setX(this->applyRandomFactor(modPtr->x()) );
            modPtr->setY(this->applyRandomFactor(modPtr->y()) );
            modPtr->setZ(this->applyRandomFactor(modPtr->z()) );
        }
        mod.data()->setModules(_modules);
        auto ptr = mod.data()->makeModule();
        _modules.insert(mod.data()->name(), ptr);
    }
}

void TextureBuilder::createImages() {
    QSharedPointer<ImageDescriptor> img;
    foreach (img,__imDesc) {
        auto ptr = img.data()->makeImage();
        _images.insert(img.data()->name(),ptr);
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
        m.value().data()->setModules(_modules);
        m.value().data()->connectModules();
    }
}

void TextureBuilder::connectNoiseMapBuilders() {
    QMapIterator<QString,QSharedPointer<NoiseMapBuilderDescriptor>> iter(_nmbDesc);
    while (iter.hasNext())
    {
        auto m = iter.next();
        m.value().data()->setModules(_modules);
        m.value().data()->setNoiseMapBuilders(_noiseMapBuilders);
        m.value().data()->setNoiseMaps(_heightMaps);
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
        ptr->setNoiseMaps(_heightMaps);
        ptr->connectImagesAndMap();
    }

}


void TextureBuilder::buildNoiseMaps()
{
    QMapIterator<QString,QSharedPointer<utils::NoiseMapBuilder>> iter(_noiseMapBuilders);
    while(iter.hasNext()) {
        utils::NoiseMapBuilder* ptr = iter.next().value().data();
        auto p1 = ptr;
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
    QString simpleFile = filename;
    simpleFile = simpleFile.replace(".textjson","");
    QFile data (filename);
     if (data.open(QFile::ReadOnly | QFile::Text)) {
         QByteArray json = data.readAll();
         QJsonParseError parserError;
        QJsonDocument doc = QJsonDocument::fromJson(json, &parserError);
        if (!doc.isNull()) {
            emit this->textureGenerationStarting();
            auto oStuff = doc.object();

            qDebug() << "Loading raw json data";
            //load raw data
            this->fromJson(oStuff);

            qDebug() << "Creating libnoise stuff";
            this->createAll();

            qDebug() << "Connecting modules and stuff";
            this->connectAll();

            qDebug() << "Building images...";
            QString outFile = "";
            QSharedPointer<utils::Image> imgPtr = this->buildImages();
            int h = 0;
            QMapIterator<QString, QSharedPointer<ImageDescriptor>> iter(__imDesc);
            _generatedMaps.clear();
            while (iter.hasNext()) {
                iter.next();
                auto name = iter.key();
                auto ImgPtr = _images[name].data();
                QString filename = simpleFile+"."+name+".png";
                if (h == 0)
                    outFile = filename;
                qDebug() << "Saving image...";
                utils::WriterBMP writer;
                writer.SetSourceImage (*ImgPtr);
                std::unique_ptr<noise::uint8[]> buff(writer.GetBRGABuffer());
                auto sizeX = _nmbDesc.first().data()->getSizeX();
                auto sizeY = _nmbDesc.first().data()->getSizeY();
                QImage img((uchar *)buff.get() ,sizeX, sizeY,sizeX*4,QImage::Format_ARGB32);
                img.save(filename,"PNG");
                _generatedMaps.append(filename);
                emit this->textureGenerated(name);
            }
            emit this->allTextureGenerated();
        }
        else {
            _generatedMaps.clear();
            QString error = parserError.errorString();
            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("<big>"+error+"</big>");
            msgBox.setInformativeText(error);
            msgBox.setStandardButtons(QMessageBox::Ok );
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
            emit this->noTextureGenerated();
        }
     }
     data.close();

}
