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

    m_xorGate = new XORGate();
    m_scene->addItem(m_xorGate);

    workspace = new WorkSpace(m_scene);
    setCentralWidget(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

