#ifndef TEXTUREBUILDEREXPLORER_H
#define TEXTUREBUILDEREXPLORER_H

#include <QObject>
#include <QWidget>
#include <QTreeWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <texturebuilder/texturebuilder.h>


class TextureBuilderExplorer : public QWidget
{
    Q_OBJECT

    TextureBuilder *_builder;
    QTreeWidget *_treeWidget;
    QLabel *_label;


public:
    explicit TextureBuilderExplorer(QWidget *parent = 0);

    QTreeWidget* tree() { return _treeWidget; }
    //accessors
    TextureBuilder* builder() { return _builder; }
    void setTextureBuilder(TextureBuilder* b);

signals:

public slots:
};

#endif // TEXTUREBUILDEREXPLORER_H
