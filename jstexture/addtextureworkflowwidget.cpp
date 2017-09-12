#include "addtextureworkflowwidget.h"

void AddTextureWorkflowWidget::createWidgets()
{
    this->c_backgroundImage = new QLineEdit(this);
    this->c_destImage = new QLineEdit(this);
    this->c_prefix = new QLineEdit("TextureFlow",this);
    this->c_last = new QCheckBox(this);
    this->c_bCreateImage = new QCheckBox(this);
}

void AddTextureWorkflowWidget::layoutWidgets()
{
    QGridLayout *grid = new QGridLayout(this);

    int nRow = 0;
    QLabel *lbl = new QLabel("Texture workflow prefix",this);
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    grid->addWidget(lbl,nRow,0);
    grid->addWidget(c_prefix,nRow,1);

    nRow++;
    lbl = new QLabel("Background Image",this);
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    grid->addWidget(lbl,nRow,0);
    grid->addWidget(c_backgroundImage,nRow,1);

    nRow++;
    lbl = new QLabel("Destination Image",this);
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    grid->addWidget(lbl,nRow,0);
    grid->addWidget(c_destImage,nRow,1);

    nRow++;
    lbl = new QLabel("Create Image",this);
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    grid->addWidget(lbl,nRow,0);
    grid->addWidget(c_bCreateImage,nRow,1);

    nRow++;
    lbl = new QLabel("Add as last",this);
    lbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    grid->addWidget(lbl,nRow,0);
    grid->addWidget(c_last,nRow,1);
}

AddTextureWorkflowWidget::AddTextureWorkflowWidget(QWidget *parent) : QWidget(parent)
{
    createWidgets();
    layoutWidgets();
}
