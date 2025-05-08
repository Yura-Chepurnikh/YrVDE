#include "./port.h"

qreal Port::clickableRadius = 10;

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
    QRectF rect(pos.x(), pos.y(), 2, 2);
    return rect;
}
