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


#ifndef APPPATHS_H
#define APPPATHS_H

#include <QtCore/QString>
#include <QtCore/QDir>
#include <QtCore>

const int FILE_ITEMS = 7;
const int DIR_ITEMS = 2;


class AppPaths
{
public:
    AppPaths();
    inline static QString appDir() {
    #if defined(Q_WS_WIN)
        QString appDirPath = QCoreApplication::applicationDirPath()+"/Warp2010_Data";
        //qDebug() << appDirPath;
        return appDirPath;
    #else
        QString warpPath =  QDir::homePath()+"/Warp2010_Data";
        QDir dir(warpPath);
        if (!dir.exists(warpPath)) {
            dir.mkpath(warpPath);

        }
        return warpPath;
    #endif
    }

    static void checkForDirectoriesAndFiles() ;


    inline static QString pluginsDir() {
        QString pluginPath = appDir()+"/plugins";
        QDir dir(pluginPath);
        if (!dir.exists(pluginPath)) {
            dir.mkpath(pluginPath);

        }
        return pluginPath;
    }

    inline static QString themesDir()  {
        QString pluginPath = appDir()+"/themes/default";
        QDir dir(pluginPath);
        if (!dir.exists(pluginPath)) {
            dir.mkpath(pluginPath);

        }
        return pluginPath;
    }

    inline static QString preferencesFile() {
        return appDir()+"/warp.preferences";
    }

    inline static QString aspectsFile() {
        return appDir()+"/aspectlist.aspect";
    }


};

#endif // APPPATHS_H
