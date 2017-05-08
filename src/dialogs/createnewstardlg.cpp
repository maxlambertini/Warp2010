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


#include "createnewstardlg.h"
#include "ui_createnewstardlg.h"
#include "ssg_structures.h"
#include "helpers/starcodehelper.h"

CreateNewStarDlg::CreateNewStarDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateNewStarDlg)
{
    ui->setupUi(this);
    validator = new QDoubleValidator(this);
    QRegExp val("(o|b|a|f|g|k|m|d)[0-9](I|II|III|IV|V|VI|VII)",Qt::CaseInsensitive);
    rv = new QRegExpValidator(val,this);

    ui->txtStarName->setText(Onomastikon::instancePtr()->pseudoNomen());
    ui->txtStarType->setText("G2V");
    ui->txtStarType->setValidator(rv);

    ui->txtX->setValidator(validator);
    ui->txtY->setValidator(validator);
    ui->txtZ->setValidator(validator);

    ui->txtRadius->setValidator(validator);
    ui->txtDistanceFromCenter->setValidator(validator);

    ui->txtZ->setText(QString("%1").arg(SSGX::floatRand()*100.0-50.0));
    ui->txtX->setText(QString("%1").arg(SSGX::floatRand()*100.0-50.0));
    ui->txtY->setText(QString("%1").arg(SSGX::floatRand()*100.0-50.0));
    ui->txtRadius->setText(QString("%1").arg(SSGX::floatRand()*25.0));
    ui->txtRadius->setText("0.0");
    ui->txtDistanceFromCenter->setText("0.0");


    ui->spinBox->setValue(1);
}

void CreateNewStarDlg::createStars() {
    //qDeleteAll(_starsToCreate);
    _starsToCreate.clear();
    if (ui->txtStarType->validator()->Acceptable) {
        double dx = ui->txtX->text().toDouble() ;
        double dy = ui->txtY->text().toDouble() ;
        double dz = ui->txtZ->text().toDouble() ;
        double min_radius = ui->txtDistanceFromCenter->text().toDouble();
        double max_radius = ui->txtRadius->text().toDouble();
        qDebug() << min_radius << max_radius;
        double avg_dist = 0.0;
        double x,y,z;
        float distance;
        int iStarsToCreate = ui->spinBox->value();
        QStringList names;
        for (int h = 0; h < iStarsToCreate; h++)  {
            if (ui->spinBox->value() > 1)  {
                do {
                    x = SSGX::floatRand()*max_radius*2-max_radius;
                    y = SSGX::floatRand()*max_radius*2-max_radius;
                    z = SSGX::floatRand()*max_radius*2-max_radius;
                    distance =  pow (pow(x,2)+ pow(y,2)+pow(z,2),0.5);
                } while (distance > max_radius || distance < min_radius);


                x = dx+ x;
                y = dy+ y;
                z = dz + z;

                qDebug() << h << min_radius <<  max_radius << x  << y << z;
                avg_dist += distance;
            }
            else {
                x = dx; y = dy; z = dz;
            }

            QSharedPointer<Star> res(new Star());
            if (h == 0)
                res->starName = ui->txtStarName->text();
            else {
                do {
                auto val = SSGX::d10();
                if (val > 7)
                    res->starName = Onomastikon::instancePtr()->nomen();
                else if (val > 5)
                    res->starName = Onomastikon::instancePtr()->sigla();
                else if (val > 3)
                    res->starName = Onomastikon::instancePtr()->greekName();
                else
                    res->starName = Onomastikon::instancePtr()->pseudoNomen();
                } while (names.contains(res->starName) || res.data()->starName.trimmed() == "");
                names.append(res.data()->starName);
            }
            res->setX(x);
            res->setY(y);
            res->setZ(z);
            if (h == 0 || !ui->chkTypes->isChecked())
                res->setStarFullType(ui->txtStarType->text());
            else
                res->setStarFullType(StarCodeHelper::createStarCode());
            _starsToCreate.append(res);
        }
        qDebug() << "Average distance: " << avg_dist / (double)ui->spinBox->value();

    }

}

QSharedPointer<Star>  CreateNewStarDlg::createStar() {
    QSharedPointer<Star> res;
    if (ui->txtStarType->validator()->Acceptable &&
        ui->txtZ->validator()->Acceptable &&
        ui->txtY->validator()->Acceptable &&
        ui->txtX->validator()->Acceptable &&
        !ui->txtStarName->text().isEmpty())
    {
        res = QSharedPointer<Star>( new Star());
        res->starName = ui->txtStarName->text();
        res->setX(ui->txtX->text().toDouble());
        res->setY(ui->txtY->text().toDouble());
        res->setZ(ui->txtZ->text().toDouble());
        res->setStarFullType(ui->txtStarType->text());
    }
    return res;
}

CreateNewStarDlg::~CreateNewStarDlg()
{
    delete ui;
}

void CreateNewStarDlg::on_buttonBox_accepted()
{
    emit accept();
}

void CreateNewStarDlg::on_buttonBox_rejected()
{
    emit reject();
}
