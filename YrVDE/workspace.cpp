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
    scene->setSceneRect(this->viewport()->rect());
    setScene(scene);
    update();
}

WorkSpace::~WorkSpace() { }

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
    gate->setZValue(1);
    scene()->addItem(gate);

    m_gates.push_back(gate);

    QObject::connect(this, &WorkSpace::SendGap, gate, &LogicGate::GetGridGap);
    emit this->SendGap(m_gap);

    m_wire = new BondingWire();
    scene()->addItem(m_wire);

    QObject::connect(this, &WorkSpace::SendGap, m_wire, &BondingWire::GetGridGap);
    emit this->SendGap(m_gap);

    QObject::connect(m_wire, &BondingWire::SendPoint, this, &WorkSpace::GetBondingWirePoint);

    PrintConsoleGates();

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
    if (event->button() == Qt::MiddleButton) {
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

void WorkSpace::GetBondingWirePoint(QPointF point) {
    qDebug() << point;
    for (size_t i = 0; i < m_gates.size(); ++i) {
        for (size_t j = 0; j < m_gates[i]->m_inputs.size(); ++j) {
            if (point == m_gates[i]->m_inputs[j]->m_point) {
                qDebug() << "aaa !!!";
                qDebug() <<  m_gates[i]->m_inputs[j].data();

                 o = m_gates[i]->m_inputs[j];
                o->m_state = GateState::LOGIC_1;
                qDebug() <<  m_gates[i]->m_inputs[j]->m_state;

                QObject::connect(this, &WorkSpace::SendInputPoint, m_gates[i], &LogicGate::GetInputPoint);
                emit this->SendInputPoint(m_gates[i]->m_inputs[j]);
                update();
            }
        }
    }
    PrintConsoleGates();
}

void WorkSpace::PrintConsoleGates() {
    qDebug() << "WorkSpace::PrintConsoleGates()";
    for (size_t i = 0; i < m_gates.size(); ++i) {
        for (size_t j = 0; j < m_gates[i]->m_inputs.size(); ++j) {
            qDebug() << m_gates[i]->m_inputs[j]->m_state;
        }
    }
    qDebug() << "WorkSpace::PrintConsoleGates()";
}

