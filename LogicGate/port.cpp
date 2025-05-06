#include "./port.h"

Port::Port(QPointF pos, LogicState state) {
    setZValue(3);
    this->pos = pos;
    state = state;
}

void Port::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Port::boundingRect() const {
    return QRectF {pos.x(), pos.y(), 100, 100};
}


