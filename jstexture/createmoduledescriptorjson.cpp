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
#include <QListWidget>
#include <QComboBox>
#include <texturebuilder/moduledescriptor.h>

CreateModuleDescriptorJson::CreateModuleDescriptorJson(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateModuleDescriptorJson)
{
    ui->setupUi(this);
    auto metaObject = modDesc.metaObject();
    int count = metaObject->propertyCount();

    QGridLayout *layout = new QGridLayout(this);
    layout->setMargin(6);

    for (int h = 1; h < count;  ++h) {
        int row = (h-1) / 2;
        int dx = 2* ((h-1) % 2);
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
            auto varVal = modDesc.property(prop.name());
            double propVal = varVal.toDouble(&bOk);
            spn->setValue(propVal);
            spn->setObjectName("c_"+name);
            spn->setMaximum(100.0);
            spn->setMinimum(-100.0);
            spn->setSingleStep(0.01);
            layout->addWidget(spn,row,dx+1);
        } else if (typeName == "int") {
            QSpinBox *spn = new QSpinBox(this);
            bool bOk;
            auto varVal = modDesc.property(prop.name());
            int propVal = varVal.toInt(&bOk);
            spn->setObjectName("c_"+name);
            spn->setValue(propVal);
            spn->setMaximum(100);
            spn->setMinimum(-100);
            spn->setSingleStep(1);
            layout->addWidget(spn,row,dx+1);
        } else if (typeName == "bool") {
            QCheckBox *spn = new QCheckBox(this);
            spn->setObjectName("c_"+name);
            auto varVal = modDesc.property(prop.name());
            bool propVal = varVal.toBool();
            spn->setChecked(propVal);
            layout->addWidget(spn,row,dx+1);
        } else {
            if (name == "moduleType") {
                QComboBox *spn = new QComboBox(this);
                for (auto i = NoiseModules::moduleList.begin(); i != NoiseModules::moduleList.end(); ++i) {
                    spn->addItem(*i);
                }
                spn->setObjectName("c_"+name);
                connect (spn, SIGNAL(currentTextChanged(QString)),this, SLOT(on_module_type_changed(QString)));
                layout->addWidget(spn,row,dx+1);

            } else {
                QLineEdit *spn = new QLineEdit(this);
                spn->setObjectName("c_"+name);
                layout->addWidget(spn,row,dx+1);
            }
        }
    }

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    layout->addWidget(buttonBox,1+count /2,0,1,4 );

    this->setLayout(layout);

}

void CreateModuleDescriptorJson::on_module_type_changed(QString& type) {
    this->modDesc.setupPropertiesToExport(type);
}

CreateModuleDescriptorJson::~CreateModuleDescriptorJson()
{
    delete ui;
}
