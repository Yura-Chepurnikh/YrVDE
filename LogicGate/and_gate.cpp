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
    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), m_gap, m_gap, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + m_gap);
    path.lineTo(m_pos.x(), m_pos.y());

    for (auto& item : m_inputs)
        painter->drawPoint(item->m_point);

    painter->drawPath(path);
}

QRectF ANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
