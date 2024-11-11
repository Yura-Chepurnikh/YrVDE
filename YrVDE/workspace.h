#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QPoint>
#include <QMouseEvent>

#include "../BondingWire/bondingwire.h"

class WorkSpace : public QGraphicsView {
    Q_OBJECT

public:
    WorkSpace(QGraphicsScene* scene);

signals:
    void SendPoint(QPoint point);
    void EmitSendPoint(); // I'm writing this for clarity

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
