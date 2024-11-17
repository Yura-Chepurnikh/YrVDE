#include "./BondingWire.h"

BondingWire::BondingWire()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    isDrag = false;
}

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::red, 2));
    QPainterPath path;

    path.addRect(0, 0, 100, 100);
    if (!m_points.empty()) {
        for (size_t i = 1; i < m_points.size(); ++i) {
            path.quadTo(m_points[i-1], m_points[i]);
        }
    }
    painter->drawPath(path);
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "asd" << '\n';

    if (event->button() == Qt::LeftButton) {
        qDebug() << "asd" << '\n';

        isDrag = true;
        m_points.push_back(event->pos());
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (isDrag && (event->buttons() & Qt::LeftButton)) {
        qDebug() << "asd" << '\n';
        auto dx = m_points.back().x() - event->pos().x();
        auto dy = m_points.back().y() - event->pos().y();

        QPointF currentPos;

        if (dx > dy) {
            currentPos.setY(m_points.back().y());
            currentPos.setX(event->pos().x());
        }
        else if (dx <= dy) {
            currentPos.setY(event->pos().y());
            currentPos.setX(m_points.back().x());
        }

        // if ((dx < 0 || dy < 0) && !m_points.empty())
        //     m_points.pop_back();
        // else
        //     m_points.push_back(currentPos);

        update();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (isDrag && event->button() == Qt::LeftButton) {
        isDrag = false;
        update();
    }
}

QRectF BondingWire::boundingRect() const {
    return QRectF { 0, 0, 100, 100 };
}
