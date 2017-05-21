#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action_Load_Texture_triggered();

    void on_action_Generate_Texture_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
