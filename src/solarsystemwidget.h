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

#ifndef SOLARSYSTEMWIDGET_H
#define SOLARSYSTEMWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>
#include "planet.h"
#include "star.h"
#include "math.h"
#include "warpexception.h"
#include "helpers/pixmaphelper.h"

inline double log2(double x) {  return (log10(x))/(log10(2)); }
inline double log4(double x) {  return (log10(x))/(log10(4)); }

static Planet nullPlanet("nullplanet");

namespace SSW {
    enum DisplayMode {
        dmSolarSystem,
        dmSatellite
    };
}

class SolarSystemWidget : public QWidget
{
private:
    QVector<Planet *> _planets;
    int _iStepWidth;
    Star *_star;

    int _currentPlanetIndex;
    Planet *_currentPlanet;
    SSW::DisplayMode _displayMode;

    int _customWidth, _customHeight;

public:   
    SolarSystemWidget(QWidget *parent);

    inline void setPlanets (QVector<Planet *> planets) {
        _planets = planets;
        this->repaint();
    }

    inline void setStar(Star *star) {
        _star = star;
        if (_star == 0) {
            _currentPlanetIndex = -1;
            _currentPlanet = 0;
            return;
        }
        if (_star->planetCount() > 0) {
            _currentPlanetIndex = 0;
        }
        else {
             _currentPlanetIndex = -1;
             _currentPlanet = 0;
         }
        this->repaint();
    }
    inline Star *star() { return _star; }

    inline int currentPlanetIndex() { return _currentPlanetIndex; }
    inline void setCurrentPlanetIndex(int idx) { _currentPlanetIndex = idx; }
    inline SSW::DisplayMode displayMode() { return _displayMode; }
    inline void setDisplayMode(SSW::DisplayMode dm) { _displayMode = dm; }
    inline Planet * currentPlanet() { return _currentPlanet; }

    inline QVector<Planet *> planets() { return _planets; }
    inline void clearPlanets() { _planets.clear(); }

    void paintSolSys(QPainter& painter);
    void paintDivisions(QPainter& painter, int iDiv);
    void paintPlanets(QPainter& painter );

    void exportToImage(QString& filename, int imgWidth, int imgHeight);
    void copyToClipboard();

    inline Planet* next()  {
        if (_star == 0)
            return 0;
        if (_star->planetCount() > 0) {
            int idx = ++_currentPlanetIndex % _star->planetCount();
            _currentPlanetIndex = idx;
            this->repaint();
            Planet * data = const_cast<Planet *>( _star->planets().data());
            return &(data[_currentPlanetIndex]);
        }
        else
            return 0;
    }

    inline Planet* prev() {
        if (_star == 0)
            return 0;
        if (_star->planetCount() > 0) {
            int idx = --_currentPlanetIndex;
            if (idx < 0) {
                idx = 0;
                _currentPlanetIndex = 0;
            }
            this->repaint();
            Planet * data = const_cast<Planet *>( _star->planets().data());
            return &(data[_currentPlanetIndex]);
        }
        else
            return 0;
    }

    inline  Planet* first() {
        if (_star->planetCount()> 0) {
            _currentPlanetIndex = 0;
            this->repaint();
            Planet * data = const_cast<Planet *>( _star->planets().data());
            return &(data[_currentPlanetIndex]);
        }
        else
            return 0;
    }

    inline  Planet* last() {
        if (_star->planetCount() > 0) {
            _currentPlanetIndex = _planets.count()-1;
            this->repaint();
            Planet * data = const_cast<Planet *>( _star->planets().data());
            return &(data[_currentPlanetIndex]);
        }
        else
            return 0;
    }

protected:
    void paintEvent(QPaintEvent *);
};

#endif // SOLARSYSTEMWIDGET_H
