#include "./BondingWire.h"

BondingWire::BondingWire() {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

BondingWire::~BondingWire() { }

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(QColor{"#23A9F2"}, 0.3));

    if (m_points.size() >= 2) {
        painter->drawLine(m_points[0], m_points[1]);
        painter->drawLine(m_points[1], m_points[2]);
    }

    painter->setPen(QPen(Qt::yellow, 0.2));
    for (size_t i = 0; i < m_allGatePoints.size(); ++i) {
        for (size_t j = 0; j < m_allGatePoints[i].size(); ++j) {
            painter->drawPoint(m_allGatePoints[i][j]->m_point);
        }
    }
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        for (size_t i = 0; i < m_allGatePoints.size(); ++i) {
            for (size_t j = 0; j < m_allGatePoints[i].size(); ++j) {
                qreal dis =
                    std::sqrt(std::pow((m_allGatePoints[i][j]->m_point.y() - event->pos().y()), 2) +
                    std::pow((m_allGatePoints[i][j]->m_point.x() - event->pos().x()), 2));
                if (dis < m_offset) {
                    m_startPos = m_allGatePoints[i][j]->m_point;
                    m_points.push_back(m_startPos);
                    m_isDrag = true;
                    update();
                }
            }
        }
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //qDebug() << "omega";
    if (m_isDrag && (event->buttons() & Qt::LeftButton)) {
        m_points.clear();
        m_points.push_back(m_startPos);

        QPointF currentPoint = ConnectToGrid(event->pos(), m_offset);

        for (size_t i = 0; i < m_allGatePoints.size(); ++i) {
            for (size_t j = 0; j < m_allGatePoints[i].size(); ++j) {
                qDebug() << "points: " << m_allGatePoints[i][j]->m_point;

                qreal dis = std::sqrt(std::pow((m_allGatePoints[i][j]->m_point.y() - event->pos().y()), 2) +
                                       std::pow((m_allGatePoints[i][j]->m_point.x() - event->pos().x()), 2));

                if (dis < m_offset)
                {
                    qDebug() << "BondingWire  + mouseReleaseEvent + iggggg + setPos" << m_allGatePoints[i][j];

                    currentPoint = m_allGatePoints[i][j]->m_point;
                    qDebug() << "BondingWire  + mouseReleaseEvent + if + setPos" << event->pos();
                }
            }
        }

        QPointF intersectionPoint = QPointF { currentPoint.x(), m_startPos.y() };
       // if (currentPoint != intersectionPoint)
            m_points.push_back(intersectionPoint);
        m_points.push_back(currentPoint);
        update();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && event->button() == Qt::LeftButton) {
        qDebug() << "BondingWire  + mouseReleaseEvent + setPos";
        m_isDrag = false;
        m_flag = false;
        update();
    }
}

QRectF BondingWire::boundingRect() const {
    if (scene()) {
        return scene()->sceneRect();
    }
    return QRectF { 0, 0, 0, 0 };
}

void BondingWire::GetGridGap(int gap) {
    m_offset = gap / 5;
}

QPointF BondingWire::ConnectToGrid(const QPointF& pos, int m_offset) {
    qreal x = qRound(pos.x() / m_offset) * m_offset;
    qreal y = qRound(pos.y() / m_offset) * m_offset;
    return QPointF { x, y };
}

void BondingWire::GetInputsPoints(std::vector<QSharedPointer<InputPoint>> points) {
    qInfo() << "BondingWire GetInputsPoints";

    for (size_t j = 0; j < points.size(); ++j) {
        qDebug() << points[j]->m_point;
    }
    if (!m_allGatePoints.empty())
        m_allGatePoints.clear();

    qInfo() << "BondingWire GetInputsPoints";
    m_allGatePoints.push_back(points);
}


