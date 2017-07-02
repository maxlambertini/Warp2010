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
