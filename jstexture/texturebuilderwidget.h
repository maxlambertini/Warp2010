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

class TextureBuilderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TextureBuilderWidget(QWidget *parent = 0);

    QLineEdit* c_north;
    QLineEdit* c_south;
    QLineEdit* c_west;
    QLineEdit* c_east;
    QComboBox* c_builderType;
    QComboBox* c_bumpMap;
    QComboBox* c_cloudMap;
    QComboBox* c_colorMap;
    QLineEdit* c_reflectionMap;
    QLineEdit* c_randomFactors;
    QLineEdit* c_sizeX;
    QLineEdit* c_sizeY;

    void createWidgets();

signals:

public slots:
};

#endif // TEXTUREBUILDERWIDGET_H
