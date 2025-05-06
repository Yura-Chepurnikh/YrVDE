#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QPoint>
#include <QMouseEvent>
#include <QApplication>
#include <QScrollBar>

#include "../BondingWire/bondingwire.h"
#include "../LogicGate/port.h"
#include "../LogicGate/logicgate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/xnor_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/and_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/pin.h"

#define GAP 100
#define INPUTS_DISTANCE GAP / 10
#define WEAK_SMOOTH 1.1
#define STRONG_SMOOTH 2

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    struct MemGatePin {
        LogicGate* gate;
        int number;

        MemGatePin() = default;
        MemGatePin(LogicGate* g, int n) : gate(g), number(n) { }
    };

    WorkSpace(QGraphicsScene* scene);
    virtual ~WorkSpace() = default;
    void connectBondingWireToGate();

public slots:
    void addGate(LogicGate* gate);
    void addWire(LogicGate* gate, QSharedPointer<Port> activePort);
    void getGateDrag(LogicGate* gate);

signals:
    void sendGap(int gap);
    void sendScene(WorkSpace* workSpace);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

    QPointF connectToGrid(const QPointF& pos, int gridGap);
private:
    std::vector<LogicGate*> m_gates;

    std::unordered_map<LogicGate*, std::pair<BondingWire*, MemGatePin>> m_table;

    BondingWire* m_currentWire {nullptr};
    QPointF m_lastPosOfScene;
    static int m_gap;
    static int m_inputsDistance;
    QSharedPointer<Port> m_activePort;
    LogicGate* m_activeGate;

    std::vector<std::vector<QPoint>> m_gridPoints;
    std::vector<BondingWire*> m_wires;
};

#endif // WORKSPACE_H
