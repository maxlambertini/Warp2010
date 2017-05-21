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


#include "clusteritemeditor.h"
#include "ui_clusteritemeditor.h"
#include "models/clusteritemreachdata.h"

ClusterItemEditor::ClusterItemEditor(QWidget *parent) :
    QWidget(parent),
    _clusterItem(0),
    _clusterPtr(0),
    _selectedClusterIndex(-1),
    ui(new Ui::ClusterItemEditor)
{
    ui->setupUi(this);
}

ClusterItemEditor::~ClusterItemEditor()
{
    delete ui;
}

void ClusterItemEditor::changeEvent(QEvent *e)
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


void ClusterItemEditor::setClusterItem(ClusterItem *itemPtr)
{
    ClusterItem& item = *itemPtr;
    if (item.aspects().count() != 3)
        return;
    _clusterItem = itemPtr;

    ui->txtSystemName->setText(item.name());

    ui->txtAspect1->setPlainText(item.aspects()[0].name());
    ui->txtAspect2->setPlainText(item.aspects()[1].name());
    ui->txtAspect3->setPlainText(item.aspects()[2].name());
    ui->spnEnv->setValue(item.environment());
    ui->spnRes->setValue(item.resources());
    ui->spnTech->setValue(item.technology());
    ui->txtSystemDescription->setPlainText(item.description());
    ui->btnConfirmEditing->setEnabled(false);

    //qDebug()
    //        << _clusterItem->name() << ","
    //        << _clusterItem->environment() << ","
    //        << _clusterItem->technology() << ","
    //        << _clusterItem->resources();

    ClusterItem cli;
    ui->lstReachability->clear();
    for (int h = 0; h < _clusterPtr->clusterItems().count(); h++) {
        cli = _clusterPtr->clusterItems()[h];
        QString name = cli.name();
        //qDebug() << "Got cluster item " << name << "; index is " << h << ", cli.name is " << cli.name();
        if (name != _clusterItem->name()) {
            ClusterItemReachData* cird = new ClusterItemReachData(name,h);
            if (_clusterItem->links().contains(h))
                cird->setCheckState(Qt::Checked);
            cird->setText(name);
            ui->lstReachability->addItem(cird);
        }

    }


}

void ClusterItemEditor::setCluster(Cluster *c)
{
    if (c == 0)
        return;
    _clusterPtr = c;
    if (c->count() > 0) {
        _selectedClusterIndex = 0;
        _clusterItem =   &(_clusterPtr->mutableClusterItems()[_selectedClusterIndex]);
        this->setClusterItem(_clusterItem);
    }

}

void ClusterItemEditor::setSelectedClusterIndex(int i)
{
    if (_clusterPtr != 0 && _clusterPtr->count() > 0) {
        _selectedClusterIndex = i % _clusterPtr->count();
        _clusterItem =   &(_clusterPtr->mutableClusterItems()[_selectedClusterIndex]);
        this->setClusterItem(_clusterItem);
    }

}


void ClusterItemEditor::fillClusterWithData() {
    if (!this->validSelectedClusterItem())
        return;
    ClusterItem* ptr = this->clusterItemPtr();
    ptr->setName(ui->txtSystemName->text());
    ptr->aspects()[0].setName(ui->txtAspect1->toPlainText());
    ptr->aspects()[1].setName(ui->txtAspect2->toPlainText());
    ptr->aspects()[2].setName(ui->txtAspect3->toPlainText());

}


void ClusterItemEditor::on_txtSystemName_textChanged(QString s)
{
    if (clusterItemPtr() == 0)
        return;
    ClusterItem* ptr = this->clusterItemPtr();
    ptr->setName(s);
    ui->btnConfirmEditing->setEnabled(true);
}


void ClusterItemEditor::on_txtAspect1_textChanged()
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->aspects()[0].setName(ui->txtAspect1->toPlainText());
    ui->btnConfirmEditing->setEnabled(true);

}

void ClusterItemEditor::on_txtAspect2_textChanged()
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->aspects()[1].setName(ui->txtAspect2->toPlainText());
    ui->btnConfirmEditing->setEnabled(true);

}

void ClusterItemEditor::on_txtAspect3_textChanged()
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->aspects()[2].setName(ui->txtAspect3->toPlainText());
    ui->btnConfirmEditing->setEnabled(true);

}

void ClusterItemEditor::on_txtSystemDescription_textChanged()
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->setDescription(ui->txtSystemDescription->toPlainText());
    ui->btnConfirmEditing->setEnabled(true);
}


void ClusterItemEditor::on_spnEnv_valueChanged(int i)
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->setEnvironment(i);
    ui->btnConfirmEditing->setEnabled(true);
}

void ClusterItemEditor::on_spnRes_valueChanged(int i)
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->setResources(i);
    ui->btnConfirmEditing->setEnabled(true);
}

void ClusterItemEditor::on_spnTech_valueChanged(int i)
{
    if (clusterItemPtr() == 0)
        return;
    clusterItemPtr()->setTechnology(i);
    ui->btnConfirmEditing->setEnabled(true);
}

void ClusterItemEditor::on_btnConfirmEditing_clicked()
{
    if (clusterItemPtr() == 0)
        return;
    //qDebug()
    //        << clusterItemPtr()->name() << ","
    //        << clusterItemPtr()->environment() << ","
    //        << clusterItemPtr()->technology() << ","
    //        << clusterItemPtr()->resources();

    QListWidgetItem* qlwi = 0;
    ClusterItemReachData *cd = 0;

    clusterItemPtr()->clearLinks();
    for (int h = 0; h < ui->lstReachability->count(); h++) {
        qlwi = ui->lstReachability->item(h);
        cd = (ClusterItemReachData *)qlwi;
        if (qlwi->checkState() == Qt::Checked) {
            _clusterPtr->addLink (_selectedClusterIndex,cd->clusterIndex());
            //qDebug() << "Adding link to " << cd->clusterIndex()  << " from " << _selectedClusterIndex;

        }
        else {
            _clusterPtr->removeLink(_selectedClusterIndex,cd->clusterIndex());
        }
    }


    //qDebug() << "done editing cluster: "  << clusterItemPtr()->links();

    emit clusterItemChanged();
    ui->btnConfirmEditing->setEnabled(false);

}

void ClusterItemEditor::enableConfirmButton() {
    ui->btnConfirmEditing->setEnabled(true);
}

void ClusterItemEditor::on_lstReachability_itemChanged(QListWidgetItem* item)
{
    ui->btnConfirmEditing->setEnabled(true);
}
