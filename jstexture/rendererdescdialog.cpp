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

#include "rendererdescdialog.h"
#include <QPushButton>
#include <qcolorops.h>
#include <gradienthelper.h>
#include <QHBoxLayout>

RendererDescDialog::RendererDescDialog(QWidget *parent) : QDialog(parent)
{
    auto grid = new QGridLayout(this);
    this->_renderer  = new QRendererDescWidget(this);
    this->gradientEditor = new QtGradientEditor(this);
    this->gradientEditor->setMinimumWidth(500);


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto vLayout = new QVBoxLayout(this);
    vLayout->addWidget(this->_renderer);
    vLayout->addSpacing(70);

    auto vLayout2 = new QVBoxLayout(this);
    vLayout2->addWidget(new QLabel("Gradient editor",this));
    vLayout2->addWidget(this->gradientEditor);

    QPushButton *btn1 = new QPushButton("Earthlike Gradient",this);
    QPushButton *btn2 = new QPushButton("Earthlike Desert",this);
    QPushButton *btn3 = new QPushButton("Marslike",this);
    QPushButton *btn4 = new QPushButton("Moonlike",this);
    QPushButton *btn = new QPushButton("Random Gradient",this);

    QHBoxLayout *hBox = new QHBoxLayout(this);

    hBox->addWidget(btn1);
    hBox->addWidget(btn2);
    hBox->addWidget(btn3);
    hBox->addWidget(btn4);
    hBox->addWidget(btn);

    vLayout2->addLayout(hBox);

    connect (btn, SIGNAL(clicked(bool)),SLOT(on_create_random_gradient()));
    connect (btn1, SIGNAL(clicked(bool)),SLOT(on_create_earthlike_gradient()));
    connect (btn2, SIGNAL(clicked(bool)),SLOT(on_create_desert_gradient()));
    connect (btn3, SIGNAL(clicked(bool)),SLOT(on_create_mars_gradient()));
    connect (btn4, SIGNAL(clicked(bool)),SLOT(on_create_moon_gradient()));


    grid->addLayout(vLayout,0,0);
    grid->addLayout(vLayout2,0,1);
    grid->addWidget(this->buttonBox,2,0,1,2);
    this->setWindowTitle("Create Renderer");
    this->setLayout(grid);

}

void RendererDescDialog::on_dialog_accept() {
    this->_renderer->fillRendererDescriptor();
    auto grad = this->gradientEditor->gradient();
    auto d = this->_renderer->rendererDescriptor();
    d->gradientInfo().clear();
    QVector<QGradientStop> stops = grad.stops();
    for (auto i = stops.begin(); i != stops.end(); ++i) {
        QGradientStop s = (*i);
        auto tpl = std::tuple<double,int,int,int,int>(
        (s.first*2.0)-1.0,s.second.red(),s.second.green(),s.second.blue(),s.second.alpha());
        d->gradientInfo().append(tpl);
    }
    QDialog::accept();
}

void RendererDescDialog::setRendererDescriptor(RendererDescriptor *v) {
    this->_renderer->setRendererDescriptor(v);
    this->_renderer->readFromRendererDescriptor();
    if (v->gradientInfo().count() > 0) {
       //auto grad = this->gradientEditor->gradient();
       QLinearGradient grad;
       //grad.stops().clear();
       for (auto gradItem : v->gradientInfo() ) {
           qDebug() << std::get<0>(gradItem) << "," << std::get<1>(gradItem) << "," << std::get<2>(gradItem) << "," << std::get<3>(gradItem) << "," << std::get<4>(gradItem) << ",";
           QColor colorStop( std::get<1>(gradItem),
                             std::get<2>(gradItem),
                             std::get<3>(gradItem),
                             std::get<4>(gradItem));
           auto pos = (std::get<0>(gradItem) + 1.0) /2.0;
           grad.setColorAt(pos, colorStop);
       }
       this->gradientEditor->setGradient(grad);
    }
}

void RendererDescDialog::on_create_random_gradient() {
    /*
    auto c1 = ColorOps::randomHSLColor();
    auto c2 = ColorOps::randomHSLColor();
    auto step = 2 + SSGX::dx(6);
    double dStep = 1.0/static_cast<double>(step);
    QLinearGradient grad;
    grad.setColorAt(0.0, c1);
    grad.setColorAt(1.0, c2);
    double ds = 0.0;
    for (auto h = 1; h < step; h++ ) {
        ds += (dStep + (dStep/2.0)*SSGX::floatRand() - dStep/4.0 );
        grad.setColorAt(ds, ColorOps::randomHSLColor());
    }
    */
    QLinearGradient grad;
    grad.stops().clear();
    double d = 0.0;
    int r1,r2,r3;
    r1 = SSGX::dn(32)+223;
    r2 = SSGX::dn(64)+191;
    r3 = SSGX::dn(92)+163;
    grad.setColorAt(0, QColor(r1,r2,r3));
    while ( d < 0.95) {
        r1 = SSGX::dn(32)+223;
        r2 = SSGX::dn(64)+191;
        r3 = SSGX::dn(92)+163;
        if ( d > 0.0) {
            d+= 0.05;
            grad.setColorAt(d, QColor(r1,r2,r3));
        }
        d += (0.015 + 0.2*SSGX::floatRand());
        if (d < 1.0)
            grad.setColorAt(d, QColor(r1,r2,r3));
    }
    r1 = SSGX::dn(32)+223;
    r2 = SSGX::dn(64)+191;
    r3 = SSGX::dn(92)+163;
    grad.setColorAt(1, QColor(r1,r2,r3));

    this->gradientEditor->setGradient(grad);

}

void RendererDescDialog::on_create_earthlike_gradient() {
    CreateEarthlikeGradient (this->gradientEditor);
}

void RendererDescDialog::on_create_desert_gradient() {
    CreateEarthlikeDesert (this->gradientEditor);

}

void RendererDescDialog::on_create_mars_gradient() {
    CreateMarslikeGradient (this->gradientEditor);

}

void RendererDescDialog::on_create_moon_gradient() {
    CreateMoonlikeGradient (this->gradientEditor);

}


