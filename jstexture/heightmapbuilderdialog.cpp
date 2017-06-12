#include "heightmapbuilderdialog.h"

HeightMapBuilderDialog::HeightMapBuilderDialog(QWidget *parent) :
    QDialog(parent)
{
    QVBoxLayout *l = new QVBoxLayout(this);
    _widget = new HeightMapBuilderWidget(this);
    l->addWidget(_widget);
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
    l->addWidget(buttonBox);
}

HeightMapBuilderDialog::~HeightMapBuilderDialog()
{

}

void HeightMapBuilderDialog::on_dialog_accept() {
    _widget->fillBuilder();
    QDialog::accept();

}
