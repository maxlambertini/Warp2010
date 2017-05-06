#include "cloudy.h"

using namespace maps;

Cloudy::Cloudy()
{

}

void Cloudy::generate() {
    module::Voronoi baseWater;
    baseWater.SetSeed (_seed);
    baseWater.SetFrequency (8.0);
    baseWater.EnableDistance (true);
    baseWater.SetDisplacement (0.0);

    // Stretch the waves along the z axis.
    module::ScalePoint baseStretchedWater;
    baseStretchedWater.SetSourceModule (0, baseWater);
    baseStretchedWater.SetScale (1.0, 1.0, 3.0);

    // Smoothly perturb the water texture for more realism.
    module::Turbulence finalWater;
    finalWater.SetSourceModule (0, baseStretchedWater);
    finalWater.SetSeed (SSGX::dn(99999));
    finalWater.SetFrequency (8.0);
    finalWater.SetPower (1.0 / 32.0);
    finalWater.SetRoughness (1);

    // Upper layer: cloud texture
    // --------------------------

    // Base of the cloud texture.  The billowy noise produces the basic shape
    // of soft, fluffy clouds.
    module::Billow cloudBase;
    cloudBase.SetSeed (_seed);
    cloudBase.SetFrequency (_frequency);
    cloudBase.SetPersistence (_persistence);
    cloudBase.SetLacunarity (_lacunarity);
    cloudBase.SetOctaveCount (4);
    cloudBase.SetNoiseQuality (QUALITY_BEST);

    // Perturb the cloud texture for more realism.
    module::Turbulence finalClouds;
    finalClouds.SetSourceModule (0, cloudBase);
    finalClouds.SetSeed (SSGX::dn(99999));
    finalClouds.SetFrequency (16.0);
    finalClouds.SetPower (1.0 / 64.0);
    finalClouds.SetRoughness (2);

    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap lowerNoiseMap;
    utils::NoiseMap upperNoiseMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);

    // Generate the lower noise map.
    sphere.SetSourceModule (finalWater);
    sphere.SetDestNoiseMap (lowerNoiseMap);
    sphere.Build ();

    // Generate the upper noise map.
    sphere.SetSourceModule (finalClouds);
    sphere.SetDestNoiseMap (upperNoiseMap);
    sphere.Build ();

    utils::RendererImage textureRenderer;
    utils::Image destTexture;
    textureRenderer.SetSourceNoiseMap (lowerNoiseMap);
    textureRenderer.SetDestImage (destTexture);
    textureRenderer.ClearGradient();

    auto gradient = ColorOps::lightningGradient(8,25,ColorOps::randomColor());
    QMapIterator<double, QColor> i(gradient);
    while (i.hasNext()) {
        i.next();
        auto clr = QColorToColor((i.value()));
        textureRenderer.AddGradientPoint(i.key(), clr);
    }

    // Set up us the texture renderer and pass the lower noise map to it.

    textureRenderer.EnableLight (true);
    textureRenderer.SetLightAzimuth (135.0);
    textureRenderer.SetLightElev (60.0);
    textureRenderer.SetLightContrast (2.0);
    textureRenderer.SetLightColor (utils::Color (255, 255, 255, 0));

    // Render the texture.
    textureRenderer.Render ();

    // Create the color gradients for the upper texture.
    textureRenderer.ClearGradient();
    auto colorMap = ColorOps::randomGradient(6,30,ColorOps::randomColor());
    QMapIterator<double, QColor> i2(colorMap);
    while (i2.hasNext()) {
        i2.next();
        auto clr = QColorToColor((i2.value()));
        auto w = SSGX::d10();
        if ( w > 4)
            clr.alpha =128+SSGX::dn(128);
        else
            clr.alpha = 0;
        textureRenderer.AddGradientPoint(i2.key(), clr);
    }

    // Set up us the texture renderer and pass the upper noise map to it.  Also
    // use the lower texture map as a background so that the upper texture map
    // can be rendered on top of the lower texture map.
    textureRenderer.SetSourceNoiseMap (upperNoiseMap);
    textureRenderer.SetBackgroundImage (destTexture);
    textureRenderer.SetDestImage (this->m_image);
    textureRenderer.EnableLight (false);

    // Render the texture.
    textureRenderer.Render ();

    emit imageCreated("CloudyPlanet");

}
