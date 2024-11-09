#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "./workspace.h"
#include "../LogicGate/logicgate.h"

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
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    LogicGate* m_logicGate;
    WorkSpace* workspace;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
