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

#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include <QObject>
#include <QtCore>

typedef QVector<int> TWordColl;
typedef QMap<int,TWordColl *> TDistanceMatrix;


class MatrixBuilder : public QObject
{
    Q_OBJECT
public:
    explicit MatrixBuilder(QObject *parent = 0);
    TDistanceMatrix *_lStart, *_lDest, *_distanceMatrix;

    void buildMatrix(int from);

signals:

public slots:

};

#endif // MATRIXBUILDER_H
