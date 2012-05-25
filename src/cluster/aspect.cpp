#include <QtCore>
#include "aspect.h"
#include "clusteritem.h"
#include "onomastikon.h"

Aspect::Aspect()
{
}

Aspect Aspect::FromString(const QString &definitionString)
{
    Aspect aspect = Aspect(definitionString);
    aspect.checkAspectString();
    return aspect;
}

bool Aspect::canApplyToClusterItem(ClusterItem &cli)
{
    int env = cli.environment();
    int tech = cli.technology();
    int res = cli.resources();

    bool bRes =
            env >= _minEnv && env <= _maxEnv &&
            tech >= _minTech && tech <= _maxTech &&
            res >= _minRes && res <= _maxRes;
    return bRes;
}

// Checks if aspect name is an aspect definition string instead
void Aspect::checkAspectString()
{
    QString aspectData =_name;
    QStringList items = aspectData.split("|",QString::SkipEmptyParts);
    int nCnt = items.count();
    if (nCnt > 1) {
        for (int h = 0; h < nCnt; h++) {
            if (h == 0 ) {
                _name = items[h];
                _name = _name.trimmed();
            }
            else {
                QString item = items.at(h).trimmed();
                QStringList namevalue = item.split("=");
                if (namevalue.count() >= 2) {
                    QString name = namevalue.at(0).trimmed();
                    name = name.toUpper();
                    QString value = namevalue.at(1).trimmed();
                    if (name.startsWith("MINE"))
                        this->_minEnv = value.toInt();
                    if (name.startsWith("MAXE"))
                        this->_maxEnv = value.toInt();
                    if (name.startsWith("MINT"))
                        this->_minTech = value.toInt();
                    if (name.startsWith("MAXT"))
                        this->_maxTech = value.toInt();
                    if (name.startsWith("MINR"))
                        this->_minRes = value.toInt();
                    if (name.startsWith("MAXR"))
                        this->_maxRes = value.toInt();


                }
            }
        }
    }
}

void Aspect::processParametricAspect() {
    if (_name.contains("[[VICE]]"))
        _name = _name.replace("[[VICE]]",Onomastikon::instancePtr()->vice(),Qt::CaseInsensitive);
    if (_name.contains("[[VIRTUE]]"))
        _name = _name.replace("[[VIRTUE]]",Onomastikon::instancePtr()->virtue(),Qt::CaseInsensitive);
    if (_name.contains("[[CRIME]]"))
        _name = _name.replace("[[CRIME]]",Onomastikon::instancePtr()->crime(),Qt::CaseInsensitive);
    if (_name.contains("[[VALUABLE]]"))
        _name = _name.replace("[[VALUABLE]]",Onomastikon::instancePtr()->valuable(),Qt::CaseInsensitive);
    if (_name.contains("[[GOOD]]"))
        _name = _name.replace("[[GOOD]]",Onomastikon::instancePtr()->good(),Qt::CaseInsensitive);
    if (_name.contains("[[PERSON]]"))
        _name = _name.replace("[[PERSON]]",Onomastikon::instancePtr()->person(),Qt::CaseInsensitive);
    if (_name.contains("[[NAME]]"))
        _name = _name.replace("[[NAME]]",Onomastikon::instancePtr()->nomen(),Qt::CaseInsensitive);
}

QDataStream & operator >> (QDataStream &in, Aspect& frm) {
    in >> frm._name >> frm._maxEnv >> frm._minEnv
            >> frm._maxRes >> frm._minRes
            >> frm._maxTech >> frm._minTech;
    return in;
}


QDataStream& operator << (QDataStream &out, const Aspect& frm)
{
    out << frm._name << frm._maxEnv << frm._minEnv
            << frm._maxRes << frm._minRes
            << frm._maxTech << frm._minTech;
    return out;
}


