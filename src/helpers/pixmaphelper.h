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


#ifndef PIXMAPHELPER_H
#define PIXMAPHELPER_H

#include <QtCore>
#include <QtGui>


class PixmapHelper
{

    static PixmapHelper _instance;
    PixmapHelper();
    ~PixmapHelper();
    PixmapHelper(const PixmapHelper & );
    PixmapHelper& operator= (const PixmapHelper&);

    QMap<QString, QPixmap> _pixHash;


public:
    void initializeBitmaps();
    static PixmapHelper *instancePtr() { return &_instance; }
    QMap<QString, QPixmap>& pixHash() { return _pixHash; }
    QPixmap* planetaryPics(int i) ;
};

#endif // PIXMAPHELPER_H
