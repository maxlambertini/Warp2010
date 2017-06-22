#include "qmoduledescdialog.h"

QModuleDescDialog::QModuleDescDialog(QWidget *parent) : QDialog(parent)
{
    _moduleDescWidget = new QModuleDescWidget(this);
    _buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    _buttonBox->setCenterButtons(true);

    QVBoxLayout *_layout = new QVBoxLayout(this);
    _layout->addWidget(_moduleDescWidget);
    _layout->addWidget(_buttonBox);

    this->setLayout(_layout);
    connect (_buttonBox, SIGNAL(accepted()), this, SLOT(on_module_dialog_accept()));
    connect (_buttonBox, SIGNAL(rejected()), this,SLOT(on_module_dialog_reject()));
}

void QModuleDescDialog::on_module_dialog_accept() {
    QDialog::accept();
}

void QModuleDescDialog::on_module_dialog_reject() {
    QDialog::reject();
}
