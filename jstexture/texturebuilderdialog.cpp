#include "texturebuilderdialog.h"

TextureBuilderDialog::TextureBuilderDialog(QWidget* parent) : QDialog(parent)
{
    QVBoxLayout *box = new QVBoxLayout(this);
    _tbw = new TextureBuilderWidget();
    btn = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    btn->setCenterButtons(true);
    connect(btn,SIGNAL(accepted()),SLOT(on_accept_dialog()));
    connect(btn,&QDialogButtonBox::rejected, this, &QDialog::reject);
    box->addWidget(_tbw);
    box->addWidget(btn);
    this->setLayout(box);
}

void TextureBuilderDialog::on_accept_dialog() {
    _tbw->writeToTextureBuilder();
    QDialog::accept();
}
