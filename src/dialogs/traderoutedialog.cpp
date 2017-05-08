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

#include "traderoutedialog.h"
#include "ui_traderoutedialog.h"

TradeRouteDialog::TradeRouteDialog(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::TradeRouteDialog)
{
    m_ui->setupUi(this);
}

TradeRouteDialog::~TradeRouteDialog()
{
    delete m_ui;
}

void TradeRouteDialog::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void TradeRouteDialog::on_btnAddRoute_clicked()
{
}

void TradeRouteDialog::on_action_NewTradeRoute_triggered()
{
    m_ui->stackedWidget->setCurrentIndex(0);
}

void TradeRouteDialog::on_action_DeleteTradeRoute_triggered()
{
    m_ui->stackedWidget->setCurrentIndex(1);

}

void TradeRouteDialog::on_action_EditTradeRoute_triggered()
{
    m_ui->stackedWidget->setCurrentIndex(0);
}

void TradeRouteDialog::on_action_SaveTradeRoutes_triggered()
{
    m_ui->stackedWidget->setCurrentIndex(1);

}

void TradeRouteDialog::on_action_LoadTradeRoutes_triggered()
{
    m_ui->stackedWidget->setCurrentIndex(1);

}

