#include "ringtexturebuilder.h"
#include <QPainter>


RingTextureBuilder::RingTextureBuilder(QObject *parent) : QObject(parent)
{
    _gradient = QLinearGradient(0.0,0.0,1024.0,0.0);
}

void RingTextureBuilder::initializeGradient() {
    _gradient.stops().clear();
    double d = 0.0;
    int r1,r2,r3;
    int alpha = 0.0;
    alpha = SSGX::d100() < 75 ? 255 : 0;
    r1 = SSGX::dn(32)+223;
    r2 = SSGX::dn(64)+191;
    r3 = SSGX::dn(92)+163;
    _gradient.setColorAt(0, QColor(r1,r2,r3,alpha));
    while ( d < 0.95) {
        if ( d > 0.0) {
            d+= 0.001;
            _gradient.setColorAt(d, QColor(r1,r2,r3,alpha));
        }
        alpha = SSGX::d100() < 75 ? 255 : 0;
        r1 = SSGX::dn(32)+223;
        r2 = SSGX::dn(64)+191;
        r3 = SSGX::dn(92)+163;
        d += (0.05 + 0.1*SSGX::floatRand());
        if (d < 1.0)
            _gradient.setColorAt(d, QColor(r1,r2,r3,alpha));
    }
    alpha = SSGX::d100() < 75 ? 255 : 0;
    r1 = SSGX::dn(32)+223;
    r2 = SSGX::dn(64)+191;
    r3 = SSGX::dn(92)+163;
    _gradient.setColorAt(1, QColor(r1,r2,r3,alpha));
}

void RingTextureBuilder::initializeGradient(const QLinearGradient &gradient) {
    _gradient = gradient;
}

void RingTextureBuilder::saveTexture(QString texturePath) {
    initializeGradient();
    QBrush gradientBrush(_gradient);
    QImage img(1024,10,QImage::Format_ARGB32);
    img.fill(qRgba(0,0,0,0));
    QPainter painter(&img);    
    painter.setPen(Qt::transparent);
    painter.setBrush(gradientBrush);
    painter.drawRect(0,0,1024,10);
    auto end = painter.end();
    img.save(texturePath);
}
