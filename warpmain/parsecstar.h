#ifndef PARSECSTAR_H
#define PARSECSTAR_H

#include <QObject>
#include <QtCore>
#include "star.h"
#include "helpers/parsecstarlisthelper.h"



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
    ParsecStar (QSharedPointer<Star> star, double _psf = 1.67);

    inline SceneMediatorDrawMode::DrawMode mode() { return _mode; }
    inline void setMode(SceneMediatorDrawMode::DrawMode m) { _mode = m; }

private:
    double _parsecStarFactor ;
public:
    double parsecStarFactor() { return _parsecStarFactor; }
    void setParsecStarFactor ( double v) { _parsecStarFactor = v; }

    int x() { return _x; }
    int y() { return _y; }
    int z() { return _z; }

    inline int pr_x() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _x;
        case SceneMediatorDrawMode::XZ:
            return _x;
        case SceneMediatorDrawMode::YZ:
            return _y;
        }
        return _x;
    }
    inline int pr_y() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _y;
        case SceneMediatorDrawMode::XZ:
            return _z;
        case SceneMediatorDrawMode::YZ:
            return _z;
        }
        return _y;
    }

    inline int pr_z() {
        switch (_mode)
        {
        case SceneMediatorDrawMode::XY:
            return _z;
        case SceneMediatorDrawMode::XZ:
            return _y;
        case SceneMediatorDrawMode::YZ:
            return _x;
        }
        return _z;
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



#endif // PARSECSTAR_H
