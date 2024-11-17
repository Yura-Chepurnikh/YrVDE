#include "./nand_gate.h"

NANDGate::NANDGate() { }

NANDGate::~NANDGate() { }

void NANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;
    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), m_gap, m_gap, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + m_gap);
    path.lineTo(m_pos.x(), m_pos.y());

    QPainterPath bubble;
    QPoint center { m_pos.x() + m_gap + m_gap/10, m_pos.y() + m_gap/2 };
    bubble.addEllipse(center, m_gap/10, m_gap/10);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
