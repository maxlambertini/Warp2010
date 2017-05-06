#include "noiseimagerunner.h"
#include <QThread>
#include <QDebug>
#include <helpers/qcolorops.h>

NoiseImageRunner::NoiseImageRunner()
{
}

void NoiseImageRunner::run() {
    {
       switch (_runType) {
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
               maps::AlienPeaks ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
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
