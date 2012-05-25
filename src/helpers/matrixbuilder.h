#ifndef MATRIXBUILDER_H
#define MATRIXBUILDER_H

#include <QObject>
#include <QtCore>

typedef QVector<int> TWordColl;
typedef QMap<int,TWordColl *> TDistanceMatrix;


class MatrixBuilder : public QObject
{
    Q_OBJECT
public:
    explicit MatrixBuilder(QObject *parent = 0);
    TDistanceMatrix *_lStart, *_lDest, *_distanceMatrix;

    void buildMatrix(int from);

signals:

public slots:

};

#endif // MATRIXBUILDER_H
