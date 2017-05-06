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
                   maps::EarthlikePeaks ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
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
               imgUtils.CreatePregarden(_seed);
               imgUtils.SaveImage(_filename);
           break;
           case Postgarden:
               imgUtils.CreatePostgarden(_seed);
               imgUtils.SaveImage(_filename);
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
               imgUtils.CreateComplexDesert(_seed,
                                        _octave,
                                        _lacunarity,
                                        _frequency,
                                        _persistence);
               imgUtils.SaveImage(_filename);
           break;
           case ComplexDesert2:
               imgUtils.CreateComplexDesert2(_seed,
                                        _octave,
                                        _lacunarity,
                                        _frequency,
                                        _persistence);
               imgUtils.SaveImage(_filename);
           break;
           case GG:
               {
                   maps::GasGiant ep; ep.setSeed(_seed); ep.generateAndSave(_filename);
               }
           break;
           case Jade:
               imgUtils.CreateJadePlanet(_seed, ColorOps::randomColor());
               imgUtils.SaveImage(_filename);
           break;
           case Jade2:
               imgUtils.CreateJade2Planet(_seed, ColorOps::randomColor());
               imgUtils.SaveImage(_filename);
           break;
           case Granite:
               imgUtils.CreateGranitePlanet(_seed, ColorOps::randomColor());
               imgUtils.SaveImage(_filename);
           break;
           case Ice:
               imgUtils.CreateIcePlanet(_seed);
               imgUtils.SaveImage(_filename);
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
