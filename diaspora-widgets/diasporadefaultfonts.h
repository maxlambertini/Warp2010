#ifndef DIASPORADEFAULTFONTS_H
#define DIASPORADEFAULTFONTS_H

#include <QFont>
#include "diaspora-widgets_global.h"

class  DIASPORAWIDGETSSHARED_EXPORT DiasporaDefaultFonts
{
public:
    DiasporaDefaultFonts();
    static QFont TitleFont() { return QFont("Helvetica",16,99); }
    static QFont BodyFont() { return QFont("Helvetica",11,99); }
};

#endif // DIASPORADEFAULTFONTS_H
