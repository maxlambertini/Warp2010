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
