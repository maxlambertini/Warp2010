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

#include "newsectordialog.h"
#include "ui_newsectordialog.h"
#include "onomastikon.h"

NewSectorDialog::NewSectorDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::NewSectorDialog)
{
    m_ui->setupUi(this);
    Onomastikon *o = Onomastikon::instancePtr();
    m_ui->txtSectorName->setText(o->pseudoNomen() + " sector");
    _validator = new QDoubleValidator(this);
    m_ui->txtX->setValidator(_validator);
    m_ui->txtY->setValidator(_validator);
    m_ui->txtZ->setValidator(_validator);
    m_ui->txtX->setText("0.0");
    m_ui->txtY->setText("0.0");
    m_ui->txtZ->setText("0.0");
}

NewSectorDialog::~NewSectorDialog()
{
    delete m_ui;
}

double NewSectorDialog::getDx() {
    return m_ui->txtX->text().toDouble();
}

double NewSectorDialog::getDy() {
    return m_ui->txtY->text().toDouble();
}

double NewSectorDialog::getDz() {
    return m_ui->txtZ->text().toDouble();
}


void NewSectorDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

QString NewSectorDialog::sectorName() {
    return m_ui->txtSectorName->text();
}

int NewSectorDialog::sectorDensity() {
    return m_ui->spnStarDensity->value();
}

int NewSectorDialog::sectorRadius() {
    return m_ui->spnRadiusInLY->value();
}

bool NewSectorDialog::createSolarSystems() {
    return m_ui->chkCreateSolSys->isChecked();
}
