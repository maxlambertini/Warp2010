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

    QRendererDescWidget *_renderer;
    QtGradientEditor *gradientEditor;
    QDialogButtonBox *buttonBox;



public:
    explicit RendererDescDialog(QWidget *parent = 0);
    RendererDescriptor* rendererDescriptor() { return _renderer->rendererDescriptor(); }
    void setRendererDescriptor(RendererDescriptor* v);
    void setImageList(QStringList& i) { _renderer->setImageList(i); }
    void setNoiseMapList(QStringList& i) { _renderer->setNoiseMapList(i); }

    QRendererDescWidget *renderer() { return this->_renderer; }

private slots:
    void on_dialog_accept();
};

#endif // RENDERERDESCDIALOG_H
