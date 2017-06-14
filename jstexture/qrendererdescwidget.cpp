#include "qrendererdescwidget.h"


QRendererDescWidget::QRendererDescWidget(QWidget *parent) : QWidget(parent)
{
    createWidgets();
}

void QRendererDescWidget::createWidgets() {
    auto gridLayout = new QGridLayout(this);

    int nRow = 0;
    c_name = new QLineEdit(this);
    c_name->setObjectName("c_name");
    gridLayout->addWidget(new QLabel("name",this),nRow,0);
    gridLayout->addWidget(c_name,nRow,1);

    nRow += 1;
    c_noiseMap = new QLineEdit(this);
    c_noiseMap->setObjectName("c_noiseMap");
    gridLayout->addWidget(new QLabel("noiseMap",this),nRow,0);
    gridLayout->addWidget(c_noiseMap,nRow,1);

    nRow += 1;
    c_backgroundImage = new QLineEdit(this);
    c_backgroundImage->setObjectName("c_backgroundImage");
    gridLayout->addWidget(new QLabel("backgroundImage",this),nRow,0);
    gridLayout->addWidget(c_backgroundImage,nRow,1);

    nRow += 1;
    c_destImage = new QLineEdit(this);
    c_destImage->setObjectName("c_destImage");
    gridLayout->addWidget(new QLabel("destImage",this),nRow,0);
    gridLayout->addWidget(c_destImage,nRow,1);

    nRow += 1;
    c_enabledLight = new QCheckBox(this);
    c_enabledLight->setObjectName("c_enabledLight");
    gridLayout->addWidget(new QLabel("enabledLight",this),nRow,0);
    gridLayout->addWidget(c_enabledLight,nRow,1);

    nRow += 1;
    c_lightContrast = new QLineEdit(this);
    c_lightContrast->setObjectName("c_lightContrast");
    c_lightContrast->setText("0.0001");
    auto v1 = new QDoubleValidator(0.0001, 9999.9,4,this);
    c_lightContrast->setValidator(v1);
    gridLayout->addWidget(new QLabel("lightContrast",this),nRow,0);
    gridLayout->addWidget(c_lightContrast,nRow,1);

    nRow += 1;
    c_lightBrightess = new QLineEdit(this);
    c_lightBrightess->setObjectName("c_lightBrightess");
    c_lightBrightess->setValidator(v1);
    c_lightBrightess->setText("0.0001");
    gridLayout->addWidget(new QLabel("lightBrightess",this),nRow,0);
    gridLayout->addWidget(c_lightBrightess,nRow,1);

    nRow += 1;
    c_randomFactorHue = new QSpinBox(this);
    c_randomFactorHue->setMaximum(250);
    c_randomFactorHue->setMinimum(1);
    c_randomFactorHue->setValue(1);
    c_randomFactorHue->setObjectName("c_randomFactorHue");
    gridLayout->addWidget(new QLabel("randomFactorHue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorHue,nRow,1);

    nRow += 1;
    c_randomFactorSaturation = new QSpinBox(this);
    c_randomFactorSaturation->setMaximum(250);
    c_randomFactorSaturation->setMinimum(1);
    c_randomFactorSaturation->setValue(1);
    c_randomFactorSaturation->setObjectName("c_randomFactorSaturation");
    gridLayout->addWidget(new QLabel("randomFactorSaturation",this),nRow,0);
    gridLayout->addWidget(c_randomFactorSaturation,nRow,1);

    nRow += 1;
    c_randomFactorValue = new QSpinBox(this);
    c_randomFactorValue->setMaximum(250);
    c_randomFactorValue->setMinimum(1);
    c_randomFactorValue->setValue(1);
    c_randomFactorValue->setObjectName("c_randomFactorValue");
    gridLayout->addWidget(new QLabel("randomFactorValue",this),nRow,0);
    gridLayout->addWidget(c_randomFactorValue,nRow,1);

    nRow += 1;
    c_enableRandomGradient = new QCheckBox(this);
    c_enableRandomGradient->setObjectName("c_enableRandomGradient");
    gridLayout->addWidget(new QLabel("Random Gradient",this),nRow,0);
    gridLayout->addWidget(c_enabledLight,nRow,1);

    this->setLayout(gridLayout);

}

void QRendererDescWidget::fillRendererDescriptor() {
    _rendererDescriptor.setBackgroundImage(this->c_backgroundImage->text());
    _rendererDescriptor.setDestImage(this->c_destImage->text());
    _rendererDescriptor.setEnabledlight(this->c_enabledLight->isChecked());
    _rendererDescriptor.setLightbrightness(this->c_lightBrightess->text().toDouble());
    _rendererDescriptor.setLightcontrast(this->c_lightContrast->text().toDouble());
    _rendererDescriptor.setName(this->c_name->text());
    _rendererDescriptor.setNoisemap(this->c_noiseMap->text());
    _rendererDescriptor.setRandomFactor(
                c_randomFactorHue->value(),
                c_randomFactorSaturation->value(),
                c_randomFactorSaturation->value());
    _rendererDescriptor.setRandomGradient(c_enableRandomGradient->isChecked());


}


