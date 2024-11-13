#include "./and_gate.h"

ANDGate::ANDGate() { }

void ANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(QColor{ "#23A9F2" }, 2));

    QPainterPath path;

    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), 10, 10, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + 10);
    path.closeSubpath();

    painter->drawPath(path);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF ANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
