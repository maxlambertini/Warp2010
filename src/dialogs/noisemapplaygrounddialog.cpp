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

#include "noisemapplaygrounddialog.h"
#include "ui_noisemapplaygrounddialog.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "star.h"
#include "ssg_structures.h"
#include <noiseimageutils.h>
#include <qcolorops.h>
#include <helpers/noiseimagerunner.h>
#include <planetmaps/maps.h>
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>

NoisemapPlaygroundDialog::  NoisemapPlaygroundDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoisemapPlaygroundDialog)
{
    ui->setupUi(this);
}

NoisemapPlaygroundDialog::~NoisemapPlaygroundDialog()
{
    delete ui;
}

void NoisemapPlaygroundDialog::on_buttonBox_clicked(QAbstractButton *button)
{
}

void NoisemapPlaygroundDialog::on_imageSaved(QString filename) {
    qApp->processEvents();
    this->setWindowTitle("Saved "+filename);
}

void NoisemapPlaygroundDialog::CreateBitmap() {
    for (auto x = 0; x < 4; x++) {
        /*
        NoiseImageRunner gg2(RT::GG2,QString("test_gg2__%1.png").arg(x),SSGX::dn(99999));gg2.start();
        NoiseImageRunner gg(RT::GG,QString("test_gg__%1.png").arg(x),SSGX::dn(99999));gg.start();
        NoiseImageRunner cp(RT::Cloudy,QString("test_cloudy__%1.png").arg(x),SSGX::dn(99999));cp.start();
        NoiseImageRunner cp2(RT::Cloudy,QString("test_cloudy__%1.png").arg(x),SSGX::dn(99999));cp2.start();
        NoiseImageRunner e1(RT::Earthlike,QString("test_e1__%1.png").arg(x),SSGX::dn(99999));e1.start();
        NoiseImageRunner e2(RT::Earthlike2,QString("test_e2__%1.png").arg(x),SSGX::dn(99999));e2.start();
        NoiseImageRunner e3(RT::Earthlike2,QString("test_e3__%1.png").arg(x),SSGX::dn(99999));e3.start();

        gg2.wait();
        gg.wait();
        cp.wait();
        cp2.wait();
        e1.wait();
        e2.wait();
        e3.wait();
        */
        NoiseImageUtils imgUtils;

        maps::Earthlike sex; sex.setSizeX(2048);sex.setSizeY(1024); sex.setSeed(SSGX::dn(999999)); sex.generateAndSave(QString("test_sp_%1.png").arg(x));
        maps::AlienPeaksVoronoi ex; ex.setSizeX(2048);ex.setSizeY(1024); ex.setSeed(SSGX::dn(999999)); ex.generateAndSave(QString("test_apv_%1.png").arg(x));
        maps::EarthlikePeaks e4; e4.setSizeX(2048);e4.setSizeY(1024);  e4.setSeed(SSGX::dn(99999)); e4.generateAndSave(QString("test_gg_%1.png").arg(x));
        // e4; e4.setSeaRatio(-0.5);e4.setIceRatio(0.25);  e4.setSeed(SSGX::dn(99999)); e4.generateAndSave(QString("test_e4_%1.png").arg(x));



        /*
        imgUtils.CreateEarthlike2(SSGX::dn(99999));
        imgUtils.SaveImage(QString("test_earth_2_%1.png").arg(x));
        imgUtils.CreateEarthlike3(SSGX::dn(99999));
        imgUtils.SaveImage(QString("test_earth_3_%1.png").arg(x));
        imgUtils.CreateEarthClouds(SSGX::d1000());
        imgUtils.SaveImage(QString("test_clouds__%1.png").arg(x));
        imgUtils.CreateDesert(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*1.2+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*1.2+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*1.2+0.7),
                                 imgUtils.QColorToColor(ColorOps::randomColor()),
                                 imgUtils.QColorToColor(ColorOps::randomColor()),
                                 imgUtils.QColorToColor(ColorOps::randomColor()));
        imgUtils.SaveImage(QString("test_desert__%1.png").arg(x));
        imgUtils.CreateDesertG(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*1.2+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*1.2+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*1.2+0.7));

        imgUtils.SaveImage(QString("test_desert_g_%1.png").arg(x));
        imgUtils.CreateDesert(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                     ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7),
                                  imgUtils.QColorToColor(ColorOps::randomColor()),
                                  imgUtils.QColorToColor(ColorOps::randomColor()),
                                  imgUtils.QColorToColor(ColorOps::randomColor()));
                              imgUtils.SaveImage(QString("test_desert2__%1.png").arg(x));
        imgUtils.CreateComplexDesert(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7),
                                 imgUtils.QColorToColor(ColorOps::randomColor()),
                                 utils::Color(223,255,255,255),
                                 utils::Color(192,255,192,255));
        imgUtils.SaveImage(QString("test_desert3__%1.png").arg(x));
        imgUtils.CreateComplexDesert2(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()* (SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()* (SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7),
                                 ColorOps::randomColor(),
                                 ColorOps::randomColor());
        imgUtils.SaveImage(QString("test_desert4__%1.png").arg(x));
        imgUtils.CreateJadePlanet(SSGX::dn(20000),
                                  ColorOps::randomColor());

        imgUtils.SaveImage(QString("test_jade__%1.png").arg(x));
        imgUtils.CreateGranitePlanet(SSGX::dn(20000), ColorOps::randomColor());
        imgUtils.SaveImage(QString("test_granite__%1.png").arg(x));
        imgUtils.CreateIcePlanet(SSGX::dn(20000));
        imgUtils.SaveImage(QString("test_ice__%1.png").arg(x));
        imgUtils.CreateGGPlanet(SSGX::dn(20000));
        imgUtils.SaveImage(QString("test_gg__%1.png").arg(x));
        */
    }
}

void NoisemapPlaygroundDialog::on_pushButton_clicked()
{
    CreateBitmap();
}


void NoisemapPlaygroundDialog::on_btnJsonTextureDemo_clicked()
{
    QString fileName =
            QFileDialog::getOpenFileName(this, tr("Open Texture Json File"),
                                         "./",
                           tr("JSON Texture File (*.texjson)"));
    if (!fileName.isEmpty() && !fileName.isNull())
    {
        TextureBuilder tb;
        tb.buildTextureFromJson(fileName);
    }

}
