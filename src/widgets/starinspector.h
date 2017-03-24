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
