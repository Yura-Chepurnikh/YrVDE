#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene();
    workspace = new WorkSpace(scene);
    setCentralWidget(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

