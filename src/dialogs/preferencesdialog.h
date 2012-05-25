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

#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QtGui/QDialog>
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
    void on_action_Aspect_Title_Font_triggered(bool checked);
    void on_action_Title_Font_triggered(bool checked);
    void on_action_Small_Font_triggered(bool checked);
    void on_action_Body_Font_triggered(bool checked);
    void on_action_Aspect_Title_Font_toggled(bool );
    void on_action_Title_Font_toggled(bool );
    void on_btnSmallFont_clicked();
    void on_btnBodyFont_clicked();
    void on_btnAspectTitleFont_clicked();
    void on_btnTitleFont_clicked();
    void on_buttonBox_accepted();

    void on_fontSelector_fontChanged();

};

#endif // PREFERENCESDIALOG_H
