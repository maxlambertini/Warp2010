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
