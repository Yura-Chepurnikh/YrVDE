#include "./buffer_gate.h"

BUFFERGate::BUFFERGate() { }

BUFFERGate::~BUFFERGate() { }

void BUFFERGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    int edge = m_gridSize;
    QPainterPath path;

    path.moveTo(m_gatePos);
    path.lineTo(m_gatePos.x() + std::sqrt(3) / 2 * edge, m_gatePos.y() + edge / 2);
    path.lineTo(m_gatePos.x(), m_gatePos.y() + edge);
    path.closeSubpath();

    painter->drawPath(path);
}

QRectF BUFFERGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}

