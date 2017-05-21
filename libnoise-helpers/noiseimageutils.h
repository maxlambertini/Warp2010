/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#ifndef NOISEIMAGEUTILS_H
#define NOISEIMAGEUTILS_H

#include <QImage>
#include <noiseutils.h>
#include <memory>
#include <QColor>
#include <qcolorops.h>
#include "libnoise-helpers_global.h"
#include <QGraphicsEffect>

class LIBNOISEHELPERSSHARED_EXPORT NoiseImageUtils : public QObject
{
    Q_OBJECT

protected:
    QImage _qimage;
    utils::Image m_image;
    std::shared_ptr<noise::uint8> _bufferPtr;
    int _sizeX, _sizeY;
    int _seed;
    int _octave;
    double _lacunarity;
    double _frequency;
    double _persistence;


public:        
    NoiseImageUtils();
    NoiseImageUtils(int nX, int nY);

    QImage& qimage() { return _qimage; }
    void setQimage (const QImage& v) { _qimage = v; }
    utils::Image& image() { return m_image; }
    void setImage (const utils::Image&  v) { m_image = v; }
    std::shared_ptr<noise::uint8>& bufferPtr() { return _bufferPtr; }
    void setBufferptr (std::shared_ptr<noise::uint8>& v) { _bufferPtr = v; }
    int sizeX() { return _sizeX; }
    void setSizex (int v) { _sizeX = v; }
    int sizeY() { return _sizeY; }
    void setSizey (int v) { _sizeY = v; }
    int seed() { return _seed; }
    void setSeed (int v) { _seed = v; }
    int octave() { return _octave; }
    void setOctave (int v) { _octave = v; }
    double lacunarity() { return _lacunarity; }
    void setLacunarity (double v) { _lacunarity = v; }
    double frequency() { return _frequency; }
    void setFrequency (double v) { _frequency = v; }
    double persistence() { return _persistence; }
    void setPersistence (double v) { _persistence = v; }

    utils::Color QColorToColor (const QColor& color) {
        utils::Color _color(
                    (noise::uint8)color.red(),
                    (noise::uint8)color.green(),
                    (noise::uint8)color.blue(),
                    (noise::uint8)color.alpha()
                    );
        return _color;
    }

    void setSizeX(int x) { _sizeX = x; }
    void setSizeY(int y) { _sizeY = y; }

    void CreateComplexDesert (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          utils::Color color1 = utils::Color(128,  0,  0,255),
                          utils::Color color2 = utils::Color(192,  0,  0,255),
                          utils::Color color3 = utils::Color(255,128, 64,255));

    void CreateComplexDesert2 (int seed = 1, int octave = 6, double lacunarity = 1.30,
                          double frequency = 3.3, double persistence = 0.32,
                          const QColor& color1 = QColor(255,255,193),
                          const QColor& color2 = QColor(128,64,32));

    void SaveImage (const QString& filename, int blurSize = 0);

signals:
    void imageCreated(const QString& imgType);
    void imageFileSaved(const QString& filename);

};

QImage applyEffectToImage(QImage src, QGraphicsEffect *effect, int extent=0);

#endif // NOISEIMAGEUTILS_H
