#include "./workspace.h"

int WorkSpace::m_gap = 30;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    setMouseTracking(true);
    this->setStyleSheet("background-color: #1F1F1F");
    m_gap = 30;
    m_mergeDistance = m_gap / 2;

    //m_highlightPoint = m_gridPoints[20][20];
}

void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen({QColor{"#404040"}, 1});

    for (auto x = static_cast<int>(rect.left()); x < rect.right(); x += m_gap) {
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    for (auto y = static_cast<int>(rect.top()); y < rect.bottom(); y += m_gap) {
        painter->drawLine(rect.right(), y, rect.left(), y);
    }

    m_gridPoints.clear();

    for (auto x = static_cast<int>(rect.left()); x < rect.right(); x += m_gap) {
        std::vector<QPoint> points;
        for (auto y = static_cast<int>(rect.top()); y < rect.bottom(); y += m_gap) {
            points.push_back(QPoint(x, y));
        }
        m_gridPoints.push_back(points);
    }

    painter->setPen({Qt::red, 5});
    painter->drawPoint(m_highlightPoint);
}

void WorkSpace::wheelEvent(QWheelEvent* event) {
    qreal scaleFactor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale (scaleFactor, scaleFactor);
    } else {
        scale (1/scaleFactor, 1/scaleFactor);
    }
}

void WorkSpace::mouseMoveEvent(QMouseEvent *event) {
    QPointF scenePos = mapToScene(event->pos());

    for (size_t i = 0; i < m_gridPoints.size(); ++i) {
        for (size_t j = 0; j < m_gridPoints[i].size(); ++j) {
            if (std::abs(scenePos.x() - m_gridPoints[i][j].x()) < m_mergeDistance &&
                std::abs(scenePos.y() - m_gridPoints[i][j].y()) < m_mergeDistance)
            {
                m_highlightPoint = m_gridPoints[i][j];
                update();
                return;
            }
        }
    }
}
