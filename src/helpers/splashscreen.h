/*
############################################################################
#
# This file is part of Warp2010, (C) Massimiliano Lambertini - 2009
# Contact: m.lambertini@gmail.com
#
# GNU General Public License Usage
# This file may be used under the terms of the GNU
# General Public License version 3.0 as published by the Free Software
# Foundation and appearing in the file LICENSE.GPL included in the
# packaging of this file.  Please review the following information to
# ensure the GNU General Public License version 3.0 requirements will be
# met: http://www.gnu.org/copyleft/gpl.html.
#
############################################################################
*/


#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QtCore>
#include <QtGui>
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
