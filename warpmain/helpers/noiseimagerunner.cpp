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

QSharedPointer<NoiseImageRunner> NoiseImageRunner::UseTextureBuilder(const QString &textureFile, const QString &imageFile) {
    QSharedPointer<NoiseImageRunner> sp(new NoiseImageRunner());
    sp.data()->setFilename(imageFile);
    sp.data()->setTextureFile(textureFile);
    sp.data()->setRunType(UseBuilder);
    return sp;
}

void NoiseImageRunner::run() {
    {
       switch (_runType) {
           case UseBuilder:
               {
                    using std::unique_ptr;
                    unique_ptr<TextureBuilder> tb(new TextureBuilder());
                    TextureBuilder *p = tb.get();
                    if (_textureFile.startsWith("/") || _textureFile.contains(":/") || _textureFile.contains(":\\"))
                        p->prepareObjectFromJsonFile( _textureFile);
                    else
                        p->prepareObjectFromJsonFile( AppPaths::appDir()+"/jstexture/"+ _textureFile);
                    p->buildImages();
                    p->saveRenderedImageToFile(p->colorMap(),_filename);
               }
           break;
           case GG2:
               {
                   maps::GasGiant ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Cloudy:
               {
                   maps::Cloudy ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Earthlike:
               {
                   maps::EarthlikePeaks ep; ep.setSeaRatio(- (this->seaRatio() / 100.0 - 0.5)); ep.setIceRatio(0.30);  ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Earthlike2:
               {
                   maps::Earthlike2 ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Earthlike3:
               {
                   maps::Earthlike3 ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Pregarden:
               {
                   maps::EarthlikePeaks ep; ep.setSeaRatio(- (this->seaRatio() / 100.0 - 0.5)); ep.setIceRatio(0.30); ep.setSeed(_seed); ep.setupPreGarden();  ep.generateAndSave(_filename);
               }
           break;
           case Glacier:
               {
                   maps::EarthlikePeaks ep; ep.setSeaRatio(- (this->seaRatio() / 100.0 - 0.5)); ep.setSeed(_seed); ep.setupGlacier(); ep.setSeaRatio(_seaRatio); ep.generateAndSave(_filename);
               }
           break;
           case Postgarden:
               {
                   maps::EarthlikePeaks ep; ep.setSeaRatio(- (this->seaRatio() / 100.0 - 0.5)); ep.setSeed(_seed); ep.setIceRatio(0.30); ep.setupPostGarden(); ep.generateAndSave(_filename);
               }
           break;
           case Clouds:
               {
                   maps::EarthClouds ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case FunkyClouds:
               {
                   maps::FunkyClouds ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Desert:
               {
                   maps::Desert ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case DesertG:
               {
                   maps::DesertG ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case ComplexDesert:
                {
                   maps::AlienPeaks ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
                }
                /*
               imgUtils.CreateComplexDesert(_seed,
                                        _octave,
                                        _lacunarity,
                                        _frequency,
                                        _persistence);
                */
           break;
           case ComplexDesert2:
            {
               maps::AlienPeaksVoronoi ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
            }
           break;
           case GG:
               {
                   maps::GasGiant ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Jade:
               {
                   maps::Jade ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Jade2:
               {
                   maps::Jade2 ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Granite:
               {
                   maps::Granite ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Ice:
               {
                   maps::Ice ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           default:
               {
                   maps::EarthlikePeaks ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
       }
       emit imageSaved(_filename);
   }
}
