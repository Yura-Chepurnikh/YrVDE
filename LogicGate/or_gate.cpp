#include "./or_gate.h"

ORGate::ORGate() {
    int gap = m_gap /2;
    m_backSide.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    m_backSide.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());
    m_inputs = CreateInputPoints(m_backSide);
    QPointF out(m_pos);
    m_output = QSharedPointer<Input>::create(QPointF{m_pos.x() +  m_gap, m_pos.y() + gap}, LogicState::HIGH_IMPEDANCE_STATE);
}

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() +  m_gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    painter->drawPath(path);

    QPainterPath back;
    back.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    back.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    painter->drawPath(back);

    painter->setPen(QPen(Qt::red, 0.5));

    m_inputs = CreateInputPoints(back);

    QPainterPath inputs;

    for (const auto& item : m_inputs) {
        inputs.addEllipse(item->pos, 1, 1);
    }
    painter->drawPath(inputs);

    if (m_activeInput) {
        if (m_activeInput->state == LogicState::LOGIC_ONE_STATE) {
            painter->setPen({Qt::green, 2});
        }
        else {
            painter->setPen({Qt::yellow, 2});
        }
        painter->drawPoint(m_activeInput->pos);
    }
}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}

QPainterPath ORGate::shape() const {
    QPainterPath path;
    int gap = m_gap/2;

    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() +  m_gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    return path;
}
