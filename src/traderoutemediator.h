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

#ifndef TRADEROUTEMEDIATOR_H
#define TRADEROUTEMEDIATOR_H

#include <QtGui>

#include "star.h"
#include "starlist.h"
#include "traderoute.h"
#include "dialogs/createtraderoutedialog.h"

bool tradeRouteLessThan(TradeRoute *tr1, TradeRoute *tr2);
bool tradeRouteGreaterThan(TradeRoute *tr1, TradeRoute *tr2);

class TradeRouteMediator : public QObject
{
    Q_OBJECT

    CreateTradeRouteDialog *_createTradeRouteDlg;
    QVector <QPointer<TradeRoute> > _tradeRoutes;
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

    inline QVector<QPointer<TradeRoute> > *tradeRoutePtr() { return &_tradeRoutes; }
    inline QVector<QPointer<TradeRoute> >& tradeRoutes() { return _tradeRoutes; }

    inline void addTradeRoute(TradeRoute *route) {
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
        TradeRoute *route = _tradeRoutes.at(idxRoute);
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
        QPointer<TradeRoute> ptr;
        foreach (ptr, _tradeRoutes)
            delete ptr;
        _tradeRoutes.clear();
        _starsInTradeRoutes.clear();
    }
    inline int tradeRoutesCount() { return _tradeRoutes.count(); }
    void tradeRouteToTableWidget(QListWidget *tw);
    void searchTradeRouteToGardenPlanets();
    TradeRoute * performAddToRouteList(
            QString & tradeRouteName,
            QColor & bgColor,
            QVector<int> &path)
    {
        QPointer<TradeRoute> tr = new TradeRoute(path);
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
