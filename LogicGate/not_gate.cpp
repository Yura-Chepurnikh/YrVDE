#include "./not_gate.h"

NOTGate::NOTGate() { }

NOTGate::~NOTGate() { }

void NOTGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    int edge = m_gap;
    QPainterPath path;

    path.moveTo(m_pos);
    path.lineTo(m_pos.x() + std::sqrt(3) / 2 * edge, m_pos.y() + edge / 2);
    path.lineTo(m_pos.x(), m_pos.y() + edge);
    path.closeSubpath();

    QPainterPath bubble;
    int radius = m_gap / 20;
    QPoint center { m_pos.x() + std::sqrt(3) / 2 * edge + radius, m_pos.y() + edge / 2 };
    bubble.addEllipse(center, radius, radius);;

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NOTGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
