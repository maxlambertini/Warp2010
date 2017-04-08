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

#include "mainscenehandler.h"
#include "stargraphicsitem.h"
#include "starhexgraphicsitem.h"
#include <QtSvg>
#include <QPrinter>
#include "sceneimageexporter.h"
#include "helpers/printingpreferences.h"
#include "helpers/preferences.h"
#include "helpers/splashscreen.h"
#include "appmessage.h"
#include "starlist.h"
#include "gfx_items/arcgraphicsitem.h"
#include "helpers/parsecstarlisthelper.h"

QBrush starBrushes[8] =
{
    QBrush (QColor("navy")),
    QBrush (QColor("blue")),
    QBrush (QColor("cyan")),
    QBrush (QColor("white")),
    QBrush (QColor("yellow")),
    QBrush (QColor("orange")),
    QBrush (QColor("red")),
    QBrush (QColor("maroon"))
};

int min (int m1, int m2 ) { return m1 < m2 ? m1 : m2; }
int max (int m1, int m2 ) { return m1 >= m2 ? m1 : m2; }

void SceneMediator::initializeRouteColors(int nStep) {
    _routeColors.clear();
    int nDelta = 256/nStep;
    for (int h = 0; h < nStep; h++)
        _routeColors.append(QColor(255,h*nDelta,0,192));
    for (int h = 0; h < nStep; h++)
        _routeColors.append(QColor(255-h*nDelta,255,0,192));
    for (int h = 0; h < nStep; h++)
        _routeColors.append(QColor(0,255-h*nDelta,h*nDelta,192));
    for (int h = 0; h < nStep; h++)
        _routeColors.append(QColor(h*nDelta,0,255,192));
}

void SceneMediator::drawTradeRoutes()
{
    Star *star;
    Star *p1, *p2;
    ArcGraphicsItem *qgline;

    if (_bShowTradeRoute && _tradeRoutes.count() != 0) {
        foreach (star, _starList->stars())
            star->leave();

        TradeRoute *tr;
        int i = 0;
        int dx, dy;
        int nx, ny;

        QFont fontDistance = Preferences::prefsPtr()->fontBody();
        if (_tradeRoutes.count() > 0) {
            foreach (tr, _tradeRoutes)
            {
                nx = 4; ny = 4;
                nx = (i / 4)+1;
                ny = i % 4;

                switch (ny) {
                    case 0:
                        dx = 4*nx; dy = 4*nx; break;
                    case 1:
                        dx = -4*nx; dy = 4*nx; break;
                    case 2:
                        dx = 4*nx; dy = -4*nx;break;
                    case 3:
                        dx = -4*nx; dy = -4*nx; break;
                }

                QPen penLine(tr->routeColor());
                penLine.setWidthF(9);
                for (int idx = 1; idx < tr->path().count(); idx++)
                {
                    p1 = _starList->stars().at(min (tr->path().at(idx-1),tr->path().at(idx)));
                    p2 = _starList->stars().at(max (tr->path().at(idx-1),tr->path().at(idx)));
                    if (!p1->visited() || !p2->visited()) {
                        qgline = new ArcGraphicsItem(
                                this->starX( p1)*_sizeFactor ,
                                this->starY( p1)*_sizeFactor ,
                                this->starX( p2)*_sizeFactor ,
                                this->starY( p2)*_sizeFactor,penLine );

                        _scene->addItem(qgline);
                        qgline->setZValue(700);
                        p1->visit(); p2->visit();

                        float d = p1->distance(p2);
                        QString sDist = QString("%1").arg(d,0,'g',2);

                        QGraphicsTextItem *qgti = _scene->addText(sDist,fontDistance);
                        qgti->setZValue(9600);
                        qgti->setX(qgline->halfway().x());
                        qgti->setY(qgline->halfway().y());
                        qgti->setFont(fontDistance);

                    }
                }
                i++;
            }
        }
    }
}

void SceneMediator::drawStarGraphicsItems()
{
    int h = 0;
    int iStar = 0;
    bool bCanDrawStar = false;
    Star *star;

    for (iStar = 0; iStar < _starList->stars().count(); iStar++)
    {
        star = _starList->stars().at(iStar);
        bCanDrawStar = false;

        if (!_bShowOnlyWorldOnRoutes) {
            bCanDrawStar = true;
            if (_bShowOnlyReachableWorlds && !_starsWithinReach.contains(iStar))
                bCanDrawStar = false;
        }
        else {
            if (_starsInTradeRoutes.contains(iStar))
                bCanDrawStar = true;
            else
                bCanDrawStar = false;
        }


        if (bCanDrawStar) {
            int nIdx = (int)star->starType();
            int posBase = (int)star->x()+(int)star->y()+(int)star->z();

            StarGraphicsItem *sgi = new StarGraphicsItem(
                    star,
                    this->starX( star)*_sizeFactor,
                    this->starY( star)*_sizeFactor,25.0);
            sgi->setPosition(posBase % 4);
            sgi->setStarBrush(starBrushes[nIdx]);
            sgi->setZValue(1500);

            h++;
            _scene->addItem(sgi);
        }
    }
}

void SceneMediator::drawNeighborsRoute()
{
    Star *star;
    Star *p1, *p2;
    ArcGraphicsItem *qgline;
    QPen   penSilver(Preferences::prefsPtr()->colorStarOtherLink());
    penSilver.setWidthF(1);

    if (Preferences::prefsPtr()->drawSecondaryRoutes()) {
        foreach (star, _starList->stars())
            star->leave();

        int iNeighbor;
        for (int idx = 0; idx < _starList->stars().count(); idx++)
        {
            star = _starList->stars().at(idx);
            if (star->path().count()) {
                foreach (iNeighbor,star->neighbors()) {
                    int i1 = min (idx, iNeighbor);
                    int i2 = max (idx,iNeighbor);
                    p1 = _starList->stars().at(i1);
                    p2 = _starList->stars().at(i2);

                    if (!_bShowTradeRoute) {
                        qgline = new ArcGraphicsItem(
                                this->starX(p1)*_sizeFactor,
                                this->starY(p1)*_sizeFactor,
                                this->starX(p2)*_sizeFactor,
                                this->starY(p2)*_sizeFactor,penSilver);
                        _scene->addItem(qgline);
                        qgline->setZValue(-20000);
                    }
                    else {
                        if (_starsInTradeRoutes.contains(i1) && _starsInTradeRoutes.contains(i2))
                        {
                            qgline = new ArcGraphicsItem(
                                    this->starX( p1)*_sizeFactor,
                                    this->starY(p1)*_sizeFactor,
                                    this->starX( p2)*_sizeFactor,
                                    this->starY(p2)*_sizeFactor,penSilver);
                            _scene->addItem(qgline);
                            qgline->setZValue(-20000);

                        }
                    }
                }
            }
        }
    }
}

void SceneMediator::drawToGraphViz(QString &fileName)
{
    Star *star;
    Star *p1, *p2;

    QFile file(fileName);
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream output(&file);

        output << "graph map { \noverlap=false;\nsplines=true;\nranksep=1.5;\n";

        foreach (star, _starList->stars())
            star->setVisited(false);

        foreach (star, _starList->stars())
        {
            int pathCount = star->path().count();
            if (pathCount > 1) {
                for (int w = 1; w < pathCount; w++)
                {
                    p1 = _starList->stars().at(star->path().at(w-1));
                    p2 = _starList->stars().at(star->path().at(w));
                    if (!p1->visited() || !p2->visited())
                    {
                        p1->visit();
                        p2->visit();
                        output << "\"" << p1->starName << "\" -- \"" << p2->starName << "\";\n";
                    }
                }
            }
        }
        output << "\n}\n";
    }
    //file.close();
}

int findMaxLen (QStringList& l) {
    int len = 0;
    QString s;
    foreach (s, l) {
        if (s.length() > len)
            len = s.length();
    }
    return len;
}

void SceneMediator::drawToGML(QString &fileName)
{
    Star *star;
    Star *p1, *p2;


    QFile file(fileName);
    QStringList links;
    if (file.open(QFile::WriteOnly | QFile::Truncate)) {
        QTextStream output(&file);

        output << "Creator\t\"Warp2010\"\nVersion\t2.14\ngraph [\n\thierarchic\t1\n\tdirected\t0\n";

        QString antani = R"(Le ore del mattino
                           Hanno sempre
                           L'oro in bocca)";

        const char colors[][16] = {
            "#FF0000",
            "#FF6000",
            "#FFB000",
            "#FFFF00",
            "#B0FF00",
            "#6FFF00",
            "#00FF00",
            "#00BF40",
            "#008F80",
            "#004FB0",
            "#0000FF",
            "#0060FF",
            "#00B0FF",
            "#00FFFF",
            "#00B0B0",
            "#008080",
        };

        qDebug("QDebug");
        foreach (star, _starList->stars())
            star->setVisited(false);


        qDebug("Nodes");
        int nCount = 0;
        int nFontSize = 15;
        foreach (star, _starList->stars()) {
            if (star->isReference() || star->path().count() > 1) {

                QStringList nameList;
                int l = star->starName.length();
                int rw = l / 10;
                int rm = l % 10;
                for (int hx = 0; hx < rw; hx++) {
                    nameList.append(star->starName.mid(hx*10,10));
                }
                nameList.append(star->starName.mid(rw*10,rm));

                //QStringList nameList = star->starName.split(" ");
                int nWidth = 16 * 10;  // * findMaxLen(nameList);
                int nHeight = nameList.count()*25;
                if (star->isReference()) {
                    nFontSize = 48;
                    nWidth = nWidth*3;
                }
                else
                    nFontSize = 18;
                QString nameComplete = nameList.join("\n");
                output << "    node [\n" << "         id " << nCount << "\n" << "        label \"" << nameComplete << "\"\n";
                QString sColor = "#EEEEEE";
                QString sFontColor = "#000000";
                switch (star->starType()) {
                case NSStar::StarType::stO:
                    sColor = "#CCCCCC";
                    break;
                case NSStar::StarType::stB:
                    sColor = "#0000FF";
                    sFontColor = "#FFFFFF";
                    break;
                case NSStar::StarType::stA:
                    sColor = "#00FFFF";
                    break;
                case NSStar::StarType::stF:
                    sColor = "#FFFFFF";
                    break;
                case NSStar::StarType::stG:
                    sColor = "#FFFF00";
                    break;
                case NSStar::StarType::stK:
                    sColor = "#FF8000";
                    break;
                case NSStar::StarType::stM:
                    sColor = "#C00000";
                    sFontColor = "#FFFFFF";
                    break;
                default:
                    break;

                }
                output << "        graphics\n        [\n";
                output << "            x    " << star->x()*100.0 << " \n";
                output << "            y    " << star->y()*100.0 << " \n";
                output << "            w    " << nWidth << "\n";
                output << "            h    " << nWidth << "\n";
                output << "            type    \"ellipse\"\n";
                output << "            fill    \"" << sColor << "\"\n";

                int hab = star->habitabilityIndex();
                if (hab >0) {
                    output << "            outlineWidth    6\n";
                    output << "            hab-index    " << star->habitabilityIndex() << "\n";
                    QString sColor = "#C07000"; // 1;
                    if (star->habitabilityIndex()> 0)
                        sColor = "#30FF30"; // 1;
                    if (star->habitabilityIndex()> 1)
                        sColor = "#00FF60"; // 1;
                    if (star->habitabilityIndex()> 2)
                        sColor = "#00FFFF"; // 1;
                    if (star->habitabilityIndex()> 4)
                        sColor = "#0000FF"; // 1;
                    output << "            outline    \"" << sColor  << "\"\n";

                }

                output << "        ]\n";
                output << "        LabelGraphics\n        [\n";
                output << "            color    \"" << sFontColor << "\"\n";
                output << "            fontSize    " << nFontSize << "\n";
                output << "\n        ]\n";

                output << "    ]\n";
                star->setVisited(false);
            }
            nCount++;
        }

        nCount = 0;
        int i1,i2,iTmp;

        qDebug("Set visited");
        foreach (star, _starList->stars())
            star->setVisited(false);

        qDebug("Calc edges");
        int myWidth = 0;
        foreach (star, _starList->stars())
        {
            int pathCount = star->path().count();
            int sPath = 15;
            if (pathCount > 1) {
                for (int w = 1; w < pathCount; w++)
                {
                    int myPath = sPath + 1 - w;
                    if (myPath < 0) myPath = 0;
                        myWidth = myPath * 2;
                    if (myWidth < 5) myWidth = 5;
                    QString fillColor = colors[sPath-myPath];
                    i1 = star->path().at(w-1);
                    i2 = star->path().at(w);
                    if (i1 > i2) {
                        iTmp = i1;
                        i1 = i2;
                        i2 = iTmp;
                    }
                    QString key = QString("%1_%2").arg(i1,i2);
                    if (!links.contains(key))
                        links.append(key);
                    p1 = _starList->stars().at(i1);
                    p2 = _starList->stars().at(i2);
                    if (!p1->visited() || !p2->visited())
                    {
                        p1->visit();
                        p2->visit();
                        output << "    edge [\n        source " << star->path().at(w-1) << "\n        target "<< star->path().at(w);
                        output << "\n        label \"" << QString::number( p1->distance(p2),'g',2) << "\"\n";
                        output << "        graphics\n        [\n";
                        output << "            width    "  << QString::number(myWidth) << "\n";
                        output << "            fill    \""<< fillColor <<  "\"\n";
                        output << "\n        ]\n";
                        output << "        labelGraphics\n        [\n";
                        output << "            text    \"" << QString::number( p1->distance(p2),'g',2) << "\"\n";
                        output << "            outline    \"" << fillColor << "\"\n";
                        output << "            fill    \"#FFFFFF\"\n";
                        output << "            fontSize    15\n";
                        output << "            model    \"centered\"\n";
                        output << "            position    \"center\"\n";
                        output << "\n        ]\n";
                        output << "\n    ]\n";
                        //output << "\"" << p1->starName << "\" -- \"" << p2->starName << "\";\n";
                    }
                }
            }
        }

        foreach (star, _starList->stars()) {
            int iNeighbor;
            foreach (iNeighbor, star->neighbors()) {
                if (iNeighbor > nCount) {
                    i1 = nCount;
                    i2 = iNeighbor;
                } else {
                    i1 = iNeighbor;
                    i2 = nCount;
                }
                QString key = QString("%1_%2").arg(i1,i2);
                if (!links.contains(key)) {
                    links.append(key);
                    p1 = _starList->stars().at(i1);
                    p2 = _starList->stars().at(i2);
                    output << "    edge [\n        source " << i1 << "\n        target "<< i2 ;
                    output << "\n        label \"" << QString::number( p1->distance(p2),'g',2) << "\"\n";
                    output << "        graphics\n        [\n";
                    output << "            fill    \"#808080\"\n";
                    output << "            width   2\n";
                    output << "\n        ]\n";
                    output << "        labelGraphics\n        [\n";
                    output << "            text    \"" << QString::number( p1->distance(p2),'g',2) << "\"\n";
                    output << "            outline    \"#808080\"\n";
                    output << "            fill    \"#808080\"\n";
                    output << "            fontSize    10\n";
                    output << "            model    \"centered\"\n";
                    output << "            position    \"center\"\n";
                    output << "\n        ]\n";
                    output << "\n    ]\n";
                }
            }

            nCount++;
        }

        output << "\n]\n";
    }
    //file.close();
}


void SceneMediator::drawOptimalPath()
{
    Star *star;
    Star *p1, *p2;
    ArcGraphicsItem *qgline;
    QColor colorSilver = Preferences::prefsPtr()->colorStarShortestLink();
    QColor colorPen = Preferences::prefsPtr()->colorStarShortestLink();
    colorPen.setAlpha(96);
    colorSilver.setAlpha(96);

    QPen   penSilver(colorSilver);
    QPen   routepen(colorPen);

    penSilver.setWidthF(8);
    routepen.setWidthF(16);


    int colorCount = _routeColors.count();
    this->initializeRouteColors(colorCount/4);

    if (_bShowOptimalPath) {
        QFont fontDistance = Preferences::prefsPtr()->fontBody();
        fontDistance.setPointSizeF(fontDistance.pointSizeF()*0.85);
        foreach (star, _starList->stars()) {
            int pathCount = star->path().count();
            if (pathCount > 1) {
                for (int w = 1; w < pathCount; w++)
                {
                    p1 = _starList->stars().at(min (star->path().at(w-1),star->path().at(w)));
                    p2 = _starList->stars().at(max (star->path().at(w-1),star->path().at(w)));
                    if (!p1->visited() || !p2->visited())
                    {
                        float fWidth = 30 - (float)(w)*1.2;
                        if (fWidth < 4.0)
                            fWidth = 4.0;
                        routepen.setWidthF(fWidth);
                        int nColor = w < colorCount ? w : colorCount -1;
                        routepen.setColor(_routeColors.at(nColor));

                        qgline = new ArcGraphicsItem(
                                this->starX( p1)*_sizeFactor,
                                this->starY( p1)*_sizeFactor,
                                this->starX( p2)*_sizeFactor,
                                this->starY( p2)*_sizeFactor,routepen);
                        _scene->addItem(qgline);
                        qgline->setZValue(1000);

                        float d = p1->distance(p2);
                        QString sDist = QString("%1").arg(d,0,'g',2);

                        QGraphicsTextItem *qgti = _scene->addText(sDist,fontDistance);
                        qgti->setZValue(9600);
                        qgti->setX(qgline->halfway().x());
                        qgti->setY(qgline->halfway().y());
                        qgti->setFont(fontDistance);


                        p1->visit();
                        p2->visit();

                    }
                }
            }
        }
    }
}

void SceneMediator::populateScene()
{
    _scene->clear();
    _scene->setSceneRect(0,0,0,0);

    if (_bShowHexMap) {
        drawHexMap();
        return;
    }

    QColor colorFill(255,128,0,128);
    QColor colorMap(255,64,0,128);
    QColor colorSilver(160,160,160,128);
    QColor colorPen("black");

    QPen   pen(colorPen);
    QPen   routepen(colorMap);
    QPen   penSilver(colorSilver);

    penSilver.setWidthF(8);
    pen.setWidthF(5);
    routepen.setWidthF(16);

    QFont  font("Arial");
    font.setPointSizeF(10);

    TradeRoute *route;
    int iPath;
    _starsInTradeRoutes.clear();
    _starsWithinReach.clear();
    foreach (route, _tradeRoutes) {
        foreach (iPath, route->path())
            if (!_starsInTradeRoutes.contains(iPath))
                _starsInTradeRoutes.append(iPath);
    }
    Star* star;
    int iStar;
    foreach (star, _starList->stars()) {
        if (star->path().count() > 0) {
            foreach (iStar, star->path()) {
                if (!_starsWithinReach.contains(iStar))
                    _starsWithinReach.append(iStar);
            }
        }
    }

    if (this->_starList->count() > 0)
    {
        if (Preferences::prefsPtr()->drawSecondaryRoutes())
            this->drawNeighborsRoute();
        foreach (star, _starList->stars())
            star->leave();

        if (_bShowOptimalPath)
            this->drawOptimalPath();
        this->drawStarGraphicsItems();
        if (_bShowTradeRoute)
            this->drawTradeRoutes();

    }


    QRectF rectScene = this->scene()->itemsBoundingRect();
    rectScene.adjust(
            -rectScene.width()*0.1, -rectScene.height()*0.1,
            rectScene.width()*0.1, rectScene.height()*0.1);

    this->scene()->setSceneRect(rectScene);
}

void SceneMediator::printSectors(QPrinter& printer) {
    SceneImageExporter::printScene(this->scene(), printer);
}

void SceneMediator::exportToImage(QString fileName)
{
     if (!fileName.isNull()) {
        if (fileName.toLower().endsWith(".pdf"))
        {

            QPrinter printer;
            SceneImageExporter sci;
            if (!_bShowHexMap)
            {
                bool bShowOnOneSize = AppMessage::Question("Press Yes to export your map to one single page\n"
                                                              "or press No to use Warp2010 printing options.", "");
                qApp->processEvents();
                SplashScreen::screenPtr()->setMessage("Exporting sector " + _starList->listName() + " to PDF");
                SplashScreen::screenPtr()->show();
                qApp->processEvents();
                sci.GraphicsSceneToPrinter(this->scene(),printer,fileName,_starList->listName(),bShowOnOneSize);
                qApp->processEvents();
                SplashScreen::screenPtr()->hide();
            }
            else {
                bool bShowOnOneSize = AppMessage::Question("Press Yes to export your hexmap to one single PDF\n"
                                                              "or press No have it split in sector according to your\n"
                                                              "printing options.", "");
                qApp->processEvents();
                SplashScreen::screenPtr()->setMessage("Exporting sector " + _starList->listName() + " to PDF");
                SplashScreen::screenPtr()->show();
                qApp->processEvents();

                if (!bShowOnOneSize) {
                  sci.PageGraphicsSceneToPrinter(this->scene(),printer,_travellerSectors,fileName, _starList->listName());
                }
                else {
                    sci.GraphicsSceneToPrinter(this->scene(),printer,fileName,_starList->listName(),bShowOnOneSize);
                }
                qApp->processEvents();
                SplashScreen::screenPtr()->hide();
            }
        }

        else if (fileName.toLower().endsWith(".svg"))
        {
            qApp->processEvents();
            SplashScreen::screenPtr()->setMessage("Exporting sector " + _starList->listName() + " to SVG");
            SplashScreen::screenPtr()->show();
            qApp->processEvents();
            SceneImageExporter::ExportToSVG(this->scene(), fileName);
            qApp->processEvents();
            SplashScreen::screenPtr()->hide();
        }
        else if (fileName.toLower().endsWith(".png"))
        {
            qApp->processEvents();
            SplashScreen::screenPtr()->setMessage("Exporting sector " + _starList->listName() + " to PNG");
            SplashScreen::screenPtr()->show();
            qApp->processEvents();
            SceneImageExporter::ExportToPNG(this->scene(), fileName);
            qApp->processEvents();
            SplashScreen::screenPtr()->hide();
        }
        else {
            //QMessageBox:::message("Select a valid image type (SVG, PNG, PDF)");
        }
     }
}

/*
void SceneMediator::customDrawArc(QPointF p1, QPointF p2, QPen pOrange)
{
    double pi = 3.14159265;
    double dist = sqrt( (p2.x()-p1.x()) * (p2.x()-p1.x()) + (p2.y()-p1.y()) * (p2.y()-p1.y()));
    double radius = dist * .866;
    QPointF pm( (p2.x()+p1.x()) /2, (p2.y()+p1.y())/2);
    double dx = p2.x()-p1.x();
    double dy = p2.y()-p1.y();
    double phi = atan2(dy,dx);

    if (p1.y() < p2.y())
        phi += pi / 2;
    else
        phi -= pi / 2;
    if (pi > 2*pi)
        phi -= (2*pi);

    double cx = pm.x()+radius+cos(phi);
    double cy = pm.y()+radius+sin(phi);
    radius = sqrt( (p2.x()-cx)*(p2.x()-cx) + (p2.y()-cy) * (p2.y()-cy));

    QRectF rect(cx-radius, cy-radius, radius*2, radius*2);

    double phiStart, phiSweep;
    if (p1.y() > p2.y())
    {
        phiStart = atan2( (p1.y()-cy), (p1.x()-cx));
        phiSweep = atan2( (p2.y()-cy), (p2.x()-cx)) - phiStart;
    }
    else
    {
        phiStart = atan2( (p2.y()-cy), (p2.x()-cx));
        phiSweep = atan2( (p1.y()-cy), (p1.x()-cx)) - phiStart;
    }

    if (rect.width() == 0)
        rect.setWidth(0.0001);
    if (rect.height() == 0)
        rect.setHeight(0.0001);

}
*/

void SceneMediator::prepareParsecStarList()
{
    _parsecStarList = StarList::StarListPtr()->prepareParsecStarList(_drawMode);
}

void SceneMediator::setParsecStarOnHexMap(int &maxX, int &maxY, int &minX, int &minY)
{
    bool bCanDrawStar = false;
    Star *myStar;
    ParsecStar ps;
    int h = 0;

    TradeRoute * route;


    for (int idx = 0; idx < _parsecStarList.count(); idx++) {
        ps = _parsecStarList[idx];
        bCanDrawStar = false;

        if (!_bShowOnlyWorldOnRoutes) {
            if (!_bShowOnlyReachableWorlds)
                bCanDrawStar = true;
            else {
                if (_starsWithinReach.contains(idx))
                    bCanDrawStar = true;
                else
                    bCanDrawStar = false;
            }
        }
        else {
            foreach (route, _tradeRoutes) {
                if (route->path().contains(h))
                {
                    bCanDrawStar = true;
                    break;
                }
            }
        }

        //qDebug() << ps.star()->starName << " can be drawn. " << _bShowOnlyWorldOnRoutes;

        h++;
        if (bCanDrawStar) {
            this->minMaxLimitsFromParsecStar(ps, &minX, &minY, &maxX, &maxY);

            myStar = ps.star();


            QPointF ptStar = this->pointFromParsecStar(ps);
            //qDebug() << ps.star()->starName << ps.x() << ps.y() << ps.pr_x() << ps.pr_y() << ptStar;
            int nIdx = (int)myStar->starType();
            double radius = 40.0 - ( (double)ps.z() / 5.0);

            // qDebug() << "Radius: " << "," <<  radius;

            int posBase = (int)myStar->x()+(int)myStar->y()+(int)myStar->z();

            StarGraphicsItem *sgi = new StarGraphicsItem(ps.star(),ptStar.x(), ptStar.y(),radius );
            sgi->setPosition(posBase % 4);
            sgi->setStarBrush(starBrushes[nIdx]);
            _scene->addItem(sgi);
            sgi->setZValue(5500+ ps.z()*10.0);
        }
    }
}

void SceneMediator::drawReachableStarsOnHexMap() {
    QStarList auxStarlist;
    ArcGraphicsItem *qgline;
    QColor colorPen = Preferences::prefsPtr()->colorStarShortestLink();
    colorPen.setAlpha(96);
    QPen penLine(colorPen);
    penLine.setWidthF(4.0);
    if (_bShowOnlyReachableWorlds) {
        QFont fontDistance = Preferences::prefsPtr()->fontBody();

        Star *star;
        for (int h = 0; h < _parsecStarList.count(); h++)
            _parsecStarList[h].leave();

        auxStarlist = _starList->getQStarList();

        int colorCount = _routeColors.count();
        this->initializeRouteColors(colorCount/4);
        for (int h = 0; h < auxStarlist.count(); h++) {
            star = auxStarlist.at(h);
            if (star->path().count()  > 0) {
                int nCount = star->path().count();
                for (int idx = 1; idx < star->path().count(); idx++)
                {
                    ParsecStar& p1 = _parsecStarList[(star->path().at(idx-1))];
                    ParsecStar& p2 = _parsecStarList[(star->path().at(idx))];
                    if (!p1.visited() || !p2.visited()) {

                        QPointF pt1 = this->pointFromParsecStar(p1);
                        QPointF pt2 = this->pointFromParsecStar(p2);

                        //qDebug() << "connecting " << p1.star()->starName << " to " << p2.star()->starName;

                        float fWidth = 30 - (float)(idx)*1.2;
                        if (fWidth < 4.0)
                            fWidth = 4.0;
                        penLine.setWidthF(fWidth);
                        int nColor = idx < colorCount ? idx : colorCount -1;
                        penLine.setColor(_routeColors.at(nColor));

                        qgline = new ArcGraphicsItem(pt1,pt2,penLine);
                        _scene->addItem(qgline);
                        qgline->setZValue(500- (nCount*2));

                        QBrush br = QBrush(QColor("white"));


                        float d = p1.star()->distance(p2.star());
                        QString sDist = QString("%1").arg(d,0,'g',2);

                        QGraphicsTextItem *qgti = _scene->addText(sDist,fontDistance);
                        qgti->setZValue(9600);
                        qgti->setX(qgline->halfway().x());
                        qgti->setY(qgline->halfway().y());
                        qgti->setFont(fontDistance);

                        p1.setVisited(true); p2.setVisited(true);
                    }
                }

            }
        }
    }
}

void SceneMediator::drawTradeRoutesOnHexMap()
{

    if (_bShowTradeRoute && _tradeRoutes.count() != 0) {

        for (int h = 0; h < _parsecStarList.count(); h++)
            _parsecStarList[h].leave();
        TradeRoute *tr;
        int i = 0;
        int dx, dy;
        int nx, ny;

        QFont fontDistance = Preferences::prefsPtr()->fontBody();
        if (_tradeRoutes.count() > 0) {
            foreach (tr, _tradeRoutes)
            {
                // qDebug() << "Exploring " << tr->routeName();
                nx = 4; ny = 4;
                nx = (i / 4)+1;
                ny = i % 4;

                switch (ny) {
                    case 0:
                        dx = 4*nx; dy = 4*nx; break;
                    case 1:
                        dx = -4*nx; dy = 4*nx; break;
                    case 2:
                        dx = 4*nx; dy = -4*nx;break;
                    case 3:
                        dx = -4*nx; dy = -4*nx; break;
                }

                QPen penLine(tr->routeColor());
                penLine.setWidthF(9);

                for (int idx = 1; idx < tr->path().count(); idx++)
                {
                    ParsecStar& p1 = _parsecStarList[(tr->path().at(idx-1))];
                    ParsecStar& p2 = _parsecStarList[(tr->path().at(idx))];
                    if (!p1.visited() || !p2.visited()) {

                        QPointF pt1 = this->pointFromParsecStar(p1);
                        QPointF pt2 = this->pointFromParsecStar(p2);

                        ArcGraphicsItem *qgline = new ArcGraphicsItem(pt1,pt2,penLine);
                        _scene->addItem(qgline);
                        qgline->setZValue(500);

                        double radius1 = 16+40.0 - ( (double)p1.z() / 5.0);
                        double radius2 = 16+40.0 - ( (double)p2.z() / 5.0);
                        QBrush br = QBrush(QColor("white"));
                        penLine.setWidthF(8.0);
                        if (!p1.visited()) {
                            QGraphicsEllipseItem* qg1 = _scene->addEllipse(pt1.x()-radius1,pt1.y()-radius1,radius1*2, radius1*2,penLine,br);
                            qg1->setZValue(400);
                        }
                        if (!p2.visited()) {
                            QGraphicsEllipseItem* qg1 = _scene->addEllipse(pt2.x()-radius2,pt2.y()-radius2,radius2*2, radius2*2,penLine,br);
                            qg1->setZValue(400);
                        }

                        float d = p1.star()->distance(p2.star());
                        QString sDist = QString("%1").arg(d,0,'g',2);

                        QGraphicsTextItem *qgti = _scene->addText(sDist,fontDistance);
                        qgti->setZValue(9600);
                        qgti->setX(qgline->halfway().x());
                        qgti->setY(qgline->halfway().y());
                        qgti->setFont(fontDistance);


                        p1.setVisited(true); p2.setVisited(true);
                    }
                }
                i++;
            }
        }
    }
}


void SceneMediator::drawHexMap()
{
    if (_starList->count() == 0)
        return;
    int maxX=0, maxY=0, minX=0, minY = 0;

    prepareParsecStarList();
    setParsecStarOnHexMap(maxX,maxY, minX, minY);
    //qDebug() << "Reachable Worlds " << _bShowOnlyReachableWorlds
    //        << " World on Routes " << _bShowOnlyWorldOnRoutes;
    if (_bShowOnlyReachableWorlds) {
        //qDebug() << "drawing reachable stars on hexmap";
        drawReachableStarsOnHexMap();
    }
    else {
        if (_bShowOnlyWorldOnRoutes) {
            drawTradeRoutesOnHexMap();
        }
    }


    int hexPerSector = PrintingPreferences::prefsPtr()->hexPerSector();
    //qDebug() << "Hex per sector is: " << PrintingPreferences::prefsPtr()->hexPerSector();

    int d_x = 1+ ((maxX - minX)+2) / hexPerSector;
    int d_y = 1+((maxY - minY)+2) / hexPerSector;

    int xCoord, yCoord;
    QRectF rect00;
    QRectF rect99;
    QRectF rectTotal;
    QRectF rectOuter;
    QRectF rectOuter2;

    _travellerSectors.clear();

    double l_rect,t_rect,r_rect,b_rect;

    qDebug() << "outputting dx" << d_x << ", dy" << d_y << ", hexSize" << _hexSize;
    for (int dy =d_y-1; dy >=0;  dy-- ) {
        for (int dx = 0; dx < d_x; dx++) {
            for (int y = 0; y < hexPerSector; y++ ) {
                for (int x = 0; x < hexPerSector; x++ ) {
                    xCoord = (minX-1) + dx * hexPerSector + x;
                    yCoord = (minY-1) + dy * hexPerSector + y;
                    StarHexGraphicsItem *hex = new StarHexGraphicsItem(
                            0,xCoord,yCoord,_hexSize,
                            Preferences::prefsPtr()->colorDiasporaAspectBox(),
                            Preferences::prefsPtr()->colorDiasporaAspectBackground());

                    hex->setZValue(1000);
                    if (x == 0 && y == 0)
                        rect00 = hex->boundingRect();
                    if ( x == hexPerSector-1 && y == hexPerSector-1) {
                        rect99 = hex->boundingRect();
                        rectTotal = rect00.united(rect99);
                        rectOuter =  rectTotal.adjusted(-rect00.width()/2,-rect00.height()/2,
                                         rect99.width()/2, rect99.height()/2);

                        rectOuter2 =  rectTotal.adjusted(0,0,
                                         -rect99.width()/4, -rect99.height()/2);
                        _travellerSectors.append(SectorRectHolder(rectOuter, rectTotal,dx,dy,true));
                        QGraphicsRectItem *item_rect = new QGraphicsRectItem(rectOuter2);
                        //_scene->addItem(item_rect);
                    }

                    if (_bDrawHexOnHexmap)
                        _scene->addItem(hex);

                }
            }
        }
    }
}

void SceneMediator::drawMetroMap()
{
}


