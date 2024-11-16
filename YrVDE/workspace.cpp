#include "./workspace.h"

int WorkSpace::m_gap = 30;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    this->setInteractive(true);
    this->setMouseTracking(true);
    this->setDragMode(QGraphicsView::ScrollHandDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    this->setStyleSheet("background-color: #1F1F1F");

    m_gap = 30;
    m_mergeDistance = m_gap / 2;

    m_andGate = new ANDGate();
    scene->addItem(m_andGate);

    wire = new BondingWire();
    scene->addItem(wire);

    QObject::connect(this, &WorkSpace::SendGap, m_andGate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendPoint, m_andGate, &LogicGate::GetGridPos);
    emit this->SendPoint(m_highlightPoint);

    update();
}

WorkSpace::~WorkSpace() { }

void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen({QColor{"#404040"}, 1});

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_gap; x < rect.right(); x += m_gap / 2) {
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_gap; y < rect.bottom(); y += m_gap / 2) {
        painter->drawLine(rect.right(), y, rect.left(), y);
    }

    m_gridPoints.clear();

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_gap; x < rect.right(); x += m_gap / 2) {
        std::vector<QPoint> points;
        for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_gap; y < rect.bottom(); y += m_gap / 2) {
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
                emit this->SendPoint(m_highlightPoint);

                update();
                return;
            }
        }
    }
}


