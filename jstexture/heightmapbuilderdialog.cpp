#include "heightmapbuilderdialog.h"
#include "ui_heightmapbuilderdialog.h"

HeightMapBuilderDialog::HeightMapBuilderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HeightMapBuilderDialog)
{
    ui->setupUi(this);
}

HeightMapBuilderDialog::~HeightMapBuilderDialog()
{
    delete ui;
}
