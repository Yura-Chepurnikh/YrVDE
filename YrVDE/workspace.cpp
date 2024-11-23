#include "./workspace.h"

int WorkSpace::m_gap = 10;
int WorkSpace::m_minDis = m_gap / 10;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    this->setMouseTracking(true);
    this->setDragMode(QGraphicsView::NoDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->setStyleSheet("background-color: #1F1F1F");

    scene->setSceneRect(this->viewport()->rect().x(),
                                       this->viewport()->rect().y(),
                                       this->viewport()->rect().width(),
                                       this->viewport()->rect().height());

 // if (m_gate)
 //    qDebug() << "m_gate is null !!!";

    setScene(scene);
    update();
}

WorkSpace::~WorkSpace() { }

void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen({QColor{"#404040"}, 0.1});

    m_minDis = m_gap / 10;

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_gap; x < rect.right(); x += m_gap) {
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_gap; y < rect.bottom(); y += m_gap) {
        painter->drawLine(rect.right(), y, rect.left(), y);
    }

    m_gridPoints.clear();

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_gap; x < rect.right(); x += m_gap) {
        std::vector<QPoint> points;
        for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_gap; y < rect.bottom(); y += m_gap) {
            points.push_back(QPoint(x, y));
        }
        m_gridPoints.push_back(points);
    }
    update();
}

void WorkSpace::GetLogicGate(LogicGate* gate) {
    m_gate = gate;
    qDebug() << (m_gate != nullptr);
    scene()->addItem(m_gate);

    QObject::connect(this, WorkSpace::SendGap, m_gate, LogicGate::GetGridGap);
    emit this->SendGap(m_gap);
    update();
}

void WorkSpace::wheelEvent(QWheelEvent* event) {
    qreal scaleFactor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale (scaleFactor, scaleFactor);
    } else {
        scale (1/scaleFactor, 1/scaleFactor);
    }
}



