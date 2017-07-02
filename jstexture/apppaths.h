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

#ifndef APPPATHS_H
#define APPPATHS_H

#include <QString>
#include <QDir>

class AppPaths
{
public:
    AppPaths();
    inline static QString appDir() {
    #if defined(Q_WS_WIN)
        QString appDirPath = QCoreApplication::applicationDirPath()+"/Warp2010_Data/jstexture";
        //qDebug() << appDirPath;
        QDir dir(appDirPath);
        if (!dir.exists(appDirPath)) {
            dir.mkpath(appDirPath);

        }
        return appDirPath;
    #else
        QString warpPath =  QDir::homePath()+"/.local/share/Warp2010_Data/jstexture";
        QDir dir(warpPath);
        if (!dir.exists(warpPath)) {
            dir.mkpath(warpPath);

        }
        return warpPath;
    }
    #endif
};

#endif // APPPATHS_H
