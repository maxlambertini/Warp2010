#include "noisemapplaygrounddialog.h"
#include "ui_noisemapplaygrounddialog.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "star.h"
#include "ssg_structures.h"
#include <helpers/noiseimageutils.h>
#include <helpers/qcolorops.h>
#include <helpers/noiseimagerunner.h>
#include <helpers/planetmaps/maps.h>

NoisemapPlaygroundDialog::NoisemapPlaygroundDialog(QWidget *parent) :
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

        maps::Earthlike e; e.setSeed(SSGX::dn(99999)); e.generate(); e.SaveImage(QString("test_e1_%1.png").arg(x));
        maps::Earthlike2 e2; e2.setSeed(SSGX::dn(99999)); e2.generate(); e2.SaveImage(QString("test_e2_%1.png").arg(x));
        maps::Earthlike3 e3; e3.setSeed(SSGX::dn(99999)); e3.generate(); e3.SaveImage(QString("test_e3_%1.png").arg(x));
        maps::EarthlikePeaks e4; e4.setSeed(SSGX::dn(99999)); e4.generate(); e4.SaveImage(QString("test_e4_%1.png").arg(x));

        imgUtils.SaveImage(QString("test_peaks__%1.png").arg(x));
        imgUtils.CreateAlienlikePeaks(SSGX::dn(99999));

        imgUtils.SaveImage(QString("test_alienpeaks__%1.png").arg(x));
        imgUtils.CreateIcePlanet(SSGX::dn(99999));

        imgUtils.SaveImage(QString("test_iceballz__%1.png").arg(x));


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

