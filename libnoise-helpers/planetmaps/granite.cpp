#include "granite.h"

using namespace maps;

Granite::Granite()
{

}

void Granite::generate() {

    module::Billow primaryGranite;
    primaryGranite.SetSeed (_seed);
    primaryGranite.SetFrequency (7.0 * ( 0.8 + SSGX::floatRand()*0.4));
    primaryGranite.SetPersistence (0.625 * ( 0.8 + SSGX::floatRand()*0.4));
    primaryGranite.SetLacunarity (2.18359375 * ( 0.8 + SSGX::floatRand()*0.4));
    primaryGranite.SetOctaveCount (6);
    primaryGranite.SetNoiseQuality (QUALITY_STD);

    // Use Voronoi polygons to produce the small grains for the granite texture.
    module::Voronoi baseGrains;
    baseGrains.SetSeed (1);
    baseGrains.SetFrequency (16.0 * ( 0.8 + SSGX::floatRand()*0.4));
    baseGrains.EnableDistance (true);

    // Scale the small grain values so that they may be added to the base
    // granite texture.  Voronoi polygons normally generate pits, so apply a
    // negative scaling factor to produce bumps instead.
    module::ScaleBias scaledGrains;
    scaledGrains.SetSourceModule (0, baseGrains);
    scaledGrains.SetScale (-0.5);
    scaledGrains.SetBias (0.0);

    // Combine the primary granite texture with the small grain texture.
    module::Add combinedGranite;
    combinedGranite.SetSourceModule (0, primaryGranite);
    combinedGranite.SetSourceModule (1, scaledGrains);

    // Finally, perturb the granite texture to add realism.
    module::Turbulence finalGranite;
    finalGranite.SetSourceModule (0, combinedGranite);
    finalGranite.SetSeed (_seed/2);
    finalGranite.SetFrequency (4.0 * ( 0.8 + SSGX::floatRand()*0.4));
    finalGranite.SetPower (1.0 / 8.0);
    finalGranite.SetRoughness (6);

    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap noiseMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);
    sphere.SetSourceModule(finalGranite);
    sphere.SetDestNoiseMap (noiseMap);
    sphere.Build ();

    utils::RendererImage textureRenderer;
    textureRenderer.ClearGradient ();

    auto steps = 2 + SSGX::d6();
    auto colorMap = ColorOps::randomGradient(steps,13);
    QMapIterator<double, QColor> i(colorMap);
    while (i.hasNext()) {
        i.next();
        textureRenderer.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }
    textureRenderer.AddGradientPoint(1.00,QColorToColor(ColorOps::randomColor()));

    // Set up us the texture renderer and pass the noise map to it.
    textureRenderer.SetSourceNoiseMap (noiseMap);
    textureRenderer.SetDestImage (m_image);
    textureRenderer.EnableLight (true);
    textureRenderer.SetLightElev (45);
    textureRenderer.SetLightContrast (0.15);
    textureRenderer.SetLightBrightness (3.0);

    // Render the texture.
    textureRenderer.Render ();

    emit imageCreated("Granite");
}
