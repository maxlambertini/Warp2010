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

#include "heightmapbuilderwidget.h"



HeightMapBuilderWidget::HeightMapBuilderWidget(NoiseMapBuilderDescriptor *ptr,
                                               QWidget *parent ) :
    QWidget(parent)
{
    this->createWidgets();
}

void HeightMapBuilderWidget::initBuilder() {
    _builder->setBounds();
    _builder->setName(_builder->name());
    _builder->setBuilderType(NoiseMapBuilderType::SPHERE);
    _builder->setSize(1024,512);
    _builder->setSeamless(true);
    _builder->setSourceModule (_builder->sourceModule());
    _builder->setDest (_builder->dest());
}

void HeightMapBuilderWidget::createWidgets() {
    _grid = new QGridLayout(this);
    _lbl = new QLabel("Name",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,0,0);
    _lbl = new QLabel("Source",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,1,0);
    _lbl = new QLabel("Dest",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,2,0);
    /*
    _lbl = new QLabel("Size (x,y)",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,3,0);
    _lbl = new QLabel("Bounds (n,s,w,e)",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,4,0);
    */
    _lbl = new QLabel("Seamless?",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,3,0);
    _grid->setMargin(6);

    _name = new QLineEdit (this);
    _grid->addWidget(_name,0,1,1,4);

    _source = new QComboBox (this);
    _grid->addWidget(_source,1,1,1,4);

    _dest = new QComboBox (this);
    _grid->addWidget(_dest,2,1,1,4);

    /*
    _sizeX = new QLineEdit(this);
    auto val1 = new QIntValidator(this);
    _sizeY = new QLineEdit(this);
    auto val2 = new QIntValidator(this);
    _sizeX->setValidator(val1);
    _sizeY->setValidator(val2);
    _grid->addWidget(_sizeX,3,1);
    _grid->addWidget(_sizeY,3,2);

    _topAngle = new QLineEdit(this);
    _bottomAngle = new QLineEdit(this);
    _leftAngle = new QLineEdit(this);
    _rightAngle = new QLineEdit(this);
    auto a1 = new QDoubleValidator(this); _topAngle->setValidator(a1);
    auto a2 = new QDoubleValidator(this); _bottomAngle->setValidator(a1);
    auto a3 = new QDoubleValidator(this); _leftAngle->setValidator(a1);
    auto a4 = new QDoubleValidator(this); _rightAngle->setValidator(a1);
    _grid->addWidget(_topAngle,4,1);
    _grid->addWidget(_bottomAngle,4,2);
    _grid->addWidget(_leftAngle,4,3);
    _grid->addWidget(_rightAngle,4,4);
    */

    _seamless = new QCheckBox(this);
    _grid->addWidget(_seamless,3,1);

    this->setLayout(_grid);
}

void HeightMapBuilderWidget::fillWidgetWithBuilder()
{
    _name->setText(_builder->name());
    _source->setCurrentText(_builder->sourceModule());
    _dest->setCurrentText(_builder->dest());
    //_topAngle->setText(QString("%1").arg(std::get<0>(_builder->bounds())));
    //_bottomAngle->setText(QString("%1").arg(std::get<1>(_builder->bounds())));
    //_leftAngle->setText(QString("%1").arg(std::get<2>(_builder->bounds())));
    //_rightAngle->setText(QString("%1").arg(std::get<3>(_builder->bounds())));
    //_sizeY->setText(QString("%1").arg(std::get<1>(_builder->size())));
    //_sizeX->setText(QString("%1").arg(std::get<0>(_builder->size())));
    _seamless->setChecked(_builder->seamless());
}

void HeightMapBuilderWidget::fillBuilder() {
    //auto iSize = std::tuple<int,int>(
    //            this->_sizeX->text().toInt(),
//                this->_sizeY->text().toInt()
//                );
//    auto dBounds = std::tuple<double,double,double,double>(
//                this->_topAngle->text().toDouble(),
//                this->_bottomAngle->text().toDouble(),
//                this->_leftAngle->text().toDouble(),
//                this->_rightAngle->text().toDouble()
//                );
//    _builder->setBounds(std::get<0>(dBounds),std::get<1>(dBounds),std::get<2>(dBounds),std::get<3>(dBounds));
//    _builder->setSize(std::get<0>(iSize),std::get<1>(iSize));
    qDebug() << _builder;
    qDebug() << _seamless;
    qDebug() << _seamless->isChecked();
    qDebug() << "Fill Builder 0";
    _builder->setSeamless(_seamless->isChecked());
    qDebug() << "Fill Builder 1";
    _builder->setName(_name->text());
    qDebug() << "Fill Builder 2";
    _builder->setSourceModule(_source->currentText());
    qDebug() << "Fill Builder 3";
    _builder->setDest(_dest->currentText());
    qDebug() << "Fill Builder 4";
}

void HeightMapBuilderWidget::setModuleList(QStringList &i) {
    _moduleList = i;
    _source->clear();
    _source->addItem("");
    _source->addItems(_moduleList);

}

void HeightMapBuilderWidget::setNoiseMapList(QStringList &i) {
    _noiseMapList = i;
    _dest->clear();
    _dest->addItem("");
    _dest->addItems(_noiseMapList);
}
