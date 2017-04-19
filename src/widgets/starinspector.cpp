/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/


#include "starinspector.h"
#include "starlist.h"

StarInspector::StarInspector(QWidget *parent) :
    QWidget(parent)
{
    createWidgets();
    layoutWidgets();

    connect(lblStarName,SIGNAL(editingFinished()),this, SLOT(editingFinished()));
    connect(lblStarFullType,SIGNAL(editingFinished()),this,SLOT(starTypeEditingChanged()));
}

void StarInspector::createWidgets() {
    /*
    QLabel *lblStarName;
    QLabel *lblStarFullType;
    QLabel *lblMagnitude;
    QLabel *lblSolarMass;
    QLabel *lblSolarAge;
    QLabel *lblTemperature;
    QLabel *lblDiameter;
    QLabel *lblLifeZones;
    QLabel *lblCoordinates;
    */

    gridLayout = new QGridLayout(this);
    QFont fnt = this->font();
    fnt.setPointSize(8);
    this->setFont(fnt);

    _l1 = new QLabel("Star name", this);
    _l2 = new QLabel("Star Type", this);
    _l3 = new QLabel("Magnitude", this);
    _l8 = new QLabel("Life Zones", this);
    _l9 = new QLabel("Coordinates", this);
    //_l4 = new QLabel("N. Gardens",this);
    //_l5 = new QLabel("N. Marginals",this);

    _starRepr = new BasicStarInfoWidget (this);
    _starRepr->setMinimumSize(100,87);
    _starRepr->setMaximumSize(100,87);

    lblStarName = new QLineEdit(this);
    lblStarFullType = new QLineEdit(this);
    QRegExp val("(o|b|a|f|g|k|m|d)[0-9](I|II|III|IV|V|VI|VII)",Qt::CaseInsensitive);
    validator = new QRegExpValidator(val,this);
    lblStarFullType->setValidator(validator);
    lblMagnitude = new QLabel("",this);
    lblLifeZones = new QLabel("",this);
    lblCoordinates = new QLabel("",this);
    //lblNumGardens= new QLabel("",this);
    //lblNumMarginals = new QLabel("",this);
    //lblNumDesert= new QLabel("",this);
    //lblNumGasGiant= new QLabel("",this);

    lstNeighbors = new QListWidget(this);
}

void StarInspector::layoutWidgets() {
    gridLayout->addWidget(_starRepr,0,0,1,2,Qt::AlignCenter);
    gridLayout->addWidget(_l1,2,0,1,1,Qt::AlignRight);
    gridLayout->addWidget(_l2,3,0,1,1,Qt::AlignRight);
    gridLayout->addWidget(_l3,4,0,1,1,Qt::AlignRight);
    gridLayout->addWidget(_l8,5,0,1,1,Qt::AlignRight);
    gridLayout->addWidget(_l9,6,0,1,1,Qt::AlignRight);

    QFrame *line = new QFrame(this);
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    line->setLineWidth(1);
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    gridLayout->addWidget(line,1,0,1,2);
    gridLayout->addWidget(lblStarName,2,1,1,1,Qt::AlignLeft);
    gridLayout->addWidget(lblStarFullType,3,1,1,1,Qt::AlignLeft);
    gridLayout->addWidget(lblMagnitude,4,1,1,1,Qt::AlignLeft);
    gridLayout->addWidget(lblLifeZones,5,1,1,1,Qt::AlignLeft);
    gridLayout->addWidget(lblCoordinates,6,1,1,1,Qt::AlignLeft);

    line = new QFrame(this);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setLineWidth(1);
        line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        gridLayout->addWidget(line,7,0,1,2);

    QLabel *lx = new QLabel("Neighbors");
    gridLayout->addWidget(lx,8,0,1,2,Qt::AlignCenter);

    lstNeighbors->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    connect(lstNeighbors,SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(lstNeighborsCurrentRowChanged(QListWidgetItem*)));

    gridLayout->addWidget(lstNeighbors,9,0,1,2);

    this->setLayout(gridLayout);
}

void StarInspector::setStarData() {
    //qDebug () << "Setting data for " << _star->starName;
    _starRepr->setStar(_star);
    //qDebug() << "Star representation set";
    NSStar::STARVALUE sv = _star->starValue();
    lblStarName->setText(_star->starName);
    lblStarFullType->setText(_star->starFullType());
    lblMagnitude->setText (QString("%1").arg(_star->luminosity()));
    lblLifeZones->setText (QString("%1, %2, %3 AU")
                           .arg(_star->innerLifeZone(),0,'f',2)
                           .arg(_star->idealLifeZone(),0,'f',2)
                           .arg(_star->outerLifeZone(),0,'f',2));
    lblCoordinates->setText (QString("(%1, %2, %3) Ly")
                           .arg(_star->x(),0,'f',2)
                           .arg(_star->y(),0,'f',2)
                           .arg(_star->z(),0,'f',2));

    int iTmp;
    //qDebug() << "Clearing neighbors' list";
    lstNeighbors->clear();
    vectNeighbors.clear();
    foreach (iTmp, _star->neighbors()) {
        vectNeighbors.append(iTmp);
        auto s_tmp = StarList::StarListPtr()->stars().at(iTmp);
        QListWidgetItem *qlw = new QListWidgetItem(s_tmp->starName,lstNeighbors);
    }
}

void StarInspector::editingFinished() {
    QString name = lblStarName->text();
    emit starNameChanged(name);
}

void StarInspector::starTypeEditingChanged()
{
    QString starType = lblStarFullType->text();
    emit starTypeChanged(starType);
}

void StarInspector::lstNeighborsSelectionChanged() {
    if (lstNeighbors->count() > 0) {
        int idx = lstNeighbors->currentRow();
        QListWidgetItem *qwi = lstNeighbors->currentItem();
        QString starname = qwi->text();
        emit neighborSelected(vectNeighbors.at(idx));
        emit neighborSelected(starname);
        //qDebug() << "emitting: " << idx << starname;
    }
}

void StarInspector::lstNeighborsCurrentRowChanged(QListWidgetItem *qwi) {
    if (lstNeighbors->count() > 0) {
        int idx = lstNeighbors->currentRow();
        QString starname = qwi->text();
        emit neighborSelected(vectNeighbors.at(idx));
        emit neighborSelected(starname);
        //qDebug() << "emitting: " << idx << starname << vectNeighbors.at(idx);
    }
}
