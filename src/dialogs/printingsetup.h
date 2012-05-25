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


#ifndef PRINTINGSETUP_H
#define PRINTINGSETUP_H

#include <QDialog>
#include "helpers/printingpreferences.h"

namespace Ui {
    class PrintingSetup;
}

class PrintingSetup : public QDialog {
    Q_OBJECT
public:
    PrintingSetup(QWidget *parent = 0);
    ~PrintingSetup();
    void readPreferences();
    void savePreferences();


protected:
    void changeEvent(QEvent *e);

private:
    PrintingPreferences* _prefs;
    Ui::PrintingSetup *ui;

private slots:
    void on_chkLandscape_toggled(bool checked);
    void on_cboPaperSizes_activated(QString );
    void on_buttonBox_accepted();
};

#endif // PRINTINGSETUP_H
