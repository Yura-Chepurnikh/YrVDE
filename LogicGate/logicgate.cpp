#include "logicgate.h"

LogicGate::LogicGate() {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
    m_min_dis =  m_gap / 10;
    qDebug() << "LogicGate m_gap" << m_gap << '\n';

}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction* action_1 = menu.addAction("Hello World");
        menu.exec(event->screenPos());
    }
    else {
        setCursor(Qt::ClosedHandCursor);
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = event->scenePos();
    m_pos = ConnectToGrid(currentPoint, m_gap);
    update();
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::CustomCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


