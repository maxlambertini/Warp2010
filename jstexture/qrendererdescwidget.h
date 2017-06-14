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

class QRendererDescWidget : public QWidget
{
    Q_OBJECT

    RendererDescriptor _rendererDescriptor;

    QLineEdit *c_name;
    QLineEdit *c_noiseMap;
    QLineEdit *c_backgroundImage;
    QLineEdit *c_destImage;
    QCheckBox *c_enabledLight;
    QCheckBox *c_enableRandomGradient;
    QLineEdit *c_lightContrast;
    QLineEdit *c_lightBrightess;
    QSpinBox *c_randomFactorHue;
    QSpinBox *c_randomFactorSaturation;
    QSpinBox *c_randomFactorValue;


public:
    explicit QRendererDescWidget(QWidget *parent = 0);

    RendererDescriptor& rendererDescriptor() { return _rendererDescriptor; }
    void createWidgets();
    void fillRendererDescriptor();

signals:

public slots:
};

#endif // QRENDERERDESCWIDGET_H
