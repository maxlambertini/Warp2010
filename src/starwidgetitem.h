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

#ifndef STARWIDGETITEM_H
#define STARWIDGETITEM_H

#include <QtGui>
#include <QListWidget>
#include <QListWidgetItem>
#include "star.h"

class StarWidgetItem : public QListWidgetItem
{

private:
    Star *_star;
    int  _indexOnList;

public:
    StarWidgetItem(Star *star, int idx, QListWidget *view) ;
    virtual ~StarWidgetItem() {  }
    Star* star() { return _star;}
    int indexOnList() { return _indexOnList;}

};

#endif // STARWIDGETITEM_H
