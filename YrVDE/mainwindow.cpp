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

    m_toolbar = addToolBar("Main toolbar");
    m_toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    m_toolbar->setStyleSheet("background-color: #181818");

    QToolButton *button = new QToolButton();
    button->setIcon(QIcon("D://YrVDE//Resources//Icons//logic-gates.png"));
    button->setText("Gates");
    button->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    button->setStyleSheet("color: white");

    m_toolbar->addWidget(button);
}

MainWindow::~MainWindow()
{
    delete ui;
}

