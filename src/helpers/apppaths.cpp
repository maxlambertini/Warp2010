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


#include "apppaths.h"


AppPaths::AppPaths()
{
}

QString itemsToCheck[7] =
{
    QString("pics/about_box.jpg"),
    QString("pics/rex_orbiting_horza.jpg"),
    QString("aspectlist.aspect"),
    QString("warp.preferences"),
    QString("50ly.str"),
    QString("100LY.STR"),
    QString("2300AD.STR")
};

QString dirToCheck[2] =
{
    QString("pics"),
    QString("themes")
};


void AppPaths::checkForDirectoriesAndFiles() {

    char * buffer;

    //prima, creiamo le directory
    for (int h = 0; h < DIR_ITEMS; h++ ) {
        QString sPath = AppPaths::appDir() + "/" + dirToCheck[h];
        QDir dir(sPath);
        if (!dir.exists()) {
            dir.mkpath(sPath);
        }
    }
    //poi,  creiamo i files
    for (int h = 0; h < FILE_ITEMS; h++) {
        QFile inFile(":/"+itemsToCheck[h]);
        QFile outFile (AppPaths::appDir()+"/"+ itemsToCheck[h]);
        if (!outFile.exists()) {
            //qDebug() << "creating "+ AppPaths::appDir()+"/"+ itemsToCheck[h];
            if (inFile.open(QIODevice::ReadOnly)) {
                if (outFile.open(QIODevice::WriteOnly | QIODevice::ReadWrite))
                {
                    buffer = new char[8192];
                    qint64 rb = 1;
                    while (rb > 0) {
                        rb = inFile.read (buffer,8192);
                        if (rb > 0)
                            outFile.write(buffer,rb);
                    }
                    outFile.close();
                    inFile.close();
                    delete buffer;
                }
            }
        }
    }
}
