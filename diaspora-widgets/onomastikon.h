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

#ifndef ONOMASTIKON_H
#define ONOMASTIKON_H

#include <QtCore>
#include "diaspora-widgets_global.h"

typedef struct lettFreqItem {
    QString letter;
    int frequency;
} LETT_FREQ_ITEM;

extern LETT_FREQ_ITEM consTable[];
extern LETT_FREQ_ITEM vowTable[];

class  DIASPORAWIDGETSSHARED_EXPORT Onomastikon
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
