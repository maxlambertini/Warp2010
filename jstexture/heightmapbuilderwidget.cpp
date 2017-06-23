#include "heightmapbuilderwidget.h"



HeightMapBuilderWidget::HeightMapBuilderWidget(NoiseMapBuilderDescriptor *ptr,
                                               bool initBld,
                                               QWidget *parent ) :
    QWidget(parent),
    _builder(ptr)
{
    if (initBld)
        initBuilder();
    createWidgets();
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
    _lbl = new QLabel("Size (x,y)",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,3,0);
    _lbl = new QLabel("Bounds (n,s,w,e)",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,4,0);
    _lbl = new QLabel("Seamless?",this);
    _lbl->setMargin(3);
    _lbl->setAlignment(Qt::AlignRight);
    _grid->addWidget(_lbl,5,0);
    _grid->setMargin(6);

    _name = new QLineEdit (_builder->name(),this);
    _grid->addWidget(_name,0,1,1,4);

    _source = new QLineEdit (_builder->sourceModule(),this);
    _grid->addWidget(_source,1,1,1,4);

    _dest = new QLineEdit (_builder->dest(),this);
    _grid->addWidget(_dest,2,1,1,4);

    _sizeX = new QLineEdit(QString("%1").arg(std::get<0>(_builder->size())));
    auto val1 = new QIntValidator(this);
    _sizeX->setValidator(val1);
    _sizeY = new QLineEdit(QString("%1").arg(std::get<1>(_builder->size())));
    auto val2 = new QIntValidator(this);
    _sizeY->setValidator(val2);
    _grid->addWidget(_sizeX,3,1);
    _grid->addWidget(_sizeY,3,2);

    _topAngle = new QLineEdit(QString("%1").arg(std::get<0>(_builder->bounds())));
    auto a1 = new QDoubleValidator(this); _topAngle->setValidator(a1);
    _bottomAngle = new QLineEdit(QString("%1").arg(std::get<1>(_builder->bounds())));
    auto a2 = new QDoubleValidator(this); _bottomAngle->setValidator(a1);
    _leftAngle = new QLineEdit(QString("%1").arg(std::get<2>(_builder->bounds())));
    auto a3 = new QDoubleValidator(this); _leftAngle->setValidator(a1);
    _rightAngle = new QLineEdit(QString("%1").arg(std::get<3>(_builder->bounds())));
    auto a4 = new QDoubleValidator(this); _rightAngle->setValidator(a1);
    _grid->addWidget(_topAngle,4,1);
    _grid->addWidget(_bottomAngle,4,2);
    _grid->addWidget(_leftAngle,4,3);
    _grid->addWidget(_rightAngle,4,4);

    _seamless = new QCheckBox(this);
    _seamless->setChecked(_builder->seamless());
    _grid->addWidget(_seamless,5,1);

    this->setLayout(_grid);
}

void HeightMapBuilderWidget::fillBuilder() {
    auto iSize = std::tuple<int,int>(
                this->_sizeX->text().toInt(),
                this->_sizeY->text().toInt()
                );
    auto dBounds = std::tuple<double,double,double,double>(
                this->_topAngle->text().toDouble(),
                this->_bottomAngle->text().toDouble(),
                this->_leftAngle->text().toDouble(),
                this->_rightAngle->text().toDouble()
                );
    _builder->setBounds(std::get<0>(dBounds),std::get<1>(dBounds),std::get<2>(dBounds),std::get<3>(dBounds));
    _builder->setSize(std::get<0>(iSize),std::get<1>(iSize));
    _builder->setSeamless(_seamless->isChecked());
    _builder->setName(_name->text());
    _builder->setSourceModule(_source->text());
    _builder->setDest(_dest->text());
}

