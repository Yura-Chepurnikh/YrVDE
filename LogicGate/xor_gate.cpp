#include "./xor_gate.h"

XORGate::XORGate() { }

XORGate::~XORGate() { }

void XORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    painter->drawPath(path);

    QPainterPath path2;
    path2.moveTo(m_pos.x() - gap/4, m_pos.y());
    path2.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x() - gap/4, m_pos.y() + 2*gap);

    painter->drawPath(path);
    painter->drawPath(path2);
}

QRectF XORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
