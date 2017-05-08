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

#include "traderoute.h"


TradeRoute::TradeRoute() : QObject()
{
}

TradeRoute::TradeRoute(QVector<int> &pathFrom) : QObject()
{
    int i;
    foreach (i, pathFrom)
        _path.append(i);
}

TradeRoute::TradeRoute(const TradeRoute & that) : QObject()
{
    this->_routeColor = that._routeColor;
    int i;
    this->_path.clear();
    foreach (i, that._path)
        this->_path.append(i);
}


void TradeRoute::WriteTradeRoutesToFile (QVector<QSharedPointer<TradeRoute> >& routes, QString file)
{
    QFile fileOut(file);
    if (fileOut.open(QFile::ReadWrite | QFile::WriteOnly | QFile::Truncate)) {
        QSharedPointer<TradeRoute> tr;
        QTextStream out (&fileOut);
        out << "TRADEROUTES" << "\n";
        foreach (tr, routes) {
            out << "ROUTE\n";
            out << tr->_routeName << "\n";
            out << tr->_routeColor.red() << "|";
            out << tr->_routeColor.green() << "|";
            out << tr->_routeColor.blue() << "|";
            out << tr->_routeColor.alpha() << "\n";
            int i;            
            foreach (i, tr->_path) {
                out << i << "|";
            }
            out << "\nENDROUTE\n";
        }
        out << "ENDROUTES\n";
        out.flush();
        fileOut.close();
    }
}

void TradeRoute::ReadTradeRoutesFromFile(QVector<QSharedPointer<TradeRoute> >& routes, QString file)
{
    QFile filein(file);
    if (filein.open(QFile::ReadWrite  | QFile::ReadOnly))
    {
        // qDebug() << "Opened file";

        QSharedPointer<TradeRoute> tr;
        QTextStream in(&filein);
        QString line = in.readLine();

        // qDebug() << "Read first line " << line;

        if (line == "TRADEROUTES") //OK
        {            
            //foreach (tr, routes)
            //    delete tr;
            routes.clear();

            // qDebug() << "Former routes have been cleared. ";

            line = in.readLine();
            while (line != "ENDROUTES")
            {
                QString routeName = in.readLine();
                QString routeColors = in.readLine();
                QString pathItems = in.readLine();
                QString pathCount = in.readLine();
                line = in.readLine();

                // qDebug() << "read name " << routeName;
                // qDebug() << "read colors " << routeColors;
                // qDebug() << "read count " << pathCount;
                // qDebug() << "read items " << pathItems;
                // qDebug() << "read line " << line;

                QSharedPointer<TradeRoute> tr(new TradeRoute());
                tr->setRouteName(routeName);
                QStringList lsColor = routeColors.split("|", QString::SkipEmptyParts);
                QStringList lsPath = pathItems.split("|",QString::SkipEmptyParts);
                QColor color;
                color.setRed(lsColor.at(0).toInt());
                color.setGreen(lsColor.at(1).toInt());
                color.setBlue(lsColor.at(2).toInt());
                color.setAlpha(lsColor.at(3).toInt());
                tr->setRouteColor(color);
                QString sPath;
                tr->clearPath();
                foreach (sPath, lsPath)
                    tr->appendToPath(sPath.toInt());
                routes.append(tr);
            }

        }
        // qDebug() << "File closed";
        filein.close();
    }
}
