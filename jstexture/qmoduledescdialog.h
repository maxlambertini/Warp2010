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
    QModuleDescWidget *_moduleDescWidget;
    QDialogButtonBox  *_buttonBox;

public:
    explicit QModuleDescDialog(QWidget *parent = 0);
    QModuleDescWidget* moduleDescWidget() { return _moduleDescWidget; }

private slots:

    void on_dialog_accept();
    void on_dialog_reject();
};

#endif // QMODULEDESCDIALOG_H
