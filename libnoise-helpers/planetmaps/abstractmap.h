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

#ifndef ABSTRACTMAP_H
#define ABSTRACTMAP_H
#include <memory>
#include <QObject>
#include <QColor>
#include <QVector>
#include <QVectorIterator>
#include <QMap>
#include <QMapIterator>
#include "noiseutils.h"
#include <libnoise-helpers_global.h>
#include "noiseimageutils.h"

namespace maps {
    struct LIBNOISEHELPERSSHARED_EXPORT GradientItem {
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

    class LIBNOISEHELPERSSHARED_EXPORT AbstractMap : public NoiseImageUtils
    {
        Q_OBJECT
    public:
        AbstractMap();
        virtual void generate() = 0;
        void generateAndSave(const QString& filename) { this->generate(); this->SaveImage(filename); }
    };
}

#endif // ABSTRACTMAP_H
