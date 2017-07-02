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

#ifndef CREATEMODULEDESCRIPTORJSON_H
#define CREATEMODULEDESCRIPTORJSON_H

#include <QDialog>
#include <texturebuilder/moduledescriptor.h>
#include <memory>
#include <QDialogButtonBox>

namespace Ui {
class CreateModuleDescriptorJson;
}

class CreateModuleDescriptorJson : public QDialog
{
    Q_OBJECT

    ModuleDescriptor *modDesc;
    QDialogButtonBox *buttonBox;

public:
    ModuleDescriptor modStatic;
    ModuleDescriptor* module()  { return modDesc; }
    void setModule(ModuleDescriptor* m) { modDesc = m; }
    explicit CreateModuleDescriptorJson(QWidget *parent = 0);
    template<typename T> void enableControlsInGrid(const QString& prefix);
    ~CreateModuleDescriptorJson();
    void fillModuleDescriptor();

private:
    Ui::CreateModuleDescriptorJson *ui;

private slots:
    void on_module_type_changed(QString type);
    void on_dialog_accept() ;
    void on_double_value_changed (double d);
    void on_int_value_changed (int i);
    void on_text_value_changed (QString s);
    void on_checkbox_state_changed(int state);
};

#endif // CREATEMODULEDESCRIPTORJSON_H
