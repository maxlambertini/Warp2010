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

#ifndef STARINSPECTOR_H
#define STARINSPECTOR_H

#include <QtGui>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include "star.h"
#include "widgets/basicstarinfowidget.h"

class StarInspector : public QWidget
{
Q_OBJECT
private:
    QGridLayout *gridLayout;
    QLabel *_l1;
    QLabel *_l2;
    QLabel *_l3;
    QLabel *_l4;
    QLabel *_l5;
    QLabel *_l6;
    QLabel *_l7;
    QLabel *_l8;
    QLabel *_l9;

    QLineEdit *lblStarName;
    QLineEdit *lblStarFullType;
    QRegExpValidator *validator;
    QLabel *lblMagnitude;
    QLabel *lblSolarMass;
    QLabel *lblSolarAge;
    QLabel *lblTemperature;
    QLabel *lblDiameter;
    QLabel *lblLifeZones;
    QLabel *lblCoordinates;

    QListWidget *lstNeighbors;

    BasicStarInfoWidget* _starRepr;

    Star * _star;

    QVector<int> vectNeighbors;

public:
    explicit StarInspector(QWidget *parent = 0);
    void setStar (Star * s) { _star = s; setStarData(); }
    Star* star() { return _star; }

    void createWidgets();
    void layoutWidgets();
    void setStarData();

signals:
    void starNameChanged(QString& name);
    void starTypeChanged(QString& type);
    void neighborSelected (QString& starName);
    void neighborSelected (int starIdx);

public slots:
    void editingFinished();
    void starTypeEditingChanged();
    void lstNeighborsSelectionChanged();
    void lstNeighborsCurrentRowChanged(QListWidgetItem *qwi);
};

#endif // STARINSPECTOR_H
