#ifndef HEIGHTMAPBUILDERDIALOG_H
#define HEIGHTMAPBUILDERDIALOG_H

#include <QDialog>
#include <heightmapbuilderwidget.h>
#include <QDialogButtonBox>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <texturebuilder/noisemapbuilderdescriptor.h>

namespace Ui {
class HeightMapBuilderDialog;
}

class HeightMapBuilderDialog : public QDialog
{
    Q_OBJECT

    QWidget *centralWidget;
    QDialogButtonBox *buttonBox;
    HeightMapBuilderWidget *_widget;

public:
    HeightMapBuilderWidget *builderWidget() { return _widget; }
    explicit HeightMapBuilderDialog(NoiseMapBuilderDescriptor* ptr, bool initBuilder=false, QWidget *parent = 0);
    ~HeightMapBuilderDialog();

private:
    Ui::HeightMapBuilderDialog *ui;

private slots:
    void on_dialog_accept();
};

#endif // HEIGHTMAPBUILDERDIALOG_H
