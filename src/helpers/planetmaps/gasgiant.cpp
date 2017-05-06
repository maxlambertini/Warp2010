#include "gasgiant.h"
#include <helpers/planetmaps/abstractmap.h>

using namespace maps;

GasGiant::GasGiant()
{

}

void GasGiant::generate() {
    // base GG modules
    module::Cylinders baseGG;
    baseGG.SetFrequency (_seed);

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pert2;
    pert2.SetSourceModule (0, baseGG);
    pert2.SetSeed (_seed*9);
    pert2.SetFrequency (0.9);
    pert2.SetPower (1.0 / 8.0);
    pert2.SetRoughness (6);

    //upper GG layer
    module::Cylinders baseGG2;
    baseGG2.SetFrequency (1.5+SSGX::floatRand());

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pert3;
    pert3.SetSourceModule (0, baseGG2);
    pert3.SetSeed (_seed*9);
    pert3.SetFrequency (0.82);
    pert3.SetPower (1.0 / 3.0);
    pert3.SetRoughness (3);

    // let's compose everything together

    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap noiseMap;
    utils::NoiseMap cloudMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);

    sphere.SetSourceModule(pert2);
    sphere.SetDestNoiseMap (noiseMap);
    sphere.Build ();

    sphere.SetSourceModule(pert3);
    sphere.SetDestNoiseMap (cloudMap);
    sphere.Build ();

    //build texture

    utils::RendererImage textureRenderer;

    // render base image
    textureRenderer.ClearGradient ();
    //auto mapGr = ColorOps::randomGradient(6,12,ColorOps::randomColor());
    auto QColor1 = ColorOps::randomColor();
    QMap<double, QColor> mapGr;
    double cnt = -1.0;
    while (cnt < 1.99) {
        mapGr.insert(cnt,QColor1);
        cnt += 0.2+0.25*SSGX::floatRand();
        if (SSGX::d10() < 5)
            QColor1 = QColor1.lighter(120+SSGX::dn(70));
        else
            QColor1 = QColor1.darker(120+SSGX::dn(70));
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

    // render clouds
    textureRenderer.ClearGradient ();
    //auto mapGr = ColorOps::randomGradient(6,12,ColorOps::randomColor());
    QColor1 = ColorOps::randomColor();
    QColor1.setAlpha(SSGX::dn(128));
    mapGr.clear();
    cnt = -1.0;
    while (cnt < 1.99) {
        mapGr.insert(cnt,QColor1);
        cnt += 0.2+0.25*SSGX::floatRand();
        auto w = SSGX::d10();
        if (w < 5)
            QColor1 = QColor1.lighter(120+SSGX::dn(70));
        else if (w > 6)
            QColor1 = QColor1.darker(120+SSGX::dn(70));
        else
            QColor1 = ColorOps::randomColor();
        if (cnt > 1.5)
            QColor1.setAlpha(255);
        else
            QColor1.setAlpha(SSGX::dn(128));
    }
    //mapGr.insert(1.0, ColorOps::randomColor());
    QMapIterator<double, QColor> i2(mapGr);
    while (i2.hasNext()) {
        i2.next();
        textureRenderer.AddGradientPoint(i2.key(), QColorToColor(i2.value()));
    }

    // Set up us the texture renderer and pass the noise map to it.
    textureRenderer.SetSourceNoiseMap (cloudMap);
    textureRenderer.SetBackgroundImage(m_image);
    textureRenderer.SetDestImage (m_image);
    textureRenderer.EnableLight (false);
    textureRenderer.SetLightElev (60.0);
    textureRenderer.SetLightContrast (1.6);
    textureRenderer.SetLightBrightness (1.6);

    // Render the texture.
    textureRenderer.Render ();


    emit imageCreated("GasGiant");
}
