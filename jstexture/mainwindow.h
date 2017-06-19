#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QPlainTextEdit>
#include <QGraphicsScene>
#include <QLabel>
#include <QScrollArea>
#include <viewingdialog.h>
#include <QAction>
#include <QWidget>
#include <QToolBar>
#include <QStatusBar>
#include <QSplitter>
#include <QListWidget>
#include <QModelIndex>
#include <QTabWidget>
#include <texturebuilderexplorer.h>



class MainWindow : public QMainWindow
{
    Q_OBJECT

    QAction *action_newTexture;
    QAction *action_Load_Texture;
    QAction *action_Save_Texture;
    QAction *actionSave_As;
    QAction *action_Exit;

    QAction *action_Generate_Texture;
    QAction *action_CreateModuleDescJson;
    QAction *action_CreateHeightmapBuilder;
    QAction *action_CreateRendererDesc;

    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    QTabWidget *tabWidget;

    QPlainTextEdit *plainTextEdit;
    QGraphicsScene *scene;
    QFrame *frame;
    QLabel *imageLabel;
    QScrollArea *scrollArea;
    QString _currentTextureFile ;
    ViewingDialog *_viewer;
    QSplitter *_splitter;
    QSplitter *_splitter1;
    QListWidget *_listFiles;
    TextureBuilderExplorer *_tex;

    TextureBuilder _tb;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void errorBox(QString msg);
    int questionBox(QString msg);
    void setCurrentTextureFile(const QString& _file) { _currentTextureFile = _file; this->setWindowTitle(_file); }

private slots:
    void on_action_new_texture_triggered();
    void on_action_Load_Texture_triggered();
    void on_action_Generate_Texture_triggered();
    void on_action_Save_Texture_triggered();
    void on_action_Exit_triggered();
    void on_actionSave_As_triggered();
    void on_action_create_rend_desc();
    void on_action_CreateModuleDescJson();
    void on_action_CreateHeightmapBuilder();

    void on_listFiles_clicked(QListWidgetItem* idx);

private:
    void createActions();
    void createMenus();
    void createWidgets();
    void layoutWidgets();
};

#endif // MAINWINDOW_H
