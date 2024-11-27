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

    painter->setPen(QPen(QColor{"#23A9F2"}, 0.5));

    if (m_points.size() >= 3) {
        painter->drawLine(m_points[0], m_points[1]);
        painter->drawLine(m_points[1], m_points[2]);
    }
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        m_startPos = ConnectToGrid(event->pos(), m_offset);
        m_points.push_back(m_startPos);
        m_isDrag = true;
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        qDebug() << "BondingWire  + mouseMoveEvent";
        m_points.clear();
        m_points.push_back(m_startPos);
        QPointF currentPoint = ConnectToGrid(event->pos(), m_offset);
        QPointF intersectionPoint = QPointF { currentPoint.x(), m_startPos.y() };
        m_points.push_back(intersectionPoint);
        m_points.push_back(currentPoint);
        update();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && event->button() == Qt::LeftButton) {
        m_isDrag = false;
        m_flag = false;
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
    m_offset = gap;
}

QPointF BondingWire::ConnectToGrid(const QPointF& pos, int m_offset) {
    qreal x = qRound(pos.x() / m_offset) * m_offset;
    qreal y = qRound(pos.y() / m_offset) * m_offset;
    return QPointF { x, y };
}


