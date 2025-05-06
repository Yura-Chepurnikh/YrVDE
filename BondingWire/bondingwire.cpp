#include "bondingwire.h"

BondingWire::BondingWire() {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

BondingWire::~BondingWire() { }

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{"#23A9F2"}, 0.3));

    if (m_path.first && m_path.second) {
        QPointF startPos = m_path.first->mapToScene(m_path.first->pos);
        QPointF endPos = m_path.second->mapToScene(m_path.second->pos);
        painter->drawLine(startPos, endPos);
    }
}

QRectF BondingWire::boundingRect() const {
    if (!m_path.first || !m_path.second)
        return QRectF();

    QPointF p1 = mapFromScene(m_path.first->mapToScene(m_path.first->pos));
    QPointF p2 = mapFromScene(m_path.second->mapToScene(m_path.second->pos));

    QRectF rect(p1, p2);
    return rect.normalized().adjusted(-1, -1, 1, 1);
}




