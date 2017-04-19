#include "matrixbuilder.h"
#include "starlist.h"
#include "star.h"
#include <QtCore>


MatrixBuilder::MatrixBuilder(QObject *parent) :
    QObject(parent)
{
}

void MatrixBuilder::buildMatrix(int from) {

    StarList *_starList = StarList::StarListPtr();

    //inizializza la matrice temporanea e poi pulisci le distanze
    _distanceMatrix = new TDistanceMatrix();
    for (int h = 0; h < _starList->count(); h++) {
        _distanceMatrix->insert(h, new TWordColl());
        _starList->stars().at(h)->clearPath();
    }

    //inizializzo i vettori di raggiungibilità
    _lStart = new TDistanceMatrix();
    _lDest = new TDistanceMatrix();

    TWordColl *wc = new TWordColl();
    wc->append(from);
    _lStart->insert(from,wc);

    //main loop!
    do {
        for (int h = 0; h < _lStart->keys().count(); h++) {
            int starKey = _lStart->keys().at(h);
            wc = _lStart->value(starKey);
            QSharedPointer<Star>  _star = _starList->stars().at(starKey);
            if (_star->neighbors().count() > 0) {
                for (int w = 0; w < _star->neighbors().count(); w++) {
                    int worldIdx = _star->neighbors().at(w);
                    TWordColl wc2;
                    wc2.append(worldIdx);
                    int iTmp;
                    foreach (iTmp, *wc)
                        wc2.append(iTmp);
                    TWordColl *dObj = _distanceMatrix->value(worldIdx);

                    double dist = _starList->calculatePathDistance(wc2);
                    double distRef  =_starList->calculatePathDistance(*dObj);

                    if (distRef > dist) {
                        dObj->clear();
                        foreach (iTmp, wc2)
                            dObj->append(iTmp);
                        if (!_lDest->keys().contains(worldIdx))
                        {
                            TWordColl *wcTmp = new TWordColl();
                            foreach (iTmp, wc2)
                                wcTmp->append(iTmp);
                           _lDest->insert(worldIdx,wcTmp);
                        }
                        else {
                            TWordColl *wcTmp = new TWordColl();
                            distRef = _starList->calculatePathDistance(*wcTmp);
                            dist = _starList->calculatePathDistance(wc2);
                            if (distRef > dist) {
                                wcTmp->clear();
                                foreach (iTmp, wc2) {
                                    wcTmp->append(iTmp);
                                }
                                _lDest->insert(worldIdx, wcTmp);
                            }
                        }
                    }

                }

            }
        }
        for (int w = 0; w < _lStart->keys().count(); w++)
        {
            int k = _lStart->keys().at(w);
            TWordColl* z = _lStart->value( k);
            delete z;
        }
        _lStart->clear();
        if (_lDest->count() > 0) {
            for (int w = 0; w < _lDest->count(); w++) {
                int k = _lDest->keys().at(w);
                TWordColl *wcTmp = _lDest->value(k);
                TWordColl *wcNew = new TWordColl();
                int iTmp;
                foreach (iTmp, *wcTmp)
                    wcNew->append(iTmp);
                delete wcTmp;
                _lDest->remove(k);
                _lStart->insert(k,wcTmp);
            }
        }


    } while (_lStart->count() > 0);

    for (int w = 0; w < _distanceMatrix->keys().count(); w++) {
        int k = _distanceMatrix->keys().at(w);
        TWordColl *wc = _distanceMatrix->value(k);
        QSharedPointer<Star>  s = StarList::StarListPtr()->stars().at(w);
        s->clearPath();
        int iTmp;
        foreach (iTmp,*wc)
           s->appendToPath(iTmp);

    }


}
