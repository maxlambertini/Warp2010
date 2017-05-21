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
