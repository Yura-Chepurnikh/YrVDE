#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QToolBar>
#include <QAction>
#include <QLabel>
#include <QMenu>
#include <QToolButton>
#include "./workspace.h"
#include "../BondingWire/bondingwire.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    BondingWire* wire;
    QToolBar* m_toolbar;
    QMenu* m_menu;
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    WorkSpace* workspace;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
