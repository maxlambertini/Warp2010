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


#include "preferences.h"
#include "helpers/apppaths.h"

Preferences Preferences::_prefs;

Preferences& Preferences::prefs() {
    return _prefs;
}


Preferences *Preferences::prefsPtr() {
    return &_prefs;
}

Preferences::Preferences() : _drawRoutesAsArcs(true), _drawSecondaryRoutes(true)
{
    //qDebug() << "Preferences Constructor invoked";

}

Preferences::~Preferences() {
    //qDebug() << "Preferences Destructor invoked";

}

void Preferences::savePreferences() {
    QString filePref = AppPaths::preferencesFile();
    QFile file(filePref);
    file.open(QIODevice::WriteOnly | QIODevice::ReadWrite);
    QDataStream out(&file);
    //qDebug() << "Streaming Preferences: " <<
    //        Preferences::prefs().fontAspectTitle().family()
    //        << Preferences::prefs().fontBody().family()
    //        << Preferences::prefs().fontSmall().family()
    //        << Preferences::prefs().fontTitle().family();

    out << Preferences::_prefs;
    file.close();
}

void Preferences::loadPreferences() {
    QString filePref = AppPaths::preferencesFile();
    if (!QFile::exists(filePref))
        savePreferences();
    QFile file(filePref);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> Preferences::_prefs;
    //qDebug() << Preferences::prefs().fontAspectTitle().family();
    file.close();
}

QDataStream & operator >> (QDataStream &in, Preferences& frm) {
    in >> frm._colorDiasporaAspectBackground
            >> frm._colorDiasporaAspectBox
            >> frm._colorDiasporaLink
            >> frm._colorStarOtherLink
            >> frm._colorStarShortestLink
            >> frm._fontAspectTitle
            >> frm._fontBody
            >> frm._fontSmall
            >> frm._fontTitle
            >> frm._drawRoutesAsArcs
            >> frm._drawSecondaryRoutes;

    //qDebug() << "Loaded Preferences: " << frm._fontAspectTitle.family()
    //        << frm._fontBody.family()
    //        << frm._fontSmall.family()
    //        << frm._fontTitle.family();

    return in;
}


QDataStream& operator << (QDataStream &out, const Preferences& frm)
{
    //qDebug() << "Saving Preferences: " <<
    //        frm._fontAspectTitle.family()
    //        << frm._fontBody.family()
    //        << frm._fontSmall.family()
    //        << frm._fontTitle.family();
    out << frm._colorDiasporaAspectBackground
            << frm._colorDiasporaAspectBox
            << frm._colorDiasporaLink
            << frm._colorStarOtherLink
            << frm._colorStarShortestLink
            << frm._fontAspectTitle
            << frm._fontBody
            << frm._fontSmall
            << frm._fontTitle
            << frm._drawRoutesAsArcs
            << frm._drawSecondaryRoutes;

    return out;
}
