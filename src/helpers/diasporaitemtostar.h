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


#ifndef DIASPORAITEMTOSTAR_H
#define DIASPORAITEMTOSTAR_H

#include "star.h"
#include "cluster/clusteritem.h"

class ClusterItem;

class DiasporaItemToStar
{
    ClusterItem* _item;
    Star _star;

    void createStarAndSolSys();
public:
    DiasporaItemToStar();
    DiasporaItemToStar(ClusterItem *item);
    ~DiasporaItemToStar();

    Star * star() { return &_star; }
    ClusterItem *clusterItem() { return _item; }
    void setClusterItem(ClusterItem *ci) {_item = ci; createStarAndSolSys();}


};

#endif // DIASPORAITEMTOSTAR_H
