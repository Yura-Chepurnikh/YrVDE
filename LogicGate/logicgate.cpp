#include "logicgate.h"

LogicGate::LogicGate()  {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "mouseMoveEvent !!!" << '\n';
    if (event->buttons() && Qt::LeftButton) {
        setPos(mapToScene(event->pos()));
    }
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "mouseReleaseEvent !!!" << '\n';
    setCursor(Qt::OpenHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void LogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    Q_UNUSED(painter);

    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}

