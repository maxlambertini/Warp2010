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

#ifndef WARPEXCEPTION_H
#define WARPEXCEPTION_H

#include <QtCore>
#include <exception>

class WarpException : public std::exception
{
private:
    QString _errorString;
public:
    WarpException (const QString &error) : std::exception()
    {
        _errorString = error;
    }
    virtual ~WarpException() throw()
    {
    }

    virtual const char* what() const throw()
    {
        QByteArray ba = _errorString.toLatin1();
        const char *char_err = ba.data();
        return char_err;
    }

};

#endif // WARPEXCEPTION_H
