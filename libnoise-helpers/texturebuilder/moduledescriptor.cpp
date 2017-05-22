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


#include "moduledescriptor.h"

ModuleDescriptor::ModuleDescriptor()
{
    this->_src1="";
    this->_src2="";
    this->_src3="";
    this->_src4="";
}

void ModuleDescriptor::fromJson(const QJsonObject& json) {
    if (!json["type"].isNull() && !json["type"].isUndefined())
        _moduleType = json["type"].toString();
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
    if (!json["disp"].isNull() && !json["disp"].isUndefined())
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
    if (!json["ctl"].isNull() && !json["ctl"].isUndefined())
        _ctl = json["ctl"].toString();
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
        _value = json["value"].toDouble();

}

void ModuleDescriptor::toJson(QJsonObject& json) {
    json["type"] = _moduleType;
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
    json["ctl"] = _ctl;
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


//static ModuleDescriptor createRandom();


ModuleDescriptor& ModuleDescriptor::connectModules()
{
    QSharedPointer<Module> currentMod;
    Module * pModule = nullptr;
    if (_name != "" && _modules.contains(_name)) {
        currentMod =_modules[_name];
        pModule = currentMod.data();
    }
    if (_moduleType != "Displace") {
    if (_src1 != "" && _modules.contains(_src1))
        currentMod.data()->SetSourceModule(0,*_modules[_src1].data());
    if (_src2 != "" && _modules.contains(_src2))
        currentMod.data()->SetSourceModule(1,*_modules[_src2].data());
    if (_src3 != "" && _modules.contains(_src3))
        currentMod.data()->SetSourceModule(2,*_modules[_src3].data());
    if (_src4 != "" && _modules.contains(_src4))
        currentMod.data()->SetSourceModule(3,*_modules[_src4].data());
    }
    if (this->_moduleType == "Displace") {
        auto mod = static_cast<Displace*>(pModule);
        mod->SetSourceModule(0,*_modules[_src1].data());
        mod->SetDisplaceModules(
            *_modules[_src2].data(),
            *_modules[_src3].data(),
            *_modules[_src4].data()
        );
    }
    if (_ctl != "" && _modules.contains(_ctl)) {
        if (this->_moduleType == "Blend") {
            auto mod = static_cast<Blend*>(pModule);
            mod->SetControlModule(*_modules[_ctl].data());
        }
        if (this->_moduleType == "Select") {
            auto mod = static_cast<Select*>(pModule);
            mod->SetControlModule(*_modules[_ctl].data());
        }
    }
    //this->c_currentModule = currentMod.data();
    return *this;
}

//from descriptor to actual object
QSharedPointer<Module> ModuleDescriptor::makeModule() {
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
    if (_moduleType=="Turbulence") return makeTurbulence();
    if (_moduleType=="Add") return makeAdd();
    if (_moduleType=="Max") return makeMax();
    if (_moduleType=="Min") return makeMin();
    if (_moduleType=="Multiply") return makeMultiply();
    if (_moduleType=="Power") return makePower();
    if (_moduleType=="Blend") return makeBlend();
    if (_moduleType=="Select") return makeSelect();
    if (_moduleType=="Displace") return makeDisplace();
    if (_moduleType=="RotatePoint") return makeRotatePoint();
    if (_moduleType=="ScalePoint") return makeScalePoint();
    if (_moduleType=="TranslatePoint") return makeTranslatePoint();
    return makePerlin();
}

//{ "module":"Billow" , "mame": "mod_name" , "seed": 0.0 , "freq": 0.0 , "lac": 0.0 , "pers": 0.0 ,
QSharedPointer<Module> ModuleDescriptor::makeBillow() {
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
QSharedPointer<Module> ModuleDescriptor::makeCheckerboard() {
    Checkerboard* m = new Checkerboard();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "module":"Const" , "name": "mod_name", "value" : 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeConst() {
    Const* m = new Const();
    m->SetConstValue(this->_value);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "module":"Cylinders" , "name": "mod_name" , "Freq": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeCylinders() {
    Cylinders* m = new Cylinders();
    m->SetFrequency(_freq);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Perlin" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Lac": 0.0 , "Pers": 0.0 , "Oct": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makePerlin() {
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
QSharedPointer<Module> ModuleDescriptor::makeRidgedMulti() {
    RidgedMulti* m = new RidgedMulti();
    m->SetLacunarity(_lac);
    m->SetFrequency(_freq);
    m->SetOctaveCount(_oct);
    m->SetSeed(_seed);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Spheres" , "Name": "mod_name" , "Freq": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeSpheres() {
    Spheres* m = new Spheres();
    m->SetFrequency(_freq);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Voronoi" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Displ": 0.0 , "EnableDist": true },
QSharedPointer<Module> ModuleDescriptor::makeVoronoi() {
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
QSharedPointer<Module> ModuleDescriptor::makeAbs() {
    Abs* m = new Abs();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Clamp" , "Name": "mod_name" , "Src1": "mod_name" , "Lbound": 0.0 , "Ubound": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeClamp() {
    Clamp* m = new Clamp();
    m->SetBounds(_lBound, _uBound);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Curve" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] },
QSharedPointer<Module> ModuleDescriptor::makeCurve() {
    Curve* m = new Curve();
    std::tuple<double,double> t;
    foreach (t, _cPoints) {
        m->AddControlPoint(std::get<0>(t),std::get<1>(t));
    }
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


//{ "Module":"Exponent" , "Name": "mod_name" , "Src1": "mod_name" , "Exp": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeExponent() {
    Exponent* m = new Exponent();
    m->SetExponent(this->_exp);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Invert" , "Name": "mod_name" , "Src1": "mod_name" },
QSharedPointer<Module> ModuleDescriptor::makeInvert() {
    Invert* m = new Invert();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


//{ "Module":"ScaleBias" , "Name": "mod_name" , "Src1": "mod_name" , "Bias": 0.0 , "Scale": 0.0 },
QSharedPointer<Module> ModuleDescriptor::makeScaleBias() {
    ScaleBias* m = new ScaleBias();
    m->SetBias(_bias);
    m->SetScale(_scale);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Terrace" , "Name": "mod_name" , "Src1": "mod_name" , "Cpoints": [[0.0,1.0],[1.0,1.1]] , "Invert": true },
QSharedPointer<Module> ModuleDescriptor::makeTerrace() {
    Terrace* m = new Terrace();
    std::tuple<double,double> t;
    foreach (t, _cPoints) {
        m->AddControlPoint(std::get<0>(t));
        //m->AddControlPoint<(std::get<0>(t),std::get<1>(t));

    }
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

//{ "Module":"Turbulence" , "Name": "mod_name" , "Seed": 0.0 , "Freq": 0.0 , "Src1": "mod_name" , "Pow": 0.0 , "Rough": 0.0 }]
QSharedPointer<Module> ModuleDescriptor::makeTurbulence() {
    Turbulence* m = new Turbulence();
    m->SetSeed(_seed);
    m->SetFrequency(_freq);
    m->SetPower(_pow);
    m->SetRoughness(_rough);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

QSharedPointer<Module> ModuleDescriptor::makeAdd() {
    Add* m = new Add();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

QSharedPointer<Module> ModuleDescriptor::makeMax() {
    Max* m = new Max();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

QSharedPointer<Module> ModuleDescriptor::makeMin() {
    Min* m = new Min();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}

QSharedPointer<Module> ModuleDescriptor::makeMultiply (){
    Multiply* m = new Multiply();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makePower (){
    Power* m = new Power();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makeBlend (){
    Blend* m = new Blend();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makeSelect (){
    Select* m = new Select();
    m->SetBounds(_lBound,_uBound);
    m->SetEdgeFalloff(_value);
    QSharedPointer<Module> p; p.reset(m);

    return p;
}

QSharedPointer<Module> ModuleDescriptor::makeDisplace() {
    Displace* m = new Displace();
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makeRotatePoint() {
    RotatePoint* m = new RotatePoint();
    m->SetAngles(_x,_y,_z);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makeScalePoint() {
    ScalePoint* m = new ScalePoint();
    m->SetXScale(_x);
    m->SetYScale(_y);
    m->SetZScale(_z);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


QSharedPointer<Module> ModuleDescriptor::makeTranslatePoint() {
    TranslatePoint* m = new TranslatePoint();
    m->SetXTranslation(_x);
    m->SetYTranslation(_y);
    m->SetZTranslation(_z);
    QSharedPointer<Module> p; p.reset(m);
    return p;
}


