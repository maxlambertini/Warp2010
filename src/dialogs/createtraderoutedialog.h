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

#ifndef CREATETRADEROUTEDIALOG_H
#define CREATETRADEROUTEDIALOG_H

#include <QDialog>
#include <QtCore>

namespace Ui {
    class CreateTradeRouteDialog;
}

class CreateTradeRouteDialog : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(CreateTradeRouteDialog)
public:
    explicit CreateTradeRouteDialog(QWidget *parent = 0);
    virtual ~CreateTradeRouteDialog();
    QColor selectedColor() { return _selectedColor; }
    QString tradeRouteName();
    void setTradeRouteName(QString &data);

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::CreateTradeRouteDialog *m_ui;
    QColor _selectedColor;

private slots:
    void on_btnChangeColor_clicked();
};

#endif // CREATETRADEROUTEDIALOG_H
