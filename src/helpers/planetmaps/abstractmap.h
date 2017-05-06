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
