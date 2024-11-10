#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene();
    m_view = new QGraphicsView(m_scene);
    m_view->setScene(m_scene);

    m_orGate = new ORGate();
    m_scene->addItem(m_orGate);

    workspace = new WorkSpace(m_scene);
    setCentralWidget(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

