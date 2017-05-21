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


#ifndef TRADEROUTEDIALOG_H
#define TRADEROUTEDIALOG_H

#include <QMainWindow>
#include "star.h"
#include "starlist.h"
#include "traderoutemediator.h"

namespace Ui {
    class TradeRouteDialog;
}

class TradeRouteDialog : public QMainWindow {
    Q_OBJECT
    Q_DISABLE_COPY(TradeRouteDialog)
public:
    explicit TradeRouteDialog(QWidget *parent = 0);
    virtual ~TradeRouteDialog();

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::TradeRouteDialog *m_ui;

    TradeRouteMediator *_mediator;

public:
    TradeRouteMediator* mediator() {return _mediator; }
    void setTradeRouteMediator(TradeRouteMediator *mediator) { _mediator = mediator; }

private slots:
    void on_action_LoadTradeRoutes_triggered();
    void on_action_SaveTradeRoutes_triggered();
    void on_action_EditTradeRoute_triggered();
    void on_action_DeleteTradeRoute_triggered();
    void on_action_NewTradeRoute_triggered();
    void on_btnAddRoute_clicked();
};

#endif // TRADEROUTEDIALOG_H
