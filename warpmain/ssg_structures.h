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

#ifndef SSG_STRUCTURES_H
#define SSG_STRUCTURES_H

#include <stdlib.h>
#include <time.h>
#include <QColor>

namespace SSGX {

    typedef struct _LumMassTempRadius {
        double L;
        double M;
        double T;
        double R;
    } LumMassTempRadius;


    enum PlanetType {
        ptNone = 0,
        ptChunk = 1,
        ptRockball = 2,
        ptDesert = 3,
        ptHotHouse = 4,
        ptGlacier = 5,
        ptGarden = 6,
        ptPreGarden = 7,
        ptPostGarden = 8,
        ptGasGiant = 9,
        ptSuperJovian = 10,
        ptFailedCore = 11,
        ptIceball = 12
    };

    extern LumMassTempRadius lmtrF_IV[];
    extern LumMassTempRadius lmtrG_IV[10];
    extern LumMassTempRadius lmtrF_V[10];
    extern LumMassTempRadius lmtrG_V[10];
    extern LumMassTempRadius lmtrK_V[10];
    extern LumMassTempRadius lmtrM_V[10];

    inline int d1000() { return 1+ rand() % 1000; }
    inline int d100() { return 1+ rand() % 100; }
    inline int d10() { return 1+ rand() % 10; }
    inline int d6() { return 1+ rand() % 6; }
    inline int d5() { return 1+ rand() % 5; }
    inline int dn(int n) { return 1+rand() % n; }
    inline int dx(int n) { return rand() % n; }
    inline int nd6(int n) { int nRes = 0;
        for (int h = 0; h < n; h++)
            nRes += (1+ rand() % 6);
        return nRes;
    }

    inline int dF(int n = 4) {
        int res = 0; for (int idx = 0 ; idx < n; idx ++)
            res += ( 1- rand() % 3);
        return res;
    }

    inline double floatRand() {
        int d = rand() % 10000;
        return ( (double)d) / 10000.0;
    }

    inline double rockyDiameter() {
        int n = d10();
        switch (n) {
            case 1:
                return (double)(d5()*1000 + d1000());
                break;
            case 2:
                return (double)(d5()*1000 + d1000());
                break;
            case 3:
                return (double)(nd6(1)*1000 + d1000());
                break;
            case 4:
                return (double)(nd6(1)*1000 + d1000());
                break;
            case 5:
                return (double)(nd6(2)*1000 + d1000());
                break;
            case 6:
                return (double)(nd6(3)*1000 + d1000());
                break;
            case 7:
                return (double)(nd6(4)*1000 + d1000());
                break;
            case 8:
                return (double)(nd6(5)*1000 + d1000());
                break;
            case 9:
                return (double)(nd6(7)*1000 + d1000());
                break;
            case 10:
                return (double)(nd6(10)*1000 + d1000());
                break;
        }
        return 12756;

    }

    inline double icyDiameter() {
        int n = d6();
        switch (n) {
            case 1:
                return (double)(d5()*1000 + d1000());
                break;
            case 2:
                return (double)(nd6(2)*1000 + d1000());
                break;
            case 3:
                return (double)(nd6(3)*1000 + d1000());
                break;
            case 4:
                return (double)(nd6(5)*1000 + d1000());
                break;
            case 5:
                return (double)(nd6(7)*1000 + d1000());
                break;
            case 6:
                return (double)(nd6(10)*1000 + d1000());
                break;
        }
        return 12756;
    }

    inline double satDiameter() {
        int n = dn(12) - 8;
        if (n < 0)
            return (double)( d1000()/2);
        else
            return rockyDiameter();
    }


}

#endif // SSG_STRUCTURES_H
