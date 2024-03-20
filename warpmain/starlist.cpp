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

#include <QtCore>
#include <exception>
#include "star.h"
#include "starlist.h"
#include "warpexception.h"
#include "ssg_structures.h"
#include "onomastikon.h"
#include "helpers/preferences.h"
#include <QVector>
#include <QList>

StarList StarList::_starList;

StarList::StarList() //: QObject()
{
    // qDebug() << "StarList constructor called";
}

StarList::StarList(const StarList &that) //: QObject()
{
    this->_stars = that._stars;
    // qDebug() <<  "StarList c-constructor called";
}

StarList::~StarList()
{
    qDebug() << "Deleting starlist";
    //Star *pstar;
    //foreach (pstar, _stars)
    //    delete pstar;

}

/*
StarList::StarList(const QString& filename)
{
    this->loadMap(filename);
}
*/

void StarList::createRandomMap(double radius = 50, double density __attribute__((unused)) = 750 , double dx, double dy, double dz)
{
    double dFactor = radius/50;
    dFactor = pow(dFactor, 3);
    int starCount = (int)(1000 * dFactor) + SSGX::d100()-SSGX::d100();
    Onomastikon*  names = Onomastikon::instancePtr();

    //Star *starToDelete;
    //foreach (starToDelete,_stars)
    //    delete starToDelete;
    qDebug() << "Creating random map....";
    _stars.clear();
    _stars.squeeze();

    for (int idx = 0; idx < starCount; idx++)
    {
        QSharedPointer<Star> newStar = QSharedPointer<Star>(new Star(radius,dx,dy,dz));;
        int die = SSGX::d10();
        if (die < 3)
            newStar->starName = names->greekName();
        else if (die >=3 && die <= 8)
            newStar->starName = names->sigla();
        else {
            QString nomen;
            do {
                nomen = names->pseudoNomen()+"'s star";
            } while (nomen.length() == 0);
            newStar->starName = nomen;
        }
        _stars.append(newStar);
        if (idx == 0) {
            newStar->starName = "(CORE) "+newStar->starName;
            newStar->setX(dx);
            newStar->setY(dy);
            newStar->setZ(dz);
            newStar->setStarFullType("G2V");
            newStar->setReference();
        }
    }
}

void StarList::saveMap(const QString& filename)
{
    QFile data(filename);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        QSharedPointer<Star> star;
        QTextStream out(&data);

        double d = 1000.00;
        QString sCode;
        out << _listName << "\n";
        foreach (star, _stars) {
            sCode.asprintf("%04.2f",d++);
            out << sCode << "/"
                << star->x() << "/"
                << star->y() << "/"
                << star->z() << "/"
                << star->starName << "/"
                << star->starName << "/"
                << star->starName << "//"
                << star->starFullType() << "/"
                << "//" << star->starName << "\n";

        }
        out.flush();
    }
    data.close();
}

void StarList::loadMap(const QString& filename) /*throw(std::exception)*/
{
    QFile data(filename);
    //qDebug() << "Loading from " << filename;
    QString prevID = "xxxxxx";
    QString ID = "";

    /*
    Star *starToDelete;
    foreach (starToDelete,_stars) {
        if (starToDelete != 0) {
            //qDebug() << "deleting... " << starToDelete->starName;
            delete starToDelete;
        }
    }
    */
    _stars.clear();
    //qDebug() << "Cleared star";

    Star *currentStar = 0;

    //qDebug() << "Set cstar = 0";

    if (data.exists())
    {
        //qDebug() << "about to read data";
        if (data.open(QFile::ReadWrite | QFile::ReadOnly))
        {
            QTextStream in(&data);
            this->_listName = in.readLine(); //use first row as listname;
            if (this->_listName.isNull())
                throw WarpException("Invalid star file format");
            QString line;
            //Star* newStar;
            //qDebug() << "stream opened, reading.";
            do
            {
                line = in.readLine();

                if (!line.isNull())
                {
                    QStringList items = line.split("/");
                    if (items.count() < 9)
                        throw WarpException("Invalid layout in star file format");

                    ID = items.at(0);
                    ID = ID.left(4);
					
                    //qDebug() << "Parsing line: " << ID;
					
                    QString x = items.at(1);
                    QString y = items.at(2);
                    QString z = items.at(3);
                    //qDebug() << x << "," << y << "," << z;
                    QSharedPointer<Star> newStar = QSharedPointer<Star>(new Star());

                    Q_ASSERT (newStar != 0);

                    QString starName1 = items.at(4);
                    QString starName2 = items.at(6);
                    QString fullStarType = items.at(8);

                    //qDebug() << starName1 << "," << starName2 << "," << fullStarType;

                    newStar->setStarFullType(fullStarType);
                    newStar->starName = (starName2.isEmpty() || starName2.isNull()) ? starName1 : starName2;

                    if (ID != prevID)
                    {
                        newStar->setX(x.toDouble());
                        newStar->setY(y.toDouble());
                        newStar->setZ(z.toDouble());

                        _stars.append(newStar);
                        newStar->setIsSister(false);
                        currentStar = newStar.data();
                        //qDebug() << "Appended star: " << ID;
                    }
                    else {
                        newStar->setIsSister(true);
                        currentStar->appendToSisters(newStar);
                        //qDebug() << "Appended sister: " << ID;
                    }

                    prevID = ID;

                }
            } while (!line.isNull());
            //qDebug() << "Reading is over";
        }
        //qDebug() << "Data has been read";
    }
    //qDebug() << "Exiting from Read";

}

void StarList::calculateNeighbors(double distance)
{
    _jumpDistance = distance;
    double fDist;
    QSharedPointer<Star> stTo, stFrom;
    QVector<int> v;
    int starCount = _stars.count();
    // qDebug() << "Cleaning neighbors list";

    foreach (stTo, _stars)
        stTo->clearNeighbors();

    // qDebug() << "Filling neighbors list";
    for (int i = 0; i < starCount; i++)
    {
        stFrom = _stars.at(i);

        for (int z = starCount-1; z > i; z--)
        {
            stTo = _stars.at(z);
            fDist = stFrom->distance(stTo.data());
            if (fDist  <= distance)
            {
                stFrom->appendToNeighbors(z);
                stTo->appendToNeighbors(i);
            }
        }
    }
    // qDebug() << "Done with neighbors list";

    QMap<double, int> neighbors;
    for (int i = 0; i < starCount; i++) {
        stFrom = _stars.at(i);
        neighbors.clear();
        for (int z = 0; z < stFrom->neighbors().count(); z++) {
            int n = stFrom->neighbors().at(z);
            stTo = _stars.at(n);
            double d = stFrom->distance(stTo.data());
            neighbors.insert(d,n);
        }
        stFrom->clearNeighbors();
        double k;
        for (int kk = neighbors.keys().count()-1; kk >= 0; kk-- ) {
            k = neighbors.keys().at(kk);
            int z = neighbors[k];
            stFrom->appendToNeighbors(z);
        }

    }

}

double StarList::calculatePathDistance(int idx)
{
    double dDist = 0.0;
    QSharedPointer<Star> star = _stars.at(idx);
    QSharedPointer<Star> s1,s2;
    if (star->path().count() > 1) {
        for (int i = 1; i < star->path().count(); i++)
        {
            s1 = _stars.at(star->path().at(i-1));
            s2 = _stars.at(star->path().at(i));
            dDist += s1->distance(s2.data());
        }
    }
    return dDist;
}

double StarList::calculatePathDistance(QVector<int>& items)
{
    double dDist = 0.0;
    QSharedPointer<Star> s1,s2;
    if (items.count() > 1) {
        for (int i = 1; i < items.count(); i++)
        {
            s1 = _stars.at(i-1);
            s2 = _stars.at(i);
            dDist += s1->distance(s2.data());
        }
    }
    return dDist;
}

void StarList::rebuildMatrix(int idx=0)
{
    QSharedPointer<Star> star;
        // qDebug() << "Clearing star paths";
    foreach (star, this->stars()) {
        star->clearPath();
        star->leave();
        star->clearReference();
    }
        // qDebug() << "Starting real build";
    buildMatrix(idx,true);
    this->buildReachableStars();
}

// WARNING don't ever, never change this algorithm to a
// recursive versione. It simply does not work well, since
// it ends up finding suboptimal paths when there are
// more than 1000 points with a lot of interconnections.
// iterative is the way :-)
void StarList::buildMatrix(int idx,bool isStartingMode)
{
    QSharedPointer<Star> wn1, wn2, wn3;
    double dist,dist2;
    QList<int> lStart, lDest;

    wn1 = _stars.at(idx);
    wn1->setVisited(true);
    if (isStartingMode)
    {
        wn1->setDistance(0.0);
        wn1->appendToPath(idx);
        wn1->setReference();
    }
    lStart.append(idx);
    do {
        lDest.clear();
        for (int zz = 0; zz < lStart.count(); zz ++) {
            idx = lStart.at(zz);
            wn1 = _stars.at(idx);
            wn1->setVisited(true);
            for (int i = 0; i < wn1->neighbors().count(); i++)
            {
                int nNeighbor = wn1->neighbors().at(i);
                wn2 = _stars.at(nNeighbor);
                if (wn2->path().count() == 0)
                {
                    for (int i2 = 0; i2 < wn1->path().count(); i2++) {
                        wn2->appendToPath(wn1->path().at(i2));
                    }
                    wn2->appendToPath(nNeighbor);
                }
                else
                {
                    dist = this->calculatePathDistance(nNeighbor);
                    dist2 = this->calculatePathDistance(idx)+wn1->distance(wn2.data());

                    if (dist2 < dist)
                    {
                        QVector<int> v_lst3;
                        wn3 = _starList.stars().at(idx);
                        for (int ix = 0; ix < wn1->path().count(); ix++) {
                            v_lst3.push_back(wn3->path().at(ix));
                        }
                        v_lst3.push_back(nNeighbor);
                        for (int midx = 0; midx < _stars.count(); midx++)
                        {
                            //// qDebug() << "adding " << midx;
                            QSharedPointer<Star> myStar = _stars.at(midx);
                            myStar->changeStartingPath(v_lst3);
                        }
                    }
                }
            }
            for (int i = 0; i < wn1->neighbors().count(); i++)
            {
                int nNeighbor = wn1->neighbors().at(i);
                wn2 = _stars.at(nNeighbor);
                if (!wn2->visited()  )
                    if (!lDest.contains(nNeighbor))
                        lDest.append(nNeighbor);
            }
        }
        lStart.clear();
        int iTmp;
        foreach (iTmp, lDest)
            lStart.append(iTmp);
        lDest.clear();
    } while (lStart.count() > 0);

}

void StarList::buildReachableStars() {
    QSharedPointer<Star> star;
    _reachableStars.clear();
    for (int idx = 0; idx < this->stars().count(); idx++) {
        star = this->stars().at(idx);
        if (star->path().count() > 0)
            _reachableStars.append(idx);
    }
    std::sort (_reachableStars.begin(), _reachableStars.end());

}

QVector<ParsecStar>& StarList::prepareParsecStarList(SceneMediatorDrawMode::DrawMode mode)
{
    _parsecStarList.clear();
    QSharedPointer<Star> star;
    int cx, cy;
    QStringList psCoord;
    foreach (star, this->stars()) {
        ParsecStar pstar = ParsecStar(star, Preferences::prefsPtr()->parsecStarFactor());
        pstar.setMode(mode);
        cx = pstar.pr_x();
        cy = pstar.pr_y();
        //qDebug() << "Setting mode: " << mode << ", coordinates=" << cx << cy;

        QString sCoord = QString().asprintf("%d-%d",cx,cy);
        //qDebug() << "sCoord " << sCoord;
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y();
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-1 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()-1;
            cy = pstar.pr_y();
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-2 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y()+1;
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-3 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()-1;
            cy = pstar.pr_y()+1;
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-4 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x();
            cy = pstar.pr_y()+1;
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-5 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y()-1;
            sCoord = QString().asprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-6 " << sCoord;
        }
        psCoord.append(sCoord);
        pstar.setX(cx);
        pstar.setY(cy);
        //qDebug() << "Setting coords to pStar " << cx << cy;
        _parsecStarList.append(pstar);

    }
    return _parsecStarList;
}

QStarList& StarList::getQStarList(bool bGreaterThan) {
    _qStarList.clear();
    for (int h = 0; h < this->count(); h++) {
        _qStarList.append(this->stars()[h]);
    }
    if (bGreaterThan)
        std::sort (_qStarList.begin(), _qStarList.end(),starGreaterThan);
    else
        std::sort (_qStarList.begin(), _qStarList.end(),starLessThan);
    return _qStarList;
}

void StarList::loadMatrix (QString filename) {
    QFile data(filename);
    if (data.open(QFile::ReadOnly | QFile::ReadWrite)) {
        QDataStream in(&data);
        deserializeStarList(in);
        data.close();
    }
}



void StarList::toJson (QJsonObject& o) {
    QJsonArray a;
    QSharedPointer<Star> p;
    foreach (p, _stars) {
        QJsonObject oStar;
        p->toJson(oStar);
        a.append(oStar);
    }
    o["jumpDistance"]    = this->_jumpDistance;
    o["sector_name"] = this->listName();
    o["stars"] = a;
}

void StarList::fromJson(const QJsonObject& o) {
    _jumpDistance = o["jumpDistance"].toDouble();
    _listName = o["sector_name"].toString();
    this->setListName(_listName);
    QJsonArray a = o["stars"].toArray();
    for (int h = 0; h < a.size(); ++h) {
        QJsonObject oStar = a[h].toObject();
        Star* s = new Star();
        s->fromJson(oStar);
        QSharedPointer<Star> p;
        p.reset(s);
        _stars.append(p);
    }
}

void StarList::saveToJson (QString filename) {
    QJsonObject o;
    this->toJson(o);
    QJsonDocument doc(o);
    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        data.write(doc.toJson());
     }
     data.close();
}

void StarList::loadFromJson (QString filename) {
    QFile data (filename);
     if (data.open(QFile::ReadOnly | QFile::Text)) {
         QByteArray json = data.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(json);
        auto oStuff = doc.object();
        this->fromJson(oStuff);
     }
     data.close();
}

void StarList::saveMatrix (QString filename)
{
        QFile data(filename);
        if (data.open(QFile::WriteOnly | QFile::Truncate)) {
            QDataStream out(&data);
            serializeStarList(out);
            data.close();
        }
    }

void StarList::serializeStarList (QDataStream& out)
{
    //some informations
    QString header = "STARLIST!";
    qint32 count = _stars.count();
    out << header << count;

    for (int h = 0; h < _stars.count(); h++)
    {
        QSharedPointer<Star> s = _stars.at(h);
        Star::serializePtr(out, s.data());
    }
}

void StarList::deserializeStarList (QDataStream& in)
{
    QString header;
    qint32 count;
    in >> header >> count;
    if (header == "STARLIST!" && count > 0) {
        QSharedPointer<Star> p;
        //foreach (p, _stars)
        //    if(p != 0) delete p;
        _stars.clear();

        for (int h = 0; h < count; h++) {
            p = Star::deserializeToPtr(in);
            _stars.append(p);
        }
    }
}

bool starLessThan(QSharedPointer<Star> st1, QSharedPointer<Star> st2)
{
    if (st2.isNull())
        return false;
    if (st1.isNull())
        return true;
    return st2->path().count() > st1->path().count();

}

bool starGreaterThan(QSharedPointer<Star> st1, QSharedPointer<Star> st2) {
    if (st1.isNull())
        return false;
    if (st2.isNull())
        return true;
    return st1->path().count() > st2->path().count();

}
