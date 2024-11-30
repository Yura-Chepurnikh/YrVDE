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
#include "../LogicGate/add_inputs.h"

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    WorkSpace(QGraphicsScene* scene);
    virtual ~WorkSpace();
    LogicGate* m_gate;
    LogicGate* m_buffer;
    BondingWire* m_wire;

public slots:
    void GetLogicGate(LogicGate* gate);

signals:
    void SendPoint(QPoint point);
    void SendIsShow(bool isShow);
    void SendGap(int gap);
    void SendScene(WorkSpace* workSpace);

protected:
    //void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;

    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    bool m_is_Drag { false };
    QPointF m_lastPosOfScene;
    static int m_gap;
    static int m_inputsDistance;

    std::vector<std::vector<QPoint>> m_gridPoints;
    BondingWire* wire;
};

#endif // WORKSPACE_H
