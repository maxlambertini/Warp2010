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

#include "createtraderoutedialog.h"
#include "ui_createtraderoutedialog.h"
#include <QColorDialog>

CreateTradeRouteDialog::CreateTradeRouteDialog(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::CreateTradeRouteDialog)
{
    m_ui->setupUi(this);
    QColor colorRed(Qt::red);
    QPalette pal = m_ui->ctlSelectedColor->palette();
    pal.setColor(m_ui->ctlSelectedColor->backgroundRole(), colorRed);
    m_ui->ctlSelectedColor->setPalette(pal);
    //m_ui->ctlSelectedColor->repaint();
    _selectedColor = colorRed;
}

CreateTradeRouteDialog::~CreateTradeRouteDialog()
{
    delete m_ui;
}

void CreateTradeRouteDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CreateTradeRouteDialog::on_btnChangeColor_clicked()
{
    QPalette pal = m_ui->ctlSelectedColor->palette();

    QColor widgetColor = QColorDialog::getColor(pal.color(QPalette::Button));
    pal.setColor(m_ui->ctlSelectedColor->backgroundRole(), widgetColor);
    m_ui->ctlSelectedColor->setPalette(pal);
    m_ui->ctlSelectedColor->repaint();
    _selectedColor = widgetColor;
}

QString CreateTradeRouteDialog::tradeRouteName()
{
    return m_ui->txtTradeRouteName->text();
}

void CreateTradeRouteDialog::setTradeRouteName(QString &data)
{
    m_ui->txtTradeRouteName->setText(data);
}

