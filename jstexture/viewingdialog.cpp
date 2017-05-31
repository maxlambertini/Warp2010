#include "viewingdialog.h"
#include "ui_viewingdialog.h"

#include <QVBoxLayout>
#include <QPixmap>

ViewingDialog::ViewingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewingDialog),
    imageLabel(new QLabel),
    scrollArea(new QScrollArea)
{
    ui->setupUi(this);

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(false);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    QVBoxLayout *layout  = new QVBoxLayout;
    layout->addWidget(scrollArea,1);
    this->setLayout(layout);
}

void ViewingDialog::loadImage(QString &filename) {
    QPixmap pixmap(filename);
    this->imageLabel->setPixmap(pixmap);
    this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());

}

ViewingDialog::~ViewingDialog()
{
    delete ui;
}
