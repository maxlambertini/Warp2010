#include "jade2.h"

using namespace maps;

Jade2::Jade2()
{

}

void Jade2::generate() {
    QColor color1 = ColorOps::randomColor();
    QColor d2 = color1.darker().darker();
    QColor d1 = color1.darker();
    QColor l1 = color1.lighter();
    QColor l2 = color1.lighter().lighter();

    // produces the veins.
    module::RidgedMulti primaryJade;
    primaryJade.SetSeed (_seed);
    primaryJade.SetFrequency (0.5+1.5*SSGX::floatRand());
    primaryJade.SetLacunarity (0.5 + SSGX::floatRand()*1.0);
    primaryJade.SetOctaveCount (4);
    primaryJade.SetNoiseQuality (QUALITY_STD);

    // Base of the secondary jade texture.  The base texture uses concentric
    // cylinders aligned on the z axis, which will eventually be perturbed.
    module::Cylinders baseSecondaryJade;
    baseSecondaryJade.SetFrequency (0.5+SSGX::floatRand());

    // Rotate the base secondary jade texture so that the cylinders are not
    // aligned with any axis.  This produces more variation in the secondary
    // jade texture since the texture is parallel to the y-axis.
    module::RotatePoint rotatedBaseSecondaryJade;
    rotatedBaseSecondaryJade.SetSourceModule (0, baseSecondaryJade);
    rotatedBaseSecondaryJade.SetAngles (90.0, 25.0, 5.0);

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence perturbedBaseSecondaryJade;
    perturbedBaseSecondaryJade.SetSourceModule (0, rotatedBaseSecondaryJade);
    perturbedBaseSecondaryJade.SetSeed (_seed*2);
    perturbedBaseSecondaryJade.SetFrequency (1.22);
    perturbedBaseSecondaryJade.SetPower (1.0 / 4.0);
    perturbedBaseSecondaryJade.SetRoughness (4);

    // Scale the secondary jade texture so it contributes a small part to the
    // final jade texture.
    module::ScaleBias secondaryJade;
    secondaryJade.SetSourceModule (0, perturbedBaseSecondaryJade);
    secondaryJade.SetScale (0.25);
    secondaryJade.SetBias (0.0);

    // Add the two jade textures together.  These two textures were produced
    // using different combinations of coherent noise, so the final texture will
    // have a lot of variation.
    module::Add combinedJade;
    combinedJade.SetSourceModule (0, primaryJade);
    combinedJade.SetSourceModule (1, secondaryJade);

    // Finally, perturb the combined jade textures to produce the final jade
    // texture.  A low roughness produces nice veins.
    module::Turbulence finalJade;
    finalJade.SetSourceModule (0, combinedJade);
    finalJade.SetSeed (_seed/2);
    finalJade.SetFrequency (4.0);
    finalJade.SetPower (1.0 / 16.0);
    finalJade.SetRoughness (2);

    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap noiseMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);
    sphere.SetSourceModule(finalJade);
    sphere.SetDestNoiseMap (noiseMap);
    sphere.Build ();

    utils::RendererImage textureRenderer;
    textureRenderer.ClearGradient ();
    auto mapGr = ColorOps::randomGradient(6,12,ColorOps::randomColor());
    QMapIterator<double, QColor> i(mapGr);
    while (i.hasNext()) {
        i.next();
        textureRenderer.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }

    // Set up us the texture renderer and pass the noise map to it.
    textureRenderer.SetSourceNoiseMap (noiseMap);
    textureRenderer.SetDestImage (m_image);
    textureRenderer.EnableLight (true);
    textureRenderer.SetLightElev (60.0);
    textureRenderer.SetLightContrast (1.6);
    textureRenderer.SetLightBrightness (1.6);

    // Render the texture.
    textureRenderer.Render ();

    emit imageCreated("Jade");

}
