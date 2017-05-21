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
        //creator.setStar(&_star);
        //creator.createSolarSystem();
        //qDebug() << "Values for " << _star.starName << ": E=" <<  _star.diasporaEnvironment()
        //        << ", R:" << _star.diasporaResources();

    } while (_star.diasporaEnvironment() != _item->environment() &&
             _star.diasporaResources() != _item->resources() );
}
