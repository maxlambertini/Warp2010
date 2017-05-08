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

#ifndef TRADEROUTE_H
#define TRADEROUTE_H

#include <QObject>
#include <QtCore>
#include <QtGui>

class TradeRoute;

class TradeRoute : public QObject
{
    Q_OBJECT

private:
    QColor _routeColor;
    QVector<int> _path;
    QString _routeName;
public:
    TradeRoute();
    TradeRoute(const TradeRoute & that);
    TradeRoute(QVector<int> &pathFrom);


    inline const QString & routeName() { return _routeName; }
    inline void setRouteName(QString  n) { _routeName = n; }

    inline const QColor & routeColor() { return _routeColor; }
    void setRouteColor(QColor &color) { _routeColor = color; }

    inline const QVector<int> & path() { return _path; }

    inline void clearPath() { _path.clear();}
    inline void appendToPath(int i) { _path.append(i);}

    static void WriteTradeRoutesToFile (QVector<QSharedPointer<TradeRoute> > & routes, QString file);
    static void ReadTradeRoutesFromFile(QVector<QSharedPointer<TradeRoute> > & routes, QString file);


};

#endif // TRADEROUTE_H
