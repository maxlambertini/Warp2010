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


#ifndef CELESTIAEXPORTER_H
#define CELESTIAEXPORTER_H

#include <QtCore>
#include "star.h" _
#include "starlist.h"
#include "planet.h"

class CelestiaExporter
{
private:
    Star *_star;
    StarList * _starList;

    QString planetToCelestia(Planet& planet, QString starName, QString planetFatherName);


public:
    CelestiaExporter(Star *star) : _star(star)
    {
    }

    inline void setStarList (StarList * sl) { _starList = sl; }

    void saveCelestiaDataToFile(QString &filename);
    void saveStarListToCelestiaFile (QString &filename);
    void saveSolarSystemsToCelestiaFile (QString &filename);

};



#endif // CELESTIAEXPORTER_H


