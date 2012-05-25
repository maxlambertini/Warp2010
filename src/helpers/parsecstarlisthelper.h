#ifndef PARSECSTARLISTHELPER_H
#define PARSECSTARLISTHELPER_H

#include <QtCore>
#include "star.h"

namespace SceneMediatorDrawMode {
    enum DrawMode {
        XY,
        XZ,
        YZ
    };
}

class ParsecStarListHelper {
    SceneMediatorDrawMode::DrawMode _drawMode;



public:

    ParsecStarListHelper() : _drawMode(SceneMediatorDrawMode::XY) {}
    SceneMediatorDrawMode::DrawMode drawMode() { return _drawMode; }
    void setDrawMode (SceneMediatorDrawMode::DrawMode dm) { _drawMode = dm; }

    inline double starX(Star *p) {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            return p->x();
            break;
        case SceneMediatorDrawMode::XZ:
            return p->x();
            break;
        case SceneMediatorDrawMode::YZ:
            return p->y();
            break;
        default:
            return p->x();
            break;

        };
    }

    inline double starY(Star *p) {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            return -p->y();
            break;
        case SceneMediatorDrawMode::XZ:
            return -p->z();
            break;
        case SceneMediatorDrawMode::YZ:
            return -p->z();
            break;
        default:
            return p->z();
            break;

        };
    }

};





#endif // PARSECSTARLISTHELPER_H
