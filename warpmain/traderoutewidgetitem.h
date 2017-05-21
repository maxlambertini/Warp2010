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

#ifndef TRADEROUTEWIDGETITEM_H
#define TRADEROUTEWIDGETITEM_H

#include <QListWidgetItem>
#include "traderoute.h"

class TradeRouteWidgetItem : public QListWidgetItem
{
    TradeRoute *_route;
    int _idx;
    double _distance;
public:
    TradeRouteWidgetItem(TradeRoute *route, int idx, QListWidget *view);
    virtual ~TradeRouteWidgetItem() { }
    TradeRoute* tradeRoute() { return _route;}
    int indexOnList() { return _idx;}

    inline double distance() { return _distance;}
    inline void setDistance(double d) { _distance = d;}
};

#endif // TRADEROUTEWIDGETITEM_H
