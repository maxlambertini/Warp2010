#ifndef HEIGHTMAPBUILDERWIDGET_H
#define HEIGHTMAPBUILDERWIDGET_H

#include <QWidget>
#include <texturebuilder/noisemapbuilderdescriptor.h>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QComboBox>
#include <QGridLayout>
#include <QCheckBox>
#include <QLabel>

class HeightMapBuilderWidget : public QWidget
{
    Q_OBJECT

    NoiseMapBuilderDescriptor _builder;

    void initBuilder();
    void createWidgets();

    QGridLayout *_grid;

    QLabel    *_lbl;
    QLineEdit *_name;
    QLineEdit *_source;
    QLineEdit *_dest;
    QLineEdit *_sizeX;
    QLineEdit *_sizeY;
    QLineEdit *_topAngle;
    QLineEdit *_bottomAngle;
    QLineEdit *_leftAngle;
    QLineEdit *_rightAngle;
    QComboBox *_type;
    QCheckBox *_seamless;

public:
    NoiseMapBuilderDescriptor* builder() { return &_builder; }
    explicit HeightMapBuilderWidget(QWidget *parent = 0);

    void fillBuilder();
signals:

public slots:
};

#endif // HEIGHTMAPBUILDERWIDGET_H
