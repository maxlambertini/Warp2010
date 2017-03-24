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
