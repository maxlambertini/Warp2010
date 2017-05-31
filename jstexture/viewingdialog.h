#ifndef VIEWINGDIALOG_H
#define VIEWINGDIALOG_H

#include <QDialog>

namespace Ui {
class ViewingDialog;
}

class ViewingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ViewingDialog(QWidget *parent = 0);
    ~ViewingDialog();

private:
    Ui::ViewingDialog *ui;
};

#endif // VIEWINGDIALOG_H
