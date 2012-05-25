/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
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
}

NewSectorDialog::~NewSectorDialog()
{
    delete m_ui;
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
