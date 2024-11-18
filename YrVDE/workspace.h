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

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    WorkSpace(QGraphicsScene* scene);
    virtual ~WorkSpace();
    LogicGate* m_andGate;
    LogicGate* m_buffer;
    BondingWire* m_wire;

signals:
    void SendPoint(QPoint point);
    void SendGap(int gap);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;

private:
    static int m_minDis;
    static int m_gap;
    int m_mergeDistance;
    std::vector<std::vector<QPoint>> m_gridPoints;
    BondingWire* wire;
};

#endif // WORKSPACE_H
