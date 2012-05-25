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

    QVector<Star *> _stars;

public:
    explicit CreateBetweenStarsDlg(QWidget *parent = 0);
    ~CreateBetweenStarsDlg();
    void addWidgetItemToStarTo(QListWidgetItem *item) ;
    void addWidgetItemToStarFrom(QListWidgetItem *item) ;
    void clearFrom();
    void clearTo();
    void createStars();

    QVector<Star *> starsToCreate() { return _stars; }

private:
    Ui::CreateBetweenStarsDlg *ui;
};

#endif // CREATEBETWEENSTARSDLG_H
