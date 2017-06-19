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
