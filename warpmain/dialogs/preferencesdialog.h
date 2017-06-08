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


#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include "helpers/preferences.h"


namespace Ui {
    class PreferencesDialog;
}

class PreferencesDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(PreferencesDialog)
public:
    explicit PreferencesDialog(QWidget *parent = 0);
    virtual ~PreferencesDialog();

    static Preferences& preferences() { return Preferences::prefs(); }

    void readPreferences();
    void writePreferences();


protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::PreferencesDialog *m_ui;

    QFont _fontTitle;
    QFont _fontAspectTitle;
    QFont _fontBody;
    QFont _fontSmall;

private slots:
    void on_action_Title_Font_triggered(bool checked);
    void on_action_Small_Font_triggered(bool checked);
    void on_action_Body_Font_triggered(bool checked);
    void on_action_Title_Font_toggled(bool );
    void on_btnSmallFont_clicked();
    void on_btnBodyFont_clicked();
    void on_btnAspectTitleFont_clicked();
    void on_btnTitleFont_clicked();
    void on_buttonBox_accepted();

    void on_fontSelector_fontChanged();

};

#endif // PREFERENCESDIALOG_H
