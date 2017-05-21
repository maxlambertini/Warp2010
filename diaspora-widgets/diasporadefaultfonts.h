#ifndef DIASPORADEFAULTFONTS_H
#define DIASPORADEFAULTFONTS_H

#include <QFont>

class DiasporaDefaultFonts
{
public:
    DiasporaDefaultFonts();
    static QFont TitleFont() { return QFont("Helvetica",16,99); }
    static QFont BodyFont() { return QFont("Helvetica",11,99); }
};

#endif // DIASPORADEFAULTFONTS_H
