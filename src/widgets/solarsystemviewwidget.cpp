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


#include "solarsystemviewwidget.h"
#include "ui_solarsystemviewwidget.h"

#include <QtCore>
#include <QtGui>
#include <QFileDialog>
#include <QPrintDialog>
#include "star.h"
#include "planet.h"
#include "helpers/solarsystemtoscene.h"
#include "widgets/starinspector.h"
#include "widgets/planetaryinspector.h"
#include "helpers/solarsystemtoscene.h"
#include "helpers/apppaths.h"
#include "sceneimageexporter.h"
#include "helpers/splashscreen.h"
#include "appmessage.h"

SolarSystemViewWidget::SolarSystemViewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SolarSystemViewWidget)
{
    ui->setupUi(this);
    _solsysToScene = new SolarSystemToScene();

    connect(_solsysToScene,SIGNAL(planetSelected(Planet*)), this, SLOT(handlePlanetSelected(Planet*)));
    connect(ui->starInspector, SIGNAL(starNameChanged(QString&)), this, SLOT(onStarNameChanged(QString&)));
    connect(ui->starInspector,SIGNAL(starTypeChanged(QString&)),this,SLOT(starFullTypeChanged(QString&)));
    connect(ui->btnRotateLeft,SIGNAL(clicked()),this,SLOT(rotateLeft()));
    connect(ui->btnRotateRight,SIGNAL(clicked()),this,SLOT(rotateRight()));
    connect(ui->btnZoomDown,SIGNAL(clicked()),this,SLOT(zoomIn()));
    connect(ui->btnZoomUp,SIGNAL(clicked()),this,SLOT(zoomOut()));
    connect(ui->rotateSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));
    connect(ui->zoomSlider,SIGNAL(valueChanged(int)),this,SLOT(sliderValueChanged(int)));
    connect(ui->planetInspector,SIGNAL(planetDataChanged()),this, SLOT(onPlanetDataChanged()));
    connect(ui->starInspector,SIGNAL(neighborSelected(int)),this, SLOT(onNeighborSelected(int)));

    ui->btnRotateLeft->setVisible(false);
    ui->btnRotateRight->setVisible(false);
    ui->rotateSlider->setVisible(false);


}

SolarSystemViewWidget::~SolarSystemViewWidget()
{
    delete ui;
    delete _solsysToScene;
}

void SolarSystemViewWidget::changeEvent(QEvent *e)
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

void SolarSystemViewWidget::emitPlanetSelected(Planet *p) {
    //qDebug() << "calling  handlePlanetSelected" << p;
    emit planetSelected(p);
}

void SolarSystemViewWidget::handlePlanetSelected(Planet *p) {
    emit planetSelected(p);
    //qDebug() << "calling  handlePlanetSelected" << p;
    ui->planetInspector->setPlanet(p);
}

void SolarSystemViewWidget::setStar(QSharedPointer<Star> s) {
    if (s != 0) {
        _star = s;
        _solsysToScene->setStar(s.data());
        ui->starInspector->setStar(s.data());
        ui->solSysWidget->setStar(s.data());
        if (_solsysToScene->scenePtr() != 0) {
            QRectF r = _solsysToScene->scenePtr()->itemsBoundingRect();
            _solsysToScene->scenePtr()->invalidate(r);
            ui->solsysView->invalidateScene(r);
        }
        else
            ui->solsysView->invalidateScene();
        ui->solsysView->setScene(_solsysToScene->scenePtr());
        ui->txtSolSys->setHtml(_star->toHtml());
        sliderValueChanged(ui->zoomSlider->value());

    } else {
        _solsysToScene->setStar(0);
        ui->txtSolSys->setHtml("");
        _solsysToScene->scenePtr()->clear();
        ui->solSysWidget->setStar(0);
        //ui->solsysView->invalidateScene();
    }
}

void SolarSystemViewWidget::onStarNameChanged(QString &s) {
    _star->starName = s;
    //qDebug() << "ssvw: changed to" << s;
    emit starNameChanged(s);
}


//slot

void SolarSystemViewWidget::rotateLeft() {
    int val = ui->rotateSlider->value();
    int step = ui->rotateSlider->pageStep();
    ui->rotateSlider->setValue(val-step);

}

void SolarSystemViewWidget::rotateRight() {
    int val = ui->rotateSlider->value();
    int step = ui->rotateSlider->pageStep();
    ui->rotateSlider->setValue(val+step);

}

void SolarSystemViewWidget::zoomIn() {
    int val = ui->zoomSlider->value();
    int step = ui->zoomSlider->pageStep();
    ui->zoomSlider->setValue(val-step);

}

void SolarSystemViewWidget::zoomOut() {
    int val = ui->zoomSlider->value();
    int step = ui->zoomSlider->pageStep();
    ui->zoomSlider->setValue(val+step);

}

void SolarSystemViewWidget::sliderValueChanged(int val)
{
    qreal scale = 0.7*qPow(qreal(2), (ui->zoomSlider->value() - 250) / qreal(50));

    QMatrix matrix;
    matrix.scale(scale, scale);
    matrix.rotate(ui->rotateSlider->value());

    ui->solsysView->setMatrix(matrix);

}

void SolarSystemViewWidget::exportSolSysToHtml() {
    if (_star != NULL) {
        QString fileName =
                QFileDialog::getSaveFileName(
                        this,
                        tr("Export cluster as HTML"),
                        AppPaths::appDir()+"/"+_star->starName+".html",
                        tr("HTML Page (*.html)"));
        if (!fileName.isEmpty() && !fileName.isNull()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::ReadWrite)) {
                QTextStream stream(&file);
                stream << _star->toHtml();

                file.flush();
                file.close();
            }

        }
    }
    else {
        AppMessage::Error("Star not defined", "Please define a cluster and select a Star");
    }

}

void SolarSystemViewWidget::exportSolSysToPDF() {
    if (_star != NULL ) {
        QString fileName =
                QFileDialog::getSaveFileName(
                        this,
                        tr("Export solar system as PDF"),
                        AppPaths::appDir()+"/"+_star->starName +".pdf",
                        tr("PDF Document (*.pdf)"));
        if (!fileName.isEmpty() && !fileName.isNull()) {
            qApp->processEvents();
            SplashScreen::screenPtr()->setMessage("Exporting solar system of "+_star->starName + " to PDF");
            SplashScreen::screenPtr()->show();
            qApp->processEvents();

            QPrinter printer;
            SceneImageExporter sci;
            sci.GraphicsSceneToPrinter(
                    this->_solsysToScene->scenePtr(),
                    printer,fileName,_star->starName,true);

            SplashScreen::screenPtr()->hide();
        }
    }
    else {
        AppMessage::Error("Star not defined", "Please define a cluster and select a Star");
    }
}

void SolarSystemViewWidget::exportSolSysToSvg() {
    if (_star != NULL ) {
        QString fileName =
                QFileDialog::getSaveFileName(
                        this,
                        tr("Export solar system as SVG"),
                        AppPaths::appDir()+"/"+_star->starName+"_solsys.svg",
                        tr("SVG Image (*.svg)"));
        if (!fileName.isEmpty() && !fileName.isNull()) {
            SceneImageExporter::ExportToSVG(this->_solsysToScene->scenePtr(),fileName);
        }
    }
    else {
        AppMessage::Error("Star not defined", "Please define a cluster and select a Star");
    }
}

void SolarSystemViewWidget::printSolsys() {
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle( "Print " + _star->starName + " solar system");
    if (dialog.exec() != QDialog::Accepted)
        return;
    qApp->processEvents();
    SplashScreen::screenPtr()->setMessage("Printing Solsys "+_star->starName);
    SplashScreen::screenPtr()->show();
    qApp->processEvents();

    SceneImageExporter sci;
    sci.GraphicsSceneToPrinter(this->_solsysToScene->scenePtr(), printer);

    SplashScreen::screenPtr()->hide();
}

void SolarSystemViewWidget::onPlanetDataChanged()
{
    ui->solsysView->invalidateScene();
    ui->solsysView->repaint();
    ui->solSysWidget->repaint();
}

void SolarSystemViewWidget::starFullTypeChanged(QString &s)
{
    _star->setStarFullType(s);
    //qDebug() << "startype changed to" << s;
    ui->starInspector->setStarData();
    //emit starNameChanged(s);

}

void SolarSystemViewWidget::onNeighborSelected(int i) {
    //qDebug() << "Received neighbor selection " << i;
    emit neighborSelected(i);
}
