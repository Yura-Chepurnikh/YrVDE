#include "./input.h"

Input::Input() {
    m_input = QSharedPointer<InputPoint>::create(m_pos, GateState::LOGIC_0);
}

Input::~Input() { }

void Input::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

    QPainterPath path;
    path.addRect(m_pos.x(), m_pos.y(), m_inputsGap, m_inputsGap);
    painter->drawPath(path);

    if (m_input->m_state == GateState::LOGIC_1)
        painter->setPen(QPen(QColor{Qt::green}, 0.5));
    else
        painter->setPen(QPen(QColor{Qt::red}, 0.5));
    painter->drawPoint(m_input->m_point);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

void Input::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    Q_UNUSED(event);
    qDebug() << "Input::mouseDoubleClickEvent";
    if (m_input->m_state == GateState::LOGIC_0)
        m_input->m_state = GateState::LOGIC_1;
    else
        m_input->m_state = GateState::LOGIC_0;
    update();
}

QRectF Input::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap/10, m_gap/10);
}
