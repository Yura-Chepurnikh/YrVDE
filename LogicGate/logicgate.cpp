#include "logicgate.h"

LogicGate::LogicGate() {
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
    m_min_dis =  m_gap;
    qDebug() << "LogicGate m_gap" << m_gap << '\n';

}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction* action_1 = menu.addAction("Hello World");
        menu.exec(event->screenPos());
    }
    else {
        setCursor(Qt::ClosedHandCursor);
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = event->scenePos();
    m_pos = ConnectToGrid(currentPoint, m_gap);
    update();
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::CustomCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

void LogicGate::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {

    QGraphicsItem::hoverMoveEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void LogicGate::AddInput() {
    m_inputsCount += 2;
}

std::vector<QPointF> LogicGate::CreateInputPoints(QPainterPath path) {
    std::vector<QPointF> points;
    QPointF begin = path.pointAtPercent(0);
    QPointF end = path.pointAtPercent(1);

    for (qreal i = 0; i < 0.4; i += 0.5/3)
        points.push_back(path.pointAtPercent(i));

    for (qreal i = 1; i > 0.6; i -= 0.5/3)
        points.push_back(path.pointAtPercent(i));

    for (size_t i = 0; i < m_inputsCount; ++i) {
        points.push_back({begin.x(), begin.y() + i * m_min_dis});
        points.push_back({end.x(), end.y() - i * m_min_dis});
    }


    return points;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


