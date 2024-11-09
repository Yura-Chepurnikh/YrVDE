#include "logicgate.h"

LogicGate::LogicGate()  { }

void LogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), 10, 10, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + 10);
    path.closeSubpath();

    painter->drawPath(path);
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
