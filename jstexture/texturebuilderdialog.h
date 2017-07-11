#ifndef TEXTUREBUILDERDIALOG_H
#define TEXTUREBUILDERDIALOG_H

#include <QObject>
#include <QDialog>
#include <QDialogButtonBox>
#include <texturebuilder/texturebuilder.h>
#include <texturebuilderwidget.h>
#include <QVBoxLayout>

class TextureBuilderDialog : public QDialog
{
    Q_OBJECT

    QDialogButtonBox *btn;
    TextureBuilderWidget *_tbw = nullptr;
    bool _editMode = false;

public:
    explicit TextureBuilderDialog(QWidget* parent = 0);
    TextureBuilderWidget* textureBuilderWidget() { return _tbw; }

    TextureBuilder* textureBuilder() {
        if (_tbw != nullptr)
            return _tbw->textureBuilder();
        return nullptr;
    }

    void setTextureBuilder(TextureBuilder *tb) {
        if (_tbw != nullptr) {
            _tbw->setTextureBuilder(tb);
            _tbw->readFromTextureBuilder();
        }
    }

public slots:
    void on_accept_dialog();

};

#endif // TEXTUREBUILDERDIALOG_H
