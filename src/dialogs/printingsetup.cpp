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


#include "printingsetup.h"
#include "ui_printingsetup.h"
#include "helpers/printingpreferences.h"

PrintingSetup::PrintingSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PrintingSetup)
{
    ui->setupUi(this);
    readPreferences();
    ui->label_10->setVisible(false);
    ui->label_9->setVisible(false);
    ui->chkImperialSystem->setVisible(false);
    ui->chkLandscape->setVisible(false);
}

void PrintingSetup::readPreferences() {
    _prefs = PrintingPreferences::prefsPtr();
    QString key;
    foreach (key, _prefs->measures().keys()) {
        ui->cboPaperSizes->addItem(key);
    }
    ui->spnBottomMargin->setValue(_prefs->bottomMargin());
    ui->spnLeftMargin->setValue (_prefs->topMargin());
    ui->spnRightMargin->setValue(_prefs->rightMargin());
    ui->spnTopMargin->setValue(_prefs->rightMargin());
    ui->spnPaperWidth->setValue(_prefs->selectedMeasure().width());
    ui->spnPaperHeight->setValue(_prefs->selectedMeasure().height());
    ui->spnVerticalDivisions->setValue(_prefs->yDivisions());
    ui->chkLandscape->setChecked(_prefs->landscape());
    ui->spnHexPerSector->setValue(_prefs->hexPerSector());
}

void PrintingSetup::savePreferences() {
    QString sKey = ui->cboPaperSizes->currentText();
    _prefs = PrintingPreferences::prefsPtr();
    _prefs->setBottomMargin(ui->spnBottomMargin->value());
    _prefs->setLeftMargin(ui->spnLeftMargin->value());
    _prefs->setRightMargin(ui->spnRightMargin->value());
    _prefs->setTopMargin(ui->spnTopMargin->value());
    _prefs->setLandscape(ui->chkLandscape->isChecked());
    _prefs->setYDivisions(ui->spnVerticalDivisions->value());
    _prefs->setHexPerSector(ui->spnHexPerSector->value());
    _prefs->setSelectedMeasure(QSizeF(ui->spnPaperWidth->value(), ui->spnPaperHeight->value()));
}

PrintingSetup::~PrintingSetup()
{
    delete ui;
}

void PrintingSetup::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void PrintingSetup::on_buttonBox_accepted()
{
    savePreferences();
}

void PrintingSetup::on_cboPaperSizes_activated(QString s)
{
    if (_prefs->measures().contains(s)) {
        QSizeF size = _prefs->measures()[s];
        ui->spnPaperHeight->setValue(size.height());
        ui->spnPaperWidth->setValue(size.width());
    }
}

void PrintingSetup::on_chkLandscape_toggled(bool checked)
{
    double tmp = ui->spnPaperHeight->value();
    ui->spnPaperHeight->setValue(ui->spnPaperWidth->value());
    ui->spnPaperWidth->setValue(tmp);
}
