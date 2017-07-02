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

#include "heightmapbuilderdialog.h"

HeightMapBuilderDialog::HeightMapBuilderDialog(NoiseMapBuilderDescriptor* ptr,
                                               QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *l = new QVBoxLayout(this);
    _widget = new HeightMapBuilderWidget(ptr,this);
    l->addWidget(_widget);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    l->addWidget(buttonBox);
    this->setLayout(l);
}



HeightMapBuilderDialog::~HeightMapBuilderDialog()
{

}

void HeightMapBuilderDialog::on_dialog_accept() {
    _widget->fillBuilder();
    QDialog::accept();

}
