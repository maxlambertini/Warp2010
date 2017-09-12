#ifndef ADDTEXTUREWORKFLOWDIALOG_H
#define ADDTEXTUREWORKFLOWDIALOG_H

#include <QWidget>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include "addtextureworkflowwidget.h"
#include <QString>
#include <QDialog>

class AddTextureWorkflowDialog : public QDialog
{
    Q_OBJECT

    AddTextureWorkflowWidget *widget;
    QDialogButtonBox *buttonBox;

public:
    explicit AddTextureWorkflowDialog(QWidget *parent = 0);

    const QString prefix() { return widget->prefix(); }
    const QString backgroundImage() { return widget->backgroundImage(); }
    const QString destImage() { return widget->destImage(); }
    bool last() { return widget->last(); }
    bool  createImage() { return widget->createImage(); }

private slots:
    void on_dialog_accept();
    void on_dialog_reject();

};

#endif // ADDTEXTUREWORKFLOWDIALOG_H
