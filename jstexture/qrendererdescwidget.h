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

#ifndef QRENDERERDESCWIDGET_H
#define QRENDERERDESCWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtGradientEditor/qtgradienteditor.h>
#include <texturebuilder/rendererdescriptor.h>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QCheckBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class QRendererDescWidget : public QWidget
{
    Q_OBJECT

    RendererDescriptor *_rendererDescriptor;

    QLineEdit *c_name;
    QComboBox *c_heightMap;
    QComboBox *c_backgroundImage;
    QComboBox *c_destImage;
    QCheckBox *c_enabledLight;
    QCheckBox *c_enableRandomGradient;
    QLineEdit *c_lightContrast;
    QLineEdit *c_lightBrightess;
    QSpinBox *c_randomFactorHue;
    QSpinBox *c_randomFactorSaturation;
    QSpinBox *c_randomFactorValue;

    QStringList _images;
    QStringList _noiseMapBuilders;

public:
    explicit QRendererDescWidget(QWidget *parent = 0);

    RendererDescriptor* rendererDescriptor() { return _rendererDescriptor; }
    void setRendererDescriptor (RendererDescriptor *v) { _rendererDescriptor = v; readFromRendererDescriptor();}
    void createWidgets();
    void fillRendererDescriptor();
    void readFromRendererDescriptor();
    void setImageList(QStringList& i);
    void setNoiseMapList(QStringList& i);

signals:

public slots:
};

#endif // QRENDERERDESCWIDGET_H
