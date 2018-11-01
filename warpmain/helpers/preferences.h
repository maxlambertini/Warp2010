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


#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QtCore>
#include <QtGui>


class Preferences
{
private:
    friend class Cleanup;
    class Cleanup {
    public:
        ~Cleanup();
    };

    //private members;
    QFont _fontTitle = QFont("Sans Serif",16,1);
    QFont _fontAspectTitle = QFont("Sans Serif",16,1);
    QFont _fontBody = QFont("Sans Serif",11,1);
    QFont _fontSmall = QFont("Sans Serif",9,1);

    QColor _colorDiasporaLink = QColor(0,128,255);
    QColor _colorDiasporaAspectBox =QColor(0,0,128);
    QColor _colorDiasporaAspectBackground =QColor(240,240,240);
    QColor _colorStarShortestLink =QColor(0,0,128);
    QColor _colorStarOtherLink =QColor(192,192,192);

    qreal  _sizeTitle=16.0;
    qreal  _sizeAspectTitle =16.0;
    qreal  _sizeBody = 11.0;
    qreal  _sizeSmall = 9.0;

    bool _drawRoutesAsArcs = true;
    bool _drawSecondaryRoutes = true;

    double _secondaryRouteWidth = 2.0;
    int    _hexPerSector = 10.0;
    double _parsecStarFactor = 1.67;

    static Preferences _prefs;

    Preferences();
    ~Preferences();
    Preferences (const Preferences & );
    Preferences& operator= (const Preferences&);


public:

    int hexPerSector() { return _hexPerSector; }
    double secondaryRouteWidth() { return _secondaryRouteWidth; }
    double parsecStarFactor() { return _parsecStarFactor; }

    void setHexPerSector( int v ) {_hexPerSector = v; }
    void setSecondaryRouteWidth( double v) { _secondaryRouteWidth = v; }
    void setParsecStarFactor( double v) { _parsecStarFactor = v; }

    static Preferences &prefs();
    static Preferences *prefsPtr();

    QFont& fontTitle()  { return _fontTitle; }
    QFont& fontAspectTitle()  { return _fontAspectTitle; }
    QFont& fontBody()  { return _fontBody; }
    QFont& fontSmall()  { return _fontSmall; }

    QColor& colorDiasporaLink()  { return _colorDiasporaLink; }
    QColor& colorDiasporaAspectBox()  { return _colorDiasporaAspectBox; }
    QColor& colorDiasporaAspectBackground()  { return _colorDiasporaAspectBackground; }
    QColor& colorStarShortestLink()  { return _colorStarShortestLink; }
    QColor& colorStarOtherLink()  { return _colorStarOtherLink; }

    bool drawRoutesAsArcs() { return _drawRoutesAsArcs;}
    bool drawSecondaryRoutes() { return _drawSecondaryRoutes;}

    void setDrawRoutesAsArcs(bool b) { _drawRoutesAsArcs = b;}
    void setDrawSecondaryRoutes(bool b)  { _drawSecondaryRoutes = b;}

    void setFontTitle(const QFont& f) { _fontTitle = f; }
    void setFontAspectTitle(const QFont& f) { _fontAspectTitle = f; }
    void setFontBody(const QFont& f) { _fontBody = f; }
    void setFontSmall(const QFont& f) { _fontSmall = f; }

    void setColorDiasporaLink(const QColor& c) {_colorDiasporaLink = c;}
    void setColorDiasporaAspectBox(const QColor& c) { _colorDiasporaAspectBox = c; }
    void setColorDiasporaAspectBackground(const QColor& c) { _colorDiasporaAspectBackground = c; }
    void setColorStarShortestLink(const QColor& c) { _colorStarShortestLink = c; }
    void setColorStarOtherLink(const QColor& c) { _colorStarOtherLink = c; }



    friend QDataStream & operator >> (QDataStream &in, Preferences& frm);
    friend QDataStream& operator << (QDataStream &out, const Preferences& frm);

    static void savePreferences() ;
    static void loadPreferences();

};



#endif // PREFERENCES_H
