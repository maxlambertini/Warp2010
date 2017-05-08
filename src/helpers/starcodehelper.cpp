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


#include "starcodehelper.h"
#include "ssg_structures.h"
#include <QString>

StarCodeHelper::StarCodeHelper()
{
}

QString StarCodeHelper::createStarCode() {
    QString starCode;

    int dStep = SSGX::d100();
    if (dStep == 1)
        starCode.append("O");
    else if (dStep == 2)
        starCode.append("B");
    else if (dStep >= 3 && dStep <= 4)
        starCode.append("A");
    else if (dStep >= 5 && dStep <= 8)
        starCode.append("F");
    else if (dStep >= 9 && dStep <= 30)
        starCode.append("G");
    else if (dStep >= 31 && dStep <= 60)
        starCode.append("K");
    else if (dStep >= 61 && dStep <= 94)
        starCode.append("M");
    else if (dStep >= 95)
        starCode.append("d");

     starCode.append(QString("%1").arg(SSGX::d10()-1));



    int lumClass = SSGX::d100();
    if (lumClass == 1)
       starCode.append("II");
    else if (lumClass == 2)
       starCode.append("III");
    else if (lumClass >=3 && lumClass <= 30)
       starCode.append("IV");
    else if (lumClass >=31 && lumClass <= 85)
       starCode.append("V");
    else if (lumClass >=86 && lumClass <= 97)
       starCode.append("VI");
    else if (lumClass >=98)
       starCode.append("VII");

    return starCode;

}
