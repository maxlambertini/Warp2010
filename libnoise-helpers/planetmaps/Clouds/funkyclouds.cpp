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

#include "funkyclouds.h"
#include <planetmaps/abstractmap.h>

using namespace maps;

FunkyClouds::FunkyClouds()
{
    _seed=1;
    _octave=4;
    _lacunarity=2.12;
    _frequency=2.0;
    _persistence=0.375;
}

void FunkyClouds::generate() {
    utils::NoiseMap cloudMap;
    utils::NoiseMapBuilderSphere cloudMapBuilder;

    module::Billow cloudBase;
    cloudBase.SetSeed (_seed);
    cloudBase.SetOctaveCount(_octave);
    cloudBase.SetFrequency (_frequency);
    cloudBase.SetPersistence (_persistence);
    cloudBase.SetLacunarity (_lacunarity);
    cloudBase.SetNoiseQuality (QUALITY_BEST);

    // Perturb the cloud texture for more realism.
    module::Turbulence finalClouds;
    finalClouds.SetSourceModule (0, cloudBase);
    finalClouds.SetSeed (3);
    finalClouds.SetFrequency (16.0);
    finalClouds.SetPower (1.0 / 64.0);
    finalClouds.SetRoughness (2);

    cloudMapBuilder.SetSourceModule (finalClouds);
    cloudMapBuilder.SetDestNoiseMap (cloudMap);
    cloudMapBuilder.SetDestSize (_sizeX, _sizeY);
    cloudMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    cloudMapBuilder.Build();

    utils::RendererImage cloudRend;
    cloudRend.SetSourceNoiseMap (cloudMap);
    cloudRend.SetDestImage (m_image);
    cloudRend.ClearGradient ();
    cloudRend.SetBackgroundColor(utils::Color(0,0,0,0));
    auto clrEnd = QColorToColor(ColorOps::randomColor());
    clrEnd.alpha = 255;

    auto colorMap = ColorOps::randomGradient(5,30,ColorOps::randomColor());
    QMapIterator<double, QColor> i(colorMap);
    while (i.hasNext()) {
        i.next();
        auto clr = QColorToColor((i.value()));
        auto w = SSGX::d10();
        if ( w > 7)
            clr.alpha =SSGX::dn(128);
        else
            clr.alpha = 0;
        cloudRend.AddGradientPoint(i.key(), clr);
    }
    cloudRend.AddGradientPoint(1.00,clrEnd);
    cloudRend.EnableLight (false);
    cloudRend.Render();

    emit imageCreated("FunkyClouds");

}
