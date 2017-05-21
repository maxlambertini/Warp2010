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

#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QtCore>
#include <QtGui>
#include <QSplashScreen>
#include "helpers/apppaths.h"

class SplashScreen
{
    static SplashScreen _screen;
    QSplashScreen *_splashScreen;
    QPixmap *_pixmap;

public:
    SplashScreen();
    ~SplashScreen() {
        //qDebug() << "destroying splashScreen";
        delete _splashScreen;
    }
    SplashScreen (const SplashScreen & );
    SplashScreen& operator= (const SplashScreen&);

    static SplashScreen& screen() { return SplashScreen::_screen; }
    static SplashScreen* screenPtr() { return &SplashScreen::_screen; }

    void initialize() {
        _pixmap = new QPixmap();
        //qDebug() << AppPaths::appDir()+"/pics/rex_orbiting_horza.jpg";
        _pixmap->load(AppPaths::appDir()+"/pics/rex_orbiting_horza.jpg");
        _splashScreen = new QSplashScreen(*_pixmap);
    }

    void show() {
        _splashScreen->show(); qApp->processEvents(QEventLoop::ExcludeUserInputEvents	);
    }
    void hide() {
        _splashScreen->hide(); qApp->processEvents(QEventLoop::ExcludeUserInputEvents	);
    }
    void setMessage (const QString& message) {
        if (_splashScreen->isHidden())
            _splashScreen->show();
        _splashScreen->showMessage(message, Qt::AlignRight, QColor(255,255,255)); qApp->processEvents(QEventLoop::ExcludeUserInputEvents	);
    }
    void clearMessage() {
        _splashScreen->clearMessage(); qApp->processEvents(QEventLoop::ExcludeUserInputEvents	);
    }
    void setPixmap(QPixmap *p) {
        _pixmap = p; _splashScreen->setPixmap(*p);
    }
};

#endif // SPLASHSCREEN_H
