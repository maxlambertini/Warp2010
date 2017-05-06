#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include <memory>
#include <helpers/noiseimageutils.h>
#include <QObject>
#include <helpers/noiseimageutils.h>
#include <noiseutils.h>
#include <helpers/planetmaps/abstractmap.h>
#include <QColor>
#include <QVector>
#include <QVectorIterator>
#include <QMap>
#include <QMapIterator>

namespace maps {
    struct GradientItem {
        double position;
        int red;
        int green;
        int blue;
        int alpha;
        utils::Color getColor() { return utils::Color(
                        static_cast<noise::uint8>(this->red),
                        static_cast<noise::uint8>(this->green),
                        static_cast<noise::uint8>(this->blue),
                        static_cast<noise::uint8>(this->alpha)); }
        QColor getQColor() { return QColor(red, green, blue, alpha); }
    };

    class AbstractMap : public NoiseImageUtils
    {
        Q_OBJECT
    public:
        AbstractMap();
        virtual void generate() = 0;
        void generateAndSave(const QString& filename) { this->generate(); this->SaveImage(filename); }
    };
}

#endif // ABSTRACTMAP_H
