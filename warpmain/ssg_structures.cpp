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

#include "ssg_structures.h"

namespace SSGX {
    LumMassTempRadius lmtrF_IV[] = {
        { 19.0, 2.5, 7300, 2.7 },
        { 16.9, 2.4, 7200, 2.7 },
        { 15.1, 2.3, 7100, 2.6 },
        { 13.4, 2.2, 6950, 2.6 },
        { 12.0, 2.1, 6800, 2.5 },
        { 10.7, 2.0, 6650, 2.5 },
        { 9.5, 1.95, 6500, 2.5 },
        { 8.5, 1.90, 6350, 2.5 },
        { 7.6, 1.85, 6200, 2.4 },
        { 6.7, 1.80, 6050, 2.4 }
    };

    LumMassTempRadius lmtrG_IV[10] = {
        { 6, 1.75, 5900,   2.4 },
        { 5.8, 1.70, 5750, 2.4 },
        { 5.6, 1.65, 5600, 2.5 },
        { 5.4, 0.60, 5450, 2.6 },
        { 5.2, 0.55, 5300, 2.7 },
        { 5.0, 0.50, 5200, 2.8 },
        { 4.8, 0.48, 5100, 2.8 },
        { 4.6, 0.46, 5000, 2.9 },
        { 4.4, 0.44, 4900, 2.9 },
        { 4.2, 0.42, 4800, 3.0 }
    };

    LumMassTempRadius lmtrF_V[10] = {
        { 6.4, 1.6, 7500, 1.5 } ,
        { 5.5, 1.53, 7350, 1.5 } ,
        { 4.7, 1.47, 7200, 1.4 } ,
        { 4.0, 1.42, 7050, 1.4 } ,
        { 3.4, 1.36, 6900, 1.3 } ,
        { 2.9, 1.31, 6750, 1.3 } ,
        { 2.5, 1.26, 6600, 1.2 } ,
        { 2.16, 1.21, 6450, 1.2 } ,
        { 1.85, 1.17, 6300, 1.2 } ,
        { 1.58, 1.12, 6150, 1.1 }
    };

    LumMassTempRadius lmtrG_V[10] = {
        { 1.36, 1.08, 6000, 1.1 } ,
        { 1.21, 1.05, 5900, 1.1 } ,
        { 1.09, 1.02, 5800, 1.0 } ,
        { 0.98, 0.99, 5700, 1.0 } ,
        { 0.88, 0.96, 5600, 1.0 } ,
        { 0.79, 0.94, 5500, 1.0 } ,
        { 0.71, 0.92, 5400, 1.0 } ,
        { 0.64, 0.89, 5300, 1.0 } ,
        { 0.57, 0.87, 5200, 0.9 } ,
        { 0.51, 0.85, 5100, 0.9 }
    };

    LumMassTempRadius lmtrK_V[10] = {
        { 0.46, 0.82, 5000, 0.9 } ,
        { 0.39, 0.79, 4850, 0.9 } ,
        { 0.32, 0.75, 4700, 0.9 } ,
        { 0.27, 0.72, 4550, 0.8 } ,
        { 0.23, 0.69, 4400, 0.8 } ,
        { 0.19, 0.66, 4250, 0.8 } ,
        { 0.16, 0.63, 4100, 0.8 } ,
        { 0.14, 0.61, 3950, 0.8 } ,
        { 0.11, 0.56, 3800, 0.8 } ,
        { 0.10, 0.49, 3650, 0.8 }
    };


    LumMassTempRadius lmtrM_V[10] = {
        { 0.08, 0.46, 3500, 0.8 } ,
        { 0.04, 0.38, 3350, 0.6 } ,
        { 0.02, 0.32, 3200, 0.5 } ,
        { 0.012, 0.26, 3050, 0.4 } ,
        { 0.006, 0.21, 2900, 0.3 } ,
        { 0.003, 0.18, 2750, 0.25 } ,
        { 0.0017, 0.15, 2600, 0.2 } ,
        { 0.0009, 0.12, 2450, 0.17 } ,
        { 0.0005, 0.10, 2300, 0.14 } ,
        { 0.0002, 0.08, 2200, 0.11 }
    };

}

