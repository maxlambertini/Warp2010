#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>
#include <QSplitter>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    imageLabel(new QLabel),
    scrollArea(new QScrollArea),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //custom setup;
    QSplitter *splitter = new QSplitter(this);
    this->plainTextEdit = new QPlainTextEdit;

    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    imageLabel->setScaledContents(false);

    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);

    splitter->addWidget(this->plainTextEdit);
    splitter->addWidget(this->scrollArea);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(splitter,1);
    ui->centralWidget->setLayout(layout);
    //this->setLayout(layout);

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

            this->plainTextEdit->setPlainText(s);

            TextureBuilder tb;
            tb.buildTextureFromJson(fileName);
            QString imgFile = fileName+".png";
            QPixmap pixmap(imgFile);
            this->imageLabel->setPixmap(pixmap);
            this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
        }

}

void MainWindow::on_action_Generate_Texture_triggered()
{

}
