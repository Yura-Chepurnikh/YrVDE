#include "./workspace.h"

int WorkSpace::m_gap = 30;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    setMouseTracking(true);
    this->setStyleSheet("background-color: #1F1F1F");
    m_gap = 30;
    m_mergeDistance = m_gap / 2;

    wire = new BondingWire();
    scene->addItem(wire);
}

void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen({QColor{"#404040"}, 1});

    qreal scaleFactor = transform().m11();

    int scaledGap = static_cast<int>(m_gap * scaleFactor);

    for (auto x = static_cast<int>(rect.left()); x < rect.right(); x += scaledGap) {
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    for (auto y = static_cast<int>(rect.top()); y < rect.bottom(); y += scaledGap) {
        painter->drawLine(rect.right(), y, rect.left(), y);
    }

    m_gridPoints.clear();

    for (auto x = static_cast<int>(rect.left()); x < rect.right(); x += scaledGap) {
        std::vector<QPoint> points;
        for (auto y = static_cast<int>(rect.top()); y < rect.bottom(); y += scaledGap) {
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

    qreal scaleFactor = transform().m11();
    int scaledMergeDistance = static_cast<int>(scaleFactor * m_mergeDistance);

    for (size_t i = 0; i < m_gridPoints.size(); ++i) {
        for (size_t j = 0; j < m_gridPoints[i].size(); ++j) {
            if (std::abs(scenePos.x() - m_gridPoints[i][j].x()) < scaledMergeDistance &&
                std::abs(scenePos.y() - m_gridPoints[i][j].y()) < scaledMergeDistance)
            {
                m_highlightPoint = m_gridPoints[i][j];
                update();
                return;
            }
        }
    }
}

void WorkSpace::SendPoint(QPoint point) {

}

void WorkSpace::EmitSendPoint() {
    emit SendPoint(m_highlightPoint);
}
