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

#ifndef HEIGHTMAPBUILDERWIDGET_H
#define HEIGHTMAPBUILDERWIDGET_H

#include <QWidget>
#include <texturebuilder/noisemapbuilderdescriptor.h>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QComboBox>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>

class HeightMapBuilderWidget : public QWidget
{
    Q_OBJECT

    NoiseMapBuilderDescriptor* _builder;



    QGridLayout *_grid;

    QLabel    *_lbl;
    QLineEdit *_name;
    QComboBox *_source;
    QComboBox *_dest;
    QLineEdit *_sizeX;
    QLineEdit *_sizeY;
    QLineEdit *_topAngle;
    QLineEdit *_bottomAngle;
    QLineEdit *_leftAngle;
    QLineEdit *_rightAngle;
    QComboBox *_type;
    QCheckBox *_seamless;

    QStringList _moduleList;
    QStringList _noiseMapList;

public:
    NoiseMapBuilderDescriptor* builder() { return _builder; }
    void setBuilder(NoiseMapBuilderDescriptor *p) { _builder = p; }
    explicit HeightMapBuilderWidget(NoiseMapBuilderDescriptor *ptr,
                                    QWidget *parent = 0);
    void initBuilder();
    void createWidgets();
    void fillBuilder();
    void fillWidgetWithBuilder();
    void setModuleList (QStringList& i);
    void setNoiseMapList (QStringList& i);
signals:

public slots:
};

#endif // HEIGHTMAPBUILDERWIDGET_H
