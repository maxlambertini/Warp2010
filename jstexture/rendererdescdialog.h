#ifndef RENDERERDESCDIALOG_H
#define RENDERERDESCDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <qrendererdescwidget.h>
#include <QtGradientEditor/qtgradienteditor.h>
#include <QDialogButtonBox>
#include <texturebuilder/rendererdescriptor.h>


class RendererDescDialog : public QDialog
{
    Q_OBJECT

    QRendererDescWidget *renderer;
    QtGradientEditor *gradientEditor;
    QDialogButtonBox *buttonBox;



public:
    explicit RendererDescDialog(QWidget *parent = 0);
    RendererDescriptor& rendererDescriptor() { return renderer->rendererDescriptor(); }

private slots:
    void on_dialog_accept();
};

#endif // RENDERERDESCDIALOG_H
