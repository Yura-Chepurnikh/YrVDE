#include "mainwindow.h"

#include <QApplication>
#include "TrySqlite.h"
#include "LogicGateSymbol.h"
#include "BondingWire.h"

int main(int argc, char *argv[])
{
   // QCoreApplication::addLibraryPath("C:\Qt\6.7.1\mingw_64\plugins\sqldrivers");
    QApplication a(argc, argv);

   BondingWire* bw = new BondingWire();

    QMainWindow w;
    w.setCentralWidget(bw);
    w.show();

    return a.exec();
}
