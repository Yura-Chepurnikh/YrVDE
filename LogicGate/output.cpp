#include "./output.h"

Output::Output() { }

Output::~Output() { }

void Output::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#777777"}, 1));

    QPainterPath path;
    path.addRect(m_pos.x(), m_pos.y(), m_min_dis, m_min_dis);
    painter->drawPath(path);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF Output::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
