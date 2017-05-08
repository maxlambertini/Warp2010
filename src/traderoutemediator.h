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

#ifndef TRADEROUTEMEDIATOR_H
#define TRADEROUTEMEDIATOR_H

#include <QtGui>
#include <QProgressBar>
#include <QListWidget>
#include <QListWidgetItem>
#include "star.h"
#include "starlist.h"
#include "traderoute.h"
#include "dialogs/createtraderoutedialog.h"

bool tradeRouteLessThan(QSharedPointer<TradeRoute> tr1, QSharedPointer<TradeRoute> tr2);
bool tradeRouteGreaterThan(QSharedPointer<TradeRoute> tr1, QSharedPointer<TradeRoute> tr2);

class TradeRouteMediator : public QObject
{
    Q_OBJECT

    CreateTradeRouteDialog *_createTradeRouteDlg;
    QVector <QSharedPointer<TradeRoute> > _tradeRoutes;
    QMap<int,int>                   _starsInTradeRoutes;
    StarList *_starList;
    QListWidget* _grid;
    QProgressBar* _progressBar;

    static TradeRouteMediator _mediator;


    TradeRouteMediator (const TradeRouteMediator & );
    TradeRouteMediator& operator= (const TradeRouteMediator&);
    TradeRouteMediator();
    virtual ~TradeRouteMediator();

signals:
    void tradeRouteCreated(QString& routeName);

public:
    //TradeRouteMediator();
    //~TradeRouteMediator() {}

    inline QMap<int,int>& starsInTradeRoutes() { return _starsInTradeRoutes; }

    inline void setCreateTradeRouteDialog (CreateTradeRouteDialog *trd) { _createTradeRouteDlg = trd; }
    inline void setStarList (StarList *sl) { _starList = sl; }
    inline void setTableWidget (QListWidget* grid) { _grid = grid; }
    inline void setProgressBar (QProgressBar* pb) { _progressBar = pb;}
    static TradeRouteMediator* mediator() { return &_mediator; }

    inline QVector<QSharedPointer<TradeRoute> > *tradeRoutePtr() { return &_tradeRoutes; }
    inline QVector<QSharedPointer<TradeRoute> >& tradeRoutes() { return _tradeRoutes; }

    inline void addTradeRoute(QSharedPointer<TradeRoute> route) {
        _tradeRoutes.append(route);
        int item;
        foreach (item,route->path())
        {
            if (_starsInTradeRoutes.contains(item))
                _starsInTradeRoutes[item] = _starsInTradeRoutes[item]+1;
            else
                _starsInTradeRoutes.insert(item,1);
        }
    }

    inline void removeRoute (int idxRoute) {
        TradeRoute *route = _tradeRoutes.at(idxRoute).data();
        int item, itemVal;
        foreach (item, route->path()) {
            itemVal = _starsInTradeRoutes[item];
            if (itemVal > 1) {
                _starsInTradeRoutes[item] = itemVal-1;
                // qDebug() << "decreased stuff to " << itemVal - 1;
            }
            else
                _starsInTradeRoutes.remove(item);
        }

        delete route;
        _tradeRoutes.remove(idxRoute);
    }

    void sortByRoute(bool bReverse);

    inline void clearTradeRoutes() {
        QSharedPointer<TradeRoute> ptr;
        //foreach (ptr, _tradeRoutes)
        //    delete ptr;
        _tradeRoutes.clear();
        _starsInTradeRoutes.clear();
    }
    inline int tradeRoutesCount() { return _tradeRoutes.count(); }
    void tradeRouteToTableWidget(QListWidget *tw);
    void searchTradeRouteToGardenPlanets();
    QSharedPointer<TradeRoute> performAddToRouteList(
            QString & tradeRouteName,
            QColor & bgColor,
            QVector<int> &path)
    {
        QSharedPointer<TradeRoute> tr(new TradeRoute(path));
        tr->setRouteName(tradeRouteName);
        tr->setRouteColor(bgColor);
        _tradeRoutes.append(tr);
        int item;
        foreach (item,tr->path())
        {
            if (_starsInTradeRoutes.contains(item))
                _starsInTradeRoutes[item] = _starsInTradeRoutes[item]+1;
            else
                _starsInTradeRoutes.insert(item,1);
        }
        return tr;
    }
    void performAddToTradeRoute (TradeRoute *tr, int indexOnList) ;

    void loadTradeRouteFromFile(QString filename);

    QString tradeRouteToHTML(TradeRoute *tr);
    double  tradeRouteDistance(TradeRoute *tr);
};

#endif // TRADEROUTEMEDIATOR_H
