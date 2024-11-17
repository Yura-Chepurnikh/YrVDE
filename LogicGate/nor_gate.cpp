#include "./nor_gate.h"

NORGate::NORGate() { }

NORGate::~NORGate() { }

void NORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    QPainterPath bubble;
    QPoint center { m_pos.x() + 1.5 * gap + gap / 10, m_pos.y() + gap };
    bubble.addEllipse(center, gap / 10, gap / 10);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
