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

    NoiseMapBuilderDescriptor* _builder;



    QGridLayout *_grid;

    QLabel    *_lbl;
    QLineEdit *_name;
    QComboBox *_source;
    QComboBox *_dest;
    QLineEdit *_sizeX;
    QLineEdit *_sizeY;
    QLineEdit *_topAngle;
    QLineEdit *_bottomAngle;
    QLineEdit *_leftAngle;
    QLineEdit *_rightAngle;
    QComboBox *_type;
    QCheckBox *_seamless;

    QStringList _moduleList;
    QStringList _noiseMapList;

public:
    NoiseMapBuilderDescriptor* builder() { return _builder; }
    void setBuilder(NoiseMapBuilderDescriptor *p) { _builder = p; }
    explicit HeightMapBuilderWidget(NoiseMapBuilderDescriptor *ptr,
                                    QWidget *parent = 0);
    void initBuilder();
    void createWidgets();
    void fillBuilder();
    void fillWidgetWithBuilder();
    void setModuleList (QStringList& i);
    void setNoiseMapList (QStringList& i);
signals:

public slots:
};

#endif // HEIGHTMAPBUILDERWIDGET_H
