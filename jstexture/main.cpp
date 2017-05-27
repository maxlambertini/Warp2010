#include "mainwindow.h"
#include <QApplication>
#include <apppaths.h>

int main(int argc, char *argv[])
{
    AppPaths::appDir();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
