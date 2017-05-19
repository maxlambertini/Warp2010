#ifndef HEIGHTMAPDESCRIPTOR_H
#define HEIGHTMAPDESCRIPTOR_H

#include <QObject>

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>

class HeightMapDescriptor : public QObject
{
    Q_OBJECT

    QString _name = "heightmap1";
public:
    QString& name() { return _name; }
    void setName(const QString& v) { _name = v; }
    HeightMapDescriptor();

    //from descriptor to actual object
    QSharedPointer<utils::NoiseMap> makeNoiseMap() {
        auto p = new utils::NoiseMap();
        QSharedPointer<utils::NoiseMap> sp; sp.reset(p);
        return sp;
    }
};

#endif // HEIGHTMAPDESCRIPTOR_H