#include "noiseimagerunner.h"
#include <QThread>
#include <QDebug>


NoiseImageRunner::NoiseImageRunner()
{

}

void NoiseImageRunner::run()
{

    qDebug() << "NoiseImageRunner running " << QThread::currentThread();
}
