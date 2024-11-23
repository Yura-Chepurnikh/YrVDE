#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_menu = this->menuBar()->addMenu("File");
    menuBar()->setStyleSheet("background-color: #181818");


    m_scene = new QGraphicsScene();
    m_view = new QGraphicsView(m_scene);
    m_view->setScene(m_scene);

    workspace = new WorkSpace(m_scene);
    setCentralWidget(workspace);
    m_toolBar = new ToolBar();
    addToolBar(m_toolBar);

    QObject::connect(workspace, &WorkSpace::SendScene, m_toolBar, &ToolBar::GetWorkSpace);

    QObject::connect(m_toolBar, &ToolBar::createLogicGate, workspace, &WorkSpace::GetLogicGate);
    emit workspace->SendScene(workspace);

}

MainWindow::~MainWindow()
{
    delete ui;
}

