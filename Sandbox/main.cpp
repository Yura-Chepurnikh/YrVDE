#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include "TrySqlite.h"
#include "LogicGateSymbol.h"
#include "BondingWire.h"
#include "./Edge.h"
#include "./Grid.h"

#include "./A.h"
#include "./B.h"

#include <QGraphicsView>
#include <QGraphicsScene>

int main(int argc, char *argv[])
{
   // !!! QCoreApplication::addLibraryPath("C:\Qt\6.7.1\mingw_64\plugins\sqldrivers"); !!!
    QApplication a(argc, argv);
    QMainWindow w;

    QGraphicsView* view = new QGraphicsView();
    QGraphicsScene* scene = new QGraphicsScene();

    // Grid* grid = new Grid(scene);
    // w.setCentralWidget(grid);


    BondingWire* wire = new BondingWire();
    scene->addItem(wire);
    view->setScene(scene);

    // A obj_A;
    // B b;

    // QObject::connect(&obj_A, &A::A_signal, &b, &B::B_slot);
    // obj_A.Emit_signal();

    // for (size_t i = 0; i < 1000; ++i) {
    //     obj_A.Increment_val();
    //     obj_A.Emit_signal();
    // }
    w.setCentralWidget(view);
    w.show();
    return a.exec();
}
