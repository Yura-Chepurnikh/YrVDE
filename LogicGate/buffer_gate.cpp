#include "./buffer_gate.h"

BUFFERGate::BUFFERGate() { }

BUFFERGate::~BUFFERGate() { }

void BUFFERGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 1));

    int edge = m_gap;
    QPainterPath path;

    path.moveTo(m_pos);
    path.lineTo(m_pos.x() + std::sqrt(3) / 2 * edge, m_pos.y() + edge / 2);
    path.lineTo(m_pos.x(), m_pos.y() + edge);
    path.closeSubpath();

    painter->drawPath(path);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF BUFFERGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}

