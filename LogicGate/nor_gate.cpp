#include "./nor_gate.h"

NORGate::NORGate() { }

NORGate::~NORGate() { }

void NORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;

    path.moveTo(m_gatePos);
    path.closeSubpath();

    int gap = m_gridSize/2;
    path.quadTo(m_gatePos.x() + gap, m_gatePos.y(), m_gatePos.x() + 1.5 * gap, m_gatePos.y() + gap);
    path.quadTo(m_gatePos.x() + gap, m_gatePos.y() + 2*gap, m_gatePos.x(), m_gatePos.y() + 2*gap);
    path.quadTo(m_gatePos.x() + gap, m_gatePos.y() + gap, m_gatePos.x(), m_gatePos.y());

    QPainterPath bubble;
    int radius = m_gridSize / 20;
    QPoint center { m_gatePos.x() + 1.5 * gap + radius, m_gatePos.y() + gap };
    bubble.addEllipse(center, radius, radius);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NORGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}
