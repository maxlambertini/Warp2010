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

class LIBNOISEHELPERSSHARED_EXPORT RingTextureBuilder : public QObject
{
    Q_OBJECT

    QLinearGradient _gradient;

public:
    explicit RingTextureBuilder(QObject *parent = 0);
    void initializeGradient();
    void initializeGradient(const QLinearGradient& gradient);
    void saveTexture(QString texturePath);

signals:

public slots:
};

#endif // RINGTEXTUREBUILDER_H
