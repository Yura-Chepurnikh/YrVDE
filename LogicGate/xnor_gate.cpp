#include "./xnor_gate.h"

XNORGate::XNORGate() { }

void XNORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    path.quadTo(m_pos.x() + 40, m_pos.y() , m_pos.x() + 60, m_pos.y() + 40);
    path.quadTo(m_pos.x() + 40, m_pos.y() + 80, m_pos.x(), m_pos.y() + 80);
    path.quadTo(m_pos.x() + 30, m_pos.y() + 40, m_pos.x(), m_pos.y());

    QPainterPath path2;
    path2.moveTo(m_pos.x() - 10, m_pos.y());
    path2.quadTo(m_pos.x() + 30, m_pos.y() + 40, m_pos.x() - 10, m_pos.y() + 80);

    QPainterPath bubble;
    QPoint center { m_pos.x() + 60 + 10, m_pos.y() + 40 };
    bubble.addEllipse(center, 10, 10);

    painter->drawPath(path);
    painter->drawPath(path2);
    painter->drawPath(bubble);
}

QRectF XNORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
