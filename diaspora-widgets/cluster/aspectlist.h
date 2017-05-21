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

#ifndef ASPECTLIST_H
#define ASPECTLIST_H

#include <QtCore>
#include "cluster/aspect.h"
#include "ssg_structures.h"

class AspectList
{
    QVector<Aspect> _aspects;
    QList<int> _drawnAspects;
    int _currentDrawIndex;
public:
    QVector<Aspect>& aspects() { return _aspects; }
    AspectList();
    static AspectList fromFile(const QString& filename);
    static AspectList fromAppDir();
    void clearAspectDraw() {
        int idMax = _aspects.count();
        _drawnAspects.clear();
        if (idMax > 0) {
            for (int x = 0; x < idMax; x++)
                _drawnAspects << x;
            for (int w = idMax; w > 1 ; w--) {
                int i2 = SSGX::dx(w);
                int t1 = _drawnAspects[i2];
                _drawnAspects[i2] = _drawnAspects[w-1];
                _drawnAspects[w-1] = t1;
            }

        }
        _currentDrawIndex = 0;
    }
    Aspect& drawAspect();
};

#endif // ASPECTLIST_H
