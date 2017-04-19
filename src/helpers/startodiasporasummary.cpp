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
