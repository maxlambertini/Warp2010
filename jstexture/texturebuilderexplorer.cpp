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

void TextureBuilderExplorer::setTextureBuilder(TextureBuilder* b)
 {
    if (b == nullptr)
        throw "Invalid TextureBuilder pointer";

    this->_builder = b;

    /*
    MapHeightMapDescriptors _hmDesc;
    MapImageDescriptors __imDesc;
    MapModuleDescriptors _modDesc;
    MapNoiseMapBuilderDescriptors _nmbDesc;
    MapRendererDescriptors _rndDesc;
    */

    updateTreeWithBuilderInfo();
}

void TextureBuilderExplorer::updateTreeWithBuilderInfo() {
    _treeWidget->clear();
    auto topLevelItem = new QTreeWidgetItem(  (QTreeWidget *)0);
    topLevelItem->setText(0,"Texture Builder");
    this->_treeWidget->insertTopLevelItem(0,topLevelItem);

    auto modTopItem = new QTreeWidgetItem((QTreeWidget *)0 );
    modTopItem->setText(0,"Modules");
    for (auto i = _builder->modDesc().begin(); i != _builder->modDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem((QTreeWidget *)0);
        modItem->setText(0,mod.data()->name());
        modItem->setText(1,"Module");
        modItem->setExpanded(true);
        modTopItem->addChild(modItem);
    }
    modTopItem->setExpanded(true);
    topLevelItem->addChild(modTopItem);

    auto hmItem = new QTreeWidgetItem((QTreeWidget *)0 );
    hmItem->setText(0,"Height maps");
    for (auto i = _builder->hmDesc().begin(); i != _builder->hmDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem((QTreeWidget *)0 );
        modItem->setText(0,mod.data()->name());
        modItem->setExpanded(true);
        modItem->setText(1,"Heightmap");
        hmItem->addChild(modItem);
    }
    hmItem->setExpanded(true);
    topLevelItem->addChild(hmItem);

    auto nmbItem = new QTreeWidgetItem((QTreeWidget *)0);
    nmbItem->setText(0,"Height Map Builders");
    for (auto i = _builder->nmbDesc().begin(); i != _builder->nmbDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem((QTreeWidget *)0);
        modItem->setText(0,mod.data()->name());
        modItem->setText(1,"HeightmapBuilder");
        modItem->setExpanded(true);
        nmbItem->addChild(modItem);
    }
    nmbItem->setExpanded(true);
    topLevelItem->addChild(nmbItem);

    auto rnItem = new QTreeWidgetItem((QTreeWidget *)0);
    rnItem->setText(0,"Renderers");
    for (auto i = _builder->rndDesc().begin(); i != _builder->rndDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem((QTreeWidget *)0);
        modItem->setText(0,mod.data()->name());
        modItem->setText(1,"Renderer");
        modItem->setExpanded(true);
        rnItem->addChild(modItem);
    }
    rnItem->setExpanded(true);
    topLevelItem->addChild(rnItem);

    auto imItem = new QTreeWidgetItem((QTreeWidget *)0);
    imItem->setText(0,"Images");
    for (auto i = _builder->imDesc().begin(); i != _builder->imDesc().end(); ++i) {
        auto mod = (*i);
        auto modItem = new QTreeWidgetItem((QTreeWidget *)0);
        modItem->setText(0,mod.data()->name());
        modItem->setText(1,"Image");
        modItem->setExpanded(true);
        imItem->addChild(modItem);
    }
    imItem->setExpanded(true);
    topLevelItem->addChild(imItem);
    topLevelItem->setExpanded(true);
}
