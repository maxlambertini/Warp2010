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

#include "celestiaexporter.h"
#include <QtCore>
#include "star.h"
#include "planet.h"
#include "ssg_structures.h"


QString CelestiaExporter::planetToCelestia(Planet& planet, QString starName, QString planetFatherName = "")
{
    QString sOutput;
    QTextStream stream(&sOutput);

    if (planetFatherName != "")
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "/" << planetFatherName << "\" {\n";
    else
        stream << "\"" << planet.name() << "\" \"" << _star->starName << "\" {\n";

    // qDebug() << "step 1";

    stream << "\tTexture \"" << planet.getPlanetTexture() << "\"\n";
    stream << "\tMass " << planet.massEarth() << "\n";
    stream << "\tRadius " << planet.radius() << "\n";
    stream << "\tRotationPeriod " << planet.orbit().day() << "\n";
    stream << "\tEllipticalOrbit { \n";
    stream << "\t\tPeriod " << planet.orbit().year() << "\n";
    stream << "\t\tEccentricity " << planet.orbit().eccentricity() << "\n";

    // qDebug() << "step 2";


    if (!planet.isSatellite())
        stream << "\t\tSemiMajorAxis " << planet.orbit().distance() << "\n";
    else
        stream << "\t\tSemiMajorAxis " << (planet.orbit().distance() ) << "\n";

    // qDebug() << "step 3";


    stream << "\t\tInclination " << planet.orbit().inclination() << "\n";
    stream << "\t\tObliquity " << planet.orbit().obliquity() << "\n";
    stream << "\t\tEpoch " << SSGX::dn(1000000) << "." << SSGX::dn(1000000) << "\n";
    stream << "\t}\n";

    // qDebug() << "step 4";


    if ( (int)planet.atmosphere() <= 3) {

        int type = (int)planet.atmosphere();
        if (type < 1) type = 1;
        stream << "\tAtmosphere { \n";
        stream << "\t\tHeight " << (SSGX::dn(40)+ SSGX::dn(40)+30)  << "\n";
        stream << "\t\tLower [" << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 6 << " " << SSGX::floatRand() << "]\n ";
        stream << "\t\tUpper [" << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 6 << " " << SSGX::floatRand() / 2 << "]\n ";
        stream << "\t\tSky [" << SSGX::floatRand() / 3 << " " << SSGX::floatRand() / 3 << " " << SSGX::floatRand() / 2 << "]\n ";
        stream << "\t\tCloudHeight " << (SSGX::d10()+ SSGX::d10()+30) / type << "\n";
        stream << "\t\tCloudSpeed " << (SSGX::d10()+ SSGX::d10()+30) / type << "\n";
        stream << "\t\tCloudMap \"" << planet.getCloudTexture() << "\"\n";
        stream << "}\n";
        // qDebug() << "step 4.2";

    }

    // qDebug() << "step 5";

    stream << "}\n\n";
    stream.flush();

    // qDebug() << "step 6";


    return sOutput;

}

void CelestiaExporter::saveCelestiaDataToFile(QString &filename)
{
    // qDebug() << "starting celestia export ";
    QString sOutput;
    QTextStream stream(&sOutput);

    Planet planet, sat;
    foreach (planet, _star->planets()) {
        stream << this->planetToCelestia(planet,_star->starName);
        // qDebug() << "celestia exporting " << planet.name();
        foreach (sat, planet.satellites()) {
            stream << this->planetToCelestia(sat,_star->starName,planet.name());
            // qDebug() << "celestia exporting sat " << sat.name();
        }
    }
    // qDebug() << "flushing ";
    stream.flush();

    // qDebug() << "writing file... " << _star->starName << ".ssc";


    QFile data (filename);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
         QTextStream out(&data);
         out << sOutput;
         out.flush();
     }
     data.close();
    // qDebug() << "ended celestia export ";
}


