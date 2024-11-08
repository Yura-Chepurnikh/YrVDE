#include "mainwindow.h"

#include <QApplication>
#include "TrySqlite.h"
#include "LogicGateSymbol.h"
#include "BondingWire.h"
#include "./Edge.h"

#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
   // QCoreApplication::addLibraryPath("C:\Qt\6.7.1\mingw_64\plugins\sqldrivers");
    QApplication a(argc, argv);

    // Edge* edge = new Edge();

    // QMainWindow w;
    // w.setCentralWidget(edge);
    // w.show();

    QGraphicsView* view = new QGraphicsView();
    QGraphicsScene* scene = new QGraphicsScene(view);
    scene->setSceneRect(-200, -200, 500, 600);
    BondingWire* bw = new BondingWire();
    scene->addItem(bw);

    view->setScene(scene);
    view->show();

    return a.exec();
}
