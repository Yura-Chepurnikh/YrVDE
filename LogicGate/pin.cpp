#include "pin.h"

Pin::Pin() {
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    createPin();
}

Pin::~Pin() { }

void Pin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;
    createPin();
    painter->drawEllipse(m_output->pos, 1, 1);
    if (m_activePort) {
        painter->setPen(QPen(Qt::red, 0.5));
    }
    path.addRect(m_gatePos.x(), m_gatePos.y(), 2 * m_activeRadius, 2 * m_activeRadius);
    painter->drawPath(path);
}

void Pin::createPin() {
    m_output = QSharedPointer<Port>::create(QPointF(m_gatePos.x() + m_activeRadius, m_gatePos.y() + m_activeRadius));
}

QRectF Pin::boundingRect() const {
    QRectF rect(m_gatePos.x(), m_gatePos.y(), m_activeRadius, m_activeRadius);
    rect.adjust(-2*m_activeRadius, -2*m_activeRadius, 2*m_activeRadius, 2*m_activeRadius);
    return rect;
}



