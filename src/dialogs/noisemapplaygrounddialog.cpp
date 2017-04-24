#include "noisemapplaygrounddialog.h"
#include "ui_noisemapplaygrounddialog.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "star.h"
#include "ssg_structures.h"
#include <helpers/noiseimageutils.h>

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
    for (auto x = 0; x < 200; x++) {
        NoiseImageUtils imgUtils;
        connect(&imgUtils,SIGNAL(imageFileSaved(QString)),
                this, SLOT(on_imageSaved(QString)));
        imgUtils.CreateEarthlike(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7));
        imgUtils.SaveImage(QString("test_earth__%1.png").arg(x));
        imgUtils.CreateEarthlikeRMF(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7)
                                 );
        imgUtils.SaveImage(QString("test_earth_rmf_%1.png").arg(x));
        imgUtils.CreateEarthClouds(SSGX::d1000());
        imgUtils.SaveImage(QString("test_clouds__%1.png").arg(x));
        imgUtils.CreateDesert(666,
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7));
        imgUtils.SaveImage(QString("test_desert__%1.png").arg(x));
        imgUtils.CreateDesert(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7),
                                 utils::Color(12,96,34,255),
                                 utils::Color(255,255,192,255),
                                 utils::Color(192,255,192,255));
        imgUtils.SaveImage(QString("test_desert2__%1.png").arg(x));
        imgUtils.CreateComplexDesert(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()*(SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7),
                                 utils::Color(212,232,255,255),
                                 utils::Color(223,255,255,255),
                                 utils::Color(192,255,192,255));
        imgUtils.SaveImage(QString("test_desert3__%1.png").arg(x));
        imgUtils.CreateComplexDesert2(SSGX::dn(99999),
                                 ui->spnOctave->value(),
                                 ui->spnLacunarity->value()* (SSGX::floatRand()*0.6+0.7),
                                 ui->spnFrequency->value()* (SSGX::floatRand()*0.6+0.7),
                                 ui->spnPersistence->value()*(SSGX::floatRand()*0.6+0.7));
        imgUtils.SaveImage(QString("test_desert4__%1.png").arg(x));
        imgUtils.CreateJadePlanet(SSGX::dn(20000),
                                  QColor(SSGX::dn(250),SSGX::dn(250),SSGX::dn(250)));
        imgUtils.SaveImage(QString("test_jade__%1.png").arg(x));
    }
}

void NoisemapPlaygroundDialog::on_pushButton_clicked()
{
    CreateBitmap();
}

