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
    m_inputsGap =  m_gap;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(event);
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
    QPointF currentPos = event->pos();

    for (size_t i = 0; i < m_inputs.size(); ++i) {
        if (std::abs(currentPos.x() - m_inputs[i].x()) < m_inputsGap / 2 &&
            std::abs(currentPos.y() - m_inputs[i].y()) < m_inputsGap / 2)
        {
            m_highlightPoint = m_inputs[i];
            update();
        }
    }
    update();
    QGraphicsItem::hoverMoveEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

std::vector<QPointF> LogicGate::CreateInputPoints(QPainterPath path) {
    m_inputs.clear();


    return m_inputs;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


