#include "./menu.h"

Menu::Menu() : QMainWindow()
{
    QMenu* menu = menuBar()->addMenu("File");

    this->setStyleSheet("background-color: #181818;"
                                    "color: white;");

    QAction *newAction = new QAction("New");
    QAction *openAction = new QAction("Open");
    QAction *exitAction = new QAction("Exit");

    menu->addAction(newAction);
    menu->addAction(openAction);
    menu->addAction(exitAction);
}

