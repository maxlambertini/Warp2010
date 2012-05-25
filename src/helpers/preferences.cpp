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
