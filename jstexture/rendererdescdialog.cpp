#include "rendererdescdialog.h"


RendererDescDialog::RendererDescDialog(QWidget *parent) : QDialog(parent)
{
    auto grid = new QGridLayout(this);
    this->renderer  = new QRendererDescWidget(this);
    this->gradientEditor = new QtGradientEditor(this);
    this->gradientEditor->setMinimumWidth(500);


    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    buttonBox->setCenterButtons(true);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(on_dialog_accept()));
    connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);

    auto vLayout = new QVBoxLayout(this);
    vLayout->addWidget(this->renderer);
    vLayout->addSpacing(70);

    auto vLayout2 = new QVBoxLayout(this);
    vLayout2->addWidget(new QLabel("Gradient editor",this));
    vLayout2->addWidget(this->gradientEditor);

    grid->addLayout(vLayout,0,0);
    grid->addLayout(vLayout2,0,1);
    grid->addWidget(this->buttonBox,2,0,1,2);
    this->setWindowTitle("Create Renderer");
    this->setLayout(grid);

}

void RendererDescDialog::on_dialog_accept() {
    this->renderer->fillRendererDescriptor();
    auto grad = this->gradientEditor->gradient();
    RendererDescriptor& d = this->renderer->rendererDescriptor();
    d.gradientInfo().clear();
    QVector<QGradientStop> stops = grad.stops();
    for (auto i = stops.begin(); i != stops.end(); ++i) {
        QGradientStop s = (*i);
        auto tpl = std::tuple<double,int,int,int,int>(
        (s.first*2.0)-1.0,s.second.red(),s.second.green(),s.second.blue(),s.second.alpha());
        d.gradientInfo().append(tpl);
    }
    QDialog::accept();
}
