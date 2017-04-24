#ifndef NOISEIMAGEUTILS_H
#define NOISEIMAGEUTILS_H

#include <QImage>
#include <noiseutils.h>
#include <memory>
#include <QColor>

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

    void CreateEarthlikeRMF (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3);

    void CreateEarthlike (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32);
    void CreateEarthClouds (int seed=1, int octave=4, double lacunarity=2.12,
                          double frequency=2.0, double persistence=0.375);
    void SaveImage (const QString& filename);

    void CreateDesert (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          utils::Color color1 = utils::Color(128,  0,  0,255),
                          utils::Color color2 = utils::Color(192,  0,  0,255),
                          utils::Color color3 = utils::Color(255,128, 64,255));

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

signals:
    void imageCreated(const QString& imgType);
    void imageFileSaved(const QString& filename);

};

#endif // NOISEIMAGEUTILS_H
