#include "./xor_gate.h"

XORGate::XORGate() { }

XORGate::~XORGate() { }

void XORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
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

    painter->drawPath(path);

    QPainterPath path2;
    path2.moveTo(m_gatePos.x() - gap/4, m_gatePos.y());
    path2.quadTo(m_gatePos.x() + gap, m_gatePos.y() + gap, m_gatePos.x() - gap/4, m_gatePos.y() + 2*gap);

    painter->drawPath(path);
    painter->drawPath(path2);
}

QRectF XORGate::boundingRect() const {
    return QRectF(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);
}
