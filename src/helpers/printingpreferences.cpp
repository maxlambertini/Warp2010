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


#include "printingpreferences.h"
#include <QtCore>

//initialize static private members;
//BPrintingPreferences::_prefs;

PrintingPreferences PrintingPreferences::_prefs;

PrintingPreferences::PrintingPreferences() :
        _leftMargin(20),
        _topMargin(20),
        _rightMargin(20),
        _bottomMargin(20),
        _yDivisions(3),
        _hexPerSector(20),
        _selectedMeasure(QSizeF(353,500)),
        _landscape(false)
{
    _measures["A0"]= QSizeF( 841 , 1189 );
    _measures["A1"]= QSizeF( 594 , 841 );
    _measures["A2"]= QSizeF( 420 , 594 );
    _measures["A3"]= QSizeF( 297 , 420 );
    _measures["A4"]= QSizeF( 210 , 297 );
    _measures["A5"]= QSizeF( 148 , 210 );
    _measures["A6"]= QSizeF( 105 , 148 );
    _measures["A7"]= QSizeF( 74 , 105 );
    _measures["A8"]= QSizeF( 52 , 74 );
    _measures["A9"]= QSizeF( 37 , 52 );
    _measures["B0"]= QSizeF( 1000 , 1414 );
    _measures["B1"]= QSizeF( 707 , 1000 );
    _measures["B2"]= QSizeF( 500 , 707 );
    _measures["B3"]= QSizeF( 353 , 500 );
    _measures["B4"]= QSizeF( 250 , 353 );
    _measures["B5"]= QSizeF( 176 , 250 );
    _measures["B6"]= QSizeF( 125 , 176 );
    _measures["B7"]= QSizeF( 88 , 125 );
    _measures["B8"]= QSizeF( 62 , 88 );
    _measures["B9"]= QSizeF( 33 , 62 );
    _measures["B10"]= QSizeF( 31 , 44 );
    _measures["C5E"]= QSizeF( 163 , 229 );
    _measures["Comm10E"]= QSizeF( 105 , 241 );
    _measures["DLE"]= QSizeF( 110 , 220 );
    _measures["Executive"]= QSizeF(190.5 , 254 );
    _measures["Folio"]= QSizeF( 210 , 330 );
    _measures["Ledger"]= QSizeF( 431.8 , 279.4 );
    _measures["Legal"]= QSizeF( 215.9 , 355.6 );
    _measures["Letter"]= QSizeF( 215.9 , 279.4 );
    _measures["Tabloid"]= QSizeF( 279.4 , 431.8 );
}

PrintingPreferences::~PrintingPreferences(){
    //qDebug() << "Printing Preferences destroyed";
}
