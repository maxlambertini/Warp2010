#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPlainTextEdit>
#include <QGraphicsScene>
#include <QLabel>
#include <QScrollArea>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QPlainTextEdit *plainTextEdit;
    QGraphicsScene *scene;
    QFrame *frame;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString _currentTextureFile ;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void errorBox(QString msg);
    int questionBox(QString msg);
    void setCurrentTextureFile(const QString& _file) { _currentTextureFile = _file; this->setWindowTitle(_file); }

private slots:
    void on_action_Load_Texture_triggered();

    void on_action_Generate_Texture_triggered();

    void on_action_Save_Texture_triggered();

    void on_action_Exit_triggered();

    void on_actionSave_As_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
