#ifndef TEXTUREBUILDERWIDGET_H
#define TEXTUREBUILDERWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QComboBox>
#include <texturebuilder/texturebuilder.h>

class TextureBuilderWidget : public QWidget
{
    Q_OBJECT

    QLineEdit* c_north;
    QLineEdit* c_south;
    QLineEdit* c_west;
    QLineEdit* c_east;
    QComboBox* c_builderType;
    QLineEdit* c_bumpMap;
    QLineEdit* c_cloudMap;
    QLineEdit* c_colorMap;
    QLineEdit* c_reflectionMap;
    QLineEdit* c_randomFactors;
    QLineEdit* c_sizeX;
    QLineEdit* c_sizeY;

    TextureBuilder *_tb;
public:
    explicit TextureBuilderWidget(QWidget *parent = 0);
    void createWidgets();
    void layoutWidgets();

    TextureBuilder *textureBuilder() { return _tb; }
    void setTextureBuilder(TextureBuilder *tb) { _tb = tb; }

    void readFromTextureBuilder();
    void writeToTextureBuilder();

signals:

public slots:
};

#endif // TEXTUREBUILDERWIDGET_H
