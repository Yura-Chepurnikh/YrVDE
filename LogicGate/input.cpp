#include "./input.h"

Input::Input() { }

Input::~Input() { }

void Input::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 1));

    QPainterPath path;
    path.addRect(m_pos.x(), m_pos.y(), m_min_dis, m_min_dis);
    painter->drawPath(path);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF Input::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
