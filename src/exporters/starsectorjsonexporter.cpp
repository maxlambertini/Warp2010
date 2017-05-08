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
