#include "funkyclouds.h"
#include <helpers/planetmaps/abstractmap.h>

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
