#include "bondingwire.h"

BondingWire::BondingWire() {}

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QLineF line (m_startPos, m_endPos);

    for (auto& line : m_wires) {
        painter->drawLine(line);
    }
}

QRectF BondingWire::boundingRect() const {
    return {0, 0, 600, 800};
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (m_startPos == QPointF(0, 0))
            m_startPos = event->pos();
        m_isDrag = true;
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        m_endPos = event->pos();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_endPos = event->pos();

        m_wires.push_back(QLineF {m_startPos, m_endPos});

        m_startPos = m_endPos;
        m_isDrag = false;

        update();
    }
}
