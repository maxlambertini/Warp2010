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

#include <QtCore>
#include "aspectlist.h"
#include "ssg_structures.h"
#include <diasporapaths.h>

AspectList::AspectList()
{
}

AspectList AspectList::fromAppDir()
{
    AspectList list;
    QString homeDir = DiasporaPaths::appDir();
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
