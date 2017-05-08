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

#include "clusterhtmlexporter.h"
#include "cluster/cluster.h"
#include "cluster/clusteritem.h"
#include "cluster/aspect.h"
#include "cluster/aspectlist.h"
#include "appmessage.h"
#include <QtCore>
#include <QtGui>

ClusterHTMLExporter::ClusterHTMLExporter()
{
}

QString ClusterHTMLExporter::ToHTML(Cluster &cluster)
{
    QString buf = "<table class='cluster_table'><tr>"
                  "<th>Name</th>"
                  "<th>Links</th>"
                  "<th>Env</th>"
                  "<th>Tech</th>"
                  "<th>Res</th>"
                  "<th>Aspects</th></tr>";
    int cnt = cluster.clusterItems().count();
    for (int i = 0; i < cnt; i++) {
        ClusterItem ci = cluster.clusterItems().at(i);
        buf += QString("\n<tr class='row_%1'>").arg( i % 2) +
               "\n<td><a name='" + QString("system_%1").arg(i) + "' />" + ci.name() + "</td>"
               "\n<td>Connected to: ";

        for (int w = 0; w < ci.linkedBy().count(); w++) {
            ClusterItem ci2 = cluster.clusterItems().at(ci.linkedBy().at(w));
            buf += "<a href='#system_" + QString("%1").arg(ci.linkedBy().at(w)) + "'>"
                   + ci2.name() + "</a> ";
        }
        for (int w = 0; w < ci.links().count(); w++) {
            ClusterItem ci2 = cluster.clusterItems().at(ci.links().at(w));
            buf += "<a href='#system_" + QString("%1").arg(ci.links().at(w)) + "'>"
                   + ci2.name() + "</a> ";
        }

        buf += "</td>"
               "\n<td>" + QString("%1").arg(ci.environment())+ "</td>"
               "\n<td>" + QString("%1").arg(ci.technology())+ "</td>"
               "\n<td>" + QString("%1").arg(ci.resources())+ "</td>\n<td>"
               "\n<ul class='aspect_list'>";
        int cntAspect = ci.aspects().count();
        for (int h = 0; h < cntAspect; h++) {
            Aspect a = ci.aspects().at(h);
            buf += "\n<li>"+a.name()+"</li>";
        }
        buf += "</ul></td></tr>\n";
    }
    buf += "</table>";

    return buf;
}
