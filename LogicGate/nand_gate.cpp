#include "./nand_gate.h"

NANDGate::NANDGate() { }

NANDGate::~NANDGate() { }

void NANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#777777"}, 1));

    QPainterPath path;
    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), m_gap, m_gap, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + m_gap);
    path.lineTo(m_pos.x(), m_pos.y());

    QPainterPath bubble;
    int radius = m_gap / 20;
    QPoint center { m_pos.x() + m_gap + radius, m_pos.y() + m_gap/2 };
    bubble.addEllipse(center, radius, radius);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}

