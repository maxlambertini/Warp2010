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

#ifndef MAINSCENEHANDLER_H
#define MAINSCENEHANDLER_H



#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>
#include <QPrinter>
#include "star.h"
#include "starlist.h"
#include "traderoute.h"
#include "helpers/splashscreen.h"
#include "helpers/sectorrectholder.h"
#include "helpers/parsecstarlisthelper.h"

namespace ParsecStarMode {
    const int DrawEverything = 0;
    const int DrawReachableStarsAndOtherRoutes = 1;
    const int DrawReachableStars = 2;
    const int DrawTradeRoutes = 3;
}

int min (int m1, int m2 );
int max (int m1, int m2 );


//class that puts a star into a wrapper object which has its coordinates
//expressed in integer parsec.


class SceneMediator {

private:


    QGraphicsScene* _scene;
    bool _bShowOnlyWorldOnRoutes;
    bool _bShowHexMap;
    bool _bShowMetroMap;
    bool _bShowOnlyReachableWorlds;
    bool _bDrawHexOnHexmap;
    int _sizeFactor;
    int _hexSize;

    StarList* _starList;

    QVector<QSharedPointer<TradeRoute> > _tradeRoutes;
    QVector<ParsecStar> _parsecStarList;
    QList<int> _starsInTradeRoutes;
    QList<int> _starsWithinReach;
    QList<SectorRectHolder> _travellerSectors;
    QList<QColor> _routeColors;


    bool _bShowNeighborsRoute;
    bool _bShowOptimalPath;
    bool _bShowTradeRoute;

    void drawMetroMap();
    void drawHexMap();

    void drawNeighborsRoute();
    void drawOptimalPath();
    void drawStarGraphicsItems();
    void drawTradeRoutes();


    void prepareParsecStarList();
    void setParsecStarOnHexMap(int &maxX, int &maxY, int &minX, int &minY);
    void drawTradeRoutesOnHexMap();
    void drawReachableStarsOnHexMap();


    void initializeRouteColors(int nStep=4);

    SceneMediatorDrawMode::DrawMode _drawMode;

    bool _exportDirectPathOnly = false;
    bool _exportGardenPathOnly = false;


public:

    void drawToGraphViz(QString& fileName);
    void drawToGML(QString& fileName);
    void drawToGraphML(QString& fileName);
    void setSizeFactor(int i) { _sizeFactor = i; }
    int sizeFactor() { return _sizeFactor; }

    void setHexSize(int i) { _hexSize = i; }
    int hexSize() { return _hexSize; }

    inline const QList<SectorRectHolder>& travellerSectors() { return _travellerSectors; }

    inline double hexHeight() { return _hexSize * .866025; }

    inline void minMaxLimitsFromParsecStar (ParsecStar& ps, int *minX, int*minY, int *maxX, int *maxY)
    {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            if (ps.x() > *maxX) *maxX = ps.x();
            if (ps.y() > *maxY) *maxY = ps.y();
            if (ps.x() < *minX) *minX = ps.x();
            if (ps.y() < *minY) *minY = ps.y();
            break;
        case SceneMediatorDrawMode::XZ:
            if (ps.x() > *maxX) *maxX = ps.x();
            if (ps.z() > *maxY) *maxY = ps.z();
            if (ps.x() < *minX) *minX = ps.x();
            if (ps.z() < *minY) *minY = ps.z();
            break;
        case SceneMediatorDrawMode::YZ:
            if (ps.y() > *maxX) *maxX = ps.y();
            if (ps.z() > *maxY) *maxY = ps.z();
            if (ps.y() < *minX) *minX = ps.y();
            if (ps.z() < *minY) *minY = ps.z();
            break;
        };

    }

    inline QPointF pointFromParsecStar(ParsecStar& ps) {
        double dy,x,y;
        switch (_drawMode) {
            /*
        case SceneMediatorDrawMode::XY:
            dy =  (ps.x() % 2 == 0) ? 0 : this->hexHeight();
            x = _hexSize*1.5*(double)(ps.x());
            y = -  (dy + (_hexSize*1.73205*(double)(ps.y())));
            return QPointF(x,y);
            break;
        case SceneMediatorDrawMode::XZ:
            dy =  (ps.x() % 2 == 0) ? 0 : this->hexHeight();
            x = _hexSize*1.5*(double)(ps.x());
            y = -  (dy + (_hexSize*1.73205*(double)(ps.z())));
            return QPointF(x,y);
            break;
        case SceneMediatorDrawMode::YZ:
            dy =  (ps.y() % 2 == 0) ? 0 : this->hexHeight();
            x = _hexSize*1.5*(double)(ps.y());
            y = -  (dy + (_hexSize*1.73205*(double)(ps.z())));
            return QPointF(x,y);
            break;
            */
        default:
            dy =  (ps.x() % 2 == 0) ? 0 : this->hexHeight();
            x = _hexSize*1.5*(double)(ps.x());
            y = -  (dy + (_hexSize*1.73205*(double)(ps.y())));
            return QPointF(x,y);
            break;
        }



    }

    QGraphicsScene* scene() { return _scene; }

    void setScene(QGraphicsScene *s) { _scene = s; }
    //void customDrawArc(QPointF p1, QPointF p2, QPen pOrange);


    bool showNeighborsRoute() const { return _bShowNeighborsRoute; }
    bool showOptimalPath() const { return _bShowOptimalPath; }
    bool showTradeRoute() const { return _bShowTradeRoute; }
    bool showOnlyWorldOnRoutes() const { return _bShowOnlyWorldOnRoutes; }
    bool showOnlyReachableWorlds() const { return _bShowOnlyReachableWorlds; }
    bool showHexMap() const { return _bShowHexMap; }
    bool showMetroMap() const { return _bShowMetroMap; }
    bool showHexOnHexMap() const { return _bDrawHexOnHexmap; }

    void setShowNeighborsRoute(bool b) { _bShowNeighborsRoute = b; }
    void setShowOptimalPath(bool b) { _bShowOptimalPath = b; }
    void setShowTradeRoute(bool b) { _bShowTradeRoute = b; }
    void setShowOnlyWorldOnRoutes(bool b) { _bShowOnlyWorldOnRoutes = b;}
    void setShowOnlyReachableWorlds(bool b) { _bShowOnlyReachableWorlds = b; }
    void setShowHexMap(bool b) { _bShowHexMap = b; }
    void setShowMetroMap(bool b) { _bShowMetroMap = b;}
    void setShowHexOnHexMap(bool b) { _bDrawHexOnHexmap = b; }

    void setStarList (StarList * sl) {
        _starList = sl;        
    }
    void setTradeRoute (QVector<QSharedPointer<TradeRoute> >  tr) { _tradeRoutes = tr; }
    void clearTradeRoute() { _tradeRoutes.clear(); }

    SceneMediator(QGraphicsScene* newScene) :
    _scene(newScene),
    _bShowOnlyWorldOnRoutes(true),
    _bShowHexMap(true),
    _bShowMetroMap(false),
    _bShowOnlyReachableWorlds(false),
    _bDrawHexOnHexmap(true),
    _sizeFactor(75),
    _hexSize(100),
    _drawMode(SceneMediatorDrawMode::XY)
    {
        initializeRouteColors(6);
    }
    void populateScene();
    void exportToImage(QString);

    void redrawScene() {
        qApp->processEvents();
        SplashScreen::screenPtr()->setMessage("Redrawing Scene");
        SplashScreen::screenPtr()->show();
        qApp->processEvents();

        this->_scene->clear();
        this->populateScene();

        qApp->processEvents();
        SplashScreen::screenPtr()->hide();
    }

    void printSectors(QPrinter& printer);

    SceneMediatorDrawMode::DrawMode drawMode() { return _drawMode; }
    void setDrawMode(SceneMediatorDrawMode::DrawMode dm) { _drawMode = dm; }

    inline double starX(Star *p) {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            return p->x();
            break;
        case SceneMediatorDrawMode::XZ:
            return p->x();
            break;
        case SceneMediatorDrawMode::YZ:
            return p->y();
            break;
        default:
            return p->x();
            break;

        };
    }

    inline double starY(Star *p) {
        switch (_drawMode) {
        case SceneMediatorDrawMode::XY:
            return -p->y();
            break;
        case SceneMediatorDrawMode::XZ:
            return -p->z();
            break;
        case SceneMediatorDrawMode::YZ:
            return -p->z();
            break;
        default:
            return p->z();
            break;

        };
    }

    void setExportDirectPathOnly (bool b = false) { _exportDirectPathOnly = b; }
    void setExportGardenPathOnly (bool b = false) { _exportGardenPathOnly = b; }



};



#endif // MAINSCENEHANDLER_H
