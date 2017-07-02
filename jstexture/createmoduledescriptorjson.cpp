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

#include "createmoduledescriptorjson.h"
#include "ui_createmoduledescriptorjson.h"
#include <QSpinBox>
#include <QDoubleValidator>
#include <QDoubleSpinBox>
#include <QIntValidator>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QComboBox>
#include <texturebuilder/moduledescriptor.h>
#include <QSpacerItem>

CreateModuleDescriptorJson::CreateModuleDescriptorJson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateModuleDescriptorJson)
{
    ui->setupUi(this);
    modDesc = &modStatic;
    auto metaObject = modDesc->metaObject();
    int count = metaObject->propertyCount();

    QGridLayout *layout = new QGridLayout(this);
    layout->setMargin(6);


    for (int h = 1; h < count;  ++h) {
        int row = (h-1) / 2;
        int dx = ((h-1) % 2)*2;
        QMetaProperty prop = metaObject->property(h);
        QString name = prop.name();
        QString typeName = prop.typeName();
        QLabel *label = new QLabel(name,this);
        label->setAlignment(Qt::AlignRight);
        label->setObjectName("l_"+name);
        label->setMargin(3);
        layout->addWidget(label,row,dx);
        if (typeName == "double") {
            QDoubleSpinBox *spn = new QDoubleSpinBox(this);
            bool bOk;
            auto varVal = modDesc->property(prop.name());
            double propVal = varVal.toDouble(&bOk);
            spn->setValue(propVal);
            spn->setObjectName("c_"+name);
            spn->setMaximum(100.0);
            spn->setMinimum(-100.0);
            spn->setSingleStep(0.01);
            connect(spn,SIGNAL(valueChanged(double)),SLOT(on_double_value_changed(double)));
            layout->addWidget(spn,row,dx+1);
        } else if (typeName == "int") {
            QSpinBox *spn = new QSpinBox(this);
            bool bOk;
            auto varVal = modDesc->property(prop.name());
            int propVal = varVal.toInt(&bOk);
            spn->setObjectName("c_"+name);
            spn->setValue(propVal);
            spn->setMaximum(100);
            spn->setMinimum(-100);
            spn->setSingleStep(1);
            connect(spn,SIGNAL(valueChanged(int)),SLOT(on_int_value_changed(int)));
            layout->addWidget(spn,row,dx+1);
        } else if (typeName == "bool") {
            QCheckBox *spn = new QCheckBox(this);
            spn->setObjectName("c_"+name);
            auto varVal = modDesc->property(prop.name());
            bool propVal = varVal.toBool();
            spn->setChecked(propVal);
            connect(spn,SIGNAL(stateChanged(int)),SLOT(on_checkbox_state_changed(int)));
            layout->addWidget(spn,row,dx+1);
        } else {
            if (name == "moduleType") {
                QComboBox *spn = new QComboBox(this);
                for (auto i = NoiseModules::moduleList.begin(); i != NoiseModules::moduleList.end(); ++i) {
                    spn->addItem(*i);
                }
                spn->setObjectName("c_"+name);
                connect (spn,SIGNAL(currentIndexChanged(QString)),SLOT(on_module_type_changed(QString)));
                layout->addWidget(spn,row,dx+1);

            } else {
                QLineEdit *spn = new QLineEdit(this);
                spn->setObjectName("c_"+name);
                connect(spn,SIGNAL(textChanged(QString)),SLOT(on_text_value_changed(QString)));
                layout->addWidget(spn,row,dx+1);
            }
        }
    }

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    QSpacerItem *spacer = new QSpacerItem(1,40,QSizePolicy::Minimum,QSizePolicy::Expanding);
    layout->addItem(spacer,count+1,0,1,4);
    layout->addWidget(buttonBox,count+2,0,1,4);
    QString x("Billow");
    this->modDesc->setupPropertiesToExport(x);
    this->enableControlsInGrid<QLabel*>("l_");
    this->enableControlsInGrid<QLineEdit*>("c_");
    this->enableControlsInGrid<QSpinBox*>("c_");
    this->enableControlsInGrid<QDoubleSpinBox*>("c_");
    this->enableControlsInGrid<QCheckBox*>("c_");

    this->setLayout(layout);

}

void CreateModuleDescriptorJson::on_dialog_accept() {

    QDialog::accept();
}

template<typename T> void CreateModuleDescriptorJson::enableControlsInGrid(const QString &prefix) {
    auto widgets = this->findChildren<T>();
    for (auto i = widgets.begin(); i != widgets.end(); ++i) {
        auto w = dynamic_cast<T>((*i)); //ottengo il widget
        auto oName = w->objectName();
        auto oProperty = oName.replace(prefix,"");
        if (oProperty != "type" || oProperty != "name") {
            if (this->modDesc->propertiesToExport().contains(oProperty)) {
                w->setEnabled(true);
                //w->setFocus();
            }
            else   {
                QString oX = w->objectName();
                if (oX.startsWith(prefix))
                    w->setEnabled(false);
            }
        }
    }

}

void CreateModuleDescriptorJson::on_module_type_changed(QString type) {
    this->modDesc->setupPropertiesToExport(type);
    this->modDesc->setModuleType(type);
    this->enableControlsInGrid<QLabel*>("l_");
    this->enableControlsInGrid<QLineEdit*>("c_");
    this->enableControlsInGrid<QSpinBox*>("c_");
    this->enableControlsInGrid<QDoubleSpinBox*>("c_");
    this->enableControlsInGrid<QCheckBox*>("c_");


}

void CreateModuleDescriptorJson::fillModuleDescriptor() {
    //this->modDesc->setEnabledist(this->findChildren<QLineEdit *>("c_ena"));
}

void CreateModuleDescriptorJson::on_double_value_changed (double d) {
    QDoubleSpinBox *snd = dynamic_cast<QDoubleSpinBox *>(sender());
    auto name = snd->objectName();
    if(snd->objectName() == "c_freq") modDesc->setFreq(snd->value());
    if(snd->objectName() == "c_lac") modDesc->setLac(snd->value());
    if(snd->objectName() == "c_pers") modDesc->setPers(snd->value());
    if(snd->objectName() == "c_displ") modDesc->setDispl(snd->value());
    if(snd->objectName() == "c_lBound") modDesc->setLbound(snd->value());
    if(snd->objectName() == "c_uBound") modDesc->setUbound(snd->value());
    if(snd->objectName() == "c_exp") modDesc->setExp(snd->value());
    if(snd->objectName() == "c_bias") modDesc->setBias(snd->value());
    if(snd->objectName() == "c_scale") modDesc->setScale(snd->value());
    if(snd->objectName() == "c_x") modDesc->setX(snd->value());
    if(snd->objectName() == "c_y") modDesc->setY(snd->value());
    if(snd->objectName() == "c_z") modDesc->setZ(snd->value());
    if(snd->objectName() == "c_pow") modDesc->setPow(snd->value());
    if(snd->objectName() == "c_rough") modDesc->setRough(snd->value());
    if(snd->objectName() == "c_value") modDesc->setValue(snd->value());
}

void CreateModuleDescriptorJson::on_int_value_changed (int i) {
    QSpinBox *snd = dynamic_cast<QSpinBox *>(sender());
    auto name = snd->objectName();
    if(snd->objectName() == "c_seed") modDesc->setSeed(snd->value());
    if(snd->objectName() == "c_oct")  modDesc->setOct(snd->value());
}

void CreateModuleDescriptorJson::on_text_value_changed (QString s) {
    QLineEdit *snd = dynamic_cast<QLineEdit *>(sender());
    auto name = snd->objectName();
    if(snd->objectName() == "c_src1") modDesc->setSrc1(s);
    if(snd->objectName() == "c_src2") modDesc->setSrc2(s);
    if(snd->objectName() == "c_src3") modDesc->setSrc3(s);
    if(snd->objectName() == "c_src4")  modDesc->setSrc4(s);
    if(snd->objectName() == "c_ctl")  modDesc->setCtl(s);
    if(snd->objectName() == "c_name") modDesc->setName(s);

}

void CreateModuleDescriptorJson::on_checkbox_state_changed(int state) {
    QCheckBox *snd = dynamic_cast<QCheckBox *>(sender());
    auto name = snd->objectName();
    if(snd->objectName() == "c_enableRandom") modDesc->setEnableRandom(snd->isChecked());
    if(snd->objectName() == "c_enableDist")   modDesc->setEnabledist(snd->isChecked());
    if(snd->objectName() == "c_invert")       modDesc->setInvert(snd->isChecked());
}


CreateModuleDescriptorJson::~CreateModuleDescriptorJson()
{
    delete ui;
}
