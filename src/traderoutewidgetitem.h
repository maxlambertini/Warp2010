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
