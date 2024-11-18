#include "./nor_gate.h"

NORGate::NORGate() { }

NORGate::~NORGate() { }

void NORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#777777"}, 1));

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    QPainterPath bubble;
    int radius = m_gap / 20;
    QPoint center { m_pos.x() + 1.5 * gap + radius, m_pos.y() + gap };
    bubble.addEllipse(center, radius, radius);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
