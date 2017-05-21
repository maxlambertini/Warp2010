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

#include "startodiasporasummary.h"
#include "ssg_structures.h"
#include "star.h"
#include "starlist.h"

StarToDiasporaSummary StarToDiasporaSummary::_current;

StarToDiasporaSummary::StarToDiasporaSummary()
{
    for (int h = -4; h < 5; h++) {
        _environmentSummary.insert(h, new StarIDList());
        _resourcesSummary.insert(h, new StarIDList());
    }

}

StarToDiasporaSummary::~StarToDiasporaSummary()
{
    for (int h = -4; h < 5; h++) {
        StarIDList* ptr = _environmentSummary[h]; delete ptr;
        ptr = _resourcesSummary[h]; delete ptr;
    }
}

void StarToDiasporaSummary::clearSummaryMap() {
    for (int h = -4; h < 5; h++) {
        StarIDList* ptr = _environmentSummary[h]; ptr->clear();
        ptr = _resourcesSummary[h]; ptr->clear();
    }

}

void StarToDiasporaSummary::addToEnvironment(int diasporaVal, int idx) {
    if (diasporaVal > 4 || diasporaVal < -4)
        return;
    StarIDList * ptr = _environmentSummary[diasporaVal];
    if (ptr != 0 && (!ptr->contains(idx)))
        ptr->append(idx);
}

void StarToDiasporaSummary::addToResources(int diasporaVal, int idx) {
    if (diasporaVal > 4 || diasporaVal < -4)
        return;
    StarIDList * ptr = _resourcesSummary[diasporaVal];
    if (ptr != 0 && (!ptr->contains(idx)))
        ptr->append(idx);
}

int StarToDiasporaSummary::randomEnvironmentIdx(int diasporaVal) {
    StarIDList * ptr = _environmentSummary[diasporaVal];
    if (ptr != 0 && ptr->count() > 0 ) {
        int dx = SSGX::dx(ptr->count());
        return dx;
    }
    else {
        return -1;
    }
}

int StarToDiasporaSummary::randomResourcesIdx(int diasporaVal) {
    StarIDList * ptr = _resourcesSummary[diasporaVal];
    if (ptr != 0 && ptr->count() > 0 ) {
        int dx = SSGX::dx(ptr->count());
        return dx;
    }
    else {
        return -1;
    }
}

Star*  StarToDiasporaSummary::randomEnvironmentStar(int diasporaVal) {
    StarIDList * ptr = _environmentSummary[diasporaVal];
    if (ptr != 0 && ptr->count() > 0 ) {
        int dx = SSGX::dx(ptr->count());
        return StarList::StarListPtr()->stars().at(dx).data();
    }
    else {
        0;
    }
}

Star* StarToDiasporaSummary::randomResourcesStar(int diasporaVal) {
    StarIDList * ptr = _resourcesSummary[diasporaVal];
    if (ptr != 0 && ptr->count() > 0 ) {
        int dx = SSGX::dx(ptr->count());
        return StarList::StarListPtr()->stars().at(dx).data();
    }
    else {
        return 0;
    }
}
