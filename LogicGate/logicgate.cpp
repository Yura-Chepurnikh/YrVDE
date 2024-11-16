#include "logicgate.h"

LogicGate::LogicGate()  {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::ClosedHandCursor);
    m_isDrag = true;
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag) {
    QPointF currentPoint = event->scenePos();
    QPointF  connectToGridPoint = ConnectToGrid(currentPoint, 30);
    setPos(connectToGridPoint);
    QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::CustomCursor);
    m_isDrag = false;
    QGraphicsItem::mouseReleaseEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void LogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen({Qt::blue, 4});
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}

