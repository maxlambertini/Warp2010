#include "noiseimageutils.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "star.h"
#include "ssg_structures.h"
#include <memory>
#include <helpers/qcolorops.h>
#include <QGraphicsBlurEffect>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>

/*
 *  cloudBase.SetSeed (2);
    cloudBase.SetOctaveCount(4);
    cloudBase.SetFrequency (2.0);
    cloudBase.SetPersistence (0.375);
    cloudBase.SetLacunarity (2.12109375);
    cloudBase.SetOctaveCount (4);
    cloudBase.SetNoiseQuality (QUALITY_BEST);

    // Perturb the cloud texture for more realism.
    module::Turbulence finalClouds;
    finalClouds.SetSourceModule (0, cloudBase);
    finalClouds.SetSeed (3);
    finalClouds.SetFrequency (16.0);
    finalClouds.SetPower (1.0 / 64.0);
    finalClouds.SetRoughness (2);
*/
NoiseImageUtils::NoiseImageUtils() : _sizeX(1024),_sizeY(512)
{

}

NoiseImageUtils::NoiseImageUtils(int nX, int nY) : _sizeX(nX), _sizeY(nY) {}


void NoiseImageUtils::CreateEarthClouds(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    utils::NoiseMap cloudMap;
    utils::NoiseMapBuilderSphere cloudMapBuilder;

    module::Billow cloudBase;
    cloudBase.SetSeed (seed);
    cloudBase.SetOctaveCount(octave);
    cloudBase.SetFrequency (frequency);
    cloudBase.SetPersistence (persistence);
    cloudBase.SetLacunarity (lacunarity);
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
    cloudRend.AddGradientPoint (-1.00, utils::Color (255, 255, 255, 0));
    cloudRend.AddGradientPoint ( 0.60, utils::Color (255, 255, 255, 0 ));
    cloudRend.AddGradientPoint ( 1.00, utils::Color (255, 255, 255  , 255));
    cloudRend.EnableLight (false);
    cloudRend.Render();

    emit imageCreated("EarthClouds");
}

void NoiseImageUtils::CreateFunkyClouds(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    utils::NoiseMap cloudMap;
    utils::NoiseMapBuilderSphere cloudMapBuilder;

    module::Billow cloudBase;
    cloudBase.SetSeed (seed);
    cloudBase.SetOctaveCount(octave);
    cloudBase.SetFrequency (frequency);
    cloudBase.SetPersistence (persistence);
    cloudBase.SetLacunarity (lacunarity);
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
        cloudRend.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }
    cloudRend.AddGradientPoint(1.00,clrEnd);
    cloudRend.EnableLight (false);
    cloudRend.Render();

    emit imageCreated("FunkyClouds");
}


void NoiseImageUtils::CreateEarthlikeRMF(int seed, int octave, double lacunarity, double frequency) {

    module::RidgedMulti myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    //myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);



    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    heightMapBuilder.SetSourceModule (myModule);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, utils::Color (  0,   0, 128, 255)); // deeps
    renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 255, 255)); // shallow
    renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255, 255)); // shore
    renderer.AddGradientPoint ( 0.0625, utils::Color (240, 240,  64, 255)); // sand
    renderer.AddGradientPoint ( 0.1250, utils::Color ( 32, 160,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.3750, utils::Color (224, 224,   0, 255)); // dirt
    renderer.AddGradientPoint ( 0.7500, utils::Color (128, 128,   0, 255)); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("EarthlikeRMF");

}

void NoiseImageUtils::CreateEarthlike(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);



    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    heightMapBuilder.SetSourceModule (myModule);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, utils::Color (  0,   0, 128, 255)); // deeps
    renderer.AddGradientPoint (-0.2500, utils::Color (  0,   0, 255, 255)); // shallow
    renderer.AddGradientPoint ( 0.0000, utils::Color (  0, 128, 255, 255)); // shore
    renderer.AddGradientPoint ( 0.0625, utils::Color (240, 240,  64, 255)); // sand
    renderer.AddGradientPoint ( 0.1250, utils::Color ( 32, 160,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.3750, utils::Color (224, 224,   0, 255)); // dirt
    renderer.AddGradientPoint ( 0.7500, utils::Color (128, 128,   0, 255)); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Earthlike");

}

void NoiseImageUtils::CreatePregarden(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);



    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, myModule);
    flatTerrain.SetBias(SSGX::floatRand()*1.20 - 0.6 );

    heightMapBuilder.SetSourceModule (flatTerrain);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();


    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, utils::Color ( 29, 94,  128, 255)); // deeps
    renderer.AddGradientPoint (-0.2500, utils::Color ( 35, 115, 141, 255)); // shallow
    renderer.AddGradientPoint ( 0.0000, utils::Color (232, 164, 123, 255)); // shore
    renderer.AddGradientPoint ( 0.0625, utils::Color (171, 193,  85, 255)); // sand
    renderer.AddGradientPoint ( 0.1250, utils::Color (153, 160,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.3750, utils::Color ( 93, 122, 149, 255)); // dirt
    renderer.AddGradientPoint ( 0.7500, utils::Color ( 69,  65,  26, 255)); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Earthlike");

}

void NoiseImageUtils::CreatePostgarden(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);



    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, myModule);
    flatTerrain.SetBias(SSGX::floatRand()*1.20 - 0.6 );


    heightMapBuilder.SetSourceModule (flatTerrain);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, utils::Color ( 19,  74,  88, 255)); // deeps
    renderer.AddGradientPoint (-0.2500, utils::Color ( 25,  85, 111, 255)); // shallow
    renderer.AddGradientPoint ( 0.0000, utils::Color (182, 124,  83, 255)); // shore
    renderer.AddGradientPoint ( 0.0625, utils::Color (141, 163,  65, 255)); // sand
    renderer.AddGradientPoint ( 0.1250, utils::Color (113, 120,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.3750, utils::Color ( 63,  92, 119, 255)); // dirt
    renderer.AddGradientPoint ( 0.7500, utils::Color ( 39,  55,  26, 255)); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Earthlike");

}

void NoiseImageUtils::CreateEarthlike2(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);

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

void NoiseImageUtils::CreateEarthlike3(int seed, int octave, double lacunarity, double frequency, double persistence)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, myModule);
    flatTerrain.SetBias(0.55);


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



void NoiseImageUtils::CreateDesert(int seed, int octave, double lacunarity, double frequency, double persistence, utils::Color color1, utils::Color color2, utils::Color color3)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);

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
    renderer.AddGradientPoint (-1.0000, color1); // deeps
    renderer.AddGradientPoint ( 0.0000, color2); // shore
    renderer.AddGradientPoint ( 0.7500, color3); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("Desert");
}


void NoiseImageUtils::CreateDesertG(int seed, int octave, double lacunarity,
                                    double frequency, double persistence,
                                    const QColor &baseColor)
{
    module::Perlin myModule;
    myModule.SetOctaveCount(octave);
    myModule.SetFrequency(frequency);
    myModule.SetLacunarity(lacunarity);
    myModule.SetPersistence(persistence);
    myModule.SetSeed(seed);

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


void NoiseImageUtils::CreateComplexDesert(int seed, int octave, double lacunarity, double frequency,
                                          double persistence, utils::Color color1, utils::Color color2,
                                          utils::Color color3) {

    module::RidgedMulti rmf;
    rmf.SetOctaveCount(4);
    rmf.SetFrequency(3.50);
    rmf.SetLacunarity(1.90);
    rmf.SetSeed(seed*2);

    module::Perlin base;
    base.SetOctaveCount(octave);
    base.SetFrequency(frequency);
    base.SetLacunarity(lacunarity);
    base.SetPersistence(persistence);
    base.SetSeed(seed/2);

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, base);
    flatTerrain.SetScale (0.5);
    flatTerrain.SetBias(-0.25);

    module::Perlin terrainType;
    terrainType.SetFrequency (0.8 * (0.7 + SSGX::floatRand()*0.7));
    terrainType.SetPersistence (0.25* (0.7 + SSGX::floatRand()*0.7));

    module::Select finalTerrain;
    finalTerrain.SetSourceModule (0, flatTerrain);
    finalTerrain.SetSourceModule (1, rmf);
    finalTerrain.SetControlModule (terrainType);
    finalTerrain.SetBounds (0.0, 1000.0);
    finalTerrain.SetEdgeFalloff (0.125);

    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;

    heightMapBuilder.SetSourceModule (finalTerrain);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build();

    utils::RendererImage renderer;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (this->m_image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, color1); // deeps
    renderer.AddGradientPoint ( 0.0000, color2); // shore
    renderer.AddGradientPoint ( 0.7500, color3); // rock
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    renderer.Render ();

    emit imageCreated("ComplexDesert");
}

void NoiseImageUtils::CreateComplexDesert2(int seed, int octave, double lacunarity,
                                           double frequency, double persistence,
                                           const QColor &color1, const QColor &color2)
{
    auto baseColor1 = this->QColorToColor(color1);
    auto darkColor1 = this->QColorToColor( color1.darker());
    auto darkerColor1 = this->QColorToColor(color1.darker().darker());
    auto lightColor1 = this->QColorToColor( color1.lighter());
    auto lighterColor1 = this->QColorToColor(color1.lighter().lighter());

    auto baseColor2 = this->QColorToColor(color2);
    auto darkColor2 = this->QColorToColor( color2.darker());
    auto darkerColor2 = this->QColorToColor(color2.darker().darker());
    auto lightColor2 = this->QColorToColor( color2.lighter());
    auto lighterColor2 = this->QColorToColor(color2.lighter().lighter());

    module::Perlin base;
    base.SetOctaveCount(octave);
    base.SetFrequency(frequency);
    base.SetLacunarity(lacunarity);
    base.SetPersistence(persistence);
    base.SetSeed(seed);

    module::ScaleBias flatTerrain;
    flatTerrain.SetSourceModule (0, base);
    flatTerrain.SetScale (0.5);
    flatTerrain.SetBias(-0.25);

    module::RidgedMulti rmf;
    rmf.SetOctaveCount(6);
    rmf.SetFrequency(2.50);
    rmf.SetLacunarity(2.90);
    rmf.SetSeed(seed*2);

    utils::NoiseMapBuilderSphere sphere;
    utils::NoiseMap lowerNoiseMap;
    utils::NoiseMap upperNoiseMap;
    sphere.SetBounds (-90.0, 90.0, -180.0, 180.0); // degrees
    sphere.SetDestSize (_sizeX, _sizeY);

    // Generate the lower noise map.
    sphere.SetSourceModule (flatTerrain);
    sphere.SetDestNoiseMap (lowerNoiseMap);
    sphere.Build ();

    // Generate the upper noise map.
    sphere.SetSourceModule (rmf);
    sphere.SetDestNoiseMap (upperNoiseMap);
    sphere.Build ();

    utils::RendererImage textureRenderer;
    textureRenderer.ClearGradient ();
    textureRenderer.AddGradientPoint (-1.00, darkerColor1);
    textureRenderer.AddGradientPoint (-0.50, darkColor1);
    textureRenderer.AddGradientPoint ( 0.00, baseColor1);
    textureRenderer.AddGradientPoint ( 0.50, lightColor1);
    textureRenderer.AddGradientPoint ( 1.00, lighterColor2);

    // Set up us the texture renderer and pass the lower noise map to it.
    textureRenderer.SetSourceNoiseMap (lowerNoiseMap);
    textureRenderer.SetDestImage (this->m_image);
    textureRenderer.EnableLight (false);
    textureRenderer.SetLightContrast (0.1);
    textureRenderer.SetLightBrightness (2.0);
    textureRenderer.SetLightColor (utils::Color (255, 255, 255, 0));

    // Render the texture.
    textureRenderer.Render ();

    // Create the color gradients for the upper texture.
    textureRenderer.ClearGradient ();
    lighterColor2.alpha = 255;
    lightColor2.alpha = 96;
    baseColor2.alpha = 0;
    darkColor2.alpha = 0;
    darkerColor2.alpha = 0;
    textureRenderer.AddGradientPoint (-1.00, darkerColor2);
    textureRenderer.AddGradientPoint (-0.50, darkColor2);
    textureRenderer.AddGradientPoint ( 0.80, baseColor2);
    textureRenderer.AddGradientPoint ( 0.90, lightColor2);
    textureRenderer.AddGradientPoint ( 1.00, lighterColor2);

    // Set up us the texture renderer and pass the upper noise map to it.  Also
    // use the lower texture map as a background so that the upper texture map
    // can be rendered on top of the lower texture map.
    textureRenderer.SetSourceNoiseMap (upperNoiseMap);
    textureRenderer.SetBackgroundImage (this->m_image);
    textureRenderer.SetDestImage (this->m_image);
    textureRenderer.EnableLight (true);
    textureRenderer.SetLightAzimuth (135.0);
    textureRenderer.SetLightElev (60.0);
    textureRenderer.SetLightContrast (1.6);
    textureRenderer.SetLightBrightness (1.6);
    textureRenderer.SetLightColor (utils::Color (255, 255, 255, 0));

    // Render the texture.
    textureRenderer.Render ();

    emit imageCreated("ComplexDesert2");
}

void NoiseImageUtils::CreateJadePlanet(int seed, const QColor &color1)
{
    QColor d2 = color1.darker().darker();
    QColor d1 = color1.darker();
    QColor l1 = color1.lighter();
    QColor l2 = color1.lighter().lighter();

    // produces the veins.
    module::RidgedMulti primaryJade;
    primaryJade.SetSeed (seed);
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
    perturbedBaseSecondaryJade.SetSeed (seed*2);
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
    finalJade.SetSeed (seed/2);
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
      textureRenderer.AddGradientPoint (-1.000, this->QColorToColor(l1));
      textureRenderer.AddGradientPoint ( 0.000, this->QColorToColor(l2));
      textureRenderer.AddGradientPoint ( 0.100, this->QColorToColor(color1));
      textureRenderer.AddGradientPoint ( 0.250, this->QColorToColor(d2 ));
      textureRenderer.AddGradientPoint ( 0.965, this->QColorToColor(d1));
      textureRenderer.AddGradientPoint ( 0.975, this->QColorToColor(ColorOps::randomColor()));

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

void NoiseImageUtils::CreateJade2Planet(int seed, const QColor &color1)
{
    QColor d2 = color1.darker().darker();
    QColor d1 = color1.darker();
    QColor l1 = color1.lighter();
    QColor l2 = color1.lighter().lighter();

    // produces the veins.
    module::RidgedMulti primaryJade;
    primaryJade.SetSeed (seed);
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
    perturbedBaseSecondaryJade.SetSeed (seed*2);
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
    finalJade.SetSeed (seed/2);
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


void NoiseImageUtils::CreateGGPlanet(int seed, const QColor &color1)
{
    QColor d2 = color1.darker().darker();
    QColor d1 = color1.darker();
    QColor l1 = color1.lighter();
    QColor l2 = color1.lighter().lighter();

    // produces the veins.
    module::RidgedMulti primaryJade;
    primaryJade.SetSeed (seed);
    primaryJade.SetFrequency (0.5+1.5*SSGX::floatRand());
    primaryJade.SetLacunarity (0.5 + SSGX::floatRand()*1.0);
    primaryJade.SetOctaveCount (4);
    primaryJade.SetNoiseQuality (QUALITY_STD);

    // Slightly perturb the secondary jade texture for more realism.
    module::Turbulence pertPrim;
    pertPrim.SetSourceModule (0, primaryJade);
    pertPrim.SetSeed (seed*2);
    pertPrim.SetFrequency (2.22);
    pertPrim.SetPower (1.0 / 7.0);
    pertPrim.SetRoughness (8);


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
    perturbedBaseSecondaryJade.SetSeed (seed*2);
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
    combinedJade.SetSourceModule (0, pertPrim);
    combinedJade.SetSourceModule (1, secondaryJade);

    // Finally, perturb the combined jade textures to produce the final jade
    // texture.  A low roughness produces nice veins.
    module::Turbulence finalJade;
    finalJade.SetSourceModule (0, combinedJade);
    finalJade.SetSeed (seed/2);
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


void NoiseImageUtils::CreateGranitePlanet(int seed, const QColor &color1) {
    utils::Color colorBlack = utils::Color(0,0,0,255);

    module::Billow primaryGranite;
    primaryGranite.SetSeed (seed);
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
    finalGranite.SetSeed (2);
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
    auto black=  ColorOps::randomColor();
    auto colorMap = ColorOps::randomGradient(steps,13,black);
    QMapIterator<double, QColor> i(colorMap);
    while (i.hasNext()) {
        i.next();
        textureRenderer.AddGradientPoint(i.key(), QColorToColor(i.value()));
    }
    textureRenderer.AddGradientPoint(1.00,QColorToColor(color1));

    // Set up us the texture renderer and pass the noise map to it.
    textureRenderer.SetSourceNoiseMap (noiseMap);
    textureRenderer.SetDestImage (m_image);
    textureRenderer.EnableLight (true);
    textureRenderer.SetLightElev (45);
    textureRenderer.SetLightContrast (0.15);
    textureRenderer.SetLightBrightness (3.0);

    // Render the texture.
    textureRenderer.Render ();
}

void NoiseImageUtils::SaveImage(const QString &filename, int blurSize)
{
    utils::WriterBMP writer;
    writer.SetSourceImage (m_image);
    std::unique_ptr<noise::uint8[]> buff(writer.GetBRGABuffer());
    QImage img((uchar *)buff.get() ,_sizeX, _sizeY,_sizeX*4,QImage::Format_ARGB32);

    if (blurSize > 0) {
        QGraphicsBlurEffect *blur = new QGraphicsBlurEffect;
        blur->setBlurRadius(blurSize);
        QImage result = applyEffectToImage(img, blur);
        result.save(filename,"PNG");
    }
    else
        img.save(filename,"PNG");

    emit imageFileSaved(filename);
}

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent)
{
    if(src.isNull()) return QImage();   //No need to do anything else!
    if(!effect) return src;             //No need to do anything else!
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));
    item.setGraphicsEffect(effect);
    scene.addItem(&item);
    QImage res(src.size()+QSize(extent*2, extent*2), QImage::Format_ARGB32);
    res.fill(Qt::transparent);
    QPainter ptr(&res);
    scene.render(&ptr, QRectF(), QRectF( -extent, -extent, src.width()+extent*2, src.height()+extent*2 ) );
    return res;
}
