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

#ifndef ONOMASTIKON_H
#define ONOMASTIKON_H

#include <QtCore>

typedef struct lettFreqItem {
    QString letter;
    int frequency;
} LETT_FREQ_ITEM;

extern LETT_FREQ_ITEM consTable[];
extern LETT_FREQ_ITEM vowTable[];

class Onomastikon
{
private:
    QStringList _stringList;
    QStringList _basicList;
    QStringList _vicesList;
    QStringList _virtuesList;
    QStringList _valuablesList;
    QStringList _crimesList;
    QStringList _goodsList;

    void initializeStringList();
    static Onomastikon _instance;

    Onomastikon();
    Onomastikon(const Onomastikon&);
    Onomastikon& operator=(const Onomastikon&);
    ~Onomastikon();
public:

    static inline Onomastikon* instancePtr() { return &Onomastikon::_instance; }

    const QStringList& stringList() { return _stringList; }
    inline void setStringList(const QStringList list) { _stringList = list; }

    QString nomen();
    QString sigla();
    QString greekName();
    QString pseudoNomen();

    QString fakeNomen();

    inline QString crime() { return _crimesList[rand() % _crimesList.count()]; }
    inline QString vice() { return _vicesList[rand() % _vicesList.count()]; }
    inline QString virtue() { return _virtuesList[rand() % _virtuesList.count()]; }
    inline QString valuable() { return _valuablesList[rand() % _valuablesList.count()]; }
    inline QString good() { return _goodsList[rand() % _goodsList.count()]; }
    inline QString person() { return nomen() +" "+ nomen(); }

    inline QString vowel() {
        int x = rand() % 100;
        LETT_FREQ_ITEM *item = vowTable;
        int w = item->frequency;
        while (x > w ) {
            item++;
            w += item->frequency;
        }
        return item->letter;
    }

    inline QString cons() {
        int x = rand() % 200;
        LETT_FREQ_ITEM *item = consTable;
        int w = item->frequency;
        while (x > w ) {
            item++;
            w += item->frequency;
        }
        return item->letter;
    }

};

#endif // ONOMASTIKON_H
