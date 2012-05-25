/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/

#include <QtCore>
#include <exception>
#include "star.h"
#include "starlist.h"
#include "warpexception.h"
#include "ssg_structures.h"
#include "onomastikon.h"

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
    // qDebug() << "Deleting starlist";
    Star *pstar;
    foreach (pstar, _stars)
        delete pstar;
}

/*
StarList::StarList(const QString& filename)
{
    this->loadMap(filename);
}
*/

void StarList::createRandomMap(double radius = 50, double density = 750)
{
    double dFactor = radius/50;
    dFactor = pow(dFactor, 3);
    int starCount = (int)(1000 * dFactor) + SSGX::d100()-SSGX::d100();
    Onomastikon*  names = Onomastikon::instancePtr();

    Star *starToDelete;
    foreach (starToDelete,_stars)
        delete starToDelete;
    _stars.clear();


    Star *newStar = 0;
    for (int idx = 0; idx < starCount; idx++)
    {
        newStar = new Star(radius);
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
            newStar->setX(0);
            newStar->setY(0);
            newStar->setZ(0);
            newStar->setStarFullType("G2V");
            newStar->setReference();
        }
    }
}

void StarList::saveMap(const QString& filename)
{
    QFile data(filename);
    if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        Star *star;
        QTextStream out(&data);

        double d = 1000.00;
        QString sCode;
        out << _listName << "\n";
        foreach (star, _stars) {
            sCode.sprintf("%04.2f",d++);
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

void StarList::loadMap(const QString& filename) throw(std::exception)
{
    QFile data(filename);
    //qDebug() << "Loading from " << filename;
    QString prevID = "xxxxxx";
    QString ID = "";

    Star *starToDelete;
    foreach (starToDelete,_stars) {
        if (starToDelete != 0) {
            //qDebug() << "deleting... " << starToDelete->starName;
            delete starToDelete;
        }
    }
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
            Star* newStar;
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
                    newStar = new Star();

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
                        currentStar = newStar;
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
    double fDist;
    Star *stTo, *stFrom;
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
            fDist = stFrom->distance(stTo);
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
            double d = stFrom->distance(stTo);
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
    Star *star = _stars.at(idx);
    Star *s1,*s2;
    if (star->path().count() > 1) {
        for (int i = 1; i < star->path().count(); i++)
        {
            s1 = _stars.at(star->path().at(i-1));
            s2 = _stars.at(star->path().at(i));
            dDist += s1->distance(s2);
        }
    }
    return dDist;
}

double StarList::calculatePathDistance(QVector<int>& items)
{
    double dDist = 0.0;
    Star *s1,*s2;
    if (items.count() > 1) {
        for (int i = 1; i < items.count(); i++)
        {
            s1 = _stars.at(i-1);
            s2 = _stars.at(i);
            dDist += s1->distance(s2);
        }
    }
    return dDist;
}

void StarList::rebuildMatrix(int idx=0)
{
    Star *star;
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
    Star *wn1, *wn2, *wn3;
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
                    // qDebug() << "Looking on star " << wn2->starName << "whose path.length is " << wn2->path().count();
                if (wn2->path().count() == 0)
                {
                        // qDebug() << "wn2 path count == 0";
                    for (int i2 = 0; i2 < wn1->path().count(); i2++) {
                        wn2->appendToPath(wn1->path().at(i2));
                            // qDebug() << "appending wn1 " << wn1->starName;
                    }
                    wn2->appendToPath(nNeighbor);
                }
                else
                {
                    //qDebug() << "calc'ing dist, neighboring star " << wn1->starName;
                    dist = this->calculatePathDistance(nNeighbor);
                    dist2 = this->calculatePathDistance(idx)+wn1->distance(wn2);
                    if (wn2->starName.startsWith("Kormoran")) {
                        //qDebug() << wn2->starName << " dist is " << dist;
                        //qDebug() << wn1->starName << " dist2 is " << dist2;
                    }



                    if (dist2 < dist)
                    {
                        //qDebug() << "distance is shorter!";
                        QVector<int> lst2;
                        wn3 = _starList.stars().at(idx);
                        for (int ix = 0; ix < wn1->path().count(); ix++)
                            lst2.append(wn3->path().at(ix));
                        lst2.append(nNeighbor);
                        for (int midx = 0; midx < _stars.count(); midx++)
                        {
                            //// qDebug() << "adding " << midx;
                            Star* myStar = _stars.at(midx);
                            myStar->changeStartingPath(lst2);
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
                    //this->buildMatrix(nNeighbor,false);
            }
            //qDebug() << "neighbors to process: " << lDest.count();
        }
        lStart.clear();
        int iTmp;
        foreach (iTmp, lDest)
            lStart.append(iTmp);
        lDest.clear();
    } while (lStart.count() > 0);

}

void StarList::buildReachableStars() {
    Star* star;
    _reachableStars.clear();
    for (int idx = 0; idx < this->stars().count(); idx++) {
        star = this->stars().at(idx);
        if (star->path().count() > 0)
            _reachableStars.append(idx);
    }
    qSort (_reachableStars.begin(), _reachableStars.end());

}

QVector<ParsecStar>& StarList::prepareParsecStarList(SceneMediatorDrawMode::DrawMode mode)
{
    _parsecStarList.clear();
    Star * star;
    int cx, cy;
    QStringList psCoord;
    foreach (star, this->stars()) {
        ParsecStar pstar = ParsecStar(star);
        pstar.setMode(mode);
        cx = pstar.pr_x();
        cy = pstar.pr_y();
        //qDebug() << "Setting mode: " << mode << ", coordinates=" << cx << cy;

        QString sCoord = QString().sprintf("%d-%d",cx,cy);
        //qDebug() << "sCoord " << sCoord;
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y();
            sCoord = QString().sprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-1 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()-1;
            cy = pstar.pr_y();
            sCoord = QString().sprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-2 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y()+1;
            sCoord = QString().sprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-3 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()-1;
            cy = pstar.pr_y()+1;
            sCoord = QString().sprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-4 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x();
            cy = pstar.pr_y()+1;
            sCoord = QString().sprintf("%d-%d",cx,cy);
            //qDebug() << "sCoord-5 " << sCoord;
        }
        if (psCoord.contains(sCoord))
        {
            cx = pstar.pr_x()+1;
            cy = pstar.pr_y()-1;
            sCoord = QString().sprintf("%d-%d",cx,cy);
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
        qSort(_qStarList.begin(), _qStarList.end(),starGreaterThan);
    else
        qSort(_qStarList.begin(), _qStarList.end(),starLessThan);
    return _qStarList;
}

bool starLessThan(Star *st1, Star *st2)
{
    if (st2 == 0)
        return false;
    if (st1 == 0)
        return true;
    return st2->path().count() > st1->path().count();

}

bool starGreaterThan(Star *st1, Star *st2) {
    if (st1 == 0)
        return false;
    if (st2 == 0)
        return true;
    return st1->path().count() > st2->path().count();

}
