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

#include "earthlike2.h"

using namespace maps;


Earthlike2::Earthlike2()
{

}

void Earthlike2::generate() {
    module::Perlin myModule;
    myModule.SetOctaveCount(_octave);
    myModule.SetFrequency(_frequency);
    myModule.SetLacunarity(_lacunarity);
    myModule.SetPersistence(_persistence);
    myModule.SetSeed(_seed);

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, myModule);
    flatTerrain.SetBias(-0.55);


    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    heightMapBuilder.SetSourceModule (flatTerrain);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.000, utils::Color (  0,   0, 128, 255)); // deeps
    renderer.AddGradientPoint (-0.200, utils::Color (  0,   0, 255, 255)); // shallow
    renderer.AddGradientPoint ( 0.000, utils::Color (  0, 128, 255, 255)); // shore
    renderer.AddGradientPoint ( 0.050, utils::Color (240, 240,  64, 255)); // sand
    renderer.AddGradientPoint ( 0.250, utils::Color ( 32, 160,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.370, utils::Color (224, 224,   0, 255)); // dirt
    renderer.AddGradientPoint ( 0.990, utils::Color (128, 128,   0, 255)); // rock
    renderer.AddGradientPoint ( 0.999, utils::Color (255, 255, 255, 255)); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0/20560.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Earthlike2");

}
