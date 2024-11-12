#include "./not_gate.h"

NOTGate::NOTGate() { }

// NOTGate::~NOTGate() { }

void NOTGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    int edge = 40;
    QPainterPath path;

    path.moveTo(m_pos);
    path.lineTo(m_pos.x() + std::sqrt(3) / 2 * edge, m_pos.y() + edge / 2);
    path.lineTo(m_pos.x(), m_pos.y() + edge);
    path.closeSubpath();

    QPainterPath bubble;
    QPoint center { m_pos.x() + std::sqrt(3) / 2 * edge + 3, m_pos.y() + edge / 2 };
    bubble.addEllipse(center, 3, 3);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NOTGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
