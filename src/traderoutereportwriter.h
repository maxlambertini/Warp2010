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

#ifndef TRADEROUTEREPORTWRITER_H
#define TRADEROUTEREPORTWRITER_H

#include <QtGui>
#include "traderoutemediator.h"
#include "starlist.h"

class TradeRouteReportWriter
{
public:
    TradeRouteReportWriter(StarList *list, TradeRouteMediator *mediator) :
            _document(new QTextDocument()),
            _cursor(_document)
    {
        _mediator = mediator;
        _starlist = list;
    }

    ~TradeRouteReportWriter() {
        delete _document;
    }

    void createDocument();
    void write(const QString& filename);
private:
    TradeRouteMediator *_mediator;
    StarList *_starlist;
    QTextDocument * const _document;
    QTextCursor _cursor;
};

#endif // TRADEROUTEREPORTWRITER_H
