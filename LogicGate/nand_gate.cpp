#include "./nand_gate.h"

NANDGate::NANDGate() { }

NANDGate::~NANDGate() { }

void NANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;
    path.moveTo(m_gatePos);
    path.arcTo(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize, 90, -180);
    path.lineTo(m_gatePos.x(), m_gatePos.y() + m_gridSize);
    path.lineTo(m_gatePos.x(), m_gatePos.y());

    QPainterPath bubble;
    int radius = m_gridSize / 20;
    QPoint center { m_gatePos.x() + m_gridSize + radius, m_gatePos.y() + m_gridSize/2 };
    bubble.addEllipse(center, radius, radius);

    painter->drawPath(path);
    painter->drawPath(bubble);
}

QRectF NANDGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}

