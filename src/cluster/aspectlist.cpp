#include <QtCore>
#include "aspectlist.h"
#include "ssg_structures.h"
#include "helpers/apppaths.h"

AspectList::AspectList()
{
}

AspectList AspectList::fromAppDir()
{
    AspectList list;
    QString homeDir = AppPaths::appDir();
    QStringList filters; filters << "*.aspect";

    QDir dir(homeDir);
    dir.setNameFilters(filters);
    QStringList entryList = dir.entryList(QDir::Files);
    QString fileName;
    foreach (fileName, entryList) {
        if (fileName.endsWith("aspect")) {
            QFile file(homeDir+"/"+fileName);
            if (file.open(QIODevice::ReadOnly )) {
                QTextStream data(&file);
                QString line;
                do
                {
                    line = data.readLine();
                    if (!line.isEmpty()) {
                        Aspect aspect = Aspect::FromString(line);
                        list._aspects.append(aspect);
                    }

                } while (!line.isNull());
            }
            file.close();
        }
    }

    return list;
}

//Load aspects from a text file;
AspectList AspectList::fromFile(const QString &filename)
{
    AspectList list;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::ReadWrite)) {
        QTextStream data(&file);
        QString line;
        do
        {
            line = data.readLine();
            if (!line.isEmpty()) {
                Aspect aspect = Aspect::FromString(line);
                list._aspects.append(aspect);
            }


        } while (!line.isNull());
    }
    file.close();
    return list;
}

//draw a random, unextracted aspect
Aspect& AspectList::drawAspect() {
    int nDrawn = _drawnAspects[_currentDrawIndex % _drawnAspects.count()];
    _currentDrawIndex++;
    return _aspects[nDrawn];
}
