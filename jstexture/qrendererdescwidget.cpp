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

#include "qrendererdescwidget.h"


QRendererDescWidget::QRendererDescWidget(QWidget *parent) : QWidget(parent)
{
    createWidgets();
}

void QRendererDescWidget::createWidgets() {
    auto gridLayout = new QGridLayout(this);

    int nRow = 0;
    c_name = new QLineEdit(this);
    c_name->setObjectName("Renderer Name");
    gridLayout->addWidget(new QLabel("name",this),nRow,0);
    gridLayout->addWidget(c_name,nRow,1);

    nRow += 1;
    c_heightMap = new QComboBox(this);
    c_heightMap->setObjectName("Noise Map");
    gridLayout->addWidget(new QLabel("noiseMap",this),nRow,0);
    gridLayout->addWidget(c_heightMap,nRow,1);

    nRow += 1;
    c_bumpMap = new QComboBox(this);
    c_bumpMap->setObjectName("Bump Map");
    gridLayout->addWidget(new QLabel("bumpMap",this),nRow,0);
    gridLayout->addWidget(c_bumpMap,nRow,1);

    nRow += 1;
    c_backgroundImage = new QComboBox(this);
    c_backgroundImage->setObjectName("Background Image");
    gridLayout->addWidget(new QLabel("backgroundImage",this),nRow,0);
    gridLayout->addWidget(c_backgroundImage,nRow,1);

    nRow += 1;
    c_destImage = new QComboBox(this);
    c_destImage->setObjectName("Dest Image");
    gridLayout->addWidget(new QLabel("destImage",this),nRow,0);
    gridLayout->addWidget(c_destImage,nRow,1);

    nRow += 1;
    c_alphaImage = new QComboBox(this);
    c_alphaImage->setObjectName("Alpha Image");
    gridLayout->addWidget(new QLabel("alphaImage",this),nRow,0);
    gridLayout->addWidget(c_alphaImage,nRow,1);

    nRow += 1;
    c_enableRandomGradient = new QCheckBox(this);
    c_enableRandomGradient->setObjectName("Random Gradient?");
    gridLayout->addWidget(new QLabel("Random Gradient",this),nRow,0);
    gridLayout->addWidget(c_enableRandomGradient,nRow,1);

    nRow += 1;
    c_enabledLight = new QCheckBox(this);
    c_enabledLight->setObjectName("Light enabled?");
    gridLayout->addWidget(new QLabel("enabledLight",this),nRow,0);
    gridLayout->addWidget(c_enabledLight,nRow,1);


    nRow += 1;
    c_lightContrast = new QLineEdit(this);
    c_lightContrast->setObjectName("Contrast Level");
    c_lightContrast->setText("0.0001");
    auto v1 = new QDoubleValidator(0.0001, 9999.9,4,this);
    c_lightContrast->setValidator(v1);
    gridLayout->addWidget(new QLabel("lightContrast",this),nRow,0);
    gridLayout->addWidget(c_lightContrast,nRow,1);

    nRow += 1;
    c_lightBrightess = new QLineEdit(this);
    c_lightBrightess->setObjectName("Brightness Level");
    c_lightBrightess->setValidator(v1);
    c_lightBrightess->setText("0.0001");
    gridLayout->addWidget(new QLabel("lightBrightess",this),nRow,0);
    gridLayout->addWidget(c_lightBrightess,nRow,1);

    nRow += 1;
    c_randomFactorHue = new QSpinBox(this);
    c_randomFactorHue->setMaximum(250);
    c_randomFactorHue->setMinimum(0);
    c_randomFactorHue->setValue(0);
    c_randomFactorHue->setObjectName("Hue Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorHue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorHue,nRow,1);

    nRow += 1;
    c_randomFactorSaturation = new QSpinBox(this);
    c_randomFactorSaturation->setMaximum(250);
    c_randomFactorSaturation->setMinimum(0);
    c_randomFactorSaturation->setValue(0);
    c_randomFactorSaturation->setObjectName("Saturation Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorSaturation",this),nRow,0);
    gridLayout->addWidget(c_randomFactorSaturation,nRow,1);

    nRow += 1;
    c_randomFactorValue = new QSpinBox(this);
    c_randomFactorValue->setMaximum(250);
    c_randomFactorValue->setMinimum(0);
    c_randomFactorValue->setValue(0);
    c_randomFactorValue->setObjectName("Value Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorValue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorValue,nRow,1);

    this->setLayout(gridLayout);

}

void QRendererDescWidget::fillRendererDescriptor() {
    _rendererDescriptor->setBackgroundImage(this->c_backgroundImage->currentText());
    _rendererDescriptor->setDestImage(this->c_destImage->currentText());
    _rendererDescriptor->setAlphaImage(this->c_alphaImage->currentText());
    _rendererDescriptor->setEnabledlight(this->c_enabledLight->isChecked());
    _rendererDescriptor->setLightbrightness(this->c_lightBrightess->text().toDouble());
    _rendererDescriptor->setLightcontrast(this->c_lightContrast->text().toDouble());
    _rendererDescriptor->setName(this->c_name->text());
    _rendererDescriptor->setHeightmap(this->c_heightMap->currentText());
    _rendererDescriptor->setBumpMap(this->c_bumpMap->currentText());
    _rendererDescriptor->setRandomFactor(
                c_randomFactorHue->value(),
                c_randomFactorSaturation->value(),
                c_randomFactorSaturation->value());
    _rendererDescriptor->setRandomGradient(c_enableRandomGradient->isChecked());


}

void QRendererDescWidget::readFromRendererDescriptor() {
    this->c_backgroundImage->setCurrentText(_rendererDescriptor->backgroundImage());
    this->c_destImage->setCurrentText(_rendererDescriptor->destImage());
    this->c_alphaImage->setCurrentText(_rendererDescriptor->alphaImage());

    this->c_enabledLight->setChecked(_rendererDescriptor->enabledLight());
    this->c_enableRandomGradient->setChecked(_rendererDescriptor->randomGradient());
    this->c_lightBrightess->setText(QString("%1").arg(_rendererDescriptor->lightBrightness()));
    this->c_lightContrast->setText(QString("%1").arg(_rendererDescriptor->lightContrast()));
    this->c_name->setText(_rendererDescriptor->name());
    this->c_heightMap->setCurrentText(_rendererDescriptor->heightMap());
    this->c_bumpMap->setCurrentText(_rendererDescriptor->bumpMap());
    c_randomFactorHue->setValue(_rendererDescriptor->rndHue());
    c_randomFactorSaturation->setValue(_rendererDescriptor->rndSaturation());
    c_randomFactorValue->setValue(_rendererDescriptor->rndValue());
}

void QRendererDescWidget::setImageList(QStringList &i) {
    _images = i;
    this->c_backgroundImage->clear();
    this->c_backgroundImage->addItem("");
    this->c_backgroundImage->addItems(_images);
    this->c_destImage->clear();
    this->c_destImage->addItem("");
    this->c_destImage->addItems(_images);
    this->c_alphaImage->clear();
    this->c_alphaImage->addItem("");
    this->c_alphaImage->addItems(_images);
}

void QRendererDescWidget::setNoiseMapList(QStringList &i)
{
    _noiseMapBuilders = i;
    this->c_heightMap->clear();
    this->c_heightMap->addItem("");
    this->c_heightMap->addItems(_noiseMapBuilders);
    this->c_bumpMap->clear();
    this->c_bumpMap->addItem("");
    this->c_bumpMap->addItems(_noiseMapBuilders);
}
