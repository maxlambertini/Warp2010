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

class ModuleDescriptor : public QObject
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

    void fromJson(const QJsonObject& json);
    void toJson(QJsonObject& json);

    ModuleDescriptor();

    //static ModuleDescriptor createRandom();

    bool mustConnect() { return _src1 != "" && _src2 != "" && _src3 != "" && _src4 != ""; }

    ModuleDescriptor& connectModules();
    QSharedPointer<Module> makeModule() ;

    //{ "module":"Billow" , "mame": "mod_name" , "seed": 0.0 , "freq": 0.0 , "lac": 0.0 , "pers": 0.0 ,
    QSharedPointer<Module> makeBillow();
    //{ "module":"Checkerboard" , "name": "mod_name" },
    QSharedPointer<Module> makeCheckerboard();
    //{ "module":"Const" , "name": "mod_name", "value" : 0.0 },
    QSharedPointer<Module> makeConst();
    //{ "module":"Cylinders" , "name": "mod_name" , "Freq": 0.0 },
    QSharedPointer<Module> makeCylinders();
    //{ "Module":"Perlin" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Pers": 0.0 , "Oct": 0.0 },
    QSharedPointer<Module> makePerlin();
    //{ "Module":"RidgedMulti" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Oct": 0.0 },
    QSharedPointer<Module> makeRidgedMulti();
    //{ "Module":"Spheres" , "Name": "mod_name" , "Freq": 0.0 },
    QSharedPointer<Module> makeSpheres();
    //{ "Module":"Voronoi" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Displ": 0.0 , "EnableDist": true },
    QSharedPointer<Module> makeVoronoi();
    //{ "Module":"Abs" , "Name": "mod_name" , "Src1": "mod_name" },
    QSharedPointer<Module> makeAbs();
    //{ "Module":"Clamp" , "Name": "mod_name" , "Src1": "mod_name" , "Lbound": 0.0 , "Ubound": 0.0 },
    QSharedPointer<Module> makeClamp();
    //{ "Module":"Curve" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] },
    QSharedPointer<Module> makeCurve();
    //{ "Module":"Exponent" , "Name": "mod_name" , "Src1": "mod_name" , "Exp": 0.0 },
    QSharedPointer<Module> makeExponent();
    //{ "Module":"Invert" , "Name": "mod_name" , "Src1": "mod_name" },
    QSharedPointer<Module> makeInvert();
    //{ "Module":"ScaleBias" , "Name": "mod_name" , "Src1": "mod_name" , "Bias": 0.0 , "Scale": 0.0 },
    QSharedPointer<Module> makeScaleBias();
    //{ "Module":"Terrace" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] , "Invert": true },
    QSharedPointer<Module> makeTerrace();



};

#endif // MODULEDESCRIPTOR_H
