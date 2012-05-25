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

