#include "./or_gate.h"

ORGate::ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    path.quadTo(m_pos.x() + 40, m_pos.y() , m_pos.x() + 60, m_pos.y() + 40);
    path.quadTo(m_pos.x() + 40, m_pos.y() + 80, m_pos.x(), m_pos.y() + 80);
    path.quadTo(m_pos.x() + 30, m_pos.y() + 40, m_pos.x(), m_pos.y());

    QPainterPath path2;
    path2.moveTo(m_pos.x() - 10, m_pos.y());
    path2.quadTo(m_pos.x() + 30, m_pos.y() + 40, m_pos.x() - 10, m_pos.y() + 80);

    //path.closeSubpath();

    painter->drawPath(path);
    painter->drawPath(path2);

}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
