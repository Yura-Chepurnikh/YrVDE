#include "./input.h"

Input::Input(QPointF pos, LogicState state) {
    this->pos = pos;
    state = state;
}

void Input::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));
    painter->drawEllipse(pos.x(), pos.y(), radius, radius);
}

QRectF Input::boundingRect() const {
    return QRectF {pos.x(), pos.y(), 100, 100};
}


