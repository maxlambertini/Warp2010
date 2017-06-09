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

    ModuleDescriptor modDesc;
    QDialogButtonBox *buttonBox;

public:
    ModuleDescriptor& module()  { return modDesc; }
    explicit CreateModuleDescriptorJson(QWidget *parent = 0);
    ~CreateModuleDescriptorJson();

private:
    Ui::CreateModuleDescriptorJson *ui;

private slots:
    void on_module_type_changed(QString& type);
};

#endif // CREATEMODULEDESCRIPTORJSON_H
