#ifndef ADDTEXTUREWORKFLOWWIDGET_H
#define ADDTEXTUREWORKFLOWWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>

//void TextureBuilder::createTextureWorkflow(QString prefix, bool bCreateImage , QString backgroundImage , QString destImage, bool last)

class AddTextureWorkflowWidget : public QWidget
{
    Q_OBJECT    
    QLineEdit* c_prefix;
    QLineEdit* c_backgroundImage;
    QLineEdit* c_destImage;
    QCheckBox* c_bCreateImage;
    QCheckBox* c_last;

public:
    explicit AddTextureWorkflowWidget(QWidget *parent = 0);

    void layoutWidgets();
    void createWidgets();

    const QString prefix() { return c_prefix->text(); }
    const QString backgroundImage() { return c_backgroundImage->text(); }
    const QString destImage() { return c_destImage->text(); }
    bool createImage() { return c_bCreateImage->isChecked(); }
    bool last() { return c_last->isChecked(); }

signals:

public slots:
};

#endif // ADDTEXTUREWORKFLOWWIDGET_H
