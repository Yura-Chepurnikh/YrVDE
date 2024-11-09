#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include "TrySqlite.h"
#include "LogicGateSymbol.h"
#include "BondingWire.h"
#include "./Edge.h"
#include "./Grid.h"

#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
   // !!! QCoreApplication::addLibraryPath("C:\Qt\6.7.1\mingw_64\plugins\sqldrivers"); !!!
    QApplication a(argc, argv);
    QMainWindow w;

    QGraphicsScene* scene = new QGraphicsScene();

    Grid* grid = new Grid(scene);
    w.setCentralWidget(grid);


    BondingWire* wire = new BondingWire(grid);
    scene->addItem(wire);

    w.show();
    return a.exec();
}
