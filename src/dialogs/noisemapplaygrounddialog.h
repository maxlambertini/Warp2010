#ifndef NOISEMAPPLAYGROUNDDIALOG_H
#define NOISEMAPPLAYGROUNDDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class NoisemapPlaygroundDialog;
}

class NoisemapPlaygroundDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoisemapPlaygroundDialog(QWidget *parent = 0);
    ~NoisemapPlaygroundDialog();
    void CreateBitmap();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

    void on_imageSaved(QString filename);

private:
    Ui::NoisemapPlaygroundDialog *ui;
};

#endif // NOISEMAPPLAYGROUNDDIALOG_H
