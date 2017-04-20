#include "noisemapplaygrounddialog.h"
#include "ui_noisemapplaygrounddialog.h"
#include <noise/noise.h>
#include <noiseutils.h>
#include "star.h"
#include "ssg_structures.h"

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

void NoisemapPlaygroundDialog::CreateBitmap() {
    module::Perlin myModule;
    myModule.SetSeed(SSGX::dx(99999));
    myModule.SetOctaveCount(ui->spnOctave->value());
    myModule.SetFrequency(ui->spnFrequency->value());
    myModule.SetPersistence(ui->spnPersistence->value());
    myModule.SetLacunarity(ui->spnLacunarity->value());


    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderSphere heightMapBuilder;
    heightMapBuilder.SetSourceModule (myModule);
    heightMapBuilder.SetDestNoiseMap (heightMap);
    heightMapBuilder.SetDestSize (1024, 512);
    heightMapBuilder.SetBounds (-90.0, 90.0, -180.0, 180.0);
    heightMapBuilder.Build ();

    utils::RendererImage renderer;
    utils::Image image;
    renderer.SetSourceNoiseMap (heightMap);
    renderer.SetDestImage (image);
    renderer.ClearGradient ();
    renderer.AddGradientPoint (-1.0000, utils::Color (  0,   0, 255, 255)); // deeps
    renderer.AddGradientPoint ( 0.2500, utils::Color (  0,   0, 255, 255)); // shallow
    renderer.AddGradientPoint ( 0.3000, utils::Color (  0, 128, 255, 255)); // shore
    renderer.AddGradientPoint ( 0.3625, utils::Color (240, 240,  64, 255)); // sand
    renderer.AddGradientPoint ( 0.4250, utils::Color ( 32, 160,   0, 255)); // grass
    renderer.AddGradientPoint ( 0.6750, utils::Color (224, 224,   0, 255)); // dirt
    renderer.AddGradientPoint ( 0.9800, utils::Color (128, 128, 128, 255)); // rock
    renderer.AddGradientPoint ( 1.0000, utils::Color (255, 255, 255, 255)); // snow
    /*
    renderer.EnableLight ();
    renderer.SetLightContrast (1.0);
    renderer.SetLightBrightness (2.0);
    */
    renderer.Render ();

    utils::WriterBMP writer;
    writer.SetSourceImage (image);
    qDebug() << "Writing into tutorial";
    writer.SetDestFilename ("tutorial.bmp");
    writer.WriteDestFile ();
}

void NoisemapPlaygroundDialog::on_pushButton_clicked()
{
    CreateBitmap();
}
