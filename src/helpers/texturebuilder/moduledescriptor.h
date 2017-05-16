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



#ifndef MODULEDESCRIPTOR_H
#define MODULEDESCRIPTOR_H

#include <QObject>
#include <QtCore>
#include <tuple>
#include <noiseutils.h>
#include <ssg_structures.h>

/*
[
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

using namespace noise;
using namespace noise::module;

class ModuleDescriptor : QObject
{
    Q_OBJECT

    QString _moduleType = "Perlin";
    QString _name = "perlin1";
    int _seed = SSGX::dn(999999);
    double _freq = 2.50;
    double _lac = 1.20;
    double _pers = 0.50 ;
    int _oct = 6;
    double _disp;
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
    double _value;

    //reference to a Map containing loaded modules
    QMap<QString, QSharedPointer<Module>> _modules;

public:
    //getters
    QString& moduleType() { return _moduleType; }
    QString& name() { return _name; }
    int seed() { return _seed; }
    double freq() { return _freq; }
    double lac() { return _lac; }
    double pers() { return _pers; }
    int oct() { return _oct; }
    double displ() { return _disp; }
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
    double value() { return _value; }

    const QMap<QString, QSharedPointer<Module>>& modules() { return _modules; }

    //setters
    void setModuleType (QString v) { _moduleType = v; }
    void setName(QString v) { _name = v ; }
    void setSeed(int v) { _seed = v ; }
    void setFreq(double v) { _freq = v ; }
    void setLac(double v) { _lac = v ; }
    void setPers(double v) { _pers = v ; }
    void setOct(int v) { _oct = v ; }
    void setDispl(double v) { _disp = v ; }
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
    void setValue(double v) { _value = v ; }

    void setModules(const QMap<QString, QSharedPointer<Module>>& m) {_modules = m; }

    void fromJson(const QJsonObject& json) {
        if (!json["module"].isNull() && !json["module"].isUndefined())
            _name = json["module"].toString();
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
            _oct = json["oct"].toInt();
        if (!json["displ"].isNull() && !json["displ"].isUndefined())
            _disp = json["disp"].toDouble();
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
        if (!json["lbound"].isNull() && !json["lbound"].isUndefined())
            _lBound = json["lbound"].toDouble();
        if (!json["ubound"].isNull() && !json["ubound"].isUndefined())
            _uBound = json["ubound"].toDouble();
        if (!json["cpoints"].isNull() && !json["cpoints"].isUndefined()) {
            QJsonArray ja = json["cpoints"].toArray();
            for (auto x = 0; x < ja.size(); ++x ) {
                QJsonArray ox = ja[x].toArray();
                _cPoints.append(std::tuple<double,double>(ox[0].toInt(),ox[1].toInt())  );
            }
        }
        //    _cPoints = json["cPoints"].toQVector<std::tuple<double,double>>();
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
        if (!json["value"].isNull() && !json["value"].isUndefined())
            _rough = json["value"].toDouble();

    }

    void toJson(QJsonObject& json) {
        json["module"] = _moduleType;
        json["name"] = _name;
        json["seed"] = _seed;
        json["freq"] = _freq;
        json["lac"] = _lac;
        json["pers"] = _pers;
        json["oct"] = _oct;
        json["disp"] = _disp;
        json["enableDist"] = _enableDist;
        json["src1"] = _src1;
        json["src2"] = _src2;
        json["src3"] = _src3;
        json["src4"] = _src4;
        json["lbound"] = _lBound;
        json["ubound"] = _uBound;

        QJsonArray a;
        std::tuple<double,double> tp;
        foreach (tp, _cPoints) {
            QJsonArray o;
            o.append(std::get<0>(tp));
            o.append(std::get<1>(tp));
            a.append(o);
        }
        json["cpoints"] = a;
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
        json["value"] = _value;
    }

    ModuleDescriptor();

    //static ModuleDescriptor createRandom();

    bool mustConnect() { return _src1 != "" && _src2 != "" && _src3 != "" && _src4 != ""; }

    Module& connectModules(Module& in)
    {
        if (_src1 != "" && _modules.contains(_src1))
            in.SetSourceModule(0,*_modules[_src1].data());
        if (_src2 != "" && _modules.contains(_src2))
            in.SetSourceModule(1,*_modules[_src2].data());
        if (_src3 != "" && _modules.contains(_src3))
            in.SetSourceModule(2,*_modules[_src3].data());
        if (_src4 != "" && _modules.contains(_src4))
            in.SetSourceModule(3,*_modules[_src4].data());
        return in;
    }

    QSharedPointer<Module> makeModule() {
        //"Oct": 0.0 },
        if (_moduleType=="Billow") return makeBillow();
        if (_moduleType=="Checkerboard") return makeCheckerboard();
        if (_moduleType=="Const") return makeConst();
        if (_moduleType=="Cylinders") return makeCylinders();
        if (_moduleType=="Perlin") return makePerlin();
        if (_moduleType=="RidgedMulti") return makeRidgedMulti();
        if (_moduleType=="Spheres") return makeSpheres();
        if (_moduleType=="Voronoi") return makeVoronoi();
        if (_moduleType=="Abs") return makeAbs();
        if (_moduleType=="Clamp") return makeClamp();
        if (_moduleType=="Curve") return makeCurve();
        if (_moduleType=="Exponent") return makeExponent();
        if (_moduleType=="Invert") return makeInvert();
        if (_moduleType=="ScaleBias") return makeScaleBias();
        if (_moduleType=="Terrace") return makeTerrace();
        return makePerlin();
    }

    //{ "module":"Billow" , "mame": "mod_name" , "seed": 0.0 , "freq": 0.0 , "lac": 0.0 , "pers": 0.0 ,
    QSharedPointer<Module> makeBillow() {
        Billow* m = new Billow();
        m->SetSeed(_seed);
        m->SetFrequency(_freq);
        m->SetLacunarity(_lac);
        m->SetPersistence(_pers);
        m->SetOctaveCount(_oct);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "module":"Checkerboard" , "name": "mod_name" },
    QSharedPointer<Module> makeCheckerboard() {
        Checkerboard* m = new Checkerboard();
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "module":"Const" , "name": "mod_name", "value" : 0.0 },
    QSharedPointer<Module> makeConst() {
        Const* m = new Const();
        m->SetConstValue(this->_value);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "module":"Cylinders" , "name": "mod_name" , "Freq": 0.0 },
    QSharedPointer<Module> makeCylinders() {
        Cylinders* m = new Cylinders();
        m->SetFrequency(_freq);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Perlin" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Pers": 0.0 , "Oct": 0.0 },
    QSharedPointer<Module> makePerlin() {
        Perlin* m = new Perlin();
        m->SetLacunarity(_lac);
        m->SetFrequency(_freq);
        m->SetOctaveCount(_oct);
        m->SetPersistence(_pers);
        m->SetSeed(_seed);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"RidgedMulti" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Oct": 0.0 },
    QSharedPointer<Module> makeRidgedMulti() {
        RidgedMulti* m = new RidgedMulti();
        m->SetLacunarity(_lac);
        m->SetFrequency(_freq);
        m->SetOctaveCount(_oct);
        m->SetSeed(_seed);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Spheres" , "Name": "mod_name" , "Freq": 0.0 },
    QSharedPointer<Module> makeSpheres() {
        Spheres* m = new Spheres();
        m->SetFrequency(_freq);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Voronoi" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Displ": 0.0 , "EnableDist": true },
    QSharedPointer<Module> makeVoronoi() {
        Voronoi* m = new Voronoi();
        m->SetFrequency(_freq);
        m->SetDisplacement(_disp);
        m->SetSeed(this->_seed);
        m->EnableDistance(_enableDist);
        QSharedPointer<Module>p;
        p.reset(m);
        return p;
    }

    //{ "Module":"Abs" , "Name": "mod_name" , "Src1": "mod_name" },
    QSharedPointer<Module> makeAbs() {
        Abs* m = new Abs();
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Clamp" , "Name": "mod_name" , "Src1": "mod_name" , "Lbound": 0.0 , "Ubound": 0.0 },
    QSharedPointer<Module> makeClamp() {
        Clamp* m = new Clamp();
        m->SetBounds(_lBound, _uBound);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Curve" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] },
    QSharedPointer<Module> makeCurve() {
        Curve* m = new Curve();
        std::tuple<double,double> t;
        foreach (t, _cPoints) {
            m->AddControlPoint(std::get<0>(t),std::get<1>(t));
        }
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }


    //{ "Module":"Exponent" , "Name": "mod_name" , "Src1": "mod_name" , "Exp": 0.0 },
    QSharedPointer<Module> makeExponent() {
        Exponent* m = new Exponent();
        m->SetExponent(this->_exp);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Invert" , "Name": "mod_name" , "Src1": "mod_name" },
    QSharedPointer<Module> makeInvert() {
        Invert* m = new Invert();
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }


    //{ "Module":"ScaleBias" , "Name": "mod_name" , "Src1": "mod_name" , "Bias": 0.0 , "Scale": 0.0 },
    QSharedPointer<Module> makeScaleBias() {
        ScaleBias* m = new ScaleBias();
        m->SetBias(_bias);
        m->SetScale(_scale);
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }

    //{ "Module":"Terrace" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] , "Invert": true },
    QSharedPointer<Module> makeTerrace() {
        Terrace* m = new Terrace();
        std::tuple<double,double> t;
        foreach (t, _cPoints) {
            m->AddControlPoint(std::get<0>(t));
            //m->AddControlPoint<(std::get<0>(t),std::get<1>(t));

        }
        QSharedPointer<Module> p; p.reset(m);
        return p;
    }




};

#endif // MODULEDESCRIPTOR_H
