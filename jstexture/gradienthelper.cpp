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


#include <gradienthelper.h>

void CreateEarthlikeDesert (QtGradientEditor *ge) {
    QLinearGradient grad;
    grad.setColorAt(0.0, QColor::fromRgb( 22, 66,169));
    grad.setColorAt(0.65,QColor::fromRgb( 62,102,196));
    grad.setColorAt(0.70,QColor::fromRgb( 62,102,196));
    grad.setColorAt(0.71,QColor::fromRgb(235,228,171));
    grad.setColorAt(0.75,QColor::fromRgb(181,148, 40));
    grad.setColorAt(0.98,QColor::fromRgb(104, 93, 59));
    grad.setColorAt(1.0, QColor::fromRgb(255,255,255));
    ge->setGradient(grad);

}

void CreateEarthlikeGradient (QtGradientEditor *ge) {
    QLinearGradient grad;
    grad.setColorAt(0.0, QColor::fromRgb( 22, 66,169));
    grad.setColorAt(0.65,QColor::fromRgb( 62,102,196));
    grad.setColorAt(0.70,QColor::fromRgb( 62,102,196));
    grad.setColorAt(0.71,QColor::fromRgb(235,228,171));
    grad.setColorAt(0.75,QColor::fromRgb(235,228,171));
    grad.setColorAt(0.98,QColor::fromRgb( 92,181, 59));
    grad.setColorAt(1.0, QColor::fromRgb(255,255,255));
    ge->setGradient(grad);

}

void CreateMarslikeGradient (QtGradientEditor *ge) {
    QLinearGradient grad;
    grad.setColorAt(0.0,QColor::fromRgb(164,69,22));
    grad.setColorAt(0.20,QColor::fromRgb(189,10,70));
    grad.setColorAt(0.50,QColor::fromRgb(169,125,22));
    grad.setColorAt(0.80,QColor::fromRgb(198,105,12));
    grad.setColorAt(1.0,QColor::fromRgb(255,94,13));
    ge->setGradient(grad);

}

void CreateMoonlikeGradient (QtGradientEditor *ge) {
    QLinearGradient grad;
    grad.setColorAt(0.0,QColor::fromRgb(243,241,135));
    grad.setColorAt(0.20,QColor::fromRgb(220,219,214));
    grad.setColorAt(0.50,QColor::fromRgb(212,210,202));
    grad.setColorAt(0.80,QColor::fromRgb(239,230,199));
    grad.setColorAt(1.0,QColor::fromRgb(199,193,174));
    ge->setGradient(grad);

}
