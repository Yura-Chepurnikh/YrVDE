#include "./or_gate.h"

ORGate::ORGate() {
    int gap = m_gap /2;
    m_backSide.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    m_backSide.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());
    m_inputs = CreateInputPoints(m_backSide);
    QPointF out(m_pos);
    m_output = QSharedPointer<InputPoint>::create(QPointF{m_pos.x() +  m_gap, m_pos.y() + gap}, GateState::LOGIC_Z);
    //m_inputs = {{1, 2},{3, 4}};
}

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //qDebug() << "START!!!";
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    //qDebug() << "START1!!!";

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() +  m_gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    painter->drawPath(path);

    //qDebug() << "START2!!!";

    QPainterPath back;
    back.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    back.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());

    painter->drawPath(back);

    painter->setPen(QPen(Qt::red, 0.5));

    m_inputs = CreateInputPoints(back);

    //qDebug() << "START3!!!";

    QPainterPath inputs;

    for (const auto& item : m_inputs) {
        inputs.addEllipse(item->m_point, 1, 1);
    }
    painter->drawPath(inputs);

    //qDebug() << "START4!!!";


    painter->setPen({Qt::green, 2});

    //qDebug() << "START5!!!";

    if (m_highlightPoint) {
        if (m_highlightPoint->m_state == GateState::LOGIC_1) {
            painter->setPen({Qt::green, 2});
        }
        painter->drawPoint(m_highlightPoint->m_point);
    }
    //qDebug() << "END!!!";

    // QPainterPath output;
    // output.addEllipse(m_output->m_point, 1, 1);

    // painter->drawPath(output);
    //painter->drawPoint(m_output->m_point);
    //painter->setBrush(Qt::yellow);
    //painter->drawRect(boundingRect());
     emit this->SendInputsPoints(m_inputs);

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
