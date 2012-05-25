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
