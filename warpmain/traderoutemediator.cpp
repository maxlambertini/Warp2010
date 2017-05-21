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

#include <QtGui>
#include <QtCore>
#include "star.h"
#include "traderoute.h"
#include "dialogs/createtraderoutedialog.h"
#include "traderoutemediator.h"
#include "traderoutewidgetitem.h"
#include <QtAlgorithms>

TradeRouteMediator TradeRouteMediator::_mediator;


bool tradeRouteLessThan(QSharedPointer<TradeRoute> tr1, QSharedPointer<TradeRoute> tr2)
{
    if (tr1.isNull())
        return true;
    if (tr2.isNull())
        return false;
    return tr1->path().count() < tr2->path().count();
}

bool tradeRouteGreaterThan(QSharedPointer<TradeRoute> tr1, QSharedPointer<TradeRoute> tr2)
{
    if (tr1.isNull())
        return false;
    if (tr2.isNull())
        return true;
    return tr1->path().count() > tr2->path().count();
}


TradeRouteMediator::TradeRouteMediator() : QObject()
{
    // qDebug() << "Initializing TradeRouteMediator";
}

TradeRouteMediator::~TradeRouteMediator()
{
    // qDebug() << "Destroying TradeRouteMediator";

}

void TradeRouteMediator::sortByRoute(bool bReverse)
{
    if (bReverse)
        qSort(_tradeRoutes.begin(), _tradeRoutes.end(), tradeRouteGreaterThan);
    else
        qSort(_tradeRoutes.begin(), _tradeRoutes.end(), tradeRouteLessThan);
}

void TradeRouteMediator::tradeRouteToTableWidget(QListWidget *tw)
{
}

void TradeRouteMediator::searchTradeRouteToGardenPlanets()
{
    QColor colors[] =
    {
        QColor("red"),
        QColor("blue"),
        QColor("green"),
        QColor("yellow"),
        QColor("orange"),
        QColor("teal"),
        QColor("maroon"),
        QColor("silver")
    };



    QSharedPointer<Star> s;
    int n = 0;
    int idx;
    if (_progressBar != 0) {
        _progressBar->setVisible(true);
        _progressBar->setMinimum(0);
        _progressBar->setMaximum(_starList->stars().count());
    }
    for (idx = 0; idx < _starList->stars().count(); idx++)
    {
        if (_progressBar != 0) _progressBar->setValue(idx);

        s = _starList->stars().at(idx);
        if (s->path().count() > 1 && s->hasGarden()) {
            auto s1 =  _starList->stars().at( s->path().at(0));
            auto s2 =  _starList->stars().at( s->path().at( s->path().count()-1 ));

            QVector<int> myPath = s->path();
            QString starName = QString("%1 to %2").arg(s1->starName,s2->starName);

            auto tr = this->performAddToRouteList(
                    starName,
                    colors[n % 8],
                    myPath);

            n++;
        }
    }
    this->sortByRoute(false);

    for (n = 0; n < _tradeRoutes.count(); n++) {
        if (_progressBar != 0) _progressBar->setValue(n);

        this->performAddToTradeRoute(_tradeRoutes.at(n).data(),n);
    }

    if (_progressBar != 0)
        _progressBar->setVisible(false);

    int nTrade;
    // qDebug() << "Stars In Trade Routes has: " << _starsInTradeRoutes.count() << ", first is " << _starsInTradeRoutes[3];

    foreach (nTrade, _starsInTradeRoutes.keys())
    {
        // qDebug() << "Value for key " << nTrade << " is: " << _starsInTradeRoutes[nTrade];
    }
}

void TradeRouteMediator::updateTradeRouteList() {
    if (_progressBar != 0) {
        _progressBar->setVisible(true);
        _progressBar->setMinimum(0);
        _progressBar->setMaximum(_tradeRoutes.count());
    }
    for (auto n = 0; n < _tradeRoutes.count(); n++) {
        if (_progressBar != 0) _progressBar->setValue(n);

        this->performAddToTradeRoute(_tradeRoutes.at(n).data(),n);
    }

    if (_progressBar != 0)
        _progressBar->setVisible(false);

}

void TradeRouteMediator::performAddToTradeRoute (TradeRoute *tr, int indexOnList)
{
    //create the trade route object

    //int nCount = _tradeRoutes.count();

    TradeRouteWidgetItem *twi = new TradeRouteWidgetItem(tr, indexOnList, _grid);

    QPixmap pixmap(32,32);
    QPainter painter(&pixmap);
    QColor bgColor = tr->routeColor();
    QString tradeRouteName = tr->routeName();
    QBrush brush(bgColor);
    QColor backColor = QColor(255,255,255,255);
    QBrush rectbrush(backColor);
    QPen pen(bgColor);
    QBrush oldBrush = painter.brush();
    pen.setWidthF(0.5);
    painter.setPen(pen);    
    painter.setBackground(rectbrush);
    painter.setBrush(rectbrush);
    painter.drawRect(0,0,33,33);
    painter.setBrush(brush);
    painter.drawEllipse(QPoint(16,16),14,14);
    painter.setBrush(oldBrush);
    QIcon icon (pixmap);

    twi->setIcon(icon);
    _grid->addItem(twi);

    emit tradeRouteCreated(tradeRouteName);

}

void TradeRouteMediator::loadTradeRouteFromFile(QString filename)
{
    //// qDebug() << "Loading " << filename;
    QVector<QSharedPointer<TradeRoute> > tempPath;
    TradeRoute::ReadTradeRoutesFromFile(tempPath,filename);

    //// qDebug() << "Read trade routes from file.";

    QSharedPointer<TradeRoute> tr;
    //int indexOnList = -1;
    _grid->clear();
    foreach (tr, tempPath)
    {
        // qDebug() << "Inserting trade route...";

        //int i = tr->path().at(tr->path().count()-1);
        QString trn = tr->routeName();
        QColor rc = tr->routeColor();
        QVector<int> path = tr->path();

        // qDebug() << "Creating with " << trn << ", " << path.count();

        //TradeRoute *tr2 = this->performAddToRouteList(trn,rc,path,i);

        // qDebug() << "created.";

        tr.clear();
    }
    this->sortByRoute(false);

    int n = 0;
    for (n = 0; n < _tradeRoutes.count(); n++)
        this->performAddToTradeRoute(_tradeRoutes.at(n).data(),n);

}

QString TradeRouteMediator::tradeRouteToHTML(TradeRoute *tr)
{
    QString sOut =
        "<html>"
        "<head><style>"
        "BODY,P,UL LI,TH,TD { "
        " font-family: arial, helvetica, sans-serif; "
        " font-size: 8pt; "
        "}"
        "</style>"
        "</head>"
        "<body>"
        "<h3>Route</h3>"
        "<table style='border: 1px solid red;' cellpadding='2' cellspacing='0' width='100%;'>\n";

    int starIdx;
    QSharedPointer<Star> myStar;
    double distance;
    QVector<int> path = tr->path();

    for (int idx = 0; idx < path.count(); idx++)
    {
        starIdx = path.at(idx);
        myStar = _starList->stars().at(starIdx);
        distance =  _starList->calculatePathDistance(starIdx);
        QString rows;
        QTextStream stream(&rows);
        stream.setRealNumberPrecision(5);
        stream << "<tr><th>" << myStar->starName << "</th><td>" << distance << " ly </td>\n";
        sOut += rows;
    }
    sOut += "</table></body></html>\n";
    return sOut;

}

double TradeRouteMediator::tradeRouteDistance(TradeRoute *tr)
{
    QVector<int> path = tr->path();
    int lastIdx = path.last();

    return _starList->calculatePathDistance(lastIdx);
}

void TradeRouteMediator::toJson(QJsonObject &json) {
    QJsonArray aRoutes;
    QSharedPointer<TradeRoute> tr;
    foreach (tr, _tradeRoutes) {
        QJsonObject oTr;
        tr.data()->toJson(oTr);
        aRoutes.append(oTr);
    }
    json["tradeRoutes"] = aRoutes;
}

void TradeRouteMediator::fromJson(const QJsonObject &json) {
    QJsonArray aRoutes = json["tradeRoutes"].toArray();
    _tradeRoutes.clear();
    for (int i = 0; i < aRoutes.size(); ++i) {
        QJsonObject oTr = aRoutes[i].toObject();
        TradeRoute* tr = new TradeRoute();
        tr->fromJson(oTr);
        QSharedPointer<TradeRoute> trp; trp.reset(tr);
        _tradeRoutes.append(trp);
    }
}
