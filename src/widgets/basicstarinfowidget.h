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


#ifndef BASICSTARINFOWIDGET_H
#define BASICSTARINFOWIDGET_H

#include <QWidget>
#include "star.h"

class BasicStarInfoWidget : public QWidget
{
Q_OBJECT
    Star* _star;
public:
    explicit BasicStarInfoWidget(QWidget *parent = 0);
    inline void setStar(Star *s) { _star = s; this->repaint();}
    inline Star* star() {return _star;}

protected:
    void paintEvent (QPaintEvent *event);

signals:

public slots:

};

#endif // BASICSTARINFOWIDGET_H
