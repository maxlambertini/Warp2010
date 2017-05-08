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


#ifndef CREATEBETWEENSTARSDLG_H
#define CREATEBETWEENSTARSDLG_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>
#include <QVector>
#include "star.h"

namespace Ui {
    class CreateBetweenStarsDlg;
}

class CreateBetweenStarsDlg : public QDialog
{
    Q_OBJECT

    QVector<QSharedPointer<Star> > _stars;

public:
    explicit CreateBetweenStarsDlg(QWidget *parent = 0);
    ~CreateBetweenStarsDlg();
    void addWidgetItemToStarTo(QListWidgetItem *item) ;
    void addWidgetItemToStarFrom(QListWidgetItem *item) ;
    void clearFrom();
    void clearTo();
    void createStars();

    QVector<QSharedPointer<Star> > starsToCreate() { return _stars; }

private:
    Ui::CreateBetweenStarsDlg *ui;
};

#endif // CREATEBETWEENSTARSDLG_H
