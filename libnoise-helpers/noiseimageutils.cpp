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

#include "noiseimageutils.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "ssg_structures.h"
#include <memory>
#include <qcolorops.h>
#include <QGraphicsBlurEffect>
#include <QImage>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPainter>


NoiseImageUtils::NoiseImageUtils() : _sizeX(1024),_sizeY(512)
{

}

NoiseImageUtils::NoiseImageUtils(int nX, int nY) : _sizeX(nX), _sizeY(nY) {}





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
