#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../BondingWire/bondingwire.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QGraphicsView* view = new QGraphicsView();
    QGraphicsScene* scene = new QGraphicsScene(view);

    BondingWire* wire = new BondingWire();
    scene->addItem(wire);

    view->setScene(scene);

    view->setGeometry(10, 10, 500, 500);

    view->show();

    //w.show();
    return a.exec();
}
