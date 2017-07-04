#include "texturebuilderwidget.h"
#include <QDialogButtonBox>
#include <QIntValidator>
#include <QDoubleValidator>

TextureBuilderWidget::TextureBuilderWidget(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    layoutWidgets();
}

void TextureBuilderWidget::createWidgets() {

    QIntValidator *v1 = new QIntValidator(-90,90,this);
    QIntValidator *v2 = new QIntValidator(-180,180,this);
    QIntValidator *v = new QIntValidator(this);

    c_sizeX = new QLineEdit(this);
    c_sizeX->setValidator(v);
    c_sizeY = new QLineEdit(this);
    c_sizeY->setValidator(v);
    c_north = new QLineEdit(this);
    c_north->setValidator(v1);
    c_south = new QLineEdit(this);
    c_south->setValidator(v1);
    c_west = new QLineEdit(this);
    c_west->setValidator(v2);
    c_east = new QLineEdit(this);
    c_east->setValidator(v2);
    c_builderType = new QComboBox(this);
    QStringList lst; lst << "sphere" << "rectangle" << "cylinder";
    c_builderType->addItems(lst);
    c_builderType->setCurrentText("sphere");
    c_bumpMap = new QLineEdit(this);
    c_cloudMap = new QLineEdit(this);
    c_colorMap = new QLineEdit(this);
    c_reflectionMap = new QLineEdit(this);
    c_randomFactors = new QLineEdit(this);
    c_randomFactors->setMinimumWidth(300);

}

void TextureBuilderWidget::layoutWidgets() {

    int nRow = 0;
    QGridLayout* grid = new QGridLayout(this);
    QVBoxLayout *l1 = new QVBoxLayout (this);
    QVBoxLayout *l2 = new QVBoxLayout (this);
    grid->addWidget(new QLabel("Size",this),nRow,0);
    l2->addWidget(new QLabel("X"));
    l2->addWidget(c_sizeX);
    l2->addWidget(new QLabel("sizeY",this),nRow,0);
    l2->addWidget(c_sizeY);
    grid->addLayout(l2,nRow, 1);

    ++nRow;
    grid->addWidget(new QLabel("Sphere Range",this),nRow,0);
    l1->addWidget(new QLabel("N"));
    l1->addWidget(c_north);
    l1->addWidget(new QLabel("S"));
    l1->addWidget(c_south);
    l1->addWidget(new QLabel("W"));
    l1->addWidget(c_west);
    l1->addWidget(new QLabel("E"));
    l1->addWidget(c_east);
    grid->addLayout(l1,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("builderType",this),nRow,0);
    grid->addWidget(c_builderType,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("bumpMap",this),nRow,0);
    grid->addWidget(c_bumpMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("cloudMap",this),nRow,0);
    grid->addWidget(c_cloudMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("colorMap",this),nRow,0);
    grid->addWidget(c_colorMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("reflectionMap",this),nRow,0);
    grid->addWidget(c_reflectionMap,nRow,1);

    ++nRow;
    grid->addWidget(new QLabel("randomFactors",this),nRow,0);
    grid->addWidget(c_randomFactors,nRow,1);


}

void TextureBuilderWidget::readFromTextureBuilder() {
    auto b = _tb->bounds();
    c_north->setText(QString("%1").arg(std::get<0>(b)));
    c_south->setText(QString("%1").arg(std::get<1>(b)));
    c_west->setText(QString("%1").arg(std::get<2>(b)));
    c_east->setText(QString("%1").arg(std::get<3>(b)));
    auto s = _tb->size();
    c_sizeX->setText(QString("%1").arg(std::get<0>(s)));
    c_sizeY->setText(QString("%1").arg(std::get<1>(s)));

    c_bumpMap->setText(_tb->bumpMap());
    c_colorMap->setText(_tb->colorMap());
    c_cloudMap->setText(_tb->cloudMap());
    c_reflectionMap->setText(_tb->reflectionMap());

    if (_tb->randomFactors().count() > 0) {
        QStringList lst;
        for (auto i = _tb->randomFactors().begin(); i != _tb->randomFactors().end(); ++i) {
            auto value = *i;
            lst << QString("%1").arg(value);
        }
        QString data = lst.join(", ");
        c_randomFactors->setText(data);
    }

}

void TextureBuilderWidget::writeToTextureBuilder() {

}
