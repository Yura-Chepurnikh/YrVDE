#include "./and_gate.h"

ANDGate::ANDGate() { }

ANDGate::~ANDGate() { }


void ANDGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(QColor{ "#23A9F2" }, 2));

    QPainterPath path;
    path.moveTo(m_pos);
    path.arcTo(m_pos.x(), m_pos.y(), m_gap, m_gap, 90, -180);
    path.lineTo(m_pos.x(), m_pos.y() + m_gap);
    path.lineTo(m_pos.x(), m_pos.y());

    painter->drawPath(path);

    painter->setPen(QPen(Qt::red, 2));
    QPainterPath inputsLine;
    inputsLine.addEllipse(m_pos.x(), m_pos.y() + 2, 1, 1);
    inputsLine.addEllipse(m_pos.x(), m_pos.y() + 4, 1, 1);
    inputsLine.addEllipse(m_pos.x(), m_pos.y() + m_gap - 4, 1, 1);
    inputsLine.addEllipse(m_pos.x(), m_pos.y() + m_gap - 2, 1, 1);
    painter->drawPath(inputsLine);

    QPainterPath outputPoint;
    outputPoint.addEllipse(m_pos.x() + m_gap, m_pos.y()  + m_gap / 2, 1, 1);
    painter->drawPath(outputPoint);

    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
}

QRectF ANDGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), 30, 30);
}
