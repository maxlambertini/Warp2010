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

#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include "helpers/preferences.h"

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::PreferencesDialog)
{
    m_ui->setupUi(this);

    QStringList colorNames = QColor::colorNames();
    for (int i = 0; i < colorNames.size(); ++i) {
        QColor color(colorNames[i]);
        m_ui->colorDiasporaBox->insertColor(color, colorNames[i]);
        m_ui->colorDiasporaBoxBackground->insertColor(color, colorNames[i]);
        m_ui->colorDiasporaLinks->insertColor(color, colorNames[i]);
        m_ui->colorMainRoute->insertColor(color, colorNames[i]);
        m_ui->colorSecondary->insertColor(color, colorNames[i]);
    }
    readPreferences();
    connect (m_ui->fontSelector,SIGNAL(currentFontChanged()),this,SLOT(on_fontSelector_fontChanged()));

    m_ui->btnAspectTitleFont->setDefaultAction(m_ui->action_Aspect_Title_Font);
    m_ui->btnTitleFont->setDefaultAction(m_ui->action_Title_Font);
    m_ui->btnBodyFont->setDefaultAction(m_ui->action_Body_Font);
    m_ui->btnSmallFont->setDefaultAction(m_ui->action_Small_Font);
    QActionGroup* grp = new QActionGroup(this);
    grp->addAction(m_ui->action_Aspect_Title_Font);
    grp->addAction(m_ui->action_Title_Font);
    grp->addAction(m_ui->action_Body_Font);
    grp->addAction(m_ui->action_Small_Font);
    m_ui->action_Body_Font->setChecked(true);
    m_ui->fontSelector->setCurrentFont(_fontBody);

}

void PreferencesDialog::readPreferences() {
    //qDebug() << "Started loading preferences ";
    Preferences& pref = Preferences::prefs();
    m_ui->colorDiasporaBox->setCurrentColor(pref.colorDiasporaAspectBox());
    m_ui->colorDiasporaBoxBackground->setCurrentColor(pref.colorDiasporaAspectBackground());
    m_ui->colorDiasporaLinks->setCurrentColor(pref.colorDiasporaLink());
    m_ui->colorMainRoute->setCurrentColor(pref.colorStarShortestLink());
    m_ui->colorSecondary->setCurrentColor(pref.colorStarOtherLink());


    _fontAspectTitle = pref.fontAspectTitle();
    _fontBody = pref.fontBody();
    _fontSmall = pref.fontSmall();
    _fontTitle = pref.fontTitle();
    if (pref.drawRoutesAsArcs())
        m_ui->rdoArcs->setChecked(true);
    else
        m_ui->rdoStraightLines->setChecked(true);
    m_ui->chkShowSecondaryRoutes->setChecked(pref.drawSecondaryRoutes());

}

void PreferencesDialog::writePreferences() {
    //qDebug() << "Started saving preferences ";
    Preferences::prefs().setColorDiasporaAspectBackground(m_ui->colorDiasporaBoxBackground->currentColor());
    Preferences::prefs().setColorDiasporaAspectBox(m_ui->colorDiasporaBox->currentColor());
    Preferences::prefs().setColorDiasporaLink(m_ui->colorDiasporaLinks->currentColor());
    Preferences::prefs().setColorStarShortestLink(m_ui->colorMainRoute->currentColor());
    Preferences::prefs().setColorStarOtherLink(m_ui->colorSecondary->currentColor());


    Preferences::prefs().setFontAspectTitle(_fontAspectTitle);
    Preferences::prefs().setFontBody(_fontBody);
    Preferences::prefs().setFontSmall(_fontSmall);
    Preferences::prefs().setFontTitle(_fontTitle);

    //qDebug() << "About to serialize preferences: "
    //        << Preferences::prefs().fontAspectTitle().family()
    //        << Preferences::prefs().fontBody().family()
    //        << Preferences::prefs().fontSmall().family()
    //        << Preferences::prefs().fontTitle().family();

    Preferences::prefs().setDrawRoutesAsArcs(m_ui->rdoArcs->isChecked());
    Preferences::prefs().setDrawSecondaryRoutes(m_ui->chkShowSecondaryRoutes->isChecked());

    //qDebug() << "Preferences secondary route is: "  << Preferences::prefsPtr()->drawSecondaryRoutes();

    Preferences::savePreferences();
}

PreferencesDialog::~PreferencesDialog()
{
    delete m_ui;
}

void PreferencesDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}



void PreferencesDialog::on_buttonBox_accepted()
{
    writePreferences();
    Preferences::savePreferences();
}


void PreferencesDialog::on_btnTitleFont_clicked()
{
}

void PreferencesDialog::on_btnAspectTitleFont_clicked()
{

}

void PreferencesDialog::on_btnBodyFont_clicked()
{

}

void PreferencesDialog::on_btnSmallFont_clicked()
{

}

void PreferencesDialog::on_fontSelector_fontChanged() {
    if (m_ui->btnAspectTitleFont->isChecked())
        _fontAspectTitle = m_ui->fontSelector->currentFont();
    if (m_ui->btnBodyFont->isChecked())
        _fontBody = m_ui->fontSelector->currentFont();
    if (m_ui->btnTitleFont->isChecked())
        _fontTitle= m_ui->fontSelector->currentFont();
    if (m_ui->btnSmallFont->isChecked())
        _fontSmall = m_ui->fontSelector->currentFont();
}

void PreferencesDialog::on_action_Title_Font_toggled(bool )
{

}

void PreferencesDialog::on_action_Aspect_Title_Font_toggled(bool )
{

}

void PreferencesDialog::on_action_Body_Font_triggered(bool checked)
{
    if (checked) m_ui->fontSelector->setCurrentFont(_fontBody);

}

void PreferencesDialog::on_action_Small_Font_triggered(bool checked)
{
    if (checked) m_ui->fontSelector->setCurrentFont(_fontSmall);

}

void PreferencesDialog::on_action_Title_Font_triggered(bool checked)
{
    if (checked) m_ui->fontSelector->setCurrentFont(_fontTitle);

}

void PreferencesDialog::on_action_Aspect_Title_Font_triggered(bool checked)
{
    if (checked) m_ui->fontSelector->setCurrentFont(_fontAspectTitle);

}
