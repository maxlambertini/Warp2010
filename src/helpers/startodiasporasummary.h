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


#ifndef STARTODIASPORASUMMARY_H
#define STARTODIASPORASUMMARY_H

#include <QtCore>
#include "star.h"

typedef QVector<int> StarIDList;
typedef QMap<int, StarIDList* > DiasporaSummaryMap;

// this class encapsulate a relation between diaspora environment and resource
// values and stars. You can use it
class StarToDiasporaSummary
{
private:
    StarToDiasporaSummary();
    ~StarToDiasporaSummary();
    StarToDiasporaSummary(const StarToDiasporaSummary&);
    StarToDiasporaSummary& operator= (const StarToDiasporaSummary&);
    static StarToDiasporaSummary _current;

    DiasporaSummaryMap _environmentSummary;
    DiasporaSummaryMap _resourcesSummary;

public:
    static StarToDiasporaSummary* current() { return &_current; }
    DiasporaSummaryMap* environmentSummary() { return &_environmentSummary; }
    DiasporaSummaryMap* resourcesSummary() { return &_resourcesSummary; }

    void clearSummaryMap();
    void addToResources(int diasporaVal, int idx);
    void addToEnvironment (int diasporaVal, int idx);
    int randomResourcesIdx(int diasporaVal);
    int randomEnvironmentIdx(int diasporaVal);
    Star* randomResourcesStar(int diasporaVal);
    Star* randomEnvironmentStar(int diasporaVal);
};

#endif // STARTODIASPORASUMMARY_H
