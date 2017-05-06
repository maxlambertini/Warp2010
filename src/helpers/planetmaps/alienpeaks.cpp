#include "alienpeaks.h"

using namespace maps;

AlienPeaks::AlienPeaks()
{

}

void AlienPeaks::generate()
{
    module::Perlin myModule;
    myModule.SetOctaveCount(_octave);
    myModule.SetFrequency(_frequency);
    myModule.SetLacunarity(_lacunarity);
    myModule.SetPersistence(_persistence);
    myModule.SetSeed(_seed);

    module::RotatePoint rot;
    rot.SetSourceModule(0,myModule);
    rot.SetAngles(45.0,45.0,45.0);

    module::ScaleBias scaleBase;
    scaleBase.SetSourceModule(0,rot);
    scaleBase.SetScale(0.7);

    module::Exponent expBase;
    expBase.SetSourceModule(0,rot);
    expBase.SetExponent(4.0);

    utils::NoiseMap heightMap;
    utils::NoiseMap heightMapPeak;

    utils::NoiseMapBuilderSphere heightMapBuilder;
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);

    heightMapBuilder.SetSourceModule (scaleBase);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.Build();

    heightMapBuilder.SetSourceModule (expBase);
    heightMapBuilder.SetDestNoiseMap (heightMapPeak);
    heightMapBuilder.Build();


    utils::RendererImage renderer;
    renderer.ClearGradient ();
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);

    auto colorMap = ColorOps::lightningGradient(12,14,ColorOps::randomColor(),40);
    QMapIterator<double, QColor> iter(colorMap);
    while (iter.hasNext())
    {
        auto v = iter.next();
        renderer.AddGradientPoint(v.key(), QColorToColor(v.value()));
    }
    renderer.AddGradientPoint(1.0, QColorToColor(ColorOps::randomColor()));

    renderer.EnableLight ();
    renderer.SetLightContrast (0.2);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    QColor c1 = ColorOps::randomColor();
    QColor c2 = c1.lighter(100+ SSGX::d100());
    QColor c3 = c2.lighter(100+ SSGX::d100());

    c1.setAlpha(64);
    c2.setAlpha(128);
    c3.setAlpha(192);

    //second rendering
    renderer.ClearGradient();
    renderer.SetDestImage (this->m_image);
    renderer.SetBackgroundImage( this->m_image);
    renderer.SetSourceNoiseMap(heightMapPeak);
    renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 192,   0)); // shallow
    renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255,   0)); // shore
    renderer.AddGradientPoint ( 0.0125, utils::Color (240, 240,  64,   0)); // sand
    renderer.AddGradientPoint ( 0.0250, utils::Color (  0, 160,   0,   0)); // grass
    renderer.AddGradientPoint ( 0.2750, utils::Color (  0, 224,   0,   0)); // grass
    renderer.AddGradientPoint ( 0.4750, QColorToColor(c1)); // grass
    renderer.AddGradientPoint ( 0.8750, QColorToColor(c2)); // grass
    renderer.AddGradientPoint ( 0.9850, QColorToColor(c3)); // grass
    renderer.EnableLight ();
    renderer.SetLightContrast (1.3);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();


    emit imageCreated("Earthlike");

}
