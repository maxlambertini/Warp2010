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

#ifndef NEWSECTORDIALOG_H
#define NEWSECTORDIALOG_H

#include <QDialog>

namespace Ui {
    class NewSectorDialog;
}

class NewSectorDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(NewSectorDialog)
public:
    explicit NewSectorDialog(QWidget *parent = 0);
    virtual ~NewSectorDialog();

    QString sectorName();
    int sectorDensity();
    int sectorRadius();

    bool createSolarSystems();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::NewSectorDialog *m_ui;
};

#endif // NEWSECTORDIALOG_H
