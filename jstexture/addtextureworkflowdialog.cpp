#include "addtextureworkflowdialog.h"

AddTextureWorkflowDialog::AddTextureWorkflowDialog(QWidget *parent ) : QDialog(parent)
{
    widget = new AddTextureWorkflowWidget(this);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    QVBoxLayout *_layout = new QVBoxLayout(this);
    _layout->addWidget(widget);
    _layout->addWidget(buttonBox);

    this->setLayout(_layout);
    connect (buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect (buttonBox, SIGNAL(rejected()), this,SLOT(on_dialog_reject()));
}


void AddTextureWorkflowDialog::on_dialog_accept() {
    QDialog::accept();
}

void AddTextureWorkflowDialog::on_dialog_reject() {
    QDialog::reject();
}
