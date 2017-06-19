#include "texturebuilderexplorer.h"

TextureBuilderExplorer::TextureBuilderExplorer(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    _label = new QLabel("Texture Builder",this);
    _treeWidget = new  QTreeWidget(this);
    _treeWidget->setColumnCount(1);
    layout->addWidget(_label);
    layout->addWidget(_treeWidget);
    this->setLayout(layout);
}

void TextureBuilderExplorer::setTextureBuilder(TextureBuilder &b)
 {
    _builder = b;

    /*
    MapHeightMapDescriptors _hmDesc;
    MapImageDescriptors __imDesc;
    MapModuleDescriptors _modDesc;
    MapNoiseMapBuilderDescriptors _nmbDesc;
    MapRendererDescriptors _rndDesc;
    */

    _treeWidget->items.clear();
    auto topLevelItem = new QTreeWidgetItem(_treeWidget);
    topLevelItem->setText(0,"Texture Builder");

    auto modTopItem = new QTreeWidgetItem(_treeWidget);
    modTopItem->setText(0,"Modules");
    for (auto i = _builder.modDesc().begin(); i != _builder.modDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem(_treeWidget);
        modItem->setText(0,mod.data()->name());
        modTopItem->addChild(modItem);
    }
    topLevelItem->addChild(modTopItem);

    auto hmItem = new QTreeWidgetItem(_treeWidget);
    hmItem->setText(0,"Height maps");
    for (auto i = _builder.hmDesc().begin(); i != _builder.hmDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem(_treeWidget);
        modItem->setText(mod.data()->name());
        hmItem->addChild(modItem);
    }

    auto hmItem = new QTreeWidgetItem(_treeWidget);
    hmItem->setText(0,"Height maps");
    for (auto i = _builder.hmDesc().begin(); i != _builder.hmDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem(_treeWidget);
        modItem->setText(0,mod.data()->name());
        hmItem->addChild(modItem);
    }

    auto nmbItem = new QTreeWidgetItem(_treeWidget);
    nmbItem->setText(0,"Noise map builders");
    for (auto i = _builder.nmbDesc().begin(); i != _builder.nmbDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem(_treeWidget);
        modItem->setText(0,mod.data()->name());
        nmbItem->addChild(modItem);
    }


}
