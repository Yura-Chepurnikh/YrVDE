#include "./not_gate.h"

NOTGate::NOTGate() { }

NOTGate::~NOTGate() { }

void NOTGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    int edge = m_gridSize;
    QPainterPath path;

    path.moveTo(m_gatePos);
    path.lineTo(m_gatePos.x() + std::sqrt(3) / 2 * edge, m_gatePos.y() + edge / 2);
    path.lineTo(m_gatePos.x(), m_gatePos.y() + edge);
    path.closeSubpath();

    QPainterPath bubble;
    int radius = m_gridSize / 20;
    QPoint center { m_gatePos.x() + std::sqrt(3) / 2 * edge + radius, m_gatePos.y() + edge / 2 };
    bubble.addEllipse(center, radius, radius);;

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NOTGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}
