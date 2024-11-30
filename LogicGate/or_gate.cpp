#include "./or_gate.h"

ORGate::ORGate() {
    int gap = m_gap /2;
    m_backSide.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    m_backSide.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());
    m_inputs = CreateInputPoints(m_backSide);
    //m_inputs = {{1, 2},{3, 4}};
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
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    painter->drawPath(path);

    QPainterPath back;
    back.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    back.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    painter->drawPath(back);

    painter->setPen(QPen(Qt::red, 10));

    m_inputs = CreateInputPoints(back);

    for (auto item : m_inputs) {
        painter->drawPoint(item);
    }
    emit this->SendInputsPoints(m_inputs);

    painter->setPen({Qt::blue, 13});
    painter->drawPoint(m_highlightPoint);
}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
