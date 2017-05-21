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

#ifndef PROGRESSBARHELPER_H
#define PROGRESSBARHELPER_H

#include <QtGui>
#include <QProgressBar>

class ProgressBarHelper
{
    QProgressBar *pbar;

public:
    ProgressBarHelper();
    ProgressBarHelper (QProgressBar *p) : pbar(p) {}
public:
    inline void show () { pbar->setVisible(true); }
    inline void reset (int minval = 0, int maxval=100, int resetval = 0) {
        if (pbar != 0) {
            pbar->setMinimum(minval);
            pbar->setMaximum(maxval);
            pbar->setValue(resetval);
        }
    }


    inline void nextStep (int val) {
        if (pbar != 0)
            pbar->setValue(val);
        qApp->processEvents();
    }

    inline void hide () { pbar->setVisible(false); }


};

#endif // PROGRESSBARHELPER_H
