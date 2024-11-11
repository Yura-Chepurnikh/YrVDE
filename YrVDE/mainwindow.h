#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "./workspace.h"
#include "../LogicGate/logicgate.h"
#include "../LogicGate/and_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/xnor_gate.h"
#include "../LogicGate/xor_gate.h"

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

    LogicGate* m_andGate;

    LogicGate* m_logicGate;

    LogicGate* m_orGate;

    LogicGate* m_nandGate;

    NORGate* m_norGate;

    NOTGate* m_notGate;

    LogicGate* m_bufferGate;

    LogicGate* m_xnorGate;

    LogicGate* m_xorGate;

    WorkSpace* workspace;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
