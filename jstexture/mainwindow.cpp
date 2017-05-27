#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTextStream>
#include <QMessageBox>
#include <apppaths.h>

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
                                             AppPaths::appDir(),
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
    try {
        this->on_action_Save_Texture_triggered();
        TextureBuilder tb;
        tb.buildTextureFromJson(_currentTextureFile);
        QString filetype = tb.images().keys().first();
        QString imgFile = _currentTextureFile;
        imgFile = imgFile.replace(".texjson", "."+ filetype+".png");
        QPixmap pixmap(imgFile);
        this->imageLabel->setPixmap(pixmap);
        this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
    }
    catch (noise::ExceptionInvalidParam &exc) {
        errorBox("Invalid parameter somewhere. Check zeros and negatives ");
    }
    catch (noise::ExceptionNoModule &exc) {
        errorBox("Unknown module referenced as source or control module ");
    }
    catch (noise::ExceptionUnknown &exc) {
        errorBox("Libnoise unknown error ");
    }
    catch (std::exception exc) {
        QString error = exc.what();
        errorBox(error);
    }
    catch (...) {
        std::string err = "Undefined error";
        throw err;
    }
}

void MainWindow::errorBox(QString msg) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("<big>"+msg+"</big>");
    msgBox.setInformativeText(msg);
    msgBox.setStandardButtons(QMessageBox::Ok );
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();

}

int MainWindow::questionBox(QString msg) {
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    return ret;
}

void MainWindow::on_action_Save_Texture_triggered()
{
    QString fileName = _currentTextureFile;
    if (_currentTextureFile == "") {
        fileName = QFileDialog::getSaveFileName(this, tr("Save Texture Json File"),
                                                AppPaths::appDir() + "/texture1.texjson",tr("JSON Texture File (*.texjson)"));
        if (!fileName.endsWith(".texjson"))
            fileName += ".texjson";
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
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Texture Json File"),
                                                    AppPaths::appDir()+ "/texture1.texjson",tr("JSON Texture File (*.texjson)"));
    if (!fileName.isEmpty() && ! fileName.isNull()) {
        if (!fileName.endsWith(".texjson"))
            fileName += ".texjson";
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
