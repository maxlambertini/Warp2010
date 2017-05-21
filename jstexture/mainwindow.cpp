#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Load_Texture_triggered()
{
    QString fileName =
                QFileDialog::getOpenFileName(this, tr("Open Texture Json File"),
                                             "./",
                               tr("JSON Texture File (*.texjson)"));
        if (!fileName.isEmpty() && !fileName.isNull())
        {
            QFile f(fileName);
            f.open(QIODevice::ReadOnly);
            QString s;
            QTextStream s1(&f);
            s.append(s1.readAll());

            this->ui->plainTextEdit->setPlainText(s);

            //TextureBuilder tb;
            //tb.buildTextureFromJson(fileName);
        }

}

void MainWindow::on_action_Generate_Texture_triggered()
{

}
