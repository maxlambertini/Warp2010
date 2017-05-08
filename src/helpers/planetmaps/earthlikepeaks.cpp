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

#include "earthlikepeaks.h"
#include <helpers/planetmaps/abstractmap.h>

using namespace maps;

EarthlikePeaks::EarthlikePeaks()
{
    this->_gardenType = GARDEN;
}

void EarthlikePeaks::generate() {
    module::Perlin myModule;
    myModule.SetOctaveCount(_octave);
    myModule.SetFrequency(_frequency);
    myModule.SetLacunarity(_lacunarity);
    myModule.SetPersistence(_persistence);
    myModule.SetSeed(_seed);

    module::ScaleBias scaleBase;
    scaleBase.SetSourceModule(0,myModule);
    scaleBase.SetScale(0.7);
    scaleBase.SetBias(seaRatio());

    module::Exponent expBase;
    expBase.SetSourceModule(0,myModule);
    expBase.SetExponent(8.0);


    //poles
    // base GG modules
    module::Cylinders baseGG;
    baseGG.SetFrequency (1.0-_iceRatio);

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pert2;
    pert2.SetSourceModule (0, baseGG);
    pert2.SetSeed (_seed*9);
    pert2.SetFrequency (2.4);
    pert2.SetPower (1.0 / 4.0);
    pert2.SetRoughness (4);

    utils::NoiseMap heightMap;
    utils::NoiseMap heightMapPeak;
    utils::NoiseMap heightPoles;


    utils::NoiseMapBuilderSphere heightMapBuilder;
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);

    heightMapBuilder.SetSourceModule (scaleBase);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.Build();

    heightMapBuilder.SetSourceModule (expBase);
    heightMapBuilder.SetDestNoiseMap (heightMapPeak);
    heightMapBuilder.Build();

    heightMapBuilder.SetSourceModule (pert2);
    heightMapBuilder.SetDestNoiseMap (heightPoles);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.ClearGradient ();
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    switch (_gardenType) {
        case PREGARDEN:
        for (auto h = 0; h < 7; h++) {
            renderer.AddGradientPoint(preGardenSteps[h].position, preGardenSteps[h].getColor());
        }
        break;
        case POSTGARDEN:
        for (auto h = 0; h < 7; h++) {
            renderer.AddGradientPoint(postGardenSteps[h].position, postGardenSteps[h].getColor());
        }
        break;
    default:
        renderer.AddGradientPoint (-0.4500, utils::Color ( 41,  51,  87, 255)); // deeps
        renderer.AddGradientPoint (-0.2500, utils::Color ( 81, 110, 153, 255)); // shallow
        renderer.AddGradientPoint (-0.0500, utils::Color ( 81, 122, 176, 255)); // shallow
        renderer.AddGradientPoint ( 0.0000, utils::Color ( 88, 115,  69, 255)); // shore
        renderer.AddGradientPoint ( 0.2125, utils::Color ( 70,  75,  58, 255)); // sand
        renderer.AddGradientPoint ( 0.4550, utils::Color ( 76, 100,  69, 255)); // grass
        renderer.AddGradientPoint ( 0.4750, utils::Color ( 52,  68,  47, 255)); // grass
        break;
    }

    renderer.EnableLight ();
    renderer.SetLightContrast (0.2);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();


    //poles rendering
    renderer.ClearGradient();
    renderer.SetDestImage (this->m_image);
    renderer.SetBackgroundImage( this->m_image);
    renderer.SetSourceNoiseMap(heightPoles);
    renderer.AddGradientPoint ( 1.0000, utils::Color (255, 255, 255, 255)); // trans
    renderer.AddGradientPoint ( 0.6850, utils::Color (255, 255, 255, 255)); // trans
    renderer.AddGradientPoint ( 0.6820, utils::Color (255, 255, 255, 0)); // trans
    renderer.AddGradientPoint ( 0.1000, utils::Color (255,   0,   0, 0));
    renderer.AddGradientPoint (-0.1000, utils::Color (255,   0,   0, 0));
    renderer.AddGradientPoint (-0.6820, utils::Color (255, 255, 255, 0)); // trans
    renderer.AddGradientPoint (-0.6850, utils::Color (255, 255, 255, 0)); // trans
    renderer.AddGradientPoint (-1.0000, utils::Color (255, 255, 255, 0)); // trans
    renderer.EnableLight ();
    renderer.SetLightContrast (0.1);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    //peak rendering
    renderer.ClearGradient();
    renderer.SetDestImage (this->m_image);
    renderer.SetBackgroundImage( this->m_image);
    renderer.SetSourceNoiseMap(heightMapPeak);
    renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 192,   0)); // trans
    renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255,   0)); // trans
    renderer.AddGradientPoint ( 0.0125, utils::Color (240, 240,  64,   0)); // trans
    renderer.AddGradientPoint ( 0.0250, utils::Color (  0, 160,   0,   0)); // trans
    renderer.AddGradientPoint ( 0.0750, utils::Color (  0, 224,   0,   0)); // trans
    renderer.AddGradientPoint ( 0.3750, utils::Color (244, 112, 165,  64)); // rock
    renderer.AddGradientPoint ( 0.7750, utils::Color (153, 133, 103, 128)); // rock
    renderer.AddGradientPoint ( 0.9850, utils::Color (224, 255, 255, 192)); // snow
    renderer.EnableLight ();
    renderer.SetLightContrast (0.9);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("EarthlikePeaks");

}
