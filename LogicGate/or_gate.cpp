#include "./or_gate.h"

ORGate::ORGate() {
    createBackside(m_backSide);
    createPorts(m_backSide);
    createOutputPort();
}

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;

    createLateralSides(path);
    painter->drawPath(path);

    m_backSide.clear();
    createBackside(m_backSide);
    painter->drawPath(m_backSide);

    createPorts(m_backSide);
    if (!m_inputWires.empty()) {
        for (auto line : m_inputWires) {
            painter->drawLine(line);
        }
    }

    qreal diameter = 2;

    if (!m_inputs.empty()) {
        for (auto input : m_inputs) {
            if (input->state == LogicState::LOGIC_ONE_STATE) {
                painter->setPen(QPen(Qt::green, 0.5));
            }
            else {
                painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));
            }
            painter->drawEllipse(input->pos, diameter, diameter);
        }
        createOutputPort();
        if (m_output) {
            if (m_output->state == LogicState::LOGIC_ONE_STATE) {
                painter->setPen(QPen(Qt::green, 0.5));
            }
            else {
                painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));
            }
            painter->drawEllipse(m_output->pos, diameter, diameter);
        }
        if (m_activePort) {
            painter->setPen(QPen(Qt::red, 0.5));
            painter->drawEllipse(m_activePort->pos, diameter, diameter);
        }
    }
}

void ORGate::createOutputPort() {
    m_output = QSharedPointer<Port>::create(QPointF{m_gatePos.x() + (m_gridSize / 10) * 8, m_gatePos.y() + m_gridSize / 2}, LogicState::HIGH_IMPEDANCE_STATE);
}

void ORGate::createLateralSides(QPainterPath &path) const {
    path.moveTo(m_gatePos);
    path.quadTo(m_gatePos.x() + m_gridSize / 2, m_gatePos.y(), m_gatePos.x() + (m_gridSize / 10) * 8 , m_gatePos.y() + m_gridSize / 2);
    path.quadTo(m_gatePos.x() + m_gridSize / 2, m_gatePos.y() + 2 * m_gridSize / 2, m_gatePos.x(), m_gatePos.y() + 2 * m_gridSize / 2);
}

void ORGate::createBackside(QPainterPath &path) const {
    path.moveTo(m_gatePos.x(), m_gatePos.y() + 2 * m_gridSize / 2);
    path.quadTo(m_gatePos.x() + m_gridSize / 2, m_gatePos.y() + m_gridSize / 2, m_gatePos.x(), m_gatePos.y());
}

