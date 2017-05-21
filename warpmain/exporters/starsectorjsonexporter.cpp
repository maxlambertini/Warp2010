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


#include "starsectorjsonexporter.h"
#include <starlist.h>
#include <traderoute.h>
#include <traderoutemediator.h>

StarSectorJsonExporter::StarSectorJsonExporter()
{

}

void StarSectorJsonExporter::saveToJson (QString filename) {
    QJsonObject oStarlist, oMediator;
    _starList->toJson(oStarlist);
    _tradeRouteMediator->toJson(oMediator);
    QJsonObject oDef;
    oDef["starList"] = oStarlist;
    oDef["tradeRoutes"] = oMediator;
    QJsonDocument doc(oDef);
    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
        data.write(doc.toJson());
     }
     data.close();
}

void StarSectorJsonExporter::loadFromJson (QString filename) {
    QFile data (filename);
     if (data.open(QFile::ReadOnly | QFile::Text)) {
         QByteArray json = data.readAll();
        QJsonDocument doc = QJsonDocument::fromJson(json);
        auto oStuff = doc.object();
        QJsonObject oStarlist = oStuff["starList"].toObject();
        QJsonObject oMediator = oStuff["tradeRoutes"].toObject();
        this->_starList ->fromJson(oStarlist);
        this->_tradeRouteMediator->fromJson(oMediator);
     }
     data.close();
}
