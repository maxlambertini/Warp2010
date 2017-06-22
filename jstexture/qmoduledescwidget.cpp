#include "qmoduledescwidget.h"
#include <QLabel>
#include <QDialog>
#include <QWidget>

QModuleDescWidget::QModuleDescWidget(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    layoutWidgets();
}

void QModuleDescWidget::createWidgets() {
    auto iVal = new QIntValidator(this);
    auto iValFreq = new QIntValidator(1,6,this);
    QDoubleValidator* dValPow = new QDoubleValidator(0.0001,0.9999,6,this);
    QDoubleValidator* dValFreq = new QDoubleValidator(0.00001,999.9,6,this);
    QDoubleValidator* dValRough = new QDoubleValidator(1.0000,9999.9,6,this);
    QDoubleValidator* dVal = new QDoubleValidator(this);
    QDoubleValidator* dBounds = new QDoubleValidator(-1.0,1.0,6,this);

    c_moduleType = new QComboBox(this); c_moduleType->setObjectName("c_moduleType");
    for (auto s : NoiseModules::moduleList) {
        c_moduleType->addItem(s);
    }
    c_moduleType->setCurrentText("Perlin");

    c_name = new QLineEdit(this); c_name->setObjectName("c_name");
    c_seed = new QLineEdit(this); c_seed->setObjectName("c_seed");
    c_seed->setValidator(iVal);
    c_oct = new QLineEdit(this); c_oct->setObjectName("c_oct");
    c_oct->setValidator(iValFreq);
    c_freq = new QLineEdit(this); c_freq->setObjectName("c_freq");
    c_freq->setValidator(dValFreq);
    c_lac = new QLineEdit(this); c_lac->setObjectName("c_lac");
    c_lac->setValidator(dValFreq);
    c_pers = new QLineEdit(this); c_pers->setObjectName("c_pers");
    c_pers->setValidator(dValFreq);
    c_src1 = new QComboBox(this); c_src1->setObjectName("c_src1");
    c_src2 = new QComboBox(this); c_src2->setObjectName("c_src2");
    c_src3 = new QComboBox(this); c_src3->setObjectName("c_src3");
    c_src4 = new QComboBox(this); c_src4->setObjectName("c_src4");
    c_ctl = new QComboBox(this); c_ctl->setObjectName("c_ctl");
    c_displ = new QLineEdit(this); c_displ->setObjectName("c_displ");
    c_displ->setValidator(dValFreq);
    c_lBound = new QLineEdit(this); c_lBound->setObjectName("c_lBound");
    c_lBound->setValidator(dBounds);
    c_uBound = new QLineEdit(this); c_uBound->setObjectName("c_uBound");
    c_uBound->setValidator(dBounds);
    c_exp = new QLineEdit(this); c_exp->setObjectName("c_exp");
    c_exp->setValidator(dValFreq);
    c_bias = new QLineEdit(this); c_bias->setObjectName("c_bias");
    c_bias->setValidator(dValFreq);
    c_scale = new QLineEdit(this); c_scale->setObjectName("c_scale");
    c_scale->setValidator(dValFreq);
    c_pow = new QLineEdit(this); c_pow->setObjectName("c_pow");
    c_pow->setValidator(dValPow);
    c_rough = new QLineEdit(this); c_rough->setObjectName("c_rough");
    c_rough->setValidator(dValRough);
    c_value = new QLineEdit(this); c_value->setObjectName("c_value");
    c_value->setValidator(dVal);
    c_x = new QLineEdit(this); c_x->setObjectName("c_x");
    c_x->setValidator(dVal);
    c_y = new QLineEdit(this); c_y->setObjectName("c_y");
    c_y->setValidator(dVal);
    c_z = new QLineEdit(this); c_z->setObjectName("c_z");
    c_z->setValidator(dVal);
    c_invert = new QCheckBox(this); c_invert->setObjectName("c_invert");
    c_enableRandom = new QCheckBox(this); c_enableRandom->setObjectName("c_enableRandom");
    c_enableDist = new QCheckBox(this); c_enableDist->setObjectName("c_enableDist");
    c_cPoints = new QTableWidget(this); c_cPoints->setObjectName("c_cPoints");


    c_cPoints->setColumnCount(2);
    c_cPoints->setRowCount(10);
    QStringList sl; sl << "x" << "y";
    c_cPoints->setHorizontalHeaderLabels(sl);
    //c_cPoints->verticalHeader()->setVisible(false);

    w = new QWidget(this);
    s_x = new QDoubleSpinBox(w);
    s_y = new QDoubleSpinBox(w);
    btnAddControlPoint = new QPushButton("Add",w);

    connect (btnAddControlPoint,SIGNAL(pressed()),this,SLOT(on_add_tuple_clicked()));
}

void QModuleDescWidget::layoutWidgets() {
    int nRow = 0;

    auto gb1 = new QGroupBox("Basic module info",this);
    auto gr1 = new QGridLayout(this);

    QLabel *lbl = new QLabel("Module Type",this); lbl->setObjectName("l_moduleType");
    lbl->setAlignment(Qt::AlignRight);
    QGridLayout *gridLayout = new QGridLayout();
    gr1->addWidget(lbl,nRow,0);
    lbl->setAlignment(Qt::AlignRight);
    gr1->addWidget(c_moduleType,nRow,1);

    lbl = new QLabel("Name",this); lbl->setObjectName("l_name");
    lbl->setAlignment(Qt::AlignRight);
    gr1->addWidget(lbl,nRow,2);
    gr1->addWidget(c_name,nRow,3);
    gb1->setLayout(gr1);


    auto gb2 = new QGroupBox("Numeric parameters",this);
    auto gr2 = new QGridLayout(this);
    nRow = 0;

    lbl = new QLabel("Seed",this); lbl->setObjectName("l_seed");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,0);
    gr2->addWidget(c_seed,nRow,1);

    lbl = new QLabel("Octave",this); lbl->setObjectName("l_oct");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_oct,nRow,3);

    lbl = new QLabel("Frequency",this); lbl->setObjectName("l_freq");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_freq,nRow,1);

    lbl = new QLabel("Lacunarity",this); lbl->setObjectName("l_lac");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_lac,nRow,3);

    lbl = new QLabel("Persistence",this); lbl->setObjectName("l_pers");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_pers,nRow,1);


    lbl = new QLabel("Displace",this); lbl->setObjectName("l_displ");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_displ,nRow,3);

    lbl = new QLabel("Upper bound",this); lbl->setObjectName("l_lBound");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_lBound,nRow,1);

    lbl = new QLabel("Lower Bound",this); lbl->setObjectName("l_uBound");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_uBound,nRow,3);

    lbl = new QLabel("Exponent",this); lbl->setObjectName("l_exp");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_exp,nRow,1);

    lbl = new QLabel("Bias",this); lbl->setObjectName("l_bias");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_bias,nRow,3);

    lbl = new QLabel("Scale",this); lbl->setObjectName("l_scale");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_scale,nRow,1);

    lbl = new QLabel("Power",this); lbl->setObjectName("l_pow");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_pow,nRow,3);

    lbl = new QLabel("Roughness",this); lbl->setObjectName("l_rough");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,++nRow,0);
    gr2->addWidget(c_rough,nRow,1);

    lbl = new QLabel("Value/Falloff",this); lbl->setObjectName("l_value");
    lbl->setAlignment(Qt::AlignRight);
    gr2->addWidget(lbl,nRow,2);
    gr2->addWidget(c_value,nRow,3);

    gb2->setLayout(gr2);

    auto gb3 = new QGroupBox("Source and Control Modules",this);
    auto gr3 = new QGridLayout(this);
    nRow = 0;


    lbl = new QLabel("Control Module",this); lbl->setObjectName("l_ctl");
    lbl->setAlignment(Qt::AlignRight);
    gr3->addWidget(lbl,nRow,0);
    gr3->addWidget(c_ctl,nRow,1);

    lbl = new QLabel("Source Mod. 1",this); lbl->setObjectName("l_src1");
    lbl->setAlignment(Qt::AlignRight);
    gr3->addWidget(lbl,nRow,2);
    gr3->addWidget(c_src1,nRow,3);

    lbl = new QLabel("Source Mod. 2",this); lbl->setObjectName("l_src2");
    lbl->setAlignment(Qt::AlignRight);
    gr3->addWidget(lbl,++nRow,0);
    gr3->addWidget(c_src2,nRow,1);

    lbl = new QLabel("Source Mod. 3",this); lbl->setObjectName("l_src3");
    lbl->setAlignment(Qt::AlignRight);
    gr3->addWidget(lbl,nRow,2);
    gr3->addWidget(c_src3,nRow,3);

    lbl = new QLabel("Source Mod. 4",this); lbl->setObjectName("l_src4");
    lbl->setAlignment(Qt::AlignRight);
    gr3->addWidget(lbl,++nRow,0);
    gr3->addWidget(c_src4,nRow,1);

    gb3->setLayout(gr3);

    auto gb4 = new QGroupBox("Point displacement parameters",this);
    auto gr4 = new QGridLayout(this);
    nRow = 0;

    lbl = new QLabel("X",this); lbl->setObjectName("l_x");
    lbl->setAlignment(Qt::AlignRight);
    gr4->addWidget(lbl,nRow,0);
    gr4->addWidget(c_x,nRow,1);

    lbl = new QLabel("Y",this); lbl->setObjectName("l_y");
    lbl->setAlignment(Qt::AlignRight);
    gr4->addWidget(lbl,nRow,2);
    gr4->addWidget(c_y,nRow,3);

    lbl = new QLabel("Z",this); lbl->setObjectName("l_z");
    lbl->setAlignment(Qt::AlignRight);
    gr4->addWidget(lbl,nRow,4);
    gr4->addWidget(c_z,nRow,5);


    gb4->setLayout(gr4);

    auto gb5 = new QGroupBox("Boolean parameters",this);
    auto gr5 = new QGridLayout(this);
    nRow = 0;

    lbl = new QLabel("Invert?",this); lbl->setObjectName("l_invert");
    lbl->setAlignment(Qt::AlignRight);
    gr5->addWidget(lbl,nRow,0);
    gr5->addWidget(c_invert,nRow,1);

    lbl = new QLabel("Enable Random?",this); lbl->setObjectName("l_enableRandom");
    lbl->setAlignment(Qt::AlignRight);
    gr5->addWidget(lbl,nRow,2);
    gr5->addWidget(c_enableRandom,nRow,3);

    lbl = new QLabel("Enable Distortion?",this); lbl->setObjectName("l_enableDist");
    lbl->setAlignment(Qt::AlignRight);
    gr5->addWidget(lbl,nRow,4);
    gr5->addWidget(c_enableDist,nRow,5);

    gb5->setLayout(gr5);

    gridLayout->addWidget(gb1,0,0);
    gridLayout->addWidget(gb2,1,0);
    gridLayout->addWidget(gb3,2,0);
    gridLayout->addWidget(gb4,3,0);
    gridLayout->addWidget(gb5,4,0);

    auto gr6 = new QGroupBox("Control points");
    auto bl6 = new QVBoxLayout(this);

    QGridLayout* l2 = new QGridLayout(this);
    lbl = new QLabel("X",this);
    l2->addWidget(lbl,0,0);
    l2->addWidget(s_x,0,1);
    lbl = new QLabel("Y",this);
    l2->addWidget(lbl,0,2);
    l2->addWidget(s_y,0,3);
    l2->addWidget(btnAddControlPoint,0,4);
    w->setLayout(l2);
    bl6->addWidget(w);
    bl6->addWidget(c_cPoints);
    gr6->setLayout(bl6);

    gridLayout->addWidget(gr6,0,1,5,1,Qt::AlignTop);
    this->setLayout(gridLayout);

}

void QModuleDescWidget::setModuleDesc(ModuleDescriptor *d)
{
    _moduleDesc = d;
    updateControlsFromDescriptor();
}

void QModuleDescWidget::setModuleList(QVector<QString> &m) {
    _moduleList = m;
    c_src1->clear();
    c_src2->clear();
    c_src3->clear();
    c_src4->clear();
    c_ctl->clear();
    c_ctl->addItem("");
    c_src1->addItem("");
    c_src2->addItem("");
    c_src3->addItem("");
    c_src4->addItem("");
    for ( auto mod : m) {
        c_ctl->addItem(mod);
        c_src1->addItem(mod);
        c_src2->addItem(mod);
        c_src3->addItem(mod);
        c_src4->addItem(mod);
    }
    c_ctl->setCurrentIndex(0);
    c_src1->setCurrentIndex(0);
    c_src2->setCurrentIndex(0);
    c_src3->setCurrentIndex(0);
    c_src4->setCurrentIndex(0);

}

void QModuleDescWidget::updateControlsFromDescriptor()
{
    if (_moduleDesc != nullptr) {
        c_bias->setText(QString("%1").arg(_moduleDesc->bias()));
        c_ctl->setCurrentText(_moduleDesc->ctl());
        c_src1->setCurrentText(_moduleDesc->src1());
        c_src2->setCurrentText(_moduleDesc->src2());
        c_src3->setCurrentText(_moduleDesc->src3());
        c_src4->setCurrentText(_moduleDesc->src4());
        c_displ->setText(QString("%1").arg(_moduleDesc->displ()));
        c_exp->setText(QString("%1").arg(_moduleDesc->exp()));
        c_freq->setText(QString("%1").arg(_moduleDesc->freq()));
        c_lac->setText(QString("%1").arg(_moduleDesc->lac()));
        c_oct->setText(QString("%1").arg(_moduleDesc->oct()));
        c_pers->setText(QString("%1").arg(_moduleDesc->pers()));
        c_pow->setText(QString("%1").arg(_moduleDesc->pow()));
        c_scale->setText(QString("%1").arg(_moduleDesc->scale()));
        c_rough->setText(QString("%1").arg(_moduleDesc->rough()));
        c_seed->setText(QString("%1").arg(_moduleDesc->seed()));
        c_uBound->setText(QString("%1").arg(_moduleDesc->uBound()));
        c_lBound->setText(QString("%1").arg(_moduleDesc->lBound()));
        c_value->setText(QString("%1").arg(_moduleDesc->value()));
        c_x->setText(QString("%1").arg(_moduleDesc->x()));
        c_y->setText(QString("%1").arg(_moduleDesc->y()));
        c_z->setText(QString("%1").arg(_moduleDesc->z()));
        c_name->setText(_moduleDesc->name());
        c_moduleType->setCurrentText(_moduleDesc->moduleType());
        c_enableDist->setChecked(_moduleDesc->enableDist());
        c_enableRandom->setChecked(_moduleDesc->enableRandom());
        c_invert->setChecked(_moduleDesc->invert());
        int nRow = 0;
        c_cPoints->clear();
        for (auto pt : _moduleDesc->cPoints()) {
            c_cPoints->setItem(nRow, 0, new QTableWidgetItem(QString("%1").arg(std::get<0>(pt))));
            c_cPoints->setItem(nRow, 1, new QTableWidgetItem(QString("%1").arg(std::get<1>(pt))));
            ++nRow;
        }
    }
}

void QModuleDescWidget::updateDescriptorFromControls() {
    if (_moduleDesc != nullptr) {
        _moduleDesc->setModuleType(c_moduleType->currentText());
        _moduleDesc->setBias(c_bias->text().toDouble());
        _moduleDesc->setCtl(c_ctl->currentText());
        _moduleDesc->setDispl(c_ctl->currentText().toDouble());
        _moduleDesc->setEnabledist(c_enableDist->isChecked());
        _moduleDesc->setEnableRandom(c_enableRandom->isChecked());
        _moduleDesc->setExp(c_exp->text().toDouble());
        _moduleDesc->setFreq(c_freq->text().toDouble());
        _moduleDesc->setInvert(c_invert->isChecked());
        _moduleDesc->setLac(c_lac->text().toDouble());
        _moduleDesc->setLbound(c_lBound->text().toDouble());
        _moduleDesc->setName(c_name->text());
        _moduleDesc->setOct(c_oct->text().toInt());
        _moduleDesc->setPers(c_pers->text().toDouble());
        _moduleDesc->setPow(c_pow->text().toDouble());
        _moduleDesc->setRough(c_rough->text().toDouble());
        _moduleDesc->setScale(c_scale->text().toDouble());
        _moduleDesc->setSeed(c_seed->text().toInt());
        _moduleDesc->setSrc1(c_src1->currentText());
        _moduleDesc->setSrc2(c_src2->currentText());
        _moduleDesc->setSrc3(c_src3->currentText());
        _moduleDesc->setSrc4(c_src4->currentText());
        _moduleDesc->setUbound(c_uBound->text().toDouble());
        _moduleDesc->setValue(c_value->text().toDouble());
        _moduleDesc->setX(c_x->text().toDouble());
        _moduleDesc->setY(c_y->text().toDouble());
        _moduleDesc->setZ(c_z->text().toDouble());
    }
}


void QModuleDescWidget::updateGridWithControlPoints() {

}

void QModuleDescWidget::on_add_tuple_clicked() {
    auto x = s_x->value();
    auto y = s_y->value();

}
