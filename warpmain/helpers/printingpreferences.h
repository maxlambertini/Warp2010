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


#ifndef PRINTINGPREFERENCES_H
#define PRINTINGPREFERENCES_H

#include <QtCore>
#include <QtGui>

class PrintingPreferences
{
private:
    friend class Cleanup;
    class Cleanup {
    public:
        ~Cleanup();
    };

    static PrintingPreferences _prefs;

    QMap<QString,QSizeF> _measures;

    double _leftMargin;
    double _topMargin;
    double _rightMargin;
    double _bottomMargin;

    int _yDivisions;
    int _hexPerSector;

    QSizeF _selectedMeasure;
    bool _landscape;

    PrintingPreferences();
    ~PrintingPreferences();
    PrintingPreferences (const PrintingPreferences & );
    PrintingPreferences& operator= (const PrintingPreferences&);

public:
    QMap<QString,QSizeF>& measures() { return _measures; }
    static PrintingPreferences& prefs() { return _prefs; }
    static PrintingPreferences* prefsPtr() { return &_prefs; }

    inline double leftMargin() { return _leftMargin; }
    inline double topMargin() { return _topMargin; }
    inline double rightMargin() { return _rightMargin; }
    inline double bottomMargin() { return _bottomMargin; }
    inline int yDivisions() { return _yDivisions; }
    inline QSizeF& selectedMeasure() { return _selectedMeasure; }
    inline bool landscape() {return _landscape;}
    inline bool portrait() {return !_landscape;}
    inline int hexPerSector() { return _hexPerSector;  }

    inline void setLeftMargin( double d) { _leftMargin = d; }
    inline void setRightMargin( double d) { _rightMargin = d; }
    inline void setTopMargin( double d) { _topMargin = d; }
    inline void setBottomMargin( double d) { _bottomMargin= d; }

    inline void setHexPerSector( int d ) { _hexPerSector = d; }
    inline void setYDivisions(int d) { _yDivisions = d; }
    inline void setSelectedMeasure(const QString& measure)  {
        if (_measures.contains(measure))
            _selectedMeasure = _measures[measure];
        else
            _selectedMeasure = QSizeF(210,297); //canonical A4, space standard
    }
    inline void setSelectedMeasure(const QSizeF& size) { _selectedMeasure = size; }
    inline void setLandscape (bool b = false) { _landscape = b; }
    inline void setPortrait  (bool b = true) { _landscape = !b; }
};

#endif // PRINTINGPREFERENCES_H
