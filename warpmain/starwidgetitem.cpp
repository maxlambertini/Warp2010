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

#include "starwidgetitem.h"
#include <QListWidgetItem>

StarWidgetItem::StarWidgetItem(QSharedPointer<Star> newStar, int idx, QListWidget *view):
        QListWidgetItem(newStar->starName, view)
{
    _star = newStar;
    this->_indexOnList = idx;
    if (newStar->path().count() > 0)
        this->setBackground( QBrush( QColor(255,255,128,128)));
}

