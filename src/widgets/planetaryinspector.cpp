/*
############################################################################
#
# centralWidget file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# centralWidget file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of centralWidget file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/


#include "planetaryinspector.h"
#include <QtGui>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QSpacerItem>
#include "star.h"
#include "planet.h"
#include "orbit.h"
#include "appmessage.h"

PlanetaryInspector::PlanetaryInspector(QWidget *parent) :
    QWidget(parent)
{
    createControls();
    connectSignalSlots();
    layoutControls();
}

void PlanetaryInspector::createControls() {

    //qDebug() << "Creating Widget" ;

    centralWidget = new QWidget(this);
    txt_name = new QLineEdit(centralWidget);
    spn_diameter = new  QDoubleSpinBox (centralWidget);
    spn_diameter->setMinimum(1);
    spn_diameter->setMaximum(1000000);
    spn_diameter->setSingleStep(100);

    spn_density = new QDoubleSpinBox(centralWidget);
    spn_density ->setMinimum(100);
    spn_density ->setMaximum(10000);
    spn_density ->setSingleStep(100);

    spn_distance = new QDoubleSpinBox();
    lbl_short_description = new QLabel("", centralWidget);

    //qDebug() << "Created widget";
}

void PlanetaryInspector::layoutControls() {
    QGridLayout *gridLayout = new QGridLayout(centralWidget);
    gridLayout->addWidget (new QLabel("Name",centralWidget),1,0,1,1,Qt::AlignRight);
    gridLayout->addWidget (txt_name,1,1,1,1,Qt::AlignLeft);
    txt_name->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::MinimumExpanding);
    gridLayout->addWidget (new QLabel("Diameter (Km)",centralWidget),1,2,1,1,Qt::AlignRight);
    gridLayout->addWidget (spn_diameter,1,3,1,1,Qt::AlignLeft);
    gridLayout->addWidget (new QLabel("Density",centralWidget),1,4,1,1,Qt::AlignRight);
    gridLayout->addWidget (spn_density,1,5,1,1,Qt::AlignLeft);

    QFrame *frmx= new QFrame(centralWidget);
    frmx->setObjectName(QString::fromUtf8("frm_6"));
    frmx->setFrameShape(QFrame::HLine);
    frmx->setFrameShadow(QFrame::Sunken);
    //gridLayout->addWidget(line, 1, 0, 1, 2);
    gridLayout->addWidget (frmx,2,0,1,6);

    gridLayout->addWidget(lbl_short_description,3,0,1,6);

    //qDebug() << "Added widget to layout";

    centralWidget->setLayout(gridLayout);
    QVBoxLayout *l = new QVBoxLayout(this);
    l->addWidget(centralWidget);
    QSpacerItem *qsp = new QSpacerItem(5, 10,  QSizePolicy::Expanding, QSizePolicy::Expanding);
    l->addSpacerItem(qsp);
    this->setLayout(l);

}

void PlanetaryInspector::fillControls() {
    if (_planet != 0) {
        txt_name->setText(_planet->name());
        spn_diameter->setValue(_planet->diameter());
        spn_density->setValue( _planet->density());

        PlanetRenderer::current()->setPlanet(_planet);
        lbl_short_description->setText(PlanetRenderer::current()->smallDescription());

    }
    emit planetDataLoaded();
}

void PlanetaryInspector::connectSignalSlots() {
    QObject::connect(txt_name, SIGNAL(editingFinished()),this,SLOT(onPlanetNameChanged()));
    QObject::connect(spn_diameter,SIGNAL(valueChanged(double)),this, SLOT(onPlanetDiameterChanged(double)));
    QObject::connect(spn_density,SIGNAL(valueChanged(double)), this, SLOT(onPlanetDensityChanged(double)));
    QObject::connect(spn_distance,SIGNAL(valueChanged(double)), this, SLOT(onDistanceChanged(double)));
}

void PlanetaryInspector::onPlanetNameChanged() {
    if (_planet != 0) {
        _planet->setName(txt_name->text());
        //qDebug() << _planet->name();
    }
    emit planetDataChanged();
}

void PlanetaryInspector::onPlanetDensityChanged(double d) {
    _planet->setDensity(d);
    this->fillControls();
    emit planetDataChanged();

}

void PlanetaryInspector::onPlanetDiameterChanged(double d) {
    _planet->setDiameter(d);
    this->fillControls();
    emit planetDataChanged();
}

void PlanetaryInspector::onDistanceChanged(double d) {
    Orbit* o = _planet->orbitPtr();
    o->setDistance(d);
    this->fillControls();
    emit planetDataChanged();

}
