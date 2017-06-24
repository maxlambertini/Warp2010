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

public:
    explicit QModuleDescDialog(QWidget *parent = 0);
    QModuleDescWidget* moduleDescWidget() { return _moduleDescWidget; }


public slots:

    void on_module_dialog_accept();
    void on_module_dialog_reject();
};

#endif // QMODULEDESCDIALOG_H
