#ifndef QRENDERERDESCWIDGET_H
#define QRENDERERDESCWIDGET_H

#include <QObject>
#include <QWidget>
#include <QtGradientEditor/qtgradienteditor.h>
#include <texturebuilder/rendererdescriptor.h>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QCheckBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>

class QRendererDescWidget : public QWidget
{
    Q_OBJECT

    RendererDescriptor *_rendererDescriptor;

    QLineEdit *c_name;
    QComboBox *c_noiseMap;
    QComboBox *c_backgroundImage;
    QComboBox *c_destImage;
    QCheckBox *c_enabledLight;
    QCheckBox *c_enableRandomGradient;
    QLineEdit *c_lightContrast;
    QLineEdit *c_lightBrightess;
    QSpinBox *c_randomFactorHue;
    QSpinBox *c_randomFactorSaturation;
    QSpinBox *c_randomFactorValue;

    QStringList _images;
    QStringList _noiseMapBuilders;

public:
    explicit QRendererDescWidget(QWidget *parent = 0);

    RendererDescriptor* rendererDescriptor() { return _rendererDescriptor; }
    void setRendererDescriptor (RendererDescriptor *v) { _rendererDescriptor = v; readFromRendererDescriptor();}
    void createWidgets();
    void fillRendererDescriptor();
    void readFromRendererDescriptor();
    void setImageList(QStringList& i);
    void setNoiseMapList(QStringList& i);

signals:

public slots:
};

#endif // QRENDERERDESCWIDGET_H
