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


#include "pixmaphelper.h"

QString pixmaps[] = {
        "",
        ":/Solsys/pics/Planets/Chunk.png",
        ":/Solsys/pics/Planets/Rockball.png",
        ":/Solsys/pics/Planets/Desert.png",
        ":/Solsys/pics/Planets/HotHouse.png",
        ":/Solsys/pics/Planets/Glacier.png",
        ":/Solsys/pics/Planets/Terrestrial.png",
        ":/Solsys/pics/Planets/Marginal.png",
        ":/Solsys/pics/Planets/Marginal.png",
        ":/Solsys/pics/Planets/GasGiant.png",
        ":/Solsys/pics/Planets/SuperJovian.png",
        ":/Solsys/pics/Planets/SmallPlanet.png",
        ":/Solsys/pics/Planets/Iceball.png"
    };

#define MIN_ARR  1
#define MAX_ARR 12

PixmapHelper PixmapHelper::_instance;

PixmapHelper::PixmapHelper()
{
}

PixmapHelper::~PixmapHelper()
{
    //qDebug() << "Destroying pixmap helper";
}

void PixmapHelper::initializeBitmaps() {
    for (int i = MIN_ARR; i <= MAX_ARR; i++)
       _pixHash[pixmaps[i]] = QPixmap(pixmaps[i]);

}

QPixmap* PixmapHelper::planetaryPics(int i) {
    if (i < MIN_ARR || i > MAX_ARR)
        return 0;
    else {
        return &(_pixHash[pixmaps[i]]);
    }
}
