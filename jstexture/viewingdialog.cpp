#include "viewingdialog.h"
#include "ui_viewingdialog.h"

ViewingDialog::ViewingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewingDialog)
{
    ui->setupUi(this);
}

ViewingDialog::~ViewingDialog()
{
    delete ui;
}
