#include "diasporaclusterform.h"
#include "ui_diasporaclusterform.h"

DiasporaClusterForm::DiasporaClusterForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DiasporaClusterForm)
{
    ui->setupUi(this);
}

DiasporaClusterForm::~DiasporaClusterForm()
{
    delete ui;
}

void DiasporaClusterForm::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
