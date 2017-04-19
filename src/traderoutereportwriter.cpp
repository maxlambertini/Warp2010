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

#include "traderoutereportwriter.h"
#include <QtCore>
#include <QtGui>
#include "traderoutemediator.h"
#include "traderoute.h"
#include "star.h"
#include "planet.h"

void TradeRouteReportWriter::createDocument()
{
    _cursor.insertHtml("<h1>Trade Routes</h1>");

    //initialize trade routes;
    QSharedPointer<TradeRoute> tr;
    QSharedPointer<Star> star;
    int i;

    //initialization
    foreach (tr, _mediator->tradeRoutes())
    {
        foreach (i, tr->path()) {
            star = _starlist->stars().at(i);
            star->setVisited(false);
        }
    }

    //let's write!
    QSharedPointer<Star> starFirst, starCur;
    foreach (tr, _mediator->tradeRoutes())
    {
        _cursor.insertBlock();
        _cursor.insertHtml("<h2>"+tr->routeName()+"</h2>");
        _cursor.insertBlock();

        starFirst = _starlist->stars().at(tr->path().first());
        QSharedPointer<Star> starPrev;
        foreach (i, tr->path()) {
            starCur = _starlist->stars().at(i);
            if (!starCur->visited()) {
                starCur->setVisited(true);
                _cursor.insertBlock();
                _cursor.insertHtml("<h3>"+starCur->starName+"</h3>");
                _cursor.insertBlock();
                if (starPrev != 0) {
                    double  dist = starCur->distance(starPrev.data());
                    _cursor.insertText(QString("Cumulative Distance: %1 ly").arg(dist));
                }
                starPrev = starCur;
                _cursor.insertBlock();
                QVector<QTextLength> columWidths;
                columWidths.append(QTextLength(QTextLength::PercentageLength, 25));
                columWidths.append(QTextLength(QTextLength::PercentageLength, 75));
                QTextTableFormat tableFormat;
                tableFormat.setCellPadding(5);
                tableFormat.setHeaderRowCount(1);
                tableFormat.setColumnWidthConstraints(columWidths);
                tableFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Solid);
                tableFormat.setWidth(QTextLength(QTextLength::PercentageLength, 100));

                if (starCur->planetCount() > 0)
                {
                    _cursor.insertTable(starCur->planetCount()+1,2,tableFormat);
                    _cursor.insertText(QObject::tr("Planet Name"));
                    _cursor.movePosition(QTextCursor::NextCell);
                    _cursor.insertText(QObject::tr("Planet Data"));
                    Planet planet;
                    foreach (planet, starCur->planets()) {
                        _cursor.movePosition(QTextCursor::NextRow);
                        _cursor.insertText(planet.name());
                        _cursor.movePosition(QTextCursor::NextCell);
                        _cursor.insertHtml(planet.toHtml());

                        if (planet.satellitesCount() > 0) {
                            Planet sat;
                            _cursor.insertBlock();
                            QTextTable *table =  _cursor.insertTable(planet.satellitesCount()+1,2,tableFormat);
                            _cursor.insertText(QObject::tr("Sat Name"));
                            _cursor.movePosition(QTextCursor::NextCell);
                            _cursor.insertText(QObject::tr("Sat sData"));
                            foreach (sat, planet.satellites()) {
                                _cursor.movePosition(QTextCursor::NextRow);
                                _cursor.insertText(sat.name());
                                _cursor.movePosition(QTextCursor::NextCell);
                                _cursor.insertHtml(sat.toHtml());
                            }
                            while (_cursor.currentTable() == table)
                                _cursor.movePosition(QTextCursor::NextBlock);
                        }
                    }
                    while (_cursor.currentTable() != 0)
                        _cursor.movePosition(QTextCursor::NextBlock);
                }

                _cursor.insertBlock();
            }
        }
    }
}

void TradeRouteReportWriter::write(const QString& filename = "cippo.odf")
{
    QTextDocumentWriter writer(filename+".html");
    writer.setFormat("HTML");
    writer.write(_document);
}
