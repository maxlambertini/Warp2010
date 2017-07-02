/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA#
############################################################################
*/

#ifndef RENDERERDESCDIALOG_H
#define RENDERERDESCDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <qrendererdescwidget.h>
#include <QtGradientEditor/qtgradienteditor.h>
#include <QDialogButtonBox>
#include <texturebuilder/rendererdescriptor.h>
#include <ssg_structures.h>

class RendererDescDialog : public QDialog
{
    Q_OBJECT

    QRendererDescWidget *_renderer;
    QtGradientEditor *gradientEditor;
    QDialogButtonBox *buttonBox;



public:
    explicit RendererDescDialog(QWidget *parent = 0);
    RendererDescriptor* rendererDescriptor() { return _renderer->rendererDescriptor(); }
    void setRendererDescriptor(RendererDescriptor* v);
    void setImageList(QStringList& i) { _renderer->setImageList(i); }
    void setNoiseMapList(QStringList& i) { _renderer->setNoiseMapList(i); }

    QRendererDescWidget *renderer() { return this->_renderer; }

private slots:
    void on_dialog_accept();
    void on_create_random_gradient();
    void on_create_earthlike_gradient();
    void on_create_desert_gradient();
    void on_create_mars_gradient();
    void on_create_moon_gradient();
};

#endif // RENDERERDESCDIALOG_H
