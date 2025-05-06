#include "logicgate.h"

LogicGate::LogicGate() {
    m_isDrag = false;
    m_gatePos = connectToGrid(m_gatePos, m_gridSize);
    setAcceptHoverEvents (true);
    setFlags (QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void LogicGate::getGridSize(int size) {
    m_gridSize = size;
    m_activeRadius = m_gridSize / PARTS;
}

void LogicGate::getGridPos(QPointF pos) {
    m_gatePos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        if (m_activePort) {
            emit this->sendCreateWire(this, m_activePort);
        }
        else {
            setCursor(Qt::ClosedHandCursor);
            QGraphicsItem::mousePressEvent(event);
        }
    }
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (!m_activePort && event->buttons() & Qt::LeftButton) {
        emit this->sendGateDrag(this);
        QPointF currentPoint = event->scenePos();
        m_gatePos = connectToGrid(currentPoint, m_activeRadius);
        update();
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {

        setCursor(Qt::CustomCursor);
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

void LogicGate::hoverMoveEvent(QGraphicsSceneHoverEvent *event) {
    qDebug() <<"gover";
    setCursor(Qt::ClosedHandCursor);

    QPointF currentPos = event->pos();
    m_activePort = nullptr;

    if (distanceToPoints(m_output->pos, currentPos) < (m_activeRadius / 2)) {
        m_activePort = m_output;
    }
}

qreal LogicGate::distanceToPoints(const QPointF &from, const QPointF &to) {
    return std::sqrt(std::pow(from.x() - to.x(), 2) + std::pow(from.y() - to.y(), 2));
}

QPointF LogicGate::connectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void LogicGate::createPorts(QPainterPath path) {
    m_inputs.clear();
    m_inputWires.clear();

    constexpr qreal offset = 0.1;

    QPointF curvePoint1 = path.pointAtPercent(offset * 3);
    QPointF curvePoint2 = path.pointAtPercent(offset * 7);

    QPointF input1 = QPointF(m_gatePos.x(), curvePoint1.y());
    QPointF input2 = QPointF(m_gatePos.x(), curvePoint2.y());

    QLineF wire1(input1, curvePoint1);
    QLineF wire2(input2, curvePoint2);

    m_inputWires.push_back(wire1);
    m_inputWires.push_back(wire2);

    m_inputs.push_back(QSharedPointer<Port>::create(input1));
    m_inputs.push_back(QSharedPointer<Port>::create(input2));
}

void LogicGate::createBackside(QPainterPath &path) const { }

QRectF LogicGate::boundingRect() const {
    QRectF rect(m_gatePos.x(), m_gatePos.y(), m_gridSize, m_gridSize);

    rect.adjust(-m_activeRadius, -m_activeRadius, m_activeRadius, m_activeRadius);
    return rect;
}


