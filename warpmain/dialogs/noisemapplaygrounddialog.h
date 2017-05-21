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

#ifndef NOISEMAPPLAYGROUNDDIALOG_H
#define NOISEMAPPLAYGROUNDDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class NoisemapPlaygroundDialog;
}

class NoisemapPlaygroundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoisemapPlaygroundDialog(QWidget *parent = 0);
    ~NoisemapPlaygroundDialog();
    void CreateBitmap();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_imageSaved(QString filename);

    void on_btnJsonTextureDemo_clicked();

private:
    Ui::NoisemapPlaygroundDialog *ui;
};

#endif // NOISEMAPPLAYGROUNDDIALOG_H
