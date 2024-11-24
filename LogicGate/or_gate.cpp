#include "./or_gate.h"

ORGate::ORGate() { }

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 1));

    QPainterPath path;
    painter->translate(boundingRect().center());
    painter->rotate(90);
    painter->translate(-boundingRect().center());

    path.moveTo(m_pos);
    path.closeSubpath();

    QPainterPath back;

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 2*gap, m_pos.x(), m_pos.y() + 2*gap);
    painter->drawPath(path);

    back.moveTo(m_pos.x(), m_pos.y() + 2*gap);
    back.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());
    painter->drawPath(back);

    painter->setPen(QPen(Qt::red, 1));

    for (int i = 0; i <= 5; ++i) {
        qreal t = static_cast<qreal>(i) / 5;
        QPointF point = back.pointAtPercent(t);
        painter->drawPoint(point);
        //qDebug << point.x <<;
    }

    painter->drawPoint(m_pos.x(), m_pos.y() - m_min_dis);
}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
