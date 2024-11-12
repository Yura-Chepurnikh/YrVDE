#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../BondingWire/bondingwire.h"

#include "../LogicGate/logicgate.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QObject();

    w.show();
    return a.exec();
}


