#ifndef HEIGHTMAPBUILDERDIALOG_H
#define HEIGHTMAPBUILDERDIALOG_H

#include <QDialog>

namespace Ui {
class HeightMapBuilderDialog;
}

class HeightMapBuilderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HeightMapBuilderDialog(QWidget *parent = 0);
    ~HeightMapBuilderDialog();

private:
    Ui::HeightMapBuilderDialog *ui;
};

#endif // HEIGHTMAPBUILDERDIALOG_H
