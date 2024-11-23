#include "./and_gate.h"

ANDGate::ANDGate() : LogicGate()
{
    m_addInputs = new AddInput();

    QObject::connect(this, &LogicGate::SendFirstCordinate, m_addInputs, &AddInput::GetFirstCordinate);
    emit SendFirstCordinate(m_pos);

    qDebug() << "m_gap" << m_gap;

    QObject::connect(this, &LogicGate::SendSecondCordinate, m_addInputs, &AddInput::GetSecondCordinate);
    emit SendSecondCordinate({m_pos.x(), m_pos.y() + 1000});

    QObject::connect(this, &LogicGate::SendInputsDistance, m_addInputs, &AddInput::GetInputsDistance);
    emit SendInputsDistance(100);
}

ANDGate::~ANDGate() { }

void ANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 5));

    painter->translate(boundingRect().center());
    painter->rotate(90);
    painter->translate(-boundingRect().center());

    QPainterPath path;
    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), m_gap, m_gap, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + m_gap);
    path.lineTo(m_pos.x(), m_pos.y());

    std::vector<QPointF> vec;
    vec = m_addInputs->Points();

    painter->drawPath(path);

    update();
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF ANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
