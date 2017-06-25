#include "rendererdescdialog.h"
#include <QPushButton>
#include <qcolorops.h>

RendererDescDialog::RendererDescDialog(QWidget *parent) : QDialog(parent)
{
    auto grid = new QGridLayout(this);
    this->_renderer  = new QRendererDescWidget(this);
    this->gradientEditor = new QtGradientEditor(this);
    this->gradientEditor->setMinimumWidth(500);


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto vLayout = new QVBoxLayout(this);
    vLayout->addWidget(this->_renderer);
    vLayout->addSpacing(70);

    auto vLayout2 = new QVBoxLayout(this);
    vLayout2->addWidget(new QLabel("Gradient editor",this));
    vLayout2->addWidget(this->gradientEditor);
    QPushButton *btn = new QPushButton("Create random gradient",this);
    vLayout2->addWidget(btn);
    connect (btn, SIGNAL(clicked(bool)),SLOT(on_create_random_gradient()));


    grid->addLayout(vLayout,0,0);
    grid->addLayout(vLayout2,0,1);
    grid->addWidget(this->buttonBox,2,0,1,2);
    this->setWindowTitle("Create Renderer");
    this->setLayout(grid);

}

void RendererDescDialog::on_dialog_accept() {
    this->_renderer->fillRendererDescriptor();
    auto grad = this->gradientEditor->gradient();
    auto d = this->_renderer->rendererDescriptor();
    d->gradientInfo().clear();
    QVector<QGradientStop> stops = grad.stops();
    for (auto i = stops.begin(); i != stops.end(); ++i) {
        QGradientStop s = (*i);
        auto tpl = std::tuple<double,int,int,int,int>(
        (s.first*2.0)-1.0,s.second.red(),s.second.green(),s.second.blue(),s.second.alpha());
        d->gradientInfo().append(tpl);
    }
    QDialog::accept();
}

void RendererDescDialog::setRendererDescriptor(RendererDescriptor *v) {
    this->_renderer->setRendererDescriptor(v);
    this->_renderer->readFromRendererDescriptor();
    if (v->gradientInfo().count() > 0) {
       //auto grad = this->gradientEditor->gradient();
       QLinearGradient grad;
       //grad.stops().clear();
       for (auto gradItem : v->gradientInfo() ) {
           QColor colorStop( std::get<1>(gradItem),
                             std::get<2>(gradItem),
                             std::get<3>(gradItem),
                             std::get<4>(gradItem));
           auto pos = (std::get<0>(gradItem) + 1.0) /2.0;
           grad.setColorAt(pos, colorStop);
       }
       this->gradientEditor->setGradient(grad);
    }
}

void RendererDescDialog::on_create_random_gradient() {
    auto c1 = ColorOps::randomHSLColor();
    auto c2 = ColorOps::randomHSLColor();
    auto step = 2 + SSGX::dx(6);
    double dStep = 1.0/static_cast<double>(step);
    QLinearGradient grad;
    grad.setColorAt(0.0, c1);
    grad.setColorAt(1.0, c2);
    double ds = 0.0;
    for (auto h = 1; h < step; h++ ) {
        ds += (dStep + (dStep/2.0)*SSGX::floatRand() - dStep/4.0 );
        grad.setColorAt(ds, ColorOps::randomHSLColor());
    }
    this->gradientEditor->setGradient(grad);

}
