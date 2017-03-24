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
