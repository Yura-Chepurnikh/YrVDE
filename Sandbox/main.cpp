#include "mainwindow.h"

#include <QApplication>
#include "TrySqlite.h"
#include "LogicGateSymbol.h"

int main(int argc, char *argv[])
{
   // QCoreApplication::addLibraryPath("C:\Qt\6.7.1\mingw_64\plugins\sqldrivers");
    QApplication a(argc, argv);

    LogicGateSymbol* sym = new LogicGateSymbol;

    QMainWindow w;
    w.setCentralWidget(sym);
    w.show();

    return a.exec();
}
