#include "texturebuilderwidget.h"
#include <QDialogButtonBox>

TextureBuilderWidget::TextureBuilderWidget(QWidget *parent) : QWidget(parent)
{
    int nRow = 0;
    QGridLayout* grid = new QGridLayout(this);

    QVBoxLayout *l1 = new QVBoxLayout (this);
    QVBoxLayout *l2 = new QVBoxLayout (this);

    grid->addWidget(new QLabel("Size",this),nRow,0);

    c_sizeX = new QLineEdit(this);
    l2->addWidget(new QLabel("X"));
    l2->addWidget(c_sizeX);

    l2->addWidget(new QLabel("sizeY",this),nRow,0);
    c_sizeY = new QLineEdit(this);
    l2->addWidget(c_sizeY);

    grid->addLayout(l2,nRow, 1);

    ++nRow;

    grid->addWidget(new QLabel("Sphere Range",this),nRow,0);

    l1->addWidget(new QLabel("N"));
    c_north = new QLineEdit(this);
    l1->addWidget(c_north);

    l1->addWidget(new QLabel("S"));
    c_south = new QLineEdit(this);
    l1->addWidget(c_south);

    l1->addWidget(new QLabel("W"));
    c_west = new QLineEdit(this);
    l1->addWidget(c_west);

    l1->addWidget(new QLabel("E"));
    c_east = new QLineEdit(this);
    l1->addWidget(c_east);

    grid->addLayout(l1,nRow,1);


    ++nRow;
    grid->addWidget(new QLabel("builderType",this),nRow,0);
    c_builderType = new QComboBox(this);
    QStringList lst; lst << "sphere" << "rectangle" << "cylinder";
    c_builderType->addItems(lst);
    grid->addWidget(c_builderType,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("bumpMap",this),nRow,0);
    c_bumpMap = new QComboBox(this);
    grid->addWidget(c_bumpMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("cloudMap",this),nRow,0);
    c_cloudMap = new QComboBox(this);
    grid->addWidget(c_cloudMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("colorMap",this),nRow,0);
    c_colorMap = new QComboBox(this);
    grid->addWidget(c_colorMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("reflectionMap",this),nRow,0);
    c_reflectionMap = new QLineEdit(this);
    grid->addWidget(c_reflectionMap,nRow,1);


    ++nRow;
    grid->addWidget(new QLabel("randomFactors",this),nRow,0);
    c_randomFactors = new QLineEdit(this);
    grid->addWidget(c_randomFactors,nRow,1);

}
