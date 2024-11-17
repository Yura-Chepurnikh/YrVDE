#include "./workspace.h"

int WorkSpace::m_gap = 1000;
int WorkSpace::m_minDis = m_gap / 10;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    // this->setInteractive(true);
    // this->setMouseTracking(true);
    this->setDragMode(QGraphicsView::NoDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    this->setStyleSheet("background-color: #1F1F1F");




    m_wire = new BondingWire();
    m_wire->setPos(0, 0);
    scene->addItem(m_wire);

    // m_gap = 30;
    // m_mergeDistance = m_gap / 2;

    // m_andGate = new ANDGate;
    // scene->addItem(m_andGate);

    // // LogicGate* b = new BUFFERGate();
    // // scene->addItem(b);

    // // LogicGate* b3 = new NORGate();
    // // scene->addItem(b3);

    // // LogicGate* b4 = new XNORGate();
    // // scene->addItem(b4);

    // QObject::connect(this, &WorkSpace::SendGap, m_andGate, &LogicGate::GetGridGap);
    // emit this->SendGap(m_gap);

    // // QObject::connect(this, &WorkSpace::SendGap, b, &LogicGate::GetGridGap);
    // // emit this->SendGap(m_gap);

    // // QObject::connect(this, &WorkSpace::SendGap, b3, &LogicGate::GetGridGap);
    // // emit this->SendGap(m_gap);

    // // QObject::connect(this, &WorkSpace::SendGap, b4, &LogicGate::GetGridGap);
    // // emit this->SendGap(m_gap);
    setScene(scene);
}

WorkSpace::~WorkSpace() { }



// void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
//     painter->setPen({QColor{"#404040"}, 0.1});

//     m_minDis = m_gap / 10;

//     for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_minDis; x < rect.right(); x += m_minDis) {
//         painter->drawLine(x, rect.top(), x, rect.bottom());
//     }

//     for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_minDis; y < rect.bottom(); y += m_minDis) {
//         painter->drawLine(rect.right(), y, rect.left(), y);
//     }

//     m_gridPoints.clear();

//     for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_minDis; x < rect.right(); x += m_minDis) {
//         std::vector<QPoint> points;
//         for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_minDis; y < rect.bottom(); y += m_minDis) {
//             points.push_back(QPoint(x, y));
//         }
//         m_gridPoints.push_back(points);
//     }
//     update();
// }

// void WorkSpace::wheelEvent(QWheelEvent* event) {
//     qreal scaleFactor = 1.1;

//     if (event->angleDelta().y() > 0) {
//         scale (scaleFactor, scaleFactor);
//     } else {
//         scale (1/scaleFactor, 1/scaleFactor);
//     }
// }



