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
#include "../LogicGate/logicgate.h"
#include "../LogicGate/nand_gate.h"
#include "../LogicGate/xnor_gate.h"
#include "../LogicGate/nor_gate.h"
#include "../LogicGate/or_gate.h"
#include "../LogicGate/buffer_gate.h"
#include "../LogicGate/not_gate.h"
#include "../LogicGate/and_gate.h"
#include "../LogicGate/xor_gate.h"
#include "../LogicGate/input.h"

#define GAP 60
#define INPUTS_DISTANCE GAP / 10
#define WEAK_SMOOTH 1.1
#define STRONG_SMOOTH 2

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    WorkSpace(QGraphicsScene* scene);
    virtual ~WorkSpace() = default;
    void ConnectBondingWireToGate();

public slots:
    void AddGate(LogicGate* gate);

signals:
    void SendGap(int gap);
    void SendScene(WorkSpace* workSpace);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    QPointF m_lastPosOfScene;
    static int m_gap;
    static int m_inputsDistance;

    std::vector<std::vector<QPoint>> m_gridPoints;
    std::vector<LogicGate*> m_gates;
};

#endif // WORKSPACE_H
