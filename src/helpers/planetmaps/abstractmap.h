#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include <memory>
#include <helpers/noiseimageutils.h>
#include <QObject>
#include <helpers/noiseimageutils.h>
#include <noiseutils.h>
#include <helpers/planetmaps/abstractmap.h>

namespace maps {
    class AbstractMap : public NoiseImageUtils
    {
        Q_OBJECT
    public:
        AbstractMap();
        virtual void generate() = 0;
    };
}

#endif // ABSTRACTMAP_H
