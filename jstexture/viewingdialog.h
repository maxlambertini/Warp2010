#ifndef VIEWINGDIALOG_H
#define VIEWINGDIALOG_H

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class ViewingDialog;
}

class ViewingDialog : public QDialog
{
    Q_OBJECT

    QFrame *frame;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
public:
    explicit ViewingDialog(QWidget *parent = 0);
    ~ViewingDialog();

    void loadImage(QString& filename);
private:
    Ui::ViewingDialog *ui;
};

#endif // VIEWINGDIALOG_H
