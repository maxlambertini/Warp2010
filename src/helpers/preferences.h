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


#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QtCore>
#include <QtGui>


class Preferences
{
private:
    friend class Cleanup;
    class Cleanup {
    public:
        ~Cleanup();
    };

    //private members;
    QFont _fontTitle;
    QFont _fontAspectTitle;
    QFont _fontBody;
    QFont _fontSmall;

    QColor _colorDiasporaLink;
    QColor _colorDiasporaAspectBox;
    QColor _colorDiasporaAspectBackground;
    QColor _colorStarShortestLink;
    QColor _colorStarOtherLink;

    qreal  _sizeTitle;
    qreal  _sizeAspectTitle;
    qreal  _sizeBody;
    qreal  _sizeSmall;

    bool _drawRoutesAsArcs;
    bool _drawSecondaryRoutes;

    static Preferences _prefs;

    Preferences();
    ~Preferences();
    Preferences (const Preferences & );
    Preferences& operator= (const Preferences&);


public:

    static Preferences &prefs();
    static Preferences *prefsPtr();

    QFont& fontTitle()  { return _fontTitle; }
    QFont& fontAspectTitle()  { return _fontAspectTitle; }
    QFont& fontBody()  { return _fontBody; }
    QFont& fontSmall()  { return _fontSmall; }

    QColor& colorDiasporaLink()  { return _colorDiasporaLink; }
    QColor& colorDiasporaAspectBox()  { return _colorDiasporaAspectBox; }
    QColor& colorDiasporaAspectBackground()  { return _colorDiasporaAspectBackground; }
    QColor& colorStarShortestLink()  { return _colorStarShortestLink; }
    QColor& colorStarOtherLink()  { return _colorStarOtherLink; }

    bool drawRoutesAsArcs() { return _drawRoutesAsArcs;}
    bool drawSecondaryRoutes() { return _drawSecondaryRoutes;}

    void setDrawRoutesAsArcs(bool b) { _drawRoutesAsArcs = b;}
    void setDrawSecondaryRoutes(bool b)  { _drawSecondaryRoutes = b;}

    void setFontTitle(const QFont& f) { _fontTitle = f; }
    void setFontAspectTitle(const QFont& f) { _fontAspectTitle = f; }
    void setFontBody(const QFont& f) { _fontBody = f; }
    void setFontSmall(const QFont& f) { _fontSmall = f; }

    void setColorDiasporaLink(const QColor& c) {_colorDiasporaLink = c;}
    void setColorDiasporaAspectBox(const QColor& c) { _colorDiasporaAspectBox = c; }
    void setColorDiasporaAspectBackground(const QColor& c) { _colorDiasporaAspectBackground = c; }
    void setColorStarShortestLink(const QColor& c) { _colorStarShortestLink = c; }
    void setColorStarOtherLink(const QColor& c) { _colorStarOtherLink = c; }


    friend QDataStream & operator >> (QDataStream &in, Preferences& frm);
    friend QDataStream& operator << (QDataStream &out, const Preferences& frm);

    static void savePreferences() ;
    static void loadPreferences();

};



#endif // PREFERENCES_H
