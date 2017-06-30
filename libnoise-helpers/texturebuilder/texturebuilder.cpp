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
    rdp.data()->setHeightmap(hmp.data()->name());
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

    if (!json["builderType"].isNull() && !json["builderType"].isUndefined()) {
        auto sType = json["builderType"].toString();
        if (sType.toLower() != "sphere" && sType.toLower() != "plane" && sType.toLower() != "cylinder")
            _builderType = "sphere";
        else
            _builderType = sType;
    }

    if (!json["size"].isNull() && !json["size"].isUndefined()) {
        auto a = json["size"].toArray();
        _size = std::tuple<int,int>(a[0].toInt(),a[1].toInt());
    }

    if (!json["bounds"].isNull() && !json["bounds"].isUndefined()) {
        auto a1 = json["bounds"].toArray();
        _bounds = std::tuple<double,double,double,double>(
            a1[0].toDouble(),
            a1[1].toDouble(),
            a1[2].toDouble(),
            a1[3].toDouble()
            );
    }

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

    _modDesc.clear();
    _modules.clear();
    for (auto h = 0; h < aModules.size(); ++h) {
        ModuleDescriptor *m = new ModuleDescriptor();
        QJsonObject o = aModules[h].toObject();
        m->fromJson(o);

        QString name = m->name();
        m->setModules(_modules);
        QSharedPointer<ModuleDescriptor> p; p.reset(m);
        _modDesc.insert(name,p);
    }

    _rndDesc.clear();
    _renderers.clear();

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

    _nmbDesc.clear();
    _noiseMapBuilders.clear();
    for (auto h = 0; h < aHMBuilders.size(); ++h) {
        NoiseMapBuilderDescriptor *m = new NoiseMapBuilderDescriptor();
        QJsonObject o = aHMBuilders[h].toObject();

        m->fromJson(o);

        assignSizeInfoToNMBDesc(m);

        //m->setBuilderType(NoiseMapBuilderType::SPHERE);
        //m->setSize(std::get<0>(_size), std::get<1>(_size));
        //m->setBounds(std::get<0>(_bounds),std::get<1>(_bounds),std::get<2>(_bounds),std::get<3>(_bounds));

        m->setModules(_modules);

        QString name = m->name();
        QSharedPointer<NoiseMapBuilderDescriptor> p; p.reset(m);
        _nmbDesc.insert(name,p);
    }

    _hmDesc.clear();
    _heightMaps.clear();
    for (auto h = 0; h < aHeightMaps.size(); ++h) {
        HeightMapDescriptor *m = new HeightMapDescriptor();
        QString o = aHeightMaps[h].toString();

        m->setName(o);

        QSharedPointer<HeightMapDescriptor> p; p.reset(m);
        _hmDesc.insert(o,p);
    }

    _images.clear();
    __imDesc.clear();
    for (auto h = 0; h < aImages.size(); ++h) {
        ImageDescriptor *m = new ImageDescriptor();
        QString o = aImages[h].toString();

        m->setName(o);
        if (h == 0 && _colorMap == "") _colorMap = o;
        if (h == 1 && _bumpMap == "") _bumpMap =  o;
        if (h == 2 && _cloudMap == "") _cloudMap = o;
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

    json["builderType"] = _builderType;

    QJsonArray a;
    a.append(std::get<0>(_size));
    a.append(std::get<1>(_size));
    json["size"] = a;
    QJsonArray a1;
    a1.append(std::get<0>(_bounds));
    a1.append(std::get<1>(_bounds));
    a1.append(std::get<2>(_bounds));
    a1.append(std::get<3>(_bounds));
    json["bounds"] = a1;


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


void TextureBuilder::prepareObjectFromJsonFile(const QString &filename) {
    try {
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

                qDebug() << "All done, let's perform a sanity check";
                this->textureSanityCheck();

                emit this->builderReady();
            }
        }
        data.close();
    }
    catch (noise::Exception err) {
        throw "Generic noise::exception";
    }
    catch (noise::ExceptionInvalidParam err) {
        throw "Invalid param error";
    }
    catch (noise::ExceptionNoModule err) {
        throw "No module defined as source or control";
    }
    catch (noise::ExceptionOutOfMemory ) {
        throw "Out of memory!";
    }
    catch (QString err) {
        throw err;
    }
    catch (std::string err) {
        throw err;
    }
    catch (...) {
        throw "Undefined error building texture " + filename;
    }

}

/// To be called before building images.
///
/// This method checks if all images defined in json file are actually used
/// and if renderers use them correctly (that is, when an Image is referenced
/// first time by a Renderer is referenced as a destination image, not
/// as a background image and the like...
///
/// textureSanityCheck() throws a QString containing the error messages if something's wrong.
void TextureBuilder::textureSanityCheck() {

    // Here, we store image usage matrix. Image name is the key,
    // while the <bool,bool> tuple means that it's been used and first
    // referenced correctly as a renderer (that is as Destination)

    QMap<QString, std::tuple<bool,bool>> imageUsage;

    // let's assume the worst
    for (auto it = __imDesc.begin(); it != __imDesc.end(); ++it) {
        imageUsage.insert(it.key(),std::tuple<bool,bool>(false,false));
    }

    // Now that we have initialized our matrix, let's work on Renderers
    for (auto it = _rndDesc.begin(); it != _rndDesc.end(); ++it) {
        auto renderer = it.value().data();

        //first thing first: let's see if it's got an image map defined.
        if (renderer->heightMap().isNull() || renderer->heightMap().isEmpty())
            throw "Renderer " + renderer->name() + " has no heightMap defined";
        //then if it's actually in list
        if (!_hmDesc.keys().contains(renderer->heightMap()))
            throw "Renderer " + renderer->name() + " references " + renderer->heightMap() + " as its heightMap but it's undefined";

        //ok, now to image. First, background. Let's check it's been defined and already used.
        //Then destination. Every renderer must define a
        //destination image
        auto back = renderer->backgroundImage();
        auto dest = renderer->destImage();

        //background can be null, let's check its existence if defined
        if (!back.isNull() && !back.isEmpty() ) {

            //if defined background must exist
            if (!__imDesc.contains(back))
                throw "Renderer " + renderer->name() + " references " + back + " as its background image but it's undefined";

            //if it exists, it must have already been used as a dest image
            auto t = imageUsage[back];
            if ( !std::get<0>(t))
                throw "Image " + back + " is used as background on Renderer " + renderer->name() + " but it's never been used before.";
            if ( !std::get<1>(t))
                throw "Image " + back + " is used as background on Renderer " + renderer->name() + " but it's never been used as a destination before.";
        }


        if (dest.isNull() || dest.isEmpty()) {
            throw "Renderer " + renderer->name() + " has no destination image defined";
        }
        if (!__imDesc.contains(dest)) {
            throw "Renderer " + renderer->name() + " references " + dest + " as its destination image but it's undefined";
        }
        std::tuple<bool,bool> tOk(true,true);
        imageUsage[dest] = tOk;
    }

    //If we get here Renderers are OK, let's see if there are unused images;
    for (auto it = imageUsage.begin(); it != imageUsage.end(); ++it) {
        auto t = it.value();
        if (!std::get<0>(t))
            throw "Image " + it.key() + " is not referenced by any Renderer";
        if (!std::get<1>(t))
            throw "Image " + it.key() + " is first referenced as a Background image. Fix this. ";
    }

    //NOW we're done.
    return;
}

void TextureBuilder::prepareObjectFromJsonString(const QString &jsonData) {
    try {
        auto json = jsonData.toUtf8();
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

            qDebug() << "All done, let's perform a sanity check";
            this->textureSanityCheck();

            emit this->builderReady();
        }
    }
    catch (noise::Exception err) {
        throw "Generic noise::exception";
    }
    catch (noise::ExceptionInvalidParam err) {
        throw "Invalid param error";
    }
    catch (noise::ExceptionNoModule err) {
        throw "No module defined as source or control";
    }
    catch (noise::ExceptionOutOfMemory ) {
        throw "Out of memory!";
    }
    catch (QString err) {
        throw err;
    }
    catch (std::string err) {
        throw err;
    }
    catch (...) {
        throw "Undefined error building texture from string data";
    }
}

void TextureBuilder::saveRenderedImageToFile(const QString &imageName, const QString &destFileName) {
    if (_images.count() > 0 && _images.contains(imageName)) {
        auto ImgPtr = _images[imageName].data();
        qDebug() << "Saving image..." + destFileName;
        utils::WriterBMP writer;
        writer.SetSourceImage (*ImgPtr);
        std::unique_ptr<noise::uint8[]> buff(writer.GetBRGABuffer());
        auto sizeX = _nmbDesc.first().data()->getSizeX();
        auto sizeY = _nmbDesc.first().data()->getSizeY();
        QImage img((uchar *)buff.get() ,sizeX, sizeY,sizeX*4,QImage::Format_ARGB32);
        img.save(destFileName,"PNG");
        emit this->textureGenerated(imageName);
    }
    else
        throw "image " + imageName + " undefined or not present, or no images have been defined";
}

void TextureBuilder::buildTextureFromJson(const QString &filename, QString path) {
    try {
        QString simpleFile = path = "" ?
                    filename : path.endsWith(QDir::separator()) ? path : path + QDir::separator()+  QFileInfo(filename).fileName();
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

                qDebug() << "All done, let's perform a sanity check";
                this->textureSanityCheck();

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
                    if (!buff)
                        throw "Buffer associated to image " + name + " is empty.\nPlease remove the image from Images or setup a Module-Heightmap-Renderer chain to display it correctly.";
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
    catch (noise::Exception err) {
        throw "Generic noise::exception";
    }
    catch (noise::ExceptionInvalidParam err) {
        throw "Invalid param error";
    }
    catch (noise::ExceptionNoModule err) {
        throw "No module defined as source or control";
    }
    catch (noise::ExceptionOutOfMemory ) {
        throw "Out of memory!";
    }
    catch (QString err) {
        throw err;
    }
    catch (std::string err) {
        throw err;
    }
    catch (...) {
        throw "Undefined error building texture " + filename;
    }
}
