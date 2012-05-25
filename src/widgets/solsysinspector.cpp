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


#include "solsysinspector.h"
#include "ui_solsysinspector.h"

SolsysInspector::SolsysInspector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SolsysInspector)
{
    ui->setupUi(this);
}

SolsysInspector::~SolsysInspector()
{
    delete ui;
}

void SolsysInspector::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
