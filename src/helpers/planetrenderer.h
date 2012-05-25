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


#ifndef PLANETRENDERER_H
#define PLANETRENDERER_H

#include <QtCore>
#include "planet.h"

class PlanetRenderer : public QObject
{
    PlanetRenderer();
    ~PlanetRenderer();
    PlanetRenderer (const PlanetRenderer & );
    PlanetRenderer& operator= (const PlanetRenderer&);

    static PlanetRenderer _current;

    QPointer<Planet> _planet;
public:
    static PlanetRenderer *current() { return &_current; }
    void setPlanet(Planet *p) { _planet = p; }
    Planet *planet()  { return _planet.isNull() ? 0 : _planet ; }

    QString description();
    QString smallDescription();

signals:

public slots:

};

#endif // PLANETRENDERER_H
