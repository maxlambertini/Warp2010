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


NoiseImageUtils::NoiseImageUtils() : _sizeX(1024),_sizeY(512)
{

}

NoiseImageUtils::NoiseImageUtils(int nX, int nY) : _sizeX(nX), _sizeY(nY) {}




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
