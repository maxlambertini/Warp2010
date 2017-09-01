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


#ifndef RINGTEXTUREBUILDER_H
#define RINGTEXTUREBUILDER_H

#include <libnoise-helpers_global.h>
#include <QObject>
#include <QGradient>
#include <QLinearGradient>
#include <QBrush>
#include <QRect>
#include <QImage>
#include <ssg_structures.h>

///
/// \brief The RingTextureBuilder class generates a texture for ringed planet
///
class LIBNOISEHELPERSSHARED_EXPORT RingTextureBuilder : public QObject
{
    Q_OBJECT

    QLinearGradient _gradient;

public:
    ///
    /// \brief RingTextureBuilder
    /// \param parent
    ///
    explicit RingTextureBuilder(QObject *parent = 0);

    ///
    /// \brief initializeGradient
    ///
    /// Initializes the gradient object with a random gradient
    ///
    void initializeGradient();

    ///
    /// \brief initializeGradient
    /// \param gradient
    ///
    /// Initializes the object with an already constructed gradient
    void initializeGradient(const QLinearGradient& gradient);

    ///
    /// \brief saveTexture Saves the texture data into an image file
    ///
    /// \param texturePath the full filename of the image file to save
    ///
    /// Save the texture data into an image file. The image will be 1024x10 pixel -- enough
    /// for a nice ring texture :-)
    ///
    /// <h3>Caveats</h3>
    ///
    /// - Use PNG file format to get best results.
    ///
    void saveTexture(QString texturePath);

signals:

public slots:
};

#endif // RINGTEXTUREBUILDER_H
