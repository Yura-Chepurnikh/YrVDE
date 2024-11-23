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
#include "./tool_bar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void CreateGate(const std::string& type);

private:
    BondingWire* wire;
    QMenu* m_menu;
    ToolBar* m_toolBar;
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    WorkSpace* workspace;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
