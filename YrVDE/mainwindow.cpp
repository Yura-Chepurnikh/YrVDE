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

    workspace = new WorkSpace(m_scene);
    setCentralWidget(workspace);
    m_toolBar = new ToolBar();

    m_toolBar->setStyleSheet("background-color: #181818");

    addToolBar(Qt::LeftToolBarArea, m_toolBar);

    QObject::connect(m_toolBar, &ToolBar::createLogicGate, workspace, &WorkSpace::addGate);
    emit workspace->sendScene(workspace);
}

MainWindow::~MainWindow()
{
    delete ui;
}

