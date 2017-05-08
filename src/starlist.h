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

#ifndef STARLIST_H
#define STARLIST_H

#include <QObject>
#include <QtCore>
#include "star.h"
#include "helpers/parsecstarlisthelper.h"

typedef QVector <QSharedPointer<Star>> QStarList;
typedef QList<int> QIdxStarList;

bool starLessThan(QSharedPointer<Star> st1, QSharedPointer<Star> st2);
bool starGreaterThan(QSharedPointer<Star> tr1, QSharedPointer<Star> tr2);


class ParsecStar
{
private:
    int _x;
    int _y;
    int _z;
    QSharedPointer<Star> _star;
    bool _visited;
    SceneMediatorDrawMode::DrawMode _mode;
public:
    ParsecStar () {}  //empty constructor;
    ParsecStar (QSharedPointer<Star> star) {
        _star = star;
        this->_x = (int)(_star->x() / 1);
        this->_y = (int)(_star->y() / 1);
        this->_z = (int)(_star->z() / 1);
        _visited = false;
        _mode = SceneMediatorDrawMode::XY;
    }

    inline SceneMediatorDrawMode::DrawMode mode() { return _mode; }
    inline void setMode(SceneMediatorDrawMode::DrawMode m) { _mode = m; }

    int x() { return _x; }
    int y() { return _y; }
    int z() { return _z; }

    inline int pr_x() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _x;
            break;
        case SceneMediatorDrawMode::XZ:
            return _x;
            break;
        case SceneMediatorDrawMode::YZ:
            return _y;
            break;
        default:
            return _x;
        }
    }
    inline int pr_y() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _y;
            break;
        case SceneMediatorDrawMode::XZ:
            return _z;
            break;
        case SceneMediatorDrawMode::YZ:
            return _z;
            break;
        default:
            return _y;
        }
    }

    inline int pr_z() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _z;
            break;
        case SceneMediatorDrawMode::XZ:
            return _y;
            break;
        case SceneMediatorDrawMode::YZ:
            return _x;
            break;
        default:
            return _z;
        }
    }


    bool visited() { return _visited; }

    void visit() { _visited = true; }
    void leave() { _visited = false; }

    void setX(int i) { _x = i; }
    void setY(int i) { _y = i; }
    void setZ(int i) { _z = i; }
    void setVisited(bool b) { _visited = b; }
    QSharedPointer<Star> star() { return _star; }

};

class StarList //: public QObject
{
    //Q_OBJECT

private:
    QString _listName;
    double  _jumpDistance;

    static StarList _starList;

    StarList (const StarList & );
    StarList& operator= (const StarList&);
    StarList();
    virtual ~StarList();
    QVector<ParsecStar> _parsecStarList;
    QVector<QSharedPointer<Star>> _stars;
    QStarList _qStarList;
    QIdxStarList _reachableStars;
    QIdxStarList _inTradeRoute;

public:

    //StarList();
    //StarList(const StarList &that);
    //virtual ~StarList();
    //TODO: implent the copy constructor, fucken idiom!

    //StarList(const QString& filename);

    static StarList& StarListRef() { return StarList::_starList; }
    static StarList* StarListPtr() { return &StarList::_starList; }

    void createRandomMap(double radius, double density);
    void loadMap(const QString& filename) throw(std::exception);
    void saveMap(const QString& filename);
    void calculateNeighbors(double distance);
    void buildMatrix(int idx = 0, bool isStartingMode = true);
    void rebuildMatrix(int idx);

    double calculatePathDistance(int idx);
    double calculatePathDistance(QVector<int> &);

    inline QString& listName() { return _listName; }
    inline void setListName(QString& name) { _listName = name; }
    inline double jumpDistance() { return _jumpDistance; }
    inline void setJumpDistance(double v) { _jumpDistance = v; }

    inline QVector<QSharedPointer<Star>>& stars() { return _stars;}
    inline int count() { return _stars.count();}
    QVector<ParsecStar>& prepareParsecStarList(SceneMediatorDrawMode::DrawMode mode = SceneMediatorDrawMode::XY);
    QStarList& qStarList() { return _qStarList; }

    QStarList& getQStarList(bool bGreaterThan = true);
    QIdxStarList& reachableStars() { return _reachableStars; }
    QIdxStarList& inTradeRoute() { return _inTradeRoute; }

    void buildReachableStars();
    bool isReachable(int idx) { return _reachableStars.contains(idx);  }

    void loadMatrix (QString filename) {
        QFile data(filename);
        if (data.open(QFile::ReadOnly | QFile::ReadWrite)) {
            QDataStream in(&data);
            deserializeStarList(in);
            data.close();
        }
    }



    void toJson (QJsonObject& o) {
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

    void fromJson(const QJsonObject& o) {
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

    void saveToJson (QString filename) {
        QJsonObject o;
        this->toJson(o);
        QJsonDocument doc(o);
        QFile data (filename);
         if (data.open(QFile::WriteOnly | QFile::Truncate)) {
            data.write(doc.toJson());
         }
         data.close();
    }

    void loadFromJson (QString filename) {
        QFile data (filename);
         if (data.open(QFile::ReadOnly | QFile::Text)) {
             QByteArray json = data.readAll();
            QJsonDocument doc = QJsonDocument::fromJson(json);
            auto oStuff = doc.object();
            this->fromJson(oStuff);
         }
         data.close();
    }

    void saveMatrix (QString filename)
    {
            QFile data(filename);
            if (data.open(QFile::WriteOnly | QFile::Truncate)) {
                QDataStream out(&data);
                serializeStarList(out);
                data.close();
            }
        }

    void serializeStarList (QDataStream& out)
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

    void deserializeStarList (QDataStream& in)
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




private:

};


#endif // STARLIST_H
