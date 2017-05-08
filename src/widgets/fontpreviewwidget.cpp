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

#include <QtGui>
#include <QFontDialog>
#include "fontpreviewwidget.h"
#include "ui_fontpreviewwidget.h"


FontPreviewWidget::FontPreviewWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FontPreviewWidget)
{
    ui->setupUi(this);
    QString txt = "The Quick Brown Fox Jumped Over The Lazy Dog";
    ui->txtPrevirew->setText(txt);
}

FontPreviewWidget::~FontPreviewWidget()
{
    delete ui;
}

void FontPreviewWidget::changeEvent(QEvent *e)
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

void FontPreviewWidget::on_btnSelectFont_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,_currentFont, this);
    if (ok) {
        _currentFont = font;
        QString item = tr("%1 - [%2 pt]").arg(_currentFont.family()).arg(_currentFont.pointSizeF());
        ui->lblFontSelected->setText(item);
        ui->txtPrevirew->setFont(_currentFont);
        emit currentFontChanged();
        emit currentFontChanged(_currentFont);
    }
}

void FontPreviewWidget::setCurrentFont(const QFont &f)
{
    _currentFont = f;
    QString item = tr("%1 - [%2 pt]").arg(_currentFont.family()).arg(_currentFont.pointSizeF());
    ui->lblFontSelected->setText(item);
    ui->txtPrevirew->setFont(f);

}
