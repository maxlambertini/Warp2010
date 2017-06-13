#include "mainwindow.h"
#include <texturebuilder/texturebuilder.h>
#include <QFileDialog>
#include <QSplitter>
#include <QVBoxLayout>
#include <QTextStream>
#include <QMessageBox>
#include <apppaths.h>
#include <QStringList>
#include <QStringListModel>
#include <createmoduledescriptorjson.h>
#include <QtGradientEditor/qtgradientdialog.h>
#include <heightmapbuilderdialog.h>
#include <rendererdescdialog.h>

MainWindow::MainWindow(QWidget *parent) :
    imageLabel(new QLabel),
    scrollArea(new QScrollArea),
    QMainWindow(parent),
    _currentTextureFile("")
{
    this->createActions();
    this->createMenus();
    this->createWidgets();
    this->layoutWidgets();
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions() {
    action_Load_Texture = new QAction("Load Texture",this);
    connect(action_Load_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Load_Texture_triggered()));
    action_Generate_Texture = new QAction("Generate Texture",this);
    connect(action_Generate_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Generate_Texture_triggered()));
    action_Save_Texture = new QAction("Save Texture", this);
    connect(action_Save_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Save_Texture_triggered()));
    action_Exit = new QAction("Exit",this);
    connect(action_Exit, SIGNAL(triggered(bool)),this, SLOT(on_action_Exit_triggered()));
    actionSave_As = new QAction("Save as",this);
    connect(actionSave_As,SIGNAL(triggered(bool)),this, SLOT(on_actionSave_As_triggered()));
    action_CreateModuleDescJson = new QAction("Create Mod. Desc",this);
    connect(action_CreateModuleDescJson,SIGNAL(triggered(bool)),this, SLOT(on_action_CreateModuleDescJson()));
    action_CreateHeightmapBuilder = new QAction("Create HMB",this);
    connect(action_CreateHeightmapBuilder,SIGNAL(triggered(bool)),this, SLOT(on_action_CreateHeightmapBuilder()));

}

void MainWindow::createMenus() {
    mainToolBar = new QToolBar(this);
    statusBar = new QStatusBar(this);
    mainToolBar->addAction(action_Load_Texture);
    mainToolBar->addAction(action_Save_Texture);
    mainToolBar->addAction(actionSave_As);
    mainToolBar->addAction(action_Generate_Texture);
    mainToolBar->addAction(action_CreateModuleDescJson);
    mainToolBar->addAction(action_CreateHeightmapBuilder);
    mainToolBar->addAction(action_Exit);
}

void MainWindow::createWidgets() {

    //custom setup;
    centralWidget = new QWidget(this);
    _splitter = new QSplitter(this);
    this->plainTextEdit = new QPlainTextEdit(this);

    const QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    this->plainTextEdit->setFont(fixedFont);
    this->_listFiles = new QListWidget(this);
    connect(this->_listFiles,SIGNAL(itemClicked(QListWidgetItem*)) ,this, SLOT(on_listFiles_clicked(QListWidgetItem*)));
}

void MainWindow::layoutWidgets() {
    this->setCentralWidget(centralWidget);
    this->addToolBar(Qt::TopToolBarArea, mainToolBar);
    this->setStatusBar(statusBar);

    _splitter->addWidget(plainTextEdit);
    _splitter->addWidget(_listFiles);
    _splitter->setOrientation(Qt::Vertical);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(_splitter,1);
    this->centralWidget->setLayout(layout);
    //this->setLayout(layout);
    this->_viewer = new ViewingDialog(this);
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
        if (tb.generatedMaps().count()> 0) {
            QString imgFile = tb.generatedMaps().first();
            if (_viewer->isHidden()) {
                _viewer->show();
                _viewer->raise();
                _viewer->activateWindow();
            }
            _viewer->loadImage(imgFile);
            _listFiles->clear();
            for (auto h = 0; h < tb.generatedMaps().count(); ++h) {
                _listFiles->addItem(tb.generatedMaps()[h]);
            }
            //QPixmap pixmap(imgFile);
            //this->imageLabel->setPixmap(pixmap);
            //this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
        }
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
    RendererDescDialog dlg(this);
    dlg.exec();
    /*
    QtGradientDialog dlg(this);
    dlg.exec();
    QGradient gradient = dlg.gradient();
    QJsonArray a;
    QVector<QGradientStop> stops = gradient.stops();
    for (auto i = stops.begin(); i != stops.end(); ++i) {
        QGradientStop s = (*i);
        QJsonArray arr;
        arr.append((s.first*2.0)-1.0);
        arr.append(s.second.red());
        arr.append(s.second.green());
        arr.append(s.second.blue());
        arr.append(s.second.alpha());
        a.append(arr);
    }
    QJsonDocument doc(a);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    this->plainTextEdit->insertPlainText(strJson);
    */

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

void MainWindow::on_listFiles_clicked(QListWidgetItem *idx) {
    //_viewer->loadImage(imgFile);
    QString data = _listFiles->currentItem()->text();
    this->setWindowTitle(data);
    _viewer->loadImage(data);
}

void MainWindow::on_action_CreateModuleDescJson()
{
    CreateModuleDescriptorJson dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        QJsonObject o;
        dlg.module().toJson(o);
        QJsonDocument doc(o);
        QString strJson(doc.toJson(QJsonDocument::Compact));
        strJson.replace("],","],\n");
        this->plainTextEdit->insertPlainText(strJson);
    }
}

void MainWindow::on_action_CreateHeightmapBuilder() {
    HeightMapBuilderDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        auto builder = dlg.builderWidget()->builder();
        QJsonObject o;
        builder->toJson(o);
        QJsonDocument doc(o);
        QString strJson(doc.toJson(QJsonDocument::Compact));
        this->plainTextEdit->insertPlainText(strJson);
    }
}
