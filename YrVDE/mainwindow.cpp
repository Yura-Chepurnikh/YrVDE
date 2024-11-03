#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_WorkSpace = new WorkSpace();
    setCentralWidget(m_WorkSpace);
}

MainWindow::~MainWindow()
{
    delete ui;
}


