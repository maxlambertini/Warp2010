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

#include "desertg.h"
#include <planetmaps/abstractmap.h>

using namespace maps;

DesertG::DesertG()
{

}

void DesertG::generate() {
    module::Perlin myModule;
    myModule.SetOctaveCount(_octave);
    myModule.SetFrequency(_frequency);
    myModule.SetLacunarity(_lacunarity);
    myModule.SetPersistence(_persistence);
    myModule.SetSeed(_seed);

    // Perturb the cloud texture for more realism.
    module::Turbulence finalClouds;
    finalClouds.SetSourceModule (0, myModule);
    finalClouds.SetSeed (3);
    finalClouds.SetFrequency (16.0);
    finalClouds.SetPower (1.0 / 64.0);
    finalClouds.SetRoughness (2);

    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    heightMapBuilder.SetSourceModule (finalClouds);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();

    QColor baseColor = ColorOps::randomColor();
    auto steps = 4 + SSGX::d6();
    auto colorMap = ColorOps::randomGradient(steps,20,baseColor);

    QMapIterator<double, QColor> i(colorMap);
    while (i.hasNext()) {
        i.next();
        renderer.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Desert");

}
