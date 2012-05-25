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

    static void WriteTradeRoutesToFile (QVector<QPointer<TradeRoute> > & routes, QString file);
    static void ReadTradeRoutesFromFile(QVector<QPointer<TradeRoute> > & routes, QString file);


};

#endif // TRADEROUTE_H
