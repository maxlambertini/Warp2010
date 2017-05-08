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
