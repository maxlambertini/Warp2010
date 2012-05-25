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

#include "starwidgetitem.h"

StarWidgetItem::StarWidgetItem(Star* newStar, int idx, QListWidget *view):
        QListWidgetItem(newStar->starName, view)
{
    _star = newStar;
    this->_indexOnList = idx;
    if (newStar->path().count() > 0)
        this->backgroundColor() = QColor(255,255,128,128);
}

