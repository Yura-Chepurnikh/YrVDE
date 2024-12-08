#include "./BondingWire.h"

BondingWire::BondingWire() {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

BondingWire::~BondingWire() { }

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{"#23A9F2"}, 0.3));
    painter->drawLine(m_startPos, m_endPos);
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_startPos = ConnectToGrid(event->pos(), m_offset);
        this->SendPoint(m_startPos);
        m_isDrag = true;
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        m_endPos = ConnectToGrid(event->pos(), m_offset);
        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && event->button() == Qt::LeftButton) {
        m_isDrag = false;
        this->SendPoint(m_endPos);
        update();
    }
}

QRectF BondingWire::boundingRect() const {
    if (scene()) {
        return scene()->sceneRect();
    }
    return QRectF { 0, 0, 0, 0 };
}

void BondingWire::GetGridGap(int gap) {
    m_offset = gap / 10;
}

QPointF BondingWire::ConnectToGrid(const QPointF& pos, int m_offset) {
    qreal x = qRound(pos.x() / m_offset) * m_offset;
    qreal y = qRound(pos.y() / m_offset) * m_offset;
    return QPointF { x, y };
}


