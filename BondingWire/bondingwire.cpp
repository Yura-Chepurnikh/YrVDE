#include "bondingwire.h"

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

    for (auto begin = m_path.begin(); begin != m_path.end(); ++begin) {
        if (*begin->first == *begin->second) // to avoid problems with the display
            continue;
        painter->drawLine(*begin->first, *begin->second);
    }
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isAllowedFromGate && event->button() == Qt::LeftButton) {
        m_isDrag = true;
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        m_path.clear();

        std::pair<QSharedPointer<QPointF>, QSharedPointer<QPointF>> segment;
        std::pair<QSharedPointer<QPointF>, QSharedPointer<QPointF>> perpendicularSegment;

        QPointF currentPos = StickToTheGrid(event->pos());
        QPointF intersectionPos = QPointF {currentPos.x(), m_startPos.y()};

        segment.first = QSharedPointer<QPointF>::create(m_startPos);
        segment.second = perpendicularSegment.first = QSharedPointer<QPointF>::create(intersectionPos);
        perpendicularSegment.second = QSharedPointer<QPointF>::create(currentPos);

        m_path.push_back(segment);
        m_path.push_back(perpendicularSegment);

        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && event->button() == Qt::LeftButton) {
        m_isDrag = false;        
    }
}

QRectF BondingWire::boundingRect() const {
    if (scene()) {
        return scene()->sceneRect();
    }
    return QRectF {0, 0, 0, 0};
}

void BondingWire::GetGridSize(int size) {
    m_step = size / 10;
}

void BondingWire::GetPermissionFromGate(bool isAllowed, QPointF& startPos) {
    m_isAllowedFromGate = isAllowed;
    m_startPos = startPos;
}

QPointF BondingWire::StickToTheGrid(const QPointF& current_pos) {
    qreal x = qRound(current_pos.x() / m_step) * m_step;
    qreal y = qRound(current_pos.y() / m_step) * m_step;
    return QPointF {x, y};
}


