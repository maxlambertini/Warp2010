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

enum class NoiseMapBuilderType {
    CYLINDER,
    PLANE,
    SPHERE
};

class NoiseMapBuilderDescriptor : public QObject
{
    Q_OBJECT

    QMap<QString,QSharedPointer<Module>> _modules;
    std::tuple<int,int> _size;
    std::tuple<double,double,double,double> _bounds;
    QString _src1;
    QSharedPointer<Module> _currentModule;
    QSharedPointer<utils::NoiseMap> _map;
    NoiseMapBuilderType _builderType;

public:
    explicit NoiseMapBuilderDescriptor(QObject *parent = 0);
    void g() {
        utils::NoiseMapBuilderPlane p;
    }

    QMap<QString, QSharedPointer<Module>>& modules() { return _modules; }
    void setModules(const QMap<QString, QSharedPointer<Module>>& m) { _modules = m; }

    int getSizeX() { return std::get<0>(_size); }
    int getSizeY() { return std::get<1>(_size); }

    void setSize (int x, int y ) { _size = std::tuple<int,int>(x,y); }
    void setBounds (double south = -90.0, double north = 90.0, double west = -180.0, double east = 180.0) {
        _bounds = std::tuple<double,double,double,double>(south,north,west,east);
    }

    NoiseMapBuilderType builderType() {return  _builderType ; }
    void setBuilderType (NoiseMapBuilderType t) { _builderType = t; }

    QSharedPointer<Module> currentModule() { return _currentModule; }
    void setCurrentModule(QSharedPointer<Module> m) { _currentModule = m; }

    QString& sourceModule() { return _src1; }
    void setSourceModule(const QString& src) { _src1 = src; }

    void toJson(QJsonObject& json) {

    }

    void fromJson(QJsonObject& json) {

    }


signals:

public slots:
};

#endif // NOISEMAPBUILDERDESCRIPTOR_H
