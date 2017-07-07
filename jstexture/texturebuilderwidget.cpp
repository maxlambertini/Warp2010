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
    QLabel *l;
    l = new QLabel("Size",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    QGridLayout* grid = new QGridLayout(this);
    QHBoxLayout *l1 = new QHBoxLayout (this);
    QHBoxLayout *l2 = new QHBoxLayout (this);
    grid->addWidget(l,nRow,0);
    l2->addWidget(new QLabel("X"));
    l2->addWidget(c_sizeX);
    l2->addWidget(new QLabel("sizeY",this),nRow,0);
    l2->addWidget(c_sizeY);
    grid->addLayout(l2,nRow,1,1,2);

    ++nRow;
    l = new QLabel("Sphere Range",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    l1->addWidget(new QLabel("S"));
    l1->addWidget(c_south);
    l1->addWidget(new QLabel("N"));
    l1->addWidget(c_north);
    l1->addWidget(new QLabel("W"));
    l1->addWidget(c_west);
    l1->addWidget(new QLabel("E"));
    l1->addWidget(c_east);
    grid->addLayout(l1,nRow,1,1,3);

    ++nRow;
    l  = new QLabel("Texture Type",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    grid->addWidget(c_builderType,nRow,1);

    ++nRow;
    l =new QLabel("Bump map",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(c_bumpMap,nRow,1);

    ++nRow;
    l = new QLabel("Cloud map",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(c_cloudMap,nRow,1);

    ++nRow;
    l = new QLabel("Color map",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    grid->addWidget(c_colorMap,nRow,1);
    grid->addItem(new QSpacerItem(100,1),nRow,2,1,2);

    ++nRow;
    l = new QLabel("Reflection map",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    grid->addWidget(c_reflectionMap,nRow,1);


    ++nRow;
    l = new QLabel("Random factors",this);
    l->setAlignment(Qt::AlignRight | Qt::AlignHCenter);
    grid->addWidget(l,nRow,0);
    grid->addWidget(c_randomFactors,nRow,1,1,3);
    grid->setColumnStretch(0,1);
    grid->setColumnStretch(1,1);
    grid->setColumnStretch(2,2);
    grid->setColumnStretch(3,2);

}

void TextureBuilderWidget::readFromTextureBuilder() {
    auto b = _tb->bounds();
    c_north->setText(QString("%1").arg(std::get<1>(b)));
    c_south->setText(QString("%1").arg(std::get<0>(b)));
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
    _tb->setBounds(
                c_south->text().toDouble(),
                c_north->text().toDouble(),
                c_west->text().toDouble(),
                c_east->text().toDouble()
                );
    _tb->setSize(c_sizeX->text().toInt(),c_sizeY->text().toInt());
    _tb->setBuilderType(c_builderType->currentText());
    _tb->setBumpMap(c_bumpMap->text());
    _tb->setColorMap(c_colorMap->text());
    _tb->setCloudMap(c_cloudMap->text());
    _tb->setReflectionMap(c_reflectionMap->text());
    if (!c_randomFactors->text().isEmpty()) {
        QStringList lst = c_randomFactors->text().split(QChar(','),QString::SkipEmptyParts);
        bool b_validate;
        bool b_first_val = true;
        for (const QString& s : lst) {
            auto d = s.toDouble(&b_validate);
            if (b_validate) {
                if (b_first_val) {
                    _tb->randomFactors().clear();
                    _tb->randomFactors().append(d);
                    b_first_val = false;
                }
                else {
                    _tb->randomFactors().append(d);
                }
            }

        }
    }


}
