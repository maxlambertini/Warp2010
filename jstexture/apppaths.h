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
