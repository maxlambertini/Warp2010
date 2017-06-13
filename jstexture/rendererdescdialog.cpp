#include "rendererdescdialog.h"

RendererDescDialog::RendererDescDialog(QWidget *parent) : QDialog(parent)
{
    auto grid = new QGridLayout(this);
    this->renderer  = new QRendererDescWidget(this);
    this->gradientEditor = new QtGradientEditor(this);
    this->gradientEditor->setMinimumWidth(300);


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    grid->addWidget(this->renderer,0,0);
    grid->addWidget(this->gradientEditor,0,1);
    grid->addWidget(this->buttonBox,1,0,1,2);
    this->setLayout(grid);
}

void RendererDescDialog::on_dialog_accept() {
    QDialog::accept();
}
