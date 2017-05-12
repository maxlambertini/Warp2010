#ifndef NOISEMAPBUILDERDESCRIPTOR_H
#define NOISEMAPBUILDERDESCRIPTOR_H

#include <QObject>

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>



/*
 * utils::NoiseMapBuilderSphere heightMapBuilder;
    heightMapBuilder.SetDestSize (_sizeX, _sizeY);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);

    heightMapBuilder.SetSourceModule (scaleBase);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.Build();

    heightMapBuilder.SetSourceModule (expBase);
    heightMapBuilder.SetDestNoiseMap (heightMapPeak);
    heightMapBuilder.Build();
    */


//{ "type"="cylinder|plane|sphere","size:=[w,h], "bounds":[N,S,W,E], "src1":"source_mod","dest":"height_map", "seamless:"seamless":true}

using namespace noise::module;

class NoiseMapBuilderDescriptor : public QObject
{
    Q_OBJECT

    QMap<QString,QSharedPointer<Module>> _modules;
    std::tuple<int,int> _size;
    std::tuple<double,double,double,double> _bounds;
    QString _src1;
    QSharedPointer<Module> _currentModule;
    QSharedPointer<utils::NoiseMap> _map;

public:
    explicit NoiseMapBuilderDescriptor(QObject *parent = 0);
    void g() {
        utils::NoiseMapBuilderPlane p;
    }

signals:

public slots:
};

#endif // NOISEMAPBUILDERDESCRIPTOR_H
