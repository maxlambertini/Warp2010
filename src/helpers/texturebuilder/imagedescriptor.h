#ifndef IMAGEDESCRIPTOR_H
#define IMAGEDESCRIPTOR_H

#include <QObject>

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>

class ImageDescriptor
{
    QString _name = "image1";
public:
    QString& name() { return _name; }
    void setName(const QString& v) { _name = v; }
    ImageDescriptor();

    //from descriptor to actual object
    QSharedPointer<utils::Image> makeImage() {
        auto p = new utils::Image();
        QSharedPointer<utils::Image> sp; sp.reset(p);
        return sp;
    }
};

#endif // IMAGEDESCRIPTOR_H
