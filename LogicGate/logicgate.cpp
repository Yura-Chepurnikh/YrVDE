#include "logicgate.h"

LogicGate::LogicGate() {
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;

    m_pos = ConnectToGrid(m_pos, m_gap);
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
    m_inputsGap =  m_gap / 10;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton && shape().contains(event->pos())) {
        setCursor(Qt::ClosedHandCursor);
        QGraphicsItem::mousePressEvent(event);
    }
    else if (event->button() == Qt::RightButton && shape().contains(event->pos()) && !m_isAllowed) {
        m_isAllowed = true;
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
    // else if (event->button() == Qt::RightButton) {
    //     m_isAllowed = false;
    // }
}

void LogicGate::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    QPointF currentPos = event->pos();

    for (size_t i = 0; i < m_inputs.size(); ++i) {
        if (std::abs(currentPos.x() - m_inputs[i]->pos.x()) < m_inputsGap / 2 &&
            std::abs(currentPos.y() - m_inputs[i]->pos.y()) < m_inputsGap / 2) {
            if (m_isAllowed) {
                qDebug() << "is clicked";
                emit this->SendPermission(m_isAllowed, m_inputs[i]->pos);
            }
            if (!m_isAllowed) {
                emit this->SendPermission(!m_isAllowed, m_inputs[i]->pos);
                qDebug() << "is not clicked";

            }
            m_activePoint = m_inputs[i];
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

std::vector<QSharedPointer<Input>> LogicGate::CreateInputPoints(QPainterPath path) {
    m_inputs.clear();

    QPointF p1 = {0,0}, p2{0,0};

    for (qreal t = 0; t <= 1; t += 0.1) {
        // if (path.pointAtPercent(t).y() == m_pos.y() + m_inputsGap) {
        //     p1 = path.pointAtPercent(t);
        // }
        // if (path.pointAtPercent(t).y() == m_pos.y() + m_gap - m_inputsGap) {
        //     p2 = path.pointAtPercent(t);
        // }
        QSharedPointer<Input> i = QSharedPointer<Input>::create(path.pointAtPercent(t));
        m_inputs.push_back(i);
    }
    //QSharedPointer<InputPoint> in1 = QSharedPointer<InputPoint>::create(path.pointAtPercent(0));
    //QSharedPointer<InputPoint> in2 = QSharedPointer<InputPoint>::create(path.pointAtPercent(1));

    //QPointF a = QPointF { m_pos.x() + m_gap, m_pos.y() + m_gap / 2 };
    //m_output = QSharedPointer<InputPoint>::create(a);
//
    //m_inputs.push_back(in1);
    //m_inputs.push_back(in2);
    //m_inputs.push_back(m_output);

    return m_inputs;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}

void LogicGate::GetInputPoint(QSharedPointer<Input> point) {
    m_activePoint = point;
}


