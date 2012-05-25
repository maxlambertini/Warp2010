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


#ifndef FONTPREVIEWWIDGET_H
#define FONTPREVIEWWIDGET_H

#include <QWidget>
#include <QtGui>

namespace Ui {
    class FontPreviewWidget;
}

class FontPreviewWidget : public QWidget {
    Q_OBJECT

    QFont _currentFont;

public:
    FontPreviewWidget(QWidget *parent = 0);
    ~FontPreviewWidget();

    QFont& currentFont() { return _currentFont; }
    void setCurrentFont(const QFont& f);

signals:
    void currentFontChanged();
    void currentFontChanged(const QFont&);


protected:
    void changeEvent(QEvent *e);

private:
    Ui::FontPreviewWidget *ui;

private slots:
    void on_btnSelectFont_clicked();
};

#endif // FONTPREVIEWWIDGET_H
