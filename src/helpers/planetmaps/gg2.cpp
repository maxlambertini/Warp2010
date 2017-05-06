#include "gg2.h"

using namespace maps;

GG2::GG2()
{

}

void GG2::generate() {
    module::Cylinders baseGG;
    baseGG.SetFrequency (0.5+SSGX::floatRand());

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pert2;
    pert2.SetSourceModule (0, baseGG);
    pert2.SetSeed (_seed*9);
    pert2.SetFrequency (0.4);
    pert2.SetPower (1.0 / 4.0);
    pert2.SetRoughness (3);


    // Rotate the base secondary jade texture so that the cylinders are not
    // aligned with any axis.  This produces more variation in the secondary
    // jade texture since the texture is parallel to the y-axis.
    module::RotatePoint rot;
    rot.SetSourceModule (0, pert2  );
    rot.SetAngles (0.0, 0.0, 0.0);

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pert;
    pert.SetSourceModule (0, rot);
    pert.SetSeed (_seed*2);
    pert.SetFrequency (1.22);
    pert.SetPower (1.0 / 4.0);
    pert.SetRoughness (4);


    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap noiseMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);
    sphere.SetSourceModule(pert);
    sphere.SetDestNoiseMap (noiseMap);
    sphere.Build ();

    //build texture

    utils::RendererImage textureRenderer;
    textureRenderer.ClearGradient ();
    //auto mapGr = ColorOps::randomGradient(6,12,ColorOps::randomColor());
    QMap<double, QColor> mapGr;
    double cnt = -1.0;
    while (cnt < 1.99) {
        mapGr.insert(cnt,ColorOps::randomColor());
        cnt += 0.2+0.25*SSGX::floatRand();
    }
    mapGr.insert(1.0, ColorOps::randomColor());
    QMapIterator<double, QColor> i(mapGr);
    while (i.hasNext()) {
        i.next();
        textureRenderer.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }

    // Set up us the texture renderer and pass the noise map to it.
    textureRenderer.SetSourceNoiseMap (noiseMap);
    textureRenderer.SetDestImage (m_image);
    textureRenderer.EnableLight (false);
    textureRenderer.SetLightElev (60.0);
    textureRenderer.SetLightContrast (1.6);
    textureRenderer.SetLightBrightness (1.6);

    // Render the texture.
    textureRenderer.Render ();

    emit imageCreated("GG2");

}
