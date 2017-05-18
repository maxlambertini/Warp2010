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
    QMap<QString,QSharedPointer<utils::NoiseMap>> _noiseMaps;
    QMap<QString,QSharedPointer<utils::NoiseMapBuilder>> _noiseMapBuilders;
    std::tuple<int,int> _size = std::tuple<int,int>(1024,512);
    std::tuple<double,double,double,double> _bounds = std::tuple<double,double,double,double>(-90.0,90.0,-180.0,180.0);
    QString _src1 = "perlin1";
    QString _name = "builder1";
    QString _dest = "heightmap1";
    QSharedPointer<Module> _currentModule;
    QSharedPointer<utils::NoiseMapBuilder> _currentNoiseMapBuilder;
    QSharedPointer<utils::NoiseMap> _currentNoiseMap;
    NoiseMapBuilderType _builderType;
    bool _seamless;

    QSharedPointer<utils::NoiseMapBuilder> makeCylinderBuilder();
    QSharedPointer<utils::NoiseMapBuilder> makePlaneBuilder();
    QSharedPointer<utils::NoiseMapBuilder> makeSphereBuilder();

public:

    NoiseMapBuilderDescriptor& connectSrcModule()
    {
        if (_src1 != "" && _modules.contains(_src1)) {
            auto mod = _modules[_src1];
            _currentModule = mod;
            _currentNoiseMapBuilder.data()->SetSourceModule(*mod);
        }
        return *this;
    }

    explicit NoiseMapBuilderDescriptor(QObject *parent = 0);

    const QString& name() { return _name; }
    void setName(const QString& n) {_name = n; }

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

    bool seamless() { return _seamless; }
    bool setSeamless(bool v) { _seamless = v; }

    void fromJson(const QJsonObject& json) {
        _dest = json["dest"].toString();
        _name = json["name"].toString();
        _src1 = json["src1"].toString();
        _seamless = json["seamless"].toBool();
        auto sType = json["type"].toString();
        _builderType = NoiseMapBuilderType::SPHERE;
        if (sType ==  "plane") _builderType = NoiseMapBuilderType::PLANE;
        if (sType ==  "cylinder") _builderType = NoiseMapBuilderType::CYLINDER;
        auto a = json["size"].toArray();
        _size = std::tuple<int,int>(a[0].toInt(),a[1].toInt());
        auto a1 = json["bounds"].toArray();
        _bounds = std::tuple<double,double,double,double>(
                a1[0].toDouble(),
                a1[1].toDouble(),
                a1[2].toDouble(),
                a1[3].toDouble()
                );
    }

    void toJson(QJsonObject& json) {
        //{ name="name", "type"="cylinder|plane|sphere","size:=[w,h], "bounds":[N,S,W,E], "src1":"source_mod","dest":"height_map",
        //"seamless:"seamless":true}
        switch (_builderType) {
            case NoiseMapBuilderType::CYLINDER:
                json["type"] = "cylinder";
                break;
            case NoiseMapBuilderType::PLANE:
                json["type"] = "plane";
                break;
            case NoiseMapBuilderType::SPHERE:
                json["type"] = "sphere";
                break;
            default:
                json["type"] = "sphere";
                break;
        }
        json["name"] = _name;
        json["dest"] = _dest;
        json["src1"] = _src1;
        json["seamless"] = _seamless;
        QJsonArray a;
        a.append(std::get<0>(_size));
        a.append(std::get<1>(_size));
        json["size"] = a;
        QJsonArray a1;
        a1.append(std::get<0>(_bounds));
        a1.append(std::get<1>(_bounds));
        a1.append(std::get<2>(_bounds));
        a1.append(std::get<3>(_bounds));
        json["bounds"] = a1;
    }

    QSharedPointer<utils::NoiseMapBuilder> makeBuilder();

signals:

public slots:
};

#endif // NOISEMAPBUILDERDESCRIPTOR_H
