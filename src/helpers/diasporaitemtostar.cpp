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


#include "diasporaitemtostar.h"
#include "solarsystemcreator.h"

DiasporaItemToStar::DiasporaItemToStar()
{
    _item = 0;
}

DiasporaItemToStar::~DiasporaItemToStar() {
}

DiasporaItemToStar::DiasporaItemToStar(ClusterItem *item)
{
    _item = item;
    createStarAndSolSys();
}

void DiasporaItemToStar::createStarAndSolSys() {
    SolarSystemCreator creator;
    do {
        _star = Star(66.6);
        _star.starName = _item->name();
        creator.setStar(&_star);
        creator.createSolarSystem();
        //qDebug() << "Values for " << _star.starName << ": E=" <<  _star.diasporaEnvironment()
        //        << ", R:" << _star.diasporaResources();

    } while (_star.diasporaEnvironment() != _item->environment() &&
             _star.diasporaResources() != _item->resources() );
}
