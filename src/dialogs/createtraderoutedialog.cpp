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
    QColor widgetColor = QColorDialog::getColor(pal.background().color());
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

