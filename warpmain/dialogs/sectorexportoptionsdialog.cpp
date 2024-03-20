#include "sectorexportoptionsdialog.h"

SectorExportOptionsDialog::SectorExportOptionsDialog(QWidget *parent) : QDialog(parent)
{
    QGridLayout *layout = new QGridLayout(this);
    layout->setContentsMargins(12,12,12,12);
    QLabel *l = new QLabel("Export shortest paths only",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    QLabel *l1 = new QLabel("Consider paths with garden planets only",this);
    l1->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    this->setWindowTitle("Export sector options");
    this->chkDirectRoutesOnly = new QCheckBox(this);
    this->chkGardenRoutesOnly = new QCheckBox(this);

    l->setMargin(6);
    l1->setMargin(6);
    this->chkDirectRoutesOnly->setChecked(true);
    this->chkGardenRoutesOnly->setChecked(false);

    layout->addWidget(l,0,0);
    layout->addWidget(this->chkDirectRoutesOnly,0,1);
    layout->addWidget(l1,1,0);
    layout->addWidget(this->chkGardenRoutesOnly,1,1);

    QDialogButtonBox *bb = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    bb->setCenterButtons(true);
    connect(bb,&QDialogButtonBox::accepted,this, &QDialog::accept);
    connect(bb,&QDialogButtonBox::rejected,this, &QDialog::reject);
    layout->addWidget(bb,2,0,1,2);

}
