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


#ifndef CREATENEWSTARDLG_H
#define CREATENEWSTARDLG_H

#include <QWidget>
#include <QtGui>
#include <QVector>
#include "star.h"
#include "onomastikon.h"

namespace Ui {
    class CreateNewStarDlg;
}

class CreateNewStarDlg : public QWidget
{
    Q_OBJECT

public:
    explicit CreateNewStarDlg(QWidget *parent = 0);
    ~CreateNewStarDlg();

    Star *createStar();
    void createStars();
    const QVector<Star *>& starsToCreate() { return _starsToCreate; }

private:
    QDoubleValidator *validator;
    QRegExpValidator *rv;
    QVector<Star *> _starsToCreate;
    Ui::CreateNewStarDlg *ui;

signals:
    void reject();
    void accept();

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // CREATENEWSTARDLG_H
