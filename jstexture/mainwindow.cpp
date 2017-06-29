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
#include <qmoduledescdialog.h>
#include <texturebuilder/noisemapbuilderdescriptor.h>
#include <QInputDialog>

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
    action_newTexture = new QAction(QIcon(":/icons/new2.png"),"Create new texture",this),
    action_Load_Texture = new QAction(QIcon(":/icons/open.png"),"Load Texture",this);
    action_Save_Texture = new QAction(QIcon(":/icons/save.png"),"Save Texture", this);
    actionSave_As = new QAction(QIcon(":/icons/save.png"),"Save as",this);
    action_Exit = new QAction(QIcon(":/icons/quit.png"),"Exit",this);


    connect(action_newTexture,SIGNAL(triggered(bool)),this, SLOT(on_action_new_texture_triggered()));
    connect(action_Load_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Load_Texture_triggered()));
    connect(action_Save_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Save_Texture_triggered()));
    connect(actionSave_As,SIGNAL(triggered(bool)),this, SLOT(on_actionSave_As_triggered()));
    connect(action_Exit, SIGNAL(triggered(bool)),this, SLOT(on_action_Exit_triggered()));

    action_Generate_Texture = new QAction(QIcon(":/icons/generate2.png"),"Generate Texture",this);
    action_CreateModuleDescJson = new QAction(QIcon(":/icons/new-module.svg"),"Create Module descriptor",this);
    action_CreateHeightmapBuilder = new QAction(QIcon(":/icons/new-heightmap-builder.svg"),"Create Heightmap Builder",this);
    action_CreateImageDesc = new QAction(QIcon(":/icons/new-image.svg"),"Create Image Descriptor",this);
    action_CreateHeightMapDesc = new QAction(QIcon(":/icons/new-heightmap.svg"),"Create Heightmap Descriptor",this);
    action_CreateRendererDesc = new QAction(QIcon(":/icons/new-renderer.svg"),"Create renderer descriptor",this);

    connect(action_Generate_Texture,SIGNAL(triggered(bool)),this, SLOT(on_action_Generate_Texture_triggered()));
    connect(action_CreateModuleDescJson,SIGNAL(triggered(bool)),this, SLOT(on_action_CreateModuleDescJson()));
    connect(action_CreateHeightmapBuilder,SIGNAL(triggered(bool)),this, SLOT(on_action_CreateHeightmapBuilder()));
    connect(action_CreateRendererDesc,SIGNAL(triggered(bool)),this,SLOT(on_action_create_rend_desc()));
    connect(action_CreateImageDesc,SIGNAL(triggered(bool)),SLOT(on_action_CreateImageDesc()));
    connect(action_CreateHeightMapDesc,SIGNAL(triggered(bool)),SLOT(on_action_CreateHeightMapDesc()));
}

void MainWindow::createMenus() {
    mainToolBar = new QToolBar(this);
    mainToolBar->setIconSize(QSize(32,32));
    statusBar = new QStatusBar(this);
    mainToolBar->addAction(action_newTexture);
    mainToolBar->addAction(action_Load_Texture);
    mainToolBar->addAction(action_Save_Texture);
    mainToolBar->addAction(actionSave_As);
    mainToolBar->addSeparator();
    mainToolBar->addAction(action_Generate_Texture);
    mainToolBar->addAction(action_CreateModuleDescJson);
    mainToolBar->addAction(action_CreateHeightMapDesc);
    mainToolBar->addAction(action_CreateImageDesc);
    mainToolBar->addAction(action_CreateHeightmapBuilder);
    mainToolBar->addAction(action_CreateRendererDesc);
    mainToolBar->addSeparator();
    mainToolBar->addAction(action_Exit);
}

void MainWindow::createWidgets() {

    //custom setup;
    tabWidget = new QTabWidget (this);
    centralWidget = new QWidget(this);
    _splitter = new QSplitter(this);
    _splitter1 = new QSplitter(this);
    this->plainTextEdit = new QPlainTextEdit();

    scrollArea = new QScrollArea(this);
    imageLabel = new QLabel(this);
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    _tex = new TextureBuilderExplorer(this);


    const QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    this->plainTextEdit->setFont(fixedFont);
    this->_listFiles = new QListWidget(this);
    connect(this->_listFiles,SIGNAL(itemClicked(QListWidgetItem*)) ,this, SLOT(on_listFiles_clicked(QListWidgetItem*)));
    connect(_tex->tree(),SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),
            this, SLOT(on_tree_item_double_clicked(QTreeWidgetItem*,int)));
}

void MainWindow::layoutWidgets() {
    this->setCentralWidget(tabWidget);
    this->addToolBar(Qt::TopToolBarArea, mainToolBar);
    this->setStatusBar(statusBar);

    _splitter1->addWidget(_tex);
    _splitter1->addWidget(this->plainTextEdit);
    _splitter->setOrientation(Qt::Horizontal);

    _splitter->addWidget(_listFiles);
    _splitter->addWidget(scrollArea);
    _splitter->setOrientation(Qt::Vertical);

    tabWidget->addTab(_splitter1,"JSON Editor");
    tabWidget->addTab(_splitter, "Generated images");
    this->setCentralWidget(tabWidget);
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
            updateTreeWithJsonFromEditor();
        }
}

void MainWindow::updateEditorsWithTBInfo() {
    QJsonObject o;
    _tb.toJson(o);
    QJsonDocument doc(o);
    QString strJson(doc.toJson());
    this->plainTextEdit->setPlainText(strJson);
    //updateTreeWithJsonFromEditor();
}

void MainWindow::updateTreeWithJsonFromEditor() {
    try {
        QString s = this->plainTextEdit->toPlainText();
        QByteArray jsonData(s.toStdString().c_str());
        QJsonParseError parserError;
        QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parserError);
        this->_tb.fromJson(doc.object());
        this->_tex->setTextureBuilder(&_tb);
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
    catch (std::string exc) {
        QString error(exc.c_str());
        errorBox(error);
    }
    catch (QString exc) {
        QString error(exc);
        errorBox(error);
    }
    catch (...) {
        std::string err = "Undefined error";
        throw err;
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
            QPixmap pixmap(imgFile);
            this->imageLabel->setPixmap(pixmap);
            this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
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
    catch (std::string exc) {
        QString error(exc.c_str());
        errorBox(error);
    }
    catch (QString exc) {
        QString error(exc);
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

void MainWindow::infoBox(QString msg) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("<big>"+msg+"</big>");
    msgBox.setInformativeText("");
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
        this->updateTreeWithJsonFromEditor();
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
        this->updateTreeWithJsonFromEditor();
    }


}

void MainWindow::on_listFiles_clicked(QListWidgetItem *idx) {
    //_viewer->loadImage(imgFile);
    QString data = _listFiles->currentItem()->text();
    this->setWindowTitle(data);
    QPixmap pixmap(data);
    this->imageLabel->setPixmap(pixmap);
    this->imageLabel->setGeometry(0,0,pixmap.width(),pixmap.height());
}

void MainWindow::on_action_CreateModuleDescJson()
{
    QModuleDescDialog dlg(this);
    QSharedPointer<ModuleDescriptor> mod(new ModuleDescriptor());
    dlg.moduleDescWidget()->setModuleDesc(mod.data());
    auto moduleList = buildModuleList();
    dlg.moduleDescWidget()->setModuleList(moduleList);
    if (dlg.exec() == QDialog::Accepted) {
        dlg.moduleDescWidget()->updateDescriptorFromControls();
        _tb.modDesc().insert(mod->name(),mod);
        //auto newPtr = dlg.moduleDescWidget()->moduleDesc();
        //modDescSPtr.reset(newPtr);
        //_tb.modDesc()[txt] = modDescSPtr;
        updateEditorsWithTBInfo();
        this->_tex->setTextureBuilder(&this->_tb);
        infoBox("Module descriptor "+ mod->name() + "("+mod->moduleType()+") created!");
    }
}

void MainWindow::on_action_CreateHeightmapBuilder() {
    QSharedPointer<NoiseMapBuilderDescriptor> bDesc(new NoiseMapBuilderDescriptor());
    auto ptr = bDesc.data();
    _tb.assignSizeInfoToNMBDesc(ptr);
    HeightMapBuilderDialog dlg(ptr);
    dlg.builderWidget()->setBuilder(ptr);
    dlg.builderWidget()->fillBuilder();
    auto ml = this->buildModuleList();
    auto hl = this->buildNoiseMapList();
    QStringList sl;
    for (auto s: ml) sl.append(s);
    dlg.builderWidget()->setModuleList(sl);
    dlg.builderWidget()->setNoiseMapList(hl);
    dlg.builderWidget()->fillWidgetWithBuilder();
    if (dlg.exec() == QDialog::Accepted) {
        dlg.builderWidget()->fillBuilder();
        _tb.nmbDesc().insert(bDesc.data()->name(),bDesc);
        updateEditorsWithTBInfo();
        this->_tex->setTextureBuilder(&this->_tb);
    }
}

void MainWindow::on_action_new_texture_triggered()
{
    TextureBuilder tb;
    QJsonObject o;
    tb.toJson(o);
    QJsonDocument doc(o);
    QString strJson(doc.toJson());
    this->plainTextEdit->setPlainText(strJson);
    this->updateTreeWithJsonFromEditor();

}

void MainWindow::on_action_create_rend_desc() {
    QStringList images = this->buildImageList();
    QStringList nmbs = this->buildNoiseMapList();
    RendererDescDialog dlg(this);
    dlg.setImageList(images);
    dlg.setNoiseMapList(nmbs);
    QSharedPointer<RendererDescriptor> sptr(new RendererDescriptor());
    dlg.setRendererDescriptor(sptr.data());
    if (dlg.exec() == QDialog::Accepted) {
        _tb.rndDesc().insert(sptr.data()->name(),sptr);
        updateEditorsWithTBInfo();
        this->_tex->setTextureBuilder(&this->_tb);
        /*
        QJsonObject oRenderer;
        auto rndDescPtr = dlg.rendererDescriptor();
        rndDescPtr->toJson(oRenderer);
        QJsonDocument doc(oRenderer);
        QString strJson(doc.toJson());
        this->plainTextEdit->insertPlainText(strJson);
        this->updateTreeWithJsonFromEditor();
        */
    }
}

void MainWindow::on_tree_item_double_clicked(QTreeWidgetItem *item, int column) {
    if (column ==0) {
        auto txt = item->text(0);
        QString mode = item->columnCount() > 1 ? item->text(1) : "";
        if (mode == "Renderer" && _tb.rndDesc().contains(txt) ) {
            auto sptr = _tb.rndDesc()[txt];
            auto ptr = sptr.data();
            QStringList images = this->buildImageList();
            QStringList nmbs = this->buildNoiseMapList();
            RendererDescDialog dlg(this);

            dlg.setImageList(images);
            dlg.setNoiseMapList(nmbs);
            dlg.setRendererDescriptor(sptr.data());
            if (dlg.exec() == QDialog::Accepted) {
                //_tb.rndDesc().insert(sptr.data()->name(),sptr);
                updateEditorsWithTBInfo();
                this->_tex->setTextureBuilder(&this->_tb);
            }
        }
        if (mode == "HeightmapBuilder" && _tb.nmbDesc().contains(txt) ) {
            auto sptr = _tb.nmbDesc()[txt];
            auto ptr = sptr.data();
            _tb.assignSizeInfoToNMBDesc(ptr);
            HeightMapBuilderDialog dlg(ptr);
            dlg.builderWidget()->setBuilder(ptr);
            auto ml = this->buildModuleList();
            auto hl = this->buildNoiseMapList();
            QStringList sl;
            for (auto s: ml) sl.append(s);
            dlg.builderWidget()->setModuleList(sl);
            dlg.builderWidget()->setNoiseMapList(hl);
            dlg.builderWidget()->fillWidgetWithBuilder();
            if (dlg.exec() == QDialog::Accepted) {
                dlg.builderWidget()->fillBuilder();
                updateEditorsWithTBInfo();
                this->_tex->setTextureBuilder(&this->_tb);
            }
        }
        if (mode == "Module" && _tb.modDesc().contains(txt)) {
            auto modDescSPtr = _tb.modDesc()[txt];
            auto modDescPtr = modDescSPtr.data();
            QModuleDescDialog dlg;
            dlg.moduleDescWidget()->setModuleDesc(modDescPtr);
            auto moduleList = buildModuleList();
            dlg.moduleDescWidget()->setModuleList(moduleList);
            dlg.moduleDescWidget()->updateControlsFromDescriptor();
            dlg.moduleDescWidget()->enableForEditing();
            if (dlg.exec() == QDialog::Accepted) {
                dlg.moduleDescWidget()->updateDescriptorFromControls();
                //auto newPtr = dlg.moduleDescWidget()->moduleDesc();
                //modDescSPtr.reset(newPtr);
                //_tb.modDesc()[txt] = modDescSPtr;
                updateEditorsWithTBInfo();
                this->_tex->setTextureBuilder(&this->_tb);
                infoBox("Module descriptor "+ modDescPtr->name() + "("+modDescPtr->moduleType()+") updated!");

            }
        }
    }
}

QVector<QString> MainWindow::buildModuleList(QString curMod) {
    QVector<QString> strng;
    for (auto m : _tb.modDesc()) {
        if (curMod != m.data()->name())
            strng.append(m.data()->name());
    }
    return strng;
}

QStringList MainWindow::buildImageList() {
    QStringList lst;
    for ( auto i : _tb.imDesc())
        lst.append(i.data()->name());
    return lst;
}

QStringList MainWindow::buildNoiseMapList() {
    QStringList lst;
    for ( auto i : _tb.hmDesc())
        lst.append(i.data()->name());
    return lst;
}

void MainWindow::on_action_CreateHeightMapDesc() {
    bool ok;
    QString hmTitle = QInputDialog::getText(this, "New HeightMap", "Insert new HeightMap",
                                            QLineEdit::Normal, QString("heightMap_%1").arg(_tb.hmDesc().count()*10),
                                            &ok);
    if (ok && !hmTitle.isEmpty() && !_tb.hmDesc().contains(hmTitle)) {
        QSharedPointer<HeightMapDescriptor> sp(new HeightMapDescriptor());
        sp.data()->setName(hmTitle);
        _tb.hmDesc().insert(sp.data()->name(),sp);
        updateEditorsWithTBInfo();
        this->_tex->setTextureBuilder(&this->_tb);
    }
    else {
        this->errorBox("Problem acquiring heightMap name or heightMap name already present");
    }
}

void MainWindow::on_action_CreateImageDesc() {
    bool ok;
    QString hmTitle = QInputDialog::getText(this, "New Image", "Insert new Image",
                                            QLineEdit::Normal, QString("Image_%1").arg(_tb.imDesc().count()*10),
                                            &ok);
    if (ok && !hmTitle.isEmpty() && !_tb.imDesc().contains(hmTitle)) {
        QSharedPointer<ImageDescriptor> sp(new ImageDescriptor());
        sp.data()->setName(hmTitle);
        _tb.imDesc().insert(sp.data()->name(),sp);
        updateEditorsWithTBInfo();
        this->_tex->setTextureBuilder(&this->_tb);
    }
    else {
        this->errorBox("Problem acquiring image name or image name already present");
    }

}

