/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and ap
pearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/

#include <QtCore>
#include "star.h"
#include "stdlib.h"
#include "ssg_structures.h"
#include "helpers/starcodehelper.h"

Star::Star() : QObject()
{
    //_coordinates = new Coordinates(0,0,0);
    _x = 0;
    _y = 0;
    _z = 0;
    _starType = NSStar::stG;
    _starClass = NSStar::scV;
    _starSize = 5.0;
    _magnitude = 4.72;
    _visited = false;
    _sister = false;
    _isReference = false;
    _numGardens = 0;
    _numMarginals = 0;
    _numDesert =0;
    _numGasGiant = 0;
    _starValue.numGarden = 0;
    _starValue.numGlacier= 0;
    _starValue.numPreGarden= 0;
    _starValue.numPostGarden= 0;

    this->setStarData();
}

Star::Star(double radius) : QObject()
{    
    _numGardens = 0;
    _numMarginals = 0;
    _numDesert =0;
    _numGasGiant = 0;
    double dx = SSGX::floatRand() *(2*radius) - radius;
    double dy = SSGX::floatRand() *(2*radius) - radius;
    double dz = SSGX::floatRand() *(2*radius) - radius;
    double star_radius = sqrt( pow(dx,2)+pow(dy,2)+pow(dz,2));
    while (star_radius > radius) {
        dx = SSGX::floatRand() *(2*radius) - radius;
        dy = SSGX::floatRand() *(2*radius) - radius;
        dz = SSGX::floatRand() *(2*radius) - radius;
        star_radius = sqrt( pow(dx,2)+pow(dy,2)+pow(dz,2));
    }

    _isReference = false;


    //_coordinates = new Coordinates(dx,dy,dz);
    _x = dx;
    _y = dy;
    _z = dz;

    /*
    QString starCode;

    int dStep = SSGX::d100();
    if (dStep == 1)
        starCode.append("O");
    else if (dStep == 2)
        starCode.append("B");
    else if (dStep >= 3 && dStep <= 4)
        starCode.append("A");
    else if (dStep >= 5 && dStep <= 8)
        starCode.append("F");
    else if (dStep >= 9 && dStep <= 30)
        starCode.append("G");
    else if (dStep >= 31 && dStep <= 60)
        starCode.append("K");
    else if (dStep >= 61 && dStep <= 94)
        starCode.append("M");
    else if (dStep >= 95)
        starCode.append("d");

     starCode.append(QString("%1").arg(SSGX::d10()-1));



    int lumClass = SSGX::d100();
    if (lumClass == 1)
       starCode.append("II");
    else if (lumClass == 2)
       starCode.append("III");
    else if (lumClass >=3 && lumClass <= 30)
       starCode.append("IV");
    else if (lumClass >=31 && lumClass <= 85)
       starCode.append("V");
    else if (lumClass >=86 && lumClass <= 97)
       starCode.append("VI");
    else if (lumClass >=98)
       starCode.append("VII");

    _visited = false;
    _sister = false;

    //// qDebug() << starCode;
    */


    this->setStarFullType(StarCodeHelper::createStarCode());
    this->setStarData();
    this->_numGardens = 0;
    this->_numMarginals = 0;
    _starValue.numGarden = 0;
    _starValue.numGlacier= 0;
    _starValue.numPreGarden= 0;
    _starValue.numPostGarden= 0;
}

Star::~Star()
{
    this->deleteSolarSystem();
}

void Star::deleteSolarSystem()
{
    Star *s;
    foreach (s, _sisters)
        delete s;
    _planets.clear();
    _sisters.clear();
}

Star::Star(const Star & that) : QObject()
{

    //this->_coordinates = that._coordinates;
    this->_diameter = that._diameter;
    this->_luminosity = that._luminosity;
    this->starName = that.starName;
    this->_starType = that._starType;
    this->_starClass = that._starClass;
    this->_visited = that._visited;
    this->_neighbors = that._neighbors;
    this->_path = that._path;
    this->_magnitude = that._magnitude;
    this->_mass = that._mass;
    this->_solarAge = that._solarAge;
    this->_solarMass = that._solarMass;
    this->_visited = that._visited;
    this->_x = that._x;
    this->_y = that._y;
    this->_z = that._z;
    this->_nx = that._nx;
    this->_ny = that._ny;
    this->_nz = that._nz;
    this->_innerLifeZone = that._innerLifeZone;
    this->_outerLifeZone = that._outerLifeZone;
    this->_idealLifeZone = that._idealLifeZone;
    this->_sister = that._sister;
    this->setStarData();
    this->_numGardens = that._numGardens;
    this->_numMarginals = that._numMarginals;
    this->_numDesert= that._numGasGiant;
    this->_numGasGiant= that._numGasGiant;
    this->_starValue = that._starValue;
}

Star& Star::operator =(const Star & that)
{
    return *this;
}

void Star::changeStartingPath(QVector<int>& subPath)
{
    int subPathCount = subPath.count();
    if (subPathCount == 0)
        return;
    int last = subPath.at(subPathCount-1);
    if (!_path.contains(last) || (_path == subPath))
        return;
    else
    {
        int oldIdx = _path.indexOf(last,0);

        QVector<int> newPath;
        int subPathItem;

        foreach (subPathItem, subPath)
            newPath.append(subPathItem);


        for (int z = oldIdx+1; z < _path.count(); z++) {
            newPath.append(_path.at(z));
        }
        _path.clear();
        foreach (subPathItem, newPath)
            _path.append(subPathItem);


    }
}

void Star::setStarFullType(const QString& type="G2V")
{
    QString temp = type.toUpper().trimmed();
    if (temp == "D")
    {
        this->_starClass = NSStar::scXX;
        this->_starType = NSStar::stDWARF;
        return;
    }
    if (temp.right(1) == "E")
        temp = temp.left(temp.length()-1);

    //first, "Oh, be a fine girl, kiss me";
    QString sType = temp.left(1);
    if (sType=="O") {
        this->_starType = NSStar::stO;
        this->_solarAge = 0.5;
    }
    else if (sType=="B") {
        this->_starType = NSStar::stB;
        this->_solarAge = 0.5;
    }
    else if (sType=="A") {
        this->_starType = NSStar::stA;
        this->_solarAge = 1.0;
    }
    else if (sType=="F") {
        this->_starType = NSStar::stF;
        this->_solarAge = 2.0;
    }
    else if (sType=="G") {
        this->_starType = NSStar::stG;
        this->_solarAge = 5.0;
    }
    else if (sType=="K") {
        this->_starType = NSStar::stK;
        this->_solarAge = 6.5;
    }
    else if (sType=="M") {
        this->_starType = NSStar::stM;
        this->_solarAge = 7.0;
    }
    else {
        this->_starType = NSStar::stDWARF;
        this->_solarAge = 8.0;
    }

    //then, the roman number
    int nRightIdx = temp.length()-1;
    int nLen = 1;
    if (temp.right(1) != "I" && temp.right(1) != "V")
        this->_starClass = NSStar::scXX;
    else {
        while (temp.mid(nRightIdx-1,1) == "I" || temp.mid(nRightIdx-1,1) == "V") {
           nRightIdx--;
            nLen++;
        }
        QString sTempClass = temp.mid(nRightIdx,nLen);
        if (sTempClass=="I")
            this->_starClass = NSStar::scI;
        else if (sTempClass=="II")
            this->_starClass = NSStar::scII;
        else if (sTempClass=="III")
            this->_starClass = NSStar::scIII;
        else if (sTempClass=="IV")
            this->_starClass = NSStar::scIV;
        else if (sTempClass=="V")
            this->_starClass = NSStar::scV;
        else if (sTempClass=="VI")
            this->_starClass = NSStar::scVI;
        else if (sTempClass=="VII")
            this->_starClass = NSStar::scVII;
        else
            this->_starClass = NSStar::scXX;
    }

    //lastly, the size.
    QString sSize = temp.mid(1,1);
    bool bOk;
    double dSize = sSize.toDouble(&bOk);
    if (!bOk) {
        if (this->_starType != NSStar::stDWARF && this->_starClass != NSStar::scXX)
            dSize = 2;
        else
            dSize = 0;
    }
    this->_starSize = dSize;
    this->_starFullType  = type;
    this->_solarAge = this->_solarAge * ( ((float)dSize+.1)/5.0);
    this->setStarData();

}

QString Star::toHtml()
{
    QString sHtml;
    sHtml = "<h1>"+ this->starName + "</h1><hr />\n";

    Planet p;
    foreach (p, this->planets()) {
        sHtml += p.toHtml();
        if (p.satellitesCount() > 0) {
            sHtml += "<ul>\n";
            Planet sat;
            foreach (sat, p.satellites())
                sHtml+= sat.toHtml();
            sHtml += "</ul>";
        }
    }
    return sHtml;

}

void Star::serializePtr(QDataStream &out, Star *p)
{
    if (p != 0) {
        //first, serialize the header,
        QString starH = "STAR!";
        out << starH;

        //then, serialize everything else. Planet collection should be serialized as well.
        out << p->starName;
        out << p->_starSize;
        out << p->_luminosity;
        out << p->_magnitude;
        out << p->_solarMass;
        out << p->_solarAge;
        out << p->_temperature;
        out << p->_diameter;
        out << p->_mass;
        out << p->_distance;
        out << p->_innerLifeZone;
        out << p->_idealLifeZone;
        out << p->_outerLifeZone;
        out << p->_x;
        out << p->_y;
        out << p->_z;
        out << (qint64)p->_nx;
        out << (qint64)p->_ny;
        out << (qint64)p->_nz;
        out << p->_visited;
        out << p->_sister;
        out << p->_isReference;
        out << p->_starFullType;
        out << (qint32)p->_starClass;
        out << (qint32)p->_starType;

        out << p->_neighbors;
        out << p->_path;
        out << p->_planets;
        out << p->_starValue.numChunk;
        out << p->_starValue.numDesert;
        out << p->_starValue.numFailedCore;
        out << p->_starValue.numGarden;
        out << p->_starValue.numGasGiant;
        out << p->_starValue.numGlacier;
        out << p->_starValue.numHotHouse;
        out << p->_starValue.numIceball;
        out << p->_starValue.numPostGarden;
        out << p->_starValue.numPreGarden;
        //QVector<Star *> _sisters;

    }
}

//sort of a named constructor. It's slightly a Ghetto-C technique, but since I started
//with the wrong foot (using Star pointers for my jumpweb since I still fail to wholly
//grok reference tricks when it comes to containers) I have to make do with this named
//constructor to perform serialization. Ah b�in....
Star * Star::deserializeToPtr(QDataStream &in)
{
    //let's check whether we have a star or not here.
    QString starH;
    in >> starH;
    Star *p = 0;
    if (starH == "STAR!") {
        //got it!
        p = new Star();
        // qDebug() << "starting star deserialization";

        //deserialize the rest
        in >> p->starName;
        in >> p->_starSize;
        in >> p->_luminosity;
        in >> p->_magnitude;
        in >> p->_solarMass;
        in >> p->_solarAge;
        in >> p->_temperature;
        in >> p->_diameter;
        in >> p->_mass;
        in >> p->_distance;
        in >> p->_innerLifeZone;
        in >> p->_idealLifeZone;
        in >> p->_outerLifeZone;
        in >> p->_x;
        in >> p->_y;
        in >> p->_z;
        qint64 l;
        in >> l; p->_nx = (long)l;
        in >> l;p->_ny = (long)l;
        in >> l;p->_nz = (long)l;
        in >> p->_visited;
        in >> p->_sister;
        in >> p->_isReference;
        in >> p->_starFullType;
        qint32 q;
        in >> q; p->_starClass = (NSStar::StarClass)q;
        in >> q; p->_starType = (NSStar::StarType)q;

        in >>  p->_neighbors;
        in >>  p->_path;
        in >>  p->_planets;
        p->setNumGardens();
        p->setNumMarginals();
        p->setNumGasGiant();
        p->setNumDesert();

        // qDebug() << "Star " << p->starName << " deserialized, got " <<
       //         p->_neighbors.count() << " neighbors, " <<
        //        p->_path.count() << " jumps from reference " <<
         //       p->_planets.count() << " planets in its solar sys.";
        in >> p->_starValue.numChunk;
        in >> p->_starValue.numDesert;
        in >> p->_starValue.numFailedCore;
        in >> p->_starValue.numGarden;
        in >> p->_starValue.numGasGiant;
        in >> p->_starValue.numGlacier;
        in >> p->_starValue.numHotHouse;
        in >> p->_starValue.numIceball;
        in >> p->_starValue.numPostGarden;
        in >> p->_starValue.numPreGarden;
    }
    return p;
}

void Star::setStarData()
{
    int nSize = (int)this->starSize();
    SSGX::LumMassTempRadius lmtr;

    switch (this->starType())
    {
        case NSStar::stF:
            if (this->starClass() == NSStar::scIV)
                lmtr = SSGX::lmtrF_IV[nSize];
            else
                lmtr = SSGX::lmtrF_V[nSize];
            break;
        case NSStar::stG:
            if (this->starClass() == NSStar::scIV)
                lmtr = SSGX::lmtrG_IV[nSize];
            else
                lmtr = SSGX::lmtrG_V[nSize];
            break;
        case NSStar::stK:
            lmtr = SSGX::lmtrK_V[nSize];
            break;
        case NSStar::stM:
            lmtr = SSGX::lmtrM_V[nSize];
            break;
        default:
            lmtr = SSGX::lmtrM_V[nSize];
            break;
    }
    this->setLuminosity(lmtr.L);
    this->setMass(lmtr.M);
    this->setTemperature(lmtr.T);
    this->setLifeZones();

}


void Star::setNumMarginals() {
    int res = 0;
    QVector<Planet>::iterator ci;
    for (ci = _planets.begin(); ci != _planets.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptPreGarden || p->planetType() == ptPostGarden)
            res++;
        res += p->numMarginals();
    }
    _numMarginals = res;

}

void Star::setNumGardens() {
    int res = 0;
    QVector<Planet>::iterator ci;
    for (ci = _planets.begin(); ci != _planets.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptGarden|| p->planetType() == ptGlacier)
            res++;
        res +=p->numGardens();
    }
    _numGardens = res;

}

void Star::setNumDesert() {
    int res = 0;
    QVector<Planet>::iterator ci, ciSat;
    for (ci = _planets.begin(); ci != _planets.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptDesert)
            res++;
        for (ciSat = p->satellites().begin();  ciSat != p->satellites().end(); ciSat++) {
            Planet *s = ciSat;
            if (s->planetType() == ptDesert)
                res++;
        }
    }
    //qDebug() << "set desert: " << res;
    _numDesert = res;

}

void Star::setNumGasGiant() {
    int res = 0;
    QVector<Planet>::iterator ci, ciSat;
    for (ci = _planets.begin(); ci != _planets.end(); ci++)
    {
        Planet *p = ci;
        if (p->planetType() == ptGasGiant)
            res++;
        for (ciSat = p->satellites().begin();  ciSat != p->satellites().end(); ciSat++) {
            Planet *s = ciSat;
            if (s->planetType() == ptGasGiant)
                res++;
        }
    }
    //qDebug() << "set gas giant: " << res;
    _numGasGiant = res;

}

NSStar::STARVALUE Star::calcStarValue() {
    NSStar::STARVALUE sv;
    sv.numGarden = 0;
    sv.numGlacier = 0;
    sv.numGasGiant = 0;
    sv.numFailedCore = 0;
    sv.numIceball = 0;
    sv.numPostGarden = 0;
    sv.numPreGarden = 0;
    sv.numRockball = 0;
    sv.numDesert= 0;
    sv.numChunk= 0;
    sv.numHotHouse= 0;

    _starValue = sv;
    QVector<Planet>::iterator ci, ciSat;
    for (ci = _planets.begin(); ci != _planets.end(); ci++)
    {
        Planet *p = ci;
        switch (p->planetType()) {
        case ptGarden:
            sv.numGarden++; break;
        case ptGlacier:
            sv.numGlacier++; break;
        case ptPostGarden:
            sv.numPostGarden++; break;
        case ptPreGarden:
            sv.numPreGarden++; break;
        case ptGasGiant:
            sv.numGasGiant++; break;
        case ptHotHouse:
            sv.numHotHouse++; break;
        case ptFailedCore:
            sv.numFailedCore++; break;
        case ptIceball:
            sv.numIceball++; break;
        case ptDesert:
            sv.numDesert++; break;
        case ptRockball:
            sv.numRockball++; break;
        case ptChunk:
            sv.numChunk++; break;
        default:
            sv.numChunk++; break;
        };

        for (ciSat = p->satellites().begin();  ciSat != p->satellites().end(); ciSat++) {
            Planet *s = ciSat;
            switch (s->planetType()) {
            case ptGarden:
                sv.numGarden++; break;
            case ptGlacier:
                sv.numGlacier++; break;
            case ptPostGarden:
                sv.numPostGarden++; break;
            case ptPreGarden:
                sv.numPreGarden++; break;
            case ptGasGiant:
                sv.numGasGiant++; break;
            case ptHotHouse:
                sv.numHotHouse++; break;
            case ptFailedCore:
                sv.numFailedCore++; break;
            case ptIceball:
                sv.numIceball++; break;
            case ptDesert:
                sv.numDesert++; break;
            case ptRockball:
                sv.numRockball++; break;
            case ptChunk:
                sv.numChunk++; break;
            default:
                sv.numChunk++; break;
            };
        }
    }

    _starValue = sv;
    return sv;
}

int Star::diasporaEnvironment() {
    if (_planets.count() == 0)
        return -4;
    NSStar::STARVALUE sv = _starValue;
    float fValue = (float)(sv.numGarden) * 1.5+
                   (float)(sv.numGlacier) * 1.0+
                   (float)(sv.numPreGarden) * 0.75+
                   (float)(sv.numPostGarden) * 0.5+
                   (float)(sv.numHotHouse) * 0.15+
                   (float)(sv.numDesert) * 0.1+
                   (float)(sv.numIceball) * 0.1+
                   (float)(sv.numRockball) * 0.1;
    float nTot = (float)(sv.numGarden+sv.numGlacier);
    fValue += nTot;
    if ((nTot) > 2 && fValue > 8.0)
        return 4;
    if ((nTot) > 1 && fValue > 6.0)
        return 3;
    if ((nTot) > 1 && fValue > 4.0)
        return 2;
    if ((nTot) >= 1 && fValue > 3.0)
        return 1;
    if ((nTot) >= 1 && fValue > 2.0)
        return 0;
    if ((nTot) >= 1 && fValue > 1.5)
        return -1;
    if ((nTot) >= 0 && fValue > 1.0)
        return -2;
    if ((nTot) >= 0 && fValue > 0.3)
        return -3;
    return -4;


}

int Star::diasporaResources() {
    if (_planets.count() == 0)
        return -4;
    NSStar::STARVALUE sv = _starValue;
    float fValue = (float)(sv.numGarden) * 4.0+
                   (float)(sv.numGlacier) * 2.5+
                   (float)(sv.numPreGarden) * 2.0+
                   (float)(sv.numPostGarden) * 1.5+
                   (float)(sv.numHotHouse) * 0.15+
                   (float)(sv.numGasGiant) * 2.0+
                   (float)(sv.numFailedCore) * 0.65+
                   (float)(sv.numChunk) * 0.35+
                   (float)(sv.numDesert) * 0.6+
                   (float)(sv.numIceball) * 0.7+
                   (float)(sv.numRockball) * 1.0;
    if (fValue > 100.0)
        return 4;
    if (fValue > 50.0)
        return 3;
    if (fValue > 25.0)
        return 2;
    if (fValue > 15.0)
        return 1;
    if (fValue > 10.0)
        return 0;
    if (fValue > 7.5)
        return -1;
    if (fValue > 5)
        return -2;
    if (fValue > 3)
        return -3;
    return -4;
}
