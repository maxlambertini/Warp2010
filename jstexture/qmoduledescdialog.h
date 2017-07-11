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

#ifndef QMODULEDESCDIALOG_H
#define QMODULEDESCDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <qmoduledescwidget.h>

class QModuleDescDialog : public QDialog
{
    Q_OBJECT

    QModuleDescWidget *_moduleDescWidget;
    QDialogButtonBox  *_buttonBox;
    bool _editMode = false;

public:
    explicit QModuleDescDialog(QWidget *parent = 0);
    QModuleDescWidget* moduleDescWidget() { return _moduleDescWidget; }


public slots:

    void on_module_dialog_accept();
    void on_module_dialog_reject();
};

#endif // QMODULEDESCDIALOG_H
