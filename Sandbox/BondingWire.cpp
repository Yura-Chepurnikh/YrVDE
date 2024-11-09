#include "./BondingWire.h"

BondingWire::BondingWire(Grid* gridData) : m_grid (gridData)
{

}

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QPainterPath path;

    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->drawLine(m_grid->m_gridPoints[4][4], m_grid->m_gridPoints[5][7]);

    if (!m_points.empty()) {
        path.moveTo(m_points[0]);
    }

    if (!m_points.empty()) {
        for (size_t i = 1; i < m_points.size(); ++i) {
            path.quadTo(m_points[i-1], m_points[i]);
        }
    }
    painter->drawPath(path);
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isDrag = true;
        m_points.push_back(MergeToPoints(event->pos()));
        update();
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (isDrag && (event->buttons() & Qt::LeftButton)) {
        auto dx = m_points.back().x() - MergeToPoints(event->pos()).x();
        auto dy = m_points.back().y() - MergeToPoints(event->pos()).y();

        QPointF currentPos;

        if (dx > dy) {
            currentPos.setY(m_points.back().y());
            currentPos.setX(MergeToPoints(event->pos()).x());
        }
        else if (dx <= dy) {
            currentPos.setY(MergeToPoints(event->pos()).y());
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
    return QRectF { -400, -400, 1920, 1080 };
}

QPointF BondingWire::MergeToPoints(QPointF cursorCurrentPos) {
    for (size_t i = 0; i < m_grid->m_gridPoints.size(); ++i) {
        for (size_t j = 0; j < m_grid->m_gridPoints[i].size(); ++j) {
            if (abs(cursorCurrentPos.x() - m_grid->m_gridPoints[i][j].x()) > m_grid->m_mergeDis  &&
                abs(cursorCurrentPos.x() - m_grid->m_gridPoints[i][j].x() > m_grid->m_mergeDis))
            {
                return m_grid->m_gridPoints[i][j];
            }
        }
    }
}
