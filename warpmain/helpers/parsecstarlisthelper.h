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
        case SceneMediatorDrawMode::XZ:
            return p->x();
        case SceneMediatorDrawMode::YZ:
            return p->y();
        default:
            return p->x();

        };
    }

    inline double starY(Star *p) {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            return -p->y();
        case SceneMediatorDrawMode::XZ:
            return -p->z();
        case SceneMediatorDrawMode::YZ:
            return -p->z();
        default:
            return p->z();

        };
    }

};





#endif // PARSECSTARLISTHELPER_H
