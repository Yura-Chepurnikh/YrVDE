#include "./or_gate.h"

ORGate::ORGate() { }

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 1));

    QPainterPath path;

    path.moveTo(m_pos);
    path.closeSubpath();

    int gap = m_gap/2;
    path.quadTo(m_pos.x() + gap, m_pos.y(), m_pos.x() + 1.5 * gap, m_pos.y() + gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + 5*gap, m_pos.x(), m_pos.y() + 2*gap);
    path.quadTo(m_pos.x() + gap, m_pos.y() + gap, m_pos.x(), m_pos.y());


    QPointF controlPoint { m_pos.x() + gap, m_pos.y() + 5*gap };
    QPointF endPoint { m_pos.x(), m_pos.y() + 2*gap };

    painter->setPen(QPen(Qt::red, 3));

    std::vector<QPointF> points = FindPointsOnTheCurve(m_pos, controlPoint, endPoint);
    for (size_t i = 0; i < points.size(); ++i) {
        painter->drawPoint(points[i]);
    }
    painter->drawPath(path);
}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
