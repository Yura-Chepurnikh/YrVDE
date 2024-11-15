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
#include "../LogicGate/and_gate.h"
#include "../LogicGate/xnor_gate.h"

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    WorkSpace(QGraphicsScene* scene);
    virtual ~WorkSpace();
    LogicGate* m_andGate;

signals:
    void SendPoint(QPoint point);
    void SendGap(int gap);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    static int m_gap;
    int m_mergeDistance;
    QPoint m_highlightPoint;
    std::vector<std::vector<QPoint>> m_gridPoints;
    BondingWire* wire;
};

#endif // WORKSPACE_H
