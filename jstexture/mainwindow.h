/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

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
#include <QTreeWidgetItem>
#include <QVector>
#include <QString>
#include <texturebuilderdialog.h>
#include <texturebuilderwidget.h>
#include <exception>
#include <stdexcept>


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
    QAction *action_CreateImageDesc;
    QAction *action_CreateHeightMapDesc;

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
    void infoBox(QString msg);
    void setCurrentTextureFile(const QString& _file) { _currentTextureFile = _file; this->setWindowTitle(_file); }

    QVector<QString> buildModuleList(QString curMod = "");
    QStringList buildImageList();
    QStringList buildNoiseMapList();

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
    void on_action_CreateImageDesc();
    void on_action_CreateHeightMapDesc();

    void on_listFiles_clicked(QListWidgetItem* idx);

    void on_tree_item_double_clicked(QTreeWidgetItem *item, int column);



private:
    void createActions();
    void createMenus();
    void createWidgets();
    void layoutWidgets();

    void updateTreeWithJsonFromEditor();
    void updateEditorsWithTBInfo();

    void handle_eptr(std::exception_ptr eptr);
};

#endif // MAINWINDOW_H
