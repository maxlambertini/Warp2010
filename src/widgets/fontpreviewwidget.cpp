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
