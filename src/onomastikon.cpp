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

#include <QtCore>
#include <QFile>
#include <QStringList>
#include "onomastikon.h"
#include "stdlib.h"

QString letters  = "ABCDEFGHJKLMNPQRSTUVWXYZ";
QString vowels = "aeiouy";
QString consonants = "bcdfghjklmnprstvxz";

const char* greek_letters[] =
{
"Alfa",
"Beta",
"Gamma",
"Delta",
"Epsilon",
"Zeta",
"Upsilon",
"Eta",
"Theta",
"Iota",
"Kappa",
"Lambda",
"Mu",
"Nu",
"Xi",
"Omicron",
"Rho",
"Sigma",
"Tau",
"Ypsilon",
"Phi",
"Chi",
"Psi",
"Omega"
};

LETT_FREQ_ITEM consTable[] = {
    { letter : "b", frequency : 10 },
    { letter : "ch", frequency : 10 },
    { letter : "d", frequency : 10 },
    { letter : "e", frequency : 10 },
    { letter : "g", frequency : 10 },
    { letter : "gr", frequency : 2 },
    { letter : "k", frequency : 10 },
    { letter : "k", frequency : 10 },
    { letter : "kr", frequency : 2 },
    { letter : "ks", frequency : 2 },
    { letter : "l", frequency : 10 },
    { letter : "m", frequency : 12 },
    { letter : "n", frequency : 12 },
    { letter : "p", frequency : 12 },
    { letter : "pr", frequency : 2 },
    { letter : "pl", frequency : 2 },
    { letter : "s", frequency : 12 },
    { letter : "r", frequency : 10 },
    { letter : "t", frequency : 12 },
    { letter : "v", frequency : 10 },
    { letter : "w", frequency : 10 },
    { letter : "x", frequency : 10 },
    { letter : "z", frequency : 10 },
};

LETT_FREQ_ITEM vowTable[] = {
    { letter : "a", frequency : 20 },
    { letter : "e", frequency : 30 },
    { letter : "o", frequency : 20 },
    { letter : "i", frequency : 10 },
    { letter : "u", frequency : 5 },
    { letter : "io", frequency : 5 },
    { letter : "ao", frequency : 2 },
    { letter : "ae", frequency : 2 },
    { letter : "oa", frequency : 2 },
    { letter : "ia", frequency : 2 },
    { letter : "ou", frequency : 2 },
};


Onomastikon Onomastikon::_instance;

Onomastikon::Onomastikon()
{
    Q_INIT_RESOURCE(Resources);
    this->_crimesList << "prostitution" << "slavery" << "drug dealing"
            << "loansharking" << "polluting the environment" << "sex" << "gluttony" << "binge drinking"
            << "recreational drugs use" << "trash food eating parties" << "poligamy";
    this->_vicesList << "dishonesty" << "greed" << "gluttony" << "dishonor"
            << "lying" << "avarice";
    this->_virtuesList << "abstinence" << "courage" << "self-sacrifice"
            << "honor" << "love" << "friendship" << "honesty";
    this->_valuablesList << "gold" << "silver" << "platinum" << "tantalium"
            << "rare metals" << "radioactives" << "heavy metals"
            << "methane" << "brains";
    this->_goodsList << "delikatessen" << "starships" << "weapons"
            << "miniaturized hi-tec products" << "cutting-edge electronical devices"
            << "haute-couture suits" << "liquors" << "beers" << "fusion reactors";
    this->initializeStringList();
    for (int h = 0; h < 100; h++)
        _basicList.append(this->pseudoNomen());
}

Onomastikon::~Onomastikon() {}

void Onomastikon::initializeStringList() {
    _stringList << "Mercury" << "Venus" << "Terra" << "Luna"
            << "Mars" << "Phobos" << "Deimos" << "Jupiter"
            << "Europa" << "Ganymede" << "Io" << "Callisto"
            << "Saturn" << "Enceladus" << "Titan"
            << "Uranus" << "Thethys" << "Rhea"
            << "Neptune";
   //qDebug() << QFile::exists(":places");
   QFile file(":/textfiles/places2.txt");
   if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
       //qDebug() << "could not open places2.txt, error:" << file.error() << "," << file.errorString();
        //return;
    }

    //file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //qDebug() << line;
        _stringList << line;
    }
    file.close();

 }

QString Onomastikon::nomen() {
    int cnt = _stringList.count();
    int idx = rand() % cnt;
    QString items = _stringList.at(idx);
    QStringList names = items.split("/");
    cnt = names.count();
    idx = rand() % cnt;
    QString name =  names.at(idx);

    //qDebug() << name;

    return name;
}

QString Onomastikon::pseudoNomen()
{

    QString baseNomen =  this->nomen();
    int len = baseNomen.length();
    if (len > 2) {
        int idx = 1+ (rand() % (len-1));
        int iterations = 2+ rand() % 6;

        for (int x = 0; x < iterations; x++)
        {
            QString letter = baseNomen.mid(idx,1);
            if (vowels.indexOf(letter,0,Qt::CaseInsensitive) != -1)
            {
                QString newVowel = vowels.mid( ( rand() % (vowels.length() -1) ),1);
                baseNomen = baseNomen.replace(idx,1,newVowel);
            }
            else {
                QString newcons = consonants.mid( (rand() % (consonants.length()) -1),1);
                baseNomen = baseNomen.replace(idx,1,newcons);
            }
        }
    }
    return baseNomen;
}

QString Onomastikon::sigla()
{
    int n = letters.length();
    QString start = letters.mid(rand() % n,1) + letters.mid(rand() % n,1) + letters.mid(rand() % n,1) + " ";
    start.append((QString("%1 %2").arg(rand() % 2000 -1000).arg(rand() % 2000 -1000)));
    return start;
}

QString Onomastikon::greekName()
{
    int n = 24;
    int w = _basicList.count();
    QString start = QString("%1 %2 %3")
                    .arg(greek_letters[rand() % n])
                    .arg(_basicList.at(rand() % w))
                    .arg(rand() % 2000 -1000);
    return start;

}

/*
  Basic algorithm:
  1. Toss a coin
  2. Get no. of couples: from 1 to 3
  3. If coin is heads, sequence is cons + vows. Eventually, a cons may be appended.g
  4. If tails, sequence is vows+cons
 */
QString Onomastikon::fakeNomen() {
    QString start = "";
    int x = rand() % 2;
    int w = rand() % 3+2;
    if (x == 1) {
       for (int z = 0; z < w; z++)
           start += vowel()+ cons();
    } else {
        for (int z = 0; z < w; z++)
            start += cons()+ vowel();
        if (rand() % 2 == 0)
            start += cons();
    }
    return start.mid(0,1).toUpper()+start.mid(1,start.size()-1).toLower();
}
