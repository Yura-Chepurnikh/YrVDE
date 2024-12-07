#include "./workspace.h"

int WorkSpace::m_gap = 60;
int WorkSpace::m_inputsDistance = m_gap / 10;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    this->setMouseTracking(true);
    this->setDragMode(QGraphicsView::NoDrag);
    this->setRenderHint(QPainter::Antialiasing);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->setStyleSheet("background-color: #1F1F1F");

    // m_wire = new BondingWire();
    // scene->addItem(m_wire);

    // QObject::connect(this, &WorkSpace::SendGap, m_wire, &BondingWire::GetGridGap);
    // emit this->SendGap(m_gap);

    scene->setSceneRect(this->viewport()->rect());

   // this->setStyleSheet("background-color: green");

    setScene(scene);
    update();
}

WorkSpace::~WorkSpace() { }

void WorkSpace::GetWire(BondingWire* wire)
{
    qDebug() << "tatatatatatatat";

    m_wire = wire;
    m_wire->setZValue(100);
    scene()->addItem(m_wire);

    if (m_wire)
        qDebug() << "m_wire exist";

    // m_gate = gate;
    // qDebug() << "m_gate not exist: " << (m_gate == nullptr);
    // scene()->addItem(m_gate);

    // QObject::connect(this, &WorkSpace::SendGap, m_gate, &LogicGate::GetGridGap);
    // emit this->SendGap(m_gap);

    // QObject::connect(m_gate, &LogicGate::SendInputsPoints, m_wire, &BondingWire::GetInputsPoints);
    // if (m_gate->m_inputs.empty())

    // if (m_gate->m_inputs.empty())
    //     qDebug() << "empty";

    // for (size_t i = 0; i < m_gate->m_inputs.size(); ++i)
    //     qDebug() << "asd" << m_gate->m_inputs[i]->m_point;
    // qDebug() << "aaaaaaaaaaaaaaaaaaaaaa";
    // emit m_gate->SendInputsPoints(m_gate->m_inputs);
}

void WorkSpace::drawBackground(QPainter *painter, const QRectF &rect) {
    painter->setPen({QColor{"#404040"}, 0.1});

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_inputsDistance; x < rect.right(); x += m_inputsDistance) {
        painter->drawLine(x, rect.top(), x, rect.bottom());
    }

    for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_inputsDistance; y < rect.bottom(); y += m_inputsDistance) {
        painter->drawLine(rect.right(), y, rect.left(), y);
    }

    m_gridPoints.clear();

    for (auto x = static_cast<int>(rect.left()) - static_cast<int>(rect.left()) % m_inputsDistance; x < rect.right(); x += m_inputsDistance) {
        std::vector<QPoint> points;
        for (auto y = static_cast<int>(rect.top()) - static_cast<int>(rect.top()) % m_inputsDistance; y < rect.bottom(); y += m_inputsDistance) {
            points.push_back(QPoint(x, y));
        }
        m_gridPoints.push_back(points);
    }
    update();
}

void WorkSpace::GetLogicGate(LogicGate* gate) {
    m_gate = gate;
    m_gate->setZValue(4);
    qDebug() << "m_gate not exist: " << (m_gate == nullptr);
    scene()->addItem(m_gate);

    QObject::connect(this, &WorkSpace::SendGap, m_gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    for (size_t i = 0; i < m_gate->m_inputs.size(); ++i)
        qDebug() << "asd" << m_gate->m_inputs[i]->m_point;
    qDebug() << "aaaaaaaaaaaaaaaaaaaaaa";


    if (m_gate->m_inputs.empty())
        qDebug() << "empty";

    // m_wire = new BondingWire();
    // scene()->addItem(m_wire);

    // QObject::connect(this, &WorkSpace::SendGap, m_wire, &BondingWire::GetGridGap);
    // emit this->SendGap(m_gap);

    for (size_t i = 0; i < m_gate->m_inputs.size(); ++i)
        m_allGatePoints.push_back(m_gate->m_inputs[i]);


    update();
}

void WorkSpace::wheelEvent(QWheelEvent* event) {
    qreal scaleFactor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale (scaleFactor, scaleFactor);
    } else {
        scale (1/scaleFactor, 1/scaleFactor);
    }
    emit this->SendGap(m_gap);
}

void WorkSpace::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        qDebug() << "ZZZX";

        for (size_t i = 0; i < m_allGatePoints.size(); ++i) {

                qDebug() << "all gate points in WorkSpace: " << m_allGatePoints[i]->m_point;
                qreal dis = std::sqrt(std::pow((m_allGatePoints[i]->m_point.y() - mapToScene(event->pos()).y()), 2) +
                                      std::pow((m_allGatePoints[i]->m_point.x() - mapToScene(event->pos()).x()), 2));

                qDebug() << "dis WorkSpace: " << dis;
                qDebug() << "m_gap WorkSpace: " << m_gap / 5;

                if (dis < m_gap / 5) {
                    qDebug() << "ZZZ";


                    m_wire = new BondingWire();
                    scene()->addItem(m_wire);

                    QObject::connect(this, &WorkSpace::SendGap, m_wire, &BondingWire::GetGridGap);
                    emit this->SendGap(m_gap);

                    QObject::connect(this, &WorkSpace::SendAllPoints, m_wire, &BondingWire::GetInputsPoints);
                    emit this->SendAllPoints(m_allGatePoints);


                    auto dummyEvent = new QGraphicsSceneMouseEvent(QEvent::GraphicsSceneMousePress);
                    dummyEvent->setScenePos(mapToScene(event->pos()));
                    dummyEvent->setButton(Qt::LeftButton);
                    dummyEvent->setButtons(Qt::LeftButton);
                    dummyEvent->setModifiers(Qt::NoModifier);
                    m_wire->mousePressEvent(dummyEvent);
                    delete dummyEvent;
            }
        }
    } else if (event->button() == Qt::MiddleButton) {
        qDebug() << "GGG";
        m_lastPosOfScene = event->pos();
        m_is_Drag = true;
    }
    QGraphicsView::mousePressEvent(event);
}

void WorkSpace::mouseMoveEvent(QMouseEvent *event) {
    if (m_is_Drag && (event->buttons() & Qt::MiddleButton)) {
        QPointF delta = event->pos() - m_lastPosOfScene;
        this->setSceneRect(m_lastPosOfScene.x(), m_lastPosOfScene.y(), delta.x(), delta.y());

        m_lastPosOfScene = event->pos();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void WorkSpace::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::MiddleButton) {
        m_is_Drag = false;
    }
    QGraphicsView::mouseReleaseEvent(event);
}



