#include "./nand_gate.h"

NANDGate::NANDGate() { }

// NANDGate::~NANDGate() { }

void NANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), 10, 10, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + 10);
    path.closeSubpath();

    QPainterPath bubble;
    QPoint center { m_pos.x() + 10 + 1, m_pos.y() + 5 };
    bubble.addEllipse(center, 1, 1);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
