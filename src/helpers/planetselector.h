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


#ifndef PLANETSELECTOR_H
#define PLANETSELECTOR_H

#include <QObject>
#include "planet.h"

class PlanetSelector : public QObject
{
Q_OBJECT
public:
    explicit PlanetSelector(QObject *parent = 0);
    void emitPlanetSelected (Planet *p);

signals:
    void planetSelected(Planet *p);

public slots:

};

#endif // PLANETSELECTOR_H
