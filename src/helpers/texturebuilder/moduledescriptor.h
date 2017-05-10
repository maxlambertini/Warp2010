#ifndef MODULEDESCRIPTOR_H
#define MODULEDESCRIPTOR_H

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>

/*
[{ "Module":"Billow" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Pers": 0.0 , "Oct": 0.0 },
{ "Module":"Checkerboard" , "Name": "mod_name" },
{ "Module":"Const" , "Name": "mod_name" },
{ "Module":"Cylinders" , "Name": "mod_name" , "Freq": 0.0 },
{ "Module":"Perlin" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Pers": 0.0 , "Oct": 0.0 },
{ "Module":"RidgedMulti" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Oct": 0.0 },
{ "Module":"Spheres" , "Name": "mod_name" , "Freq": 0.0 },
{ "Module":"Voronoi" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Displ": 0.0 , "EnableDist": true },
{ "Module":"Abs" , "Name": "mod_name" , "Src1": "mod_name" },
{ "Module":"Clamp" , "Name": "mod_name" , "Src1": "mod_name" , "Lbound": 0.0 , "Ubound": 0.0 },
{ "Module":"Curve" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] },
{ "Module":"Exponent" , "Name": "mod_name" , "Src1": "mod_name" , "Exp": 0.0 },
{ "Module":"Invert" , "Name": "mod_name" , "Src1": "mod_name" },
{ "Module":"ScaleBias" , "Name": "mod_name" , "Src1": "mod_name" , "Bias": 0.0 , "Scale": 0.0 },
{ "Module":"Terrace" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] , "Invert": true },
{ "Module":"Add" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" },
{ "Module":"Max" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" },
{ "Module":"Min" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" },
{ "Module":"Multiply" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" },
{ "Module":"Power" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" },
{ "Module":"Blend" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" , "Src3": "mod_name" },
{ "Module":"Select" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" , "Src3": "mod_name" , "Lbound": 0.0 , "Ubound": 0.0 },
{ "Module":"Displace" , "Name": "mod_name" , "Src1": "mod_name" , "Src2": "mod_name" , "Src3": "mod_name" , "Src4": "mod_name" },
{ "Module":"Rotate" , "Name": "mod_name" , "Src1": "mod_name" , "x": 0.0 , "y": 0.0 , "z": 0.0 },
{ "Module":"ScalePoint" , "Name": "mod_name" , "Src1": "mod_name" , "x": 0.0 , "y": 0.0 , "z": 0.0 },
{ "Module":"TranslatePoint" , "Name": "mod_name" , "Src1": "mod_name" , "x": 0.0 , "y": 0.0 , "z": 0.0 },
{ "Module":"Turbulence" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Src1": "mod_name" , "Pow": 0.0 , "Rough": 0.0 }]
*/


class ModuleDescriptor : QObject
{
    Q_OBJECT

    QString _name;
    int _seed;
    double _freq;
    double _lac;
    double _pers;
    double _oct;
    double _displ;
    bool _enableDist;
    QString _src1;
    QString _src2;
    QString _src3;
    QString _src4;
    double _lBound;
    double _uBound;
    QVector<std::tuple<double,double>> _cPoints;
    double _exp;
    double _bias;
    double _scale;
    bool _invert;
    double _x;
    double _y;
    double _z;
    double _pow;
    double _rough;

public:
    //getters
    QString& name() { return _name; }
    int seed() { return _seed; }
    double freq() { return _freq; }
    double lac() { return _lac; }
    double pers() { return _pers; }
    double oct() { return _oct; }
    double displ() { return _displ; }
    bool enableDist() { return _enableDist; }
    QString& src1() { return _src1; }
    QString& src2() { return _src2; }
    QString& src3() { return _src3; }
    QString& src4() { return _src4; }
    double lBound() { return _lBound; }
    double uBound() { return _uBound; }
    QVector<std::tuple<double,double>>& cPoints() { return _cPoints; }
    double exp() { return _exp; }
    double bias() { return _bias; }
    double scale() { return _scale; }
    bool invert() { return _invert; }
    double x() { return _x; }
    double y() { return _y; }
    double z() { return _z; }
    double pow() { return _pow; }
    double rough() { return _rough; }

    //setters
    void setName(QString v) { _name = v ; }
    void setSeed(int v) { _seed = v ; }
    void setFreq(double v) { _freq = v ; }
    void setLac(double v) { _lac = v ; }
    void setPers(double v) { _pers = v ; }
    void setOct(double v) { _oct = v ; }
    void setDispl(double v) { _displ = v ; }
    void setEnabledist(bool v) { _enableDist = v ; }
    void setSrc1(QString& v) { _src1 = v ; }
    void setSrc2(QString& v) { _src2 = v ; }
    void setSrc3(QString& v) { _src3 = v ; }
    void setSrc4(QString& v) { _src4 = v ; }
    void setLbound(double v) { _lBound = v ; }
    void setUbound(double v) { _uBound = v ; }
    void setCpoints(const QVector<std::tuple<double,double>>& v) { _cPoints = v ; }
    void setExp(double v) { _exp = v ; }
    void setBias(double v) { _bias = v ; }
    void setScale(double v) { _scale = v ; }
    void setInvert(bool v) { _invert = v ; }
    void setX(double v) { _x = v ; }
    void setY(double v) { _y = v ; }
    void setZ(double v) { _z = v ; }
    void setPow(double v) { _pow = v ; }
    void setRough(double v) { _rough = v ; }

    void fromJson(const QJsonObject& json) {
        if (!json["name"].isNull() && !json["name"].isUndefined())
            _name = json["name"].toString();
        if (!json["seed"].isNull() && !json["seed"].isUndefined())
            _seed = json["seed"].toInt();
        if (!json["freq"].isNull() && !json["freq"].isUndefined())
            _freq = json["freq"].toDouble();
        if (!json["lac"].isNull() && !json["lac"].isUndefined())
            _lac = json["lac"].toDouble();
        if (!json["pers"].isNull() && !json["pers"].isUndefined())
            _pers = json["pers"].toDouble();
        if (!json["oct"].isNull() && !json["oct"].isUndefined())
            _oct = json["oct"].toDouble();
        if (!json["displ"].isNull() && !json["displ"].isUndefined())
            _displ = json["displ"].toDouble();
        if (!json["enableDist"].isNull() && !json["enableDist"].isUndefined())
            _enableDist = json["enableDist"].toBool();
        if (!json["src1"].isNull() && !json["src1"].isUndefined())
            _src1 = json["src1"].toString();
        if (!json["src2"].isNull() && !json["src2"].isUndefined())
            _src2 = json["src2"].toString();
        if (!json["src3"].isNull() && !json["src3"].isUndefined())
            _src3 = json["src3"].toString();
        if (!json["src4"].isNull() && !json["src4"].isUndefined())
            _src4 = json["src4"].toString();
        if (!json["lBound"].isNull() && !json["lBound"].isUndefined())
            _lBound = json["lBound"].toDouble();
        if (!json["uBound"].isNull() && !json["uBound"].isUndefined())
            _uBound = json["uBound"].toDouble();
        //if (!json["cPoints"].isNull() && !json["cPoints"].isUndefined())  _cPoints = json["cPoints"].toQVector<std::tuple<double,double>>();
        if (!json["exp"].isNull() && !json["exp"].isUndefined())
            _exp = json["exp"].toDouble();
        if (!json["bias"].isNull() && !json["bias"].isUndefined())
            _bias = json["bias"].toDouble();
        if (!json["scale"].isNull() && !json["scale"].isUndefined())
            _scale = json["scale"].toDouble();
        if (!json["invert"].isNull() && !json["invert"].isUndefined())
            _invert = json["invert"].toBool();
        if (!json["x"].isNull() && !json["x"].isUndefined())
            _x = json["x"].toDouble();
        if (!json["y"].isNull() && !json["y"].isUndefined())
            _y = json["y"].toDouble();
        if (!json["z"].isNull() && !json["z"].isUndefined())
            _z = json["z"].toDouble();
        if (!json["pow"].isNull() && !json["pow"].isUndefined())
            _pow = json["pow"].toDouble();
        if (!json["rough"].isNull() && !json["rough"].isUndefined())
            _rough = json["rough"].toDouble();

    }

    void toJson(QJsonObject& json) {
        json["name"] = _name;
        json["seed"] = _seed;
        json["freq"] = _freq;
        json["lac"] = _lac;
        json["pers"] = _pers;
        json["oct"] = _oct;
        json["displ"] = _displ;
        json["enableDist"] = _enableDist;
        json["src1"] = _src1;
        json["src2"] = _src2;
        json["src3"] = _src3;
        json["src4"] = _src4;
        json["lBound"] = _lBound;
        json["uBound"] = _uBound;
        //json["cPoints"] = _cPoints;
        json["exp"] = _exp;
        json["bias"] = _bias;
        json["scale"] = _scale;
        json["invert"] = _invert;
        json["x"] = _x;
        json["y"] = _y;
        json["z"] = _z;
        json["pow"] = _pow;
        json["rough"] = _rough;
    }

    ModuleDescriptor();
};

#endif // MODULEDESCRIPTOR_H
