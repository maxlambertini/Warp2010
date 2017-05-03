#ifndef NOISEIMAGEUTILS_H
#define NOISEIMAGEUTILS_H

#include <QImage>
#include <noiseutils.h>
#include <memory>
#include <QColor>
#include <helpers/qcolorops.h>
#include <QGraphicsEffect>

class NoiseImageUtils : public QObject
{
    Q_OBJECT

    QImage _qimage;
    utils::Image m_image;
    std::shared_ptr<noise::uint8> _bufferPtr;
    int _sizeX, _sizeY;

public:
    NoiseImageUtils();
    NoiseImageUtils(int nX, int nY);

    utils::Color QColorToColor (const QColor& color) {
        utils::Color _color(
                    (noise::uint8)color.red(),
                    (noise::uint8)color.green(),
                    (noise::uint8)color.blue(),
                    (noise::uint8)color.alpha()
                    );
        return _color;
    }

    int sizeX() { return _sizeX; }
    int sizeY() { return _sizeY; }
    void setSizeX(int x) { _sizeX = x; }
    void setSizeY(int y) { _sizeY = y; }

    void CreateEarthlikeRMF (int seed = 1, int octave = 6, double lacunarity = 2.30,
                          double frequency = 3.3);

    void CreateEarthlike (int seed = 1, int octave = 6, double lacunarity = 3.30,
                          double frequency = 3.3, double persistence = 0.28);
    void CreateEarthlike2 (int seed = 1, int octave = 6, double lacunarity = 3.30,
                          double frequency = 3.3, double persistence = 0.28);
    void CreateEarthlike3 (int seed = 1, int octave = 6, double lacunarity = 3.30,
                          double frequency = 3.3, double persistence = 0.28);
    void CreatePregarden (int seed = 1, int octave = 6, double lacunarity = 3.30,
                          double frequency = 3.3, double persistence = 0.28);
    void CreatePostgarden (int seed = 1, int octave = 6, double lacunarity = 3.30,
                          double frequency = 3.3, double persistence = 0.28);
    void CreateEarthClouds (int seed=1, int octave=4, double lacunarity=2.12,
                          double frequency=2.0, double persistence=0.375);
    void CreateFunkyClouds (int seed=1, int octave=4, double lacunarity=2.12,
                          double frequency=2.0, double persistence=0.375);
    void CreateCloudyPlanet (int seed=1, int octave=4, double lacunarity=2.12,
                             double frequency=2.0, double persistence= 0.375);
    void SaveImage (const QString& filename, int blurSize = 0);

    void CreateDesert (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          utils::Color color1 = utils::Color(128,  0,  0,255),
                          utils::Color color2 = utils::Color(192,  0,  0,255),
                          utils::Color color3 = utils::Color(255,128, 64,255));

    void CreateDesertG (int seed = 1, int octave = 4, double lacunarity = 1.30,
                        double frequency = 3.3, double persistence = 0.12,
                        const QColor& baseColor = ColorOps::randomColor());

    void CreateComplexDesert (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          utils::Color color1 = utils::Color(128,  0,  0,255),
                          utils::Color color2 = utils::Color(192,  0,  0,255),
                          utils::Color color3 = utils::Color(255,128, 64,255));

    void CreateComplexDesert2 (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          const QColor& color1 = QColor(255,255,193),
                          const QColor& color2 = QColor(128,64,32));

    void CreateJadePlanet (int seed = 1, const QColor& color1 = QColor(255,255,193));
    void CreateJade2Planet (int seed = 1, const QColor& color1 = QColor(255,255,193));
    void CreateGGPlanet (int seed = 1, const QColor& color1 = QColor(255,255,193));
    void CreateGranitePlanet (int seed = 1, const QColor& color1 = QColor (96,96,128));
    void CreateIcePlanet (int seed = 1, const QColor& color1 = QColor (96,96,128));

signals:
    void imageCreated(const QString& imgType);
    void imageFileSaved(const QString& filename);

};

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent=0);

#endif // NOISEIMAGEUTILS_H
