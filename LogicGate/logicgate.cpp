#include "logicgate.h"

LogicGate::LogicGate() {
    setAcceptHoverEvents(true);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
    m_pos = ConnectToGrid(m_pos, m_gap);
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
    m_inputsGap = m_gap / PARTS;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (m_activeInput) {
        emit this->SendCreateWire(this);
        qDebug() << "m_activeInput";
    }
    else if (event->button() == Qt::LeftButton && shape().contains(event->pos())) {
        setCursor(Qt::ClosedHandCursor);
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        QPointF currentPoint = event->scenePos();
        m_pos = ConnectToGrid(currentPoint, m_inputsGap);
        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton && shape().contains(event->pos())) {
        setCursor(Qt::CustomCursor);
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

void LogicGate::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    QPointF currentPos = event->pos();

    QSharedPointer<Input> closestInput;
    qreal min_distance = m_inputsGap;

    for (auto input : m_inputs) {
        qreal dis = DistanceToPoints(input.data()->pos, currentPos);
        if (dis < min_distance) {
            min_distance = dis;
            closestInput = input;
        }
    }
    if (min_distance < m_inputsGap / 2) {
        m_activeInput = closestInput;
    }
    else {
        m_activeInput = nullptr;
    }
    update();
}

qreal LogicGate::DistanceToPoints(const QPointF &from, const QPointF &to) {
    return std::sqrt(std::pow(from.x() - to.x(), 2) + std::pow(from.y() - to.y(), 2));
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

std::vector<QSharedPointer<Input>> LogicGate::CreateInputPoints(QPainterPath path) {
    m_inputs.clear();

    for (qreal t = 0; t <= 1; t += 0.1) {
        QSharedPointer<Input> i = QSharedPointer<Input>::create(path.pointAtPercent(t));
        m_inputs.push_back(i);
    }

    return m_inputs;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


