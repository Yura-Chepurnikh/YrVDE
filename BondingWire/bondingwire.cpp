#include "./BondingWire.h"

BondingWire::BondingWire()
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

BondingWire::~BondingWire() { }

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{"#23A9F2"}, 2));

    // if (!m_points.empty()) {
    //     for (size_t i = 1; i < m_points.size(); ++i) {
    //         path.quadTo(m_points[i-1], m_points[i]);
    //     }
    // }
    qDebug() << "size " << m_points.size() << '\n';
    QPainterPath path;

    if (!m_all_Points.empty()) {
        for (size_t i = 0; i < m_all_Points.size(); ++i) {
            std::vector<QPointF> vec = m_all_Points[i];
            if (!vec.empty() && vec.size() >= 3) {
                path.moveTo(m_points[0]);
                path.lineTo(m_points[1]);
                path.lineTo(m_points[2]);
                qDebug() << "m_points[0] " << m_points[0] << '\n';

                qDebug() << "m_points[1] " << m_points[1] << '\n';

                qDebug() << "m_points[2] " << m_points[2] << '\n';
            }
        }
    }
    painter->drawPath(path);

    if (!m_points.empty() && m_points.size() >= 3) {
        path.moveTo(m_points[0]);
        path.lineTo(m_points[1]);
        path.lineTo(m_points[2]);
        qDebug() << "m_points[0] " << m_points[0] << '\n';

        qDebug() << "m_points[1] " << m_points[1] << '\n';

        qDebug() << "m_points[2] " << m_points[2] << '\n';

    }

    // if (!m_all_Points.empty()) {
    //     for (size_t i = 0; i < m_all_Points.size(); ++i) {
    //         std::vector<QPointF> vec = m_all_Points[i];
    //         path.moveTo(vec[0]);
    //         for (size_t j = 1; j < vec.size(); ++j) {
    //             path.lineTo(vec[j]);
    //         }
    //     }
    // }
    // if (!m_points.empty()) {
    //     for (size_t i = 0; i < m_points.size(); ++i) {
    //         qDebug() << "m_points: " << m_points[i] << '\n';
    //     }
    // }

    painter->drawPath(path);
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        //m_points.clear();
        m_startPos = ConnectToGrid(event->pos(), m_offset);
        m_points.push_back(m_startPos);
        qDebug() << "m_startPos: " <<  m_startPos << '\n';
        m_isDrag = true;
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        m_points.clear();
        m_points.push_back(m_startPos);
        QPointF currentPoint = ConnectToGrid(event->pos(), m_offset);
        qDebug() << "currentPoint: " <<  currentPoint << '\n';
        QPointF intersectionPoint = QPointF { currentPoint.x(), m_startPos.y() };
        qDebug() << "intersectionPoint: " <<  intersectionPoint << '\n';
        m_points.push_back(intersectionPoint);
        m_points.push_back(currentPoint);
        update();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && event->button() == Qt::LeftButton) {
        qDebug() << "mouseReleaseEvent !!!" << '\n';
        m_isDrag = false;
        m_all_Points.push_back(m_points);
        update();
    }
}

QRectF BondingWire::boundingRect() const {
    return QRectF { -100, -100, 1000, 1000 };
}

void BondingWire::GetGridGap(int gap) {
    m_offset = gap;
    qDebug() << m_offset;
}

QPointF BondingWire::ConnectToGrid(const QPointF& pos, int m_offset) {
    if (m_offset < 0) {
        qDebug() << "m_offset > 0";
        return pos;
    }
    qreal x = qRound(pos.x() / m_offset) * m_offset;
    qreal y = qRound(pos.y() / m_offset) * m_offset;
    return QPointF { x, y };
}
