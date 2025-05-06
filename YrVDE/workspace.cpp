#include "./workspace.h"
#include <QDebug>
#include <thread>

int WorkSpace::m_gap = GAP;
int WorkSpace::m_inputsDistance = INPUTS_DISTANCE;

WorkSpace::WorkSpace(QGraphicsScene* scene) : QGraphicsView(scene)
{
    this->setStyleSheet("background-color: #1F1F1F");
    scene->setSceneRect(this->viewport()->rect());
    setScene(scene);

    update();
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

void WorkSpace::addGate(LogicGate* gate) {
    m_activeGate = gate;
    gate->setZValue(1);
    scene()->addItem(gate);
    m_gates.push_back(gate);

    QObject::connect(this, &WorkSpace::sendGap, gate, &LogicGate::getGridSize);
    emit this->sendGap(m_gap);

    QObject::connect(gate, &LogicGate::sendCreateWire, this, &WorkSpace::addWire);
    QObject::connect(gate, &LogicGate::sendGateDrag, this, &WorkSpace::getGateDrag);
}

void WorkSpace::addWire(LogicGate* gate, QSharedPointer<Port> activeInput) {
    m_activePort = activeInput;
    m_currentWire = new BondingWire();
    m_currentWire->setPos(m_activePort->pos);
    scene()->addItem(m_currentWire);
    m_wires.push_back(m_currentWire);
}

void WorkSpace::wheelEvent(QWheelEvent* event) {
    qreal scaleFactor = 1.1;

    if (event->angleDelta().y() > 0) {
        scale (scaleFactor, scaleFactor);
    } else {
        scale (1 / scaleFactor, 1 / scaleFactor);
    }
    emit this->sendGap(m_gap);
}

void WorkSpace::mousePressEvent(QMouseEvent *event) {
    if (m_currentWire && (event->buttons() & Qt::LeftButton)) {
        this->setCursor(Qt::PointingHandCursor);
    }
    if (event->button() == Qt::MiddleButton) {
        this->setCursor(Qt::ClosedHandCursor);
        m_lastPosOfScene = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
}

void WorkSpace::mouseMoveEvent(QMouseEvent *event) {
    if (m_currentWire && (event->buttons() & Qt::LeftButton)) {
        if (m_activePort) {
            QPointF sceneEnd = this->mapToScene(event->pos());
            QPointF snappedEnd = connectToGrid(sceneEnd, m_inputsDistance);
            QPointF localEnd = snappedEnd - m_activePort->pos;

            auto p1 = QSharedPointer<Port>::create(QPointF(0, 0));
            auto p2 = QSharedPointer<Port>::create(localEnd);
            m_currentWire->m_path = std::make_pair(p1, p2);
            m_currentWire->update();
        }
    }

    else if (event->buttons() & Qt::MiddleButton) {
        QPointF delta = event->pos() - m_lastPosOfScene;

        bool horizontal_visible = horizontalScrollBar()->isVisible();
        bool vertical_visible = verticalScrollBar()->isVisible();

        if (horizontal_visible || vertical_visible) {
            delta /= STRONG_SMOOTH;
            this->horizontalScrollBar()->setValue(this->horizontalScrollBar()->value() + delta.x());
            this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() + delta.y());
        }
        else {
            delta /= WEAK_SMOOTH;
            QRectF sceneRect = this->scene()->sceneRect();
            sceneRect.moveLeft(sceneRect.left() - delta.x());
            sceneRect.moveTop(sceneRect.top() - delta.y());
            this->scene()->setSceneRect(sceneRect);
        }
        m_lastPosOfScene = event->pos();
    }

    QGraphicsView::mouseMoveEvent(event);
}

void WorkSpace::getGateDrag(LogicGate* gate) {
    auto it = m_table.find(gate);
    if (it != m_table.end()) {
        auto& pair = it->second;

        auto wire = pair.first;
        auto mem = pair.second;

        auto memGate = mem.gate;
        auto port = memGate->m_inputs[mem.number];

        wire->m_path = std::make_pair(gate->m_output, port);
    }
}


QPointF WorkSpace::connectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void WorkSpace::mouseReleaseEvent(QMouseEvent *event) {
    if (m_currentWire && event->button() == Qt::LeftButton) {
        QPointF wireEnd = m_currentWire->mapToScene(m_currentWire->m_path.second->pos);

        for (auto gate : m_gates) {
            for (int i = 0; i < gate->m_inputs.size(); ++i) {
                if (wireEnd == gate->m_inputs[i].data()->pos) {
                    MemGatePin m(gate, i);
                    m_table[m_activeGate] = std::make_pair(m_currentWire, m);
                    m_currentWire->update();
                    break;
                }
            }
        }
        m_currentWire = nullptr;
        m_activePort = nullptr;
    }
    else {
        QGraphicsView::mouseReleaseEvent(event);
    }
    this->setCursor(Qt::ArrowCursor);
}
