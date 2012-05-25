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

#include "ssg_structures.h"

namespace SSGX {
    LumMassTempRadius lmtrF_IV[] = {
        { L : 19.0, M : 2.5, T : 7300, R : 2.7 },
        { L : 16.9, M : 2.4, T : 7200, R : 2.7 },
        { L : 15.1, M : 2.3, T : 7100, R : 2.6 },
        { L : 13.4, M : 2.2, T : 6950, R : 2.6 },
        { L : 12.0, M : 2.1, T : 6800, R : 2.5 },
        { L : 10.7, M : 2.0, T : 6650, R : 2.5 },
        { L : 9.5, M : 1.95, T : 6500, R : 2.5 },
        { L : 8.5, M : 1.90, T : 6350, R : 2.5 },
        { L : 7.6, M : 1.85, T : 6200, R : 2.4 },
        { L : 6.7, M : 1.80, T : 6050, R : 2.4 }
    };

    LumMassTempRadius lmtrG_IV[10] = {
        { L : 6, M : 1.75, T : 5900,   R : 2.4 },
        { L : 5.8, M : 1.70, T : 5750, R : 2.4 },
        { L : 5.6, M : 1.65, T : 5600, R : 2.5 },
        { L : 5.4, M : 0.60, T : 5450, R : 2.6 },
        { L : 5.2, M : 0.55, T : 5300, R : 2.7 },
        { L : 5.0, M : 0.50, T : 5200, R : 2.8 },
        { L : 4.8, M : 0.48, T : 5100, R : 2.8 },
        { L : 4.6, M : 0.46, T : 5000, R : 2.9 },
        { L : 4.4, M : 0.44, T : 4900, R : 2.9 },
        { L : 4.2, M : 0.42, T : 4800, R : 3.0 }
    };

    LumMassTempRadius lmtrF_V[10] = {
        { L : 6.4, M : 1.6, T : 7500, R : 1.5 } ,
        { L : 5.5, M : 1.53, T : 7350, R : 1.5 } ,
        { L : 4.7, M : 1.47, T : 7200, R : 1.4 } ,
        { L : 4.0, M : 1.42, T : 7050, R : 1.4 } ,
        { L : 3.4, M : 1.36, T : 6900, R : 1.3 } ,
        { L : 2.9, M : 1.31, T : 6750, R : 1.3 } ,
        { L : 2.5, M : 1.26, T : 6600, R : 1.2 } ,
        { L : 2.16, M : 1.21, T : 6450, R : 1.2 } ,
        { L : 1.85, M : 1.17, T : 6300, R : 1.2 } ,
        { L : 1.58, M : 1.12, T : 6150, R : 1.1 }
    };

    LumMassTempRadius lmtrG_V[10] = {
        { L : 1.36, M : 1.08, T : 6000, R : 1.1 } ,
        { L : 1.21, M : 1.05, T : 5900, R : 1.1 } ,
        { L : 1.09, M : 1.02, T : 5800, R : 1.0 } ,
        { L : 0.98, M : 0.99, T : 5700, R : 1.0 } ,
        { L : 0.88, M : 0.96, T : 5600, R : 1.0 } ,
        { L : 0.79, M : 0.94, T : 5500, R : 1.0 } ,
        { L : 0.71, M : 0.92, T : 5400, R : 1.0 } ,
        { L : 0.64, M : 0.89, T : 5300, R : 1.0 } ,
        { L : 0.57, M : 0.87, T : 5200, R : 0.9 } ,
        { L : 0.51, M : 0.85, T : 5100, R : 0.9 }
    };

    LumMassTempRadius lmtrK_V[10] = {
        { L : 0.46, M : 0.82, T : 5000, R : 0.9 } ,
        { L : 0.39, M : 0.79, T : 4850, R : 0.9 } ,
        { L : 0.32, M : 0.75, T : 4700, R : 0.9 } ,
        { L : 0.27, M : 0.72, T : 4550, R : 0.8 } ,
        { L : 0.23, M : 0.69, T : 4400, R : 0.8 } ,
        { L : 0.19, M : 0.66, T : 4250, R : 0.8 } ,
        { L : 0.16, M : 0.63, T : 4100, R : 0.8 } ,
        { L : 0.14, M : 0.61, T : 3950, R : 0.8 } ,
        { L : 0.11, M : 0.56, T : 3800, R : 0.8 } ,
        { L : 0.10, M : 0.49, T : 3650, R : 0.8 }
    };


    LumMassTempRadius lmtrM_V[10] = {
        { L : 0.08, M : 0.46, T : 3500, R : 0.8 } ,
        { L : 0.04, M : 0.38, T : 3350, R : 0.6 } ,
        { L : 0.02, M : 0.32, T : 3200, R : 0.5 } ,
        { L : 0.012, M : 0.26, T : 3050, R : 0.4 } ,
        { L : 0.006, M : 0.21, T : 2900, R : 0.3 } ,
        { L : 0.003, M : 0.18, T : 2750, R : 0.25 } ,
        { L : 0.0017, M : 0.15, T : 2600, R : 0.2 } ,
        { L : 0.0009, M : 0.12, T : 2450, R : 0.17 } ,
        { L : 0.0005, M : 0.10, T : 2300, R : 0.14 } ,
        { L : 0.0002, M : 0.08, T : 2200, R : 0.11 }
    };

};

