#include "./and_gate.h"

ANDGate::ANDGate() : LogicGate() { }

ANDGate::~ANDGate() { }

void ANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    painter->translate(boundingRect().center());
    painter->rotate(90);
    painter->translate(-boundingRect().center());

    QPainterPath path;
    path.moveTo(m_gatePos);
    path.arcTo(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize, 90, -180);
    path.lineTo(m_gatePos.x(), m_gatePos.y() + m_gridSize);
    path.lineTo(m_gatePos.x(), m_gatePos.y());

    for (auto& item : m_inputs)
        painter->drawPoint(item->pos);

    painter->drawPath(path);
}

QRectF ANDGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}
