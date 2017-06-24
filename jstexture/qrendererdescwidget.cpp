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
    c_noiseMap = new QComboBox(this);
    c_noiseMap->setObjectName("Noise Map");
    gridLayout->addWidget(new QLabel("noiseMap",this),nRow,0);
    gridLayout->addWidget(c_noiseMap,nRow,1);

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
    c_randomFactorHue->setMinimum(1);
    c_randomFactorHue->setValue(1);
    c_randomFactorHue->setObjectName("Hue Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorHue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorHue,nRow,1);

    nRow += 1;
    c_randomFactorSaturation = new QSpinBox(this);
    c_randomFactorSaturation->setMaximum(250);
    c_randomFactorSaturation->setMinimum(1);
    c_randomFactorSaturation->setValue(1);
    c_randomFactorSaturation->setObjectName("Saturation Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorSaturation",this),nRow,0);
    gridLayout->addWidget(c_randomFactorSaturation,nRow,1);

    nRow += 1;
    c_randomFactorValue = new QSpinBox(this);
    c_randomFactorValue->setMaximum(250);
    c_randomFactorValue->setMinimum(1);
    c_randomFactorValue->setValue(1);
    c_randomFactorValue->setObjectName("Value Random Factor");
    gridLayout->addWidget(new QLabel("randomFactorValue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorValue,nRow,1);

    this->setLayout(gridLayout);

}

void QRendererDescWidget::fillRendererDescriptor() {
    _rendererDescriptor->setBackgroundImage(this->c_backgroundImage->currentText());
    _rendererDescriptor->setDestImage(this->c_destImage->currentText());
    _rendererDescriptor->setEnabledlight(this->c_enabledLight->isChecked());
    _rendererDescriptor->setLightbrightness(this->c_lightBrightess->text().toDouble());
    _rendererDescriptor->setLightcontrast(this->c_lightContrast->text().toDouble());
    _rendererDescriptor->setName(this->c_name->text());
    _rendererDescriptor->setNoisemap(this->c_noiseMap->currentText());
    _rendererDescriptor->setRandomFactor(
                c_randomFactorHue->value(),
                c_randomFactorSaturation->value(),
                c_randomFactorSaturation->value());
    _rendererDescriptor->setRandomGradient(c_enableRandomGradient->isChecked());


}

void QRendererDescWidget::readFromRendererDescriptor() {
    this->c_backgroundImage->setCurrentText(_rendererDescriptor->backgroundImage());
    this->c_destImage->setCurrentText(_rendererDescriptor->destImage());
    this->c_enabledLight->setChecked(_rendererDescriptor->enabledLight());
    this->c_enableRandomGradient->setChecked(_rendererDescriptor->randomGradient());
    this->c_lightBrightess->setText(QString("%1").arg(_rendererDescriptor->lightBrightness()));
    this->c_lightContrast->setText(QString("%1").arg(_rendererDescriptor->lightContrast()));
    this->c_name->setText(_rendererDescriptor->name());
    this->c_noiseMap->setCurrentText(_rendererDescriptor->noiseMap());
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
}

void QRendererDescWidget::setNoiseMapList(QStringList &i)
{
    _noiseMapBuilders = i;
    this->c_noiseMap->clear();
    this->c_noiseMap->addItem("");
    this->c_noiseMap->addItems(_noiseMapBuilders);
}
