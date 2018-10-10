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


#include "noiseimagerunner.h"
#include <QThread>
#include <QDebug>
#include <qcolorops.h>
#include <utility>
#include "helpers/apppaths.h"


NoiseImageRunner::NoiseImageRunner()
{
}

QSharedPointer<NoiseImageRunner> NoiseImageRunner::UseTextureBuilder(const QString &textureFile, const QString &imageFile,
                                                                     bool generateSpecular, bool generateNormal) {
    QSharedPointer<NoiseImageRunner> sp(new NoiseImageRunner());
    sp.data()->setFilename(imageFile);

    /*
    QString normalFile(textureFile); normalFile = normalFile.replace(".png",".norm.png");
    QString specFile(textureFile); specFile = specFile.replace(".png",".spec.png");
    sp.data()->setFilenameNormal(normalFile);
    sp.data()->setFilenameSpecular(specFile);
    */

    sp.data()->_generateNormal = generateNormal;
    sp.data()->_generateSpecular = generateSpecular;
    sp.data()->setTextureFile(textureFile);
    sp.data()->setRunType(UseBuilder);
    return sp;
}

QSharedPointer<NoiseImageRunner> NoiseImageRunner::UseRingBuilder(const QString &imageFile) {
    QSharedPointer<NoiseImageRunner> sp(new NoiseImageRunner());
    sp.data()->setFilename(imageFile);
    sp.data()->setRunType(Ring);
    return sp;
}


void NoiseImageRunner::run() {
    {
       switch (_runType) {
           case Ring:
               {
                    qDebug() << "Ring " << _filename;
                    using std::unique_ptr;
                    unique_ptr<RingTextureBuilder> tb(new RingTextureBuilder());
                    RingTextureBuilder* tx = tb.get();
                    tx->saveTexture(_filename);
                    qDebug() << "Ring -- done";
                    emit imageSaved(_filename);
               }
           break;
           case UseBuilder:
               {
                    qDebug() << "UseBuilder " << _textureFile << ", " << _filename;
                    using std::unique_ptr;
                    unique_ptr<TextureBuilder> tb(new TextureBuilder());
                    qDebug() << "Creating texture for planet " << _planetName << ", type(" << _planetType << ") using file " << _textureFile << " to filename " << _filename;
                    TextureBuilder *p = tb.get();
                    if (_textureFile.startsWith("/") || _textureFile.contains(":/") || _textureFile.contains(":\\"))
                        p->prepareObjectFromJsonFile( _textureFile);
                    else
                        p->prepareObjectFromJsonFile( AppPaths::appDir()+"/jstexture/"+ _textureFile);
                    p->buildImages();
                    p->saveRenderedImageToFile(p->colorMap(),_filename);
                    if (!_filenameSpecular.isEmpty() && !p->reflectionMap().isEmpty()) {
                        qDebug() << "Saving Specular map to " << _filenameSpecular;
                        p->saveRenderedImageToFile(p->reflectionMap(),_filenameSpecular);
                    }
                    if (!_filenameNormal.isEmpty() && !p->bumpMap().isEmpty()) {
                        qDebug() << "Saving Normal map to " << _filenameNormal;
                        p->saveRenderedImageToFile(p->bumpMap(),_filenameNormal);
                    }
                    qDebug() << "UseBuilder -- done";
                    emit imageSaved(_filename);
               }
           break;
           default:
           break;
       }

   }
}
