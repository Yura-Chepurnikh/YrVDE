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
    qDebug() << "hoverMoveEvent";
    QPointF currentPos = event->pos();
    for (size_t i = 0; i < m_inputs.size(); ++i) {
        if (std::abs(currentPos.x() - m_inputs[i].x()) < m_inputsGap / 2 &&
            std::abs(currentPos.y() - m_inputs[i].y()) < m_inputsGap / 2) {
            qDebug() << "hoverMoveEvent if";
            emit this->SendPointToWireTrue();
            m_highlightPoint = m_inputs[i];
            update();
        }
        else {
            emit this->SendPointToWireFalse();
        }
    }
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
    m_inputs.clear();
    QPointF begin = path.pointAtPercent(0);
    QPointF end = path.pointAtPercent(1);

    m_inputs.push_back(path.pointAtPercent(0));
    m_inputs.push_back(path.pointAtPercent(1));
    m_inputs.push_back(path.pointAtPercent(1/m_inputsGap));
    m_inputs.push_back(path.pointAtPercent(1/2*m_inputsGap));
    m_inputs.push_back(path.pointAtPercent(1/(1-m_inputsGap)));
    m_inputs.push_back(path.pointAtPercent(1/(1-2*m_inputsGap)));

    for (size_t i = 0; i < m_inputsCount; ++i) {
        m_inputs.push_back({begin.x(), begin.y() + i * m_inputsGap});
        m_inputs.push_back({end.x(), end.y() - i * m_inputsGap});
    }
    return m_inputs;
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


