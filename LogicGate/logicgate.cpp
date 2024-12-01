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
    m_inputsGap =  m_gap / 5;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = event->scenePos();
    auto dis = std::sqrt(std::pow(currentPoint.x() - m_output->m_point.x(), 2) + std::pow(currentPoint.y() - m_output->m_point.y(), 2));
    if (dis <= m_inputsGap) {
        qDebug() << "pppppppppppppppppppppppppppppppp";

        m_wire->mousePressEvent(event);
    }
    setCursor(Qt::ClosedHandCursor);
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = event->scenePos();
    auto dis = std::sqrt(std::pow(currentPoint.x() - m_output->m_point.x(), 2) + std::pow(currentPoint.y() - m_output->m_point.y(), 2));
    if (dis <= m_inputsGap) {
        qDebug() << "mmmmmmmmmmmmmmmmmmmmmmmmmm";
        m_wire->mouseMoveEvent(event);
    }
    else {
        m_pos = ConnectToGrid(currentPoint, m_gap);
        emit this->SendInputsPoints(m_inputs);

        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::CustomCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

void LogicGate::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    QPointF currentPos = event->pos();

    for (size_t i = 0; i < m_inputs.size(); ++i) {
        if (std::abs(currentPos.x() - m_inputs[i]->m_point.x()) < m_inputsGap / 2 &&
            std::abs(currentPos.y() - m_inputs[i]->m_point.y()) < m_inputsGap / 2)
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

std::vector<QSharedPointer<InputPoint>> LogicGate::CreateInputPoints(QPainterPath path) {
    m_inputs.clear();

    QPointF p1 = {0,0}, p2{0,0};

    for (qreal t = 0; t <= 1; t += 0.1) {
        if (path.pointAtPercent(t).y() == m_pos.y() + m_inputsGap) {
            p1 = path.pointAtPercent(t);
        }
        if (path.pointAtPercent(t).y() == m_pos.y() + m_gap - m_inputsGap) {
            p2 = path.pointAtPercent(t);
        }
    }
    // QPointF p1 = path.pointAtPercent(0.2);
    // QPointF p2 = path.pointAtPercent(0.8);

    QSharedPointer<InputPoint> in1 = QSharedPointer<InputPoint>::create(p1, GateState::LOGIC_Z);
    QSharedPointer<InputPoint> in2 = QSharedPointer<InputPoint>::create(p2, GateState::LOGIC_Z);

    QPointF a = QPointF {m_pos.x() + m_gap, m_pos.y() + m_gap / 2};
    m_output = QSharedPointer<InputPoint>::create(a, GateState::LOGIC_Z);

    m_inputs.push_back(in1);
    m_inputs.push_back(in2);
    m_inputs.push_back(m_output);

    return m_inputs;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


