#include "./or_gate.h"

ORGate::ORGate() {
    AddInput();
    AddInput();
    AddInput();
    AddInput();
    AddInput();
}

ORGate::~ORGate() { }

void ORGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{ "#23A9F2"}, 0.5));

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

    painter->setPen(QPen(Qt::red, 0.4));

    std::vector<QPointF> points = CreateInputPoints(back);
    for (auto item : points) {
        painter->drawPoint(item);
    }

    painter->setPen({Qt::blue, 0.6});
    painter->drawPoint(m_highlightPoint);


}

QRectF ORGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}
