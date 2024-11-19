#include "./workspace.h"

int WorkSpace::m_gap = 1000;
int WorkSpace::m_minDis = m_gap / 10;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    // this->setInteractive(true);
     this->setMouseTracking(true);

    this->setDragMode(QGraphicsView::NoDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    this->setStyleSheet("background-color: #1F1F1F");




    m_wire = new BondingWire();
    m_wire->setPos(0, 0);
    scene->addItem(m_wire);


    QObject::connect(this, &WorkSpace::SendGap, m_wire, &BondingWire::GetGridGap);
    emit this->SendGap(m_gap);

    m_gap = 30;
    m_mergeDistance = m_gap / 2;

    LogicGate* input = new Input;
    scene->addItem(input);


    LogicGate* nand_gate = new NANDGate;
    scene->addItem(nand_gate);

    LogicGate* not_gate = new NOTGate();
    scene->addItem(not_gate);

    LogicGate* or_gate = new ORGate();
    scene->addItem(or_gate);

    LogicGate* xor_gate = new XORGate();
    scene->addItem(xor_gate);

    QObject::connect(this, &WorkSpace::SendGap, input, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, nand_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, not_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, or_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, xor_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    LogicGate* and_gate = new ANDGate;
    scene->addItem(and_gate);

    LogicGate* buffer = new BUFFERGate();
    scene->addItem(buffer);

    LogicGate* nor_gate = new NORGate();
    scene->addItem(nor_gate);

    LogicGate* xnor_gate = new XNORGate();
    scene->addItem(xnor_gate);

    QObject::connect(this, &WorkSpace::SendGap, and_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, buffer, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, nor_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, xnor_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(this, &WorkSpace::SendGap, xnor_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    setScene(scene);
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

void WorkSpace::wheelEvent(QWheelEvent* event) {
    qreal scaleFactor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale (scaleFactor, scaleFactor);
    } else {
        scale (1/scaleFactor, 1/scaleFactor);
    }
}



