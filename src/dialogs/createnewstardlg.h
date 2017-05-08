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

    QSharedPointer<Star>  createStar();
    void createStars();
    const QVector<QSharedPointer<Star> >& starsToCreate() { return _starsToCreate; }

private:
    QDoubleValidator *validator;
    QRegExpValidator *rv;
    QVector<QSharedPointer<Star> > _starsToCreate;
    Ui::CreateNewStarDlg *ui;

signals:
    void reject();
    void accept();

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // CREATENEWSTARDLG_H
