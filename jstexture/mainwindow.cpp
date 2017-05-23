#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    imageLabel(new QLabel),
    scrollArea(new QScrollArea),
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _currentTextureFile("")
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

    const QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    splitter->addWidget(this->plainTextEdit);
    this->plainTextEdit->setFont(fixedFont);
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
            _currentTextureFile = fileName;
            QFile f(fileName);
            f.open(QIODevice::ReadOnly);
            QString s;
            QTextStream s1(&f);
            s.append(s1.readAll());

            this->plainTextEdit->setPlainText(s);


        }

}

void MainWindow::on_action_Generate_Texture_triggered()
{
    this->on_action_Save_Texture_triggered();
    TextureBuilder tb;
    tb.buildTextureFromJson(_currentTextureFile);
    QString imgFile = _currentTextureFile+".png";
    QPixmap pixmap(imgFile);
    this->imageLabel->setPixmap(pixmap);
    this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
}

void MainWindow::on_action_Save_Texture_triggered()
{
    QString fileName = _currentTextureFile;
    if (_currentTextureFile == "") {
        fileName = QFileDialog::getSaveFileName(this, tr("Save Texture Json File"),"./texture1.texjson",tr("JSON Texture File (*.texjson)"));
        setCurrentTextureFile( fileName);
    }
    if (!fileName.isEmpty() && ! fileName.isNull()) {
        QFile f(fileName);
        f.open((QIODevice::ReadWrite | QIODevice::Truncate));
        QTextStream s1(&f);
        auto data = this->plainTextEdit->toPlainText();
        s1 <<  data;
        f.flush();
        f.close();
    }

}

void MainWindow::on_action_Exit_triggered()
{

}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Texture Json File"),"./texture1.texjson",tr("JSON Texture File (*.texjson)"));
    if (!fileName.isEmpty() && ! fileName.isNull()) {
        QFile f(fileName);
        f.open((QIODevice::ReadWrite | QIODevice::Truncate));
        QTextStream s1(&f);
        auto data = this->plainTextEdit->toPlainText();
        s1 << data;
        f.flush();
        f.close();
        setCurrentTextureFile( fileName);
    }


}
