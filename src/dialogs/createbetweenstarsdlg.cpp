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


#include "createbetweenstarsdlg.h"
#include "ui_createbetweenstarsdlg.h"
#include "star.h"
#include "starwidgetitem.h"
#include "ssg_structures.h"
#include "helpers/starcodehelper.h"
#include "onomastikon.h"

CreateBetweenStarsDlg::CreateBetweenStarsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateBetweenStarsDlg)
{
    ui->setupUi(this);
}

CreateBetweenStarsDlg::~CreateBetweenStarsDlg()
{
    delete ui;
}

void CreateBetweenStarsDlg::addWidgetItemToStarFrom(QListWidgetItem *item) {

    StarWidgetItem *swx = (StarWidgetItem *)item;
    StarWidgetItem* swi = new StarWidgetItem(swx->star(), swx->indexOnList(), ui->lstFrom);
}

void CreateBetweenStarsDlg::addWidgetItemToStarTo(QListWidgetItem *item) {
    StarWidgetItem *swx = (StarWidgetItem *)item;
    StarWidgetItem* swi = new StarWidgetItem(swx->star(), swx->indexOnList(), ui->lstTo);
}

void CreateBetweenStarsDlg::clearTo() { ui->lstTo->clear(); }
void CreateBetweenStarsDlg::clearFrom() { ui->lstFrom->clear(); }

void CreateBetweenStarsDlg::createStars() {
    StarWidgetItem* swiFrom = (StarWidgetItem *)ui->lstFrom->currentItem();
    StarWidgetItem* swiTo = (StarWidgetItem *)ui->lstTo->currentItem();

    double x1 = swiFrom->star()->x();
    double y1 = swiFrom->star()->y();
    double z1 = swiFrom->star()->z();

    double x2 = swiTo->star()->x();
    double y2 = swiTo->star()->y();
    double z2 = swiTo->star()->z();

    double s = (double)ui->spinBox->value()+1.0;
    double dx = (x2-x1)/s;
    double dy = (y2-y1)/s;
    double dz = (z2-z1)/s;

    _stars.clear();
    for (int h = 0; h < ui->spinBox->value(); h++ ) {
        double nx = (dx*h)+ (dx+ (SSGX::floatRand()*0.5*dx)-(0.25*dx));
        double ny = (dy*h)+ (dy+ (SSGX::floatRand()*0.5*dy)-(0.25*dx));
        double nz = (dz*h)+ (dz+ (SSGX::floatRand()*0.5*dz)-(0.25*dz));

        Star *s = new Star();
        s->setX(x1+nx); s->setY(y1+ny); s->setZ(z1+nz);
        s->starName =  Onomastikon::instancePtr()->nomen();
        s->setStarFullType(StarCodeHelper::createStarCode());
        _stars.append(s);
    }

}
