#include "logicgate.h"

LogicGate::LogicGate() {
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);
    m_isDrag = false;
}

void LogicGate::GetGridGap(int gap) {
    m_gap = gap;
    m_min_dis =  m_gap / 10;
    qDebug() << "LogicGate m_gap" << m_gap << '\n';

}

double LogicGate::FindDeterminant(double p1, double p2, double p3) {
    return p1*p1*p2*1 + p2*p2*p3*1 + p3*p3*p1*1 - p3*p3*p2*1 - p1*p1*p3*1 - p2*p2*p1*1;
}

std::vector<int> LogicGate::Find_abc(QPointF begin, QPointF middle, QPointF end) {
    std::vector<int> abc;

    double x1 = begin.x(); double y1= begin.y();
    double x2 = middle.x(); double y2= middle.y();
    double x3 = end.x(); double y3= end.y();

    qDebug() << begin;
    qDebug() << middle;
    qDebug() << end;


    double delta = FindDeterminant(x1, x2, x3);
    if (delta == 0) {
        qDebug() << "Zero!!!\n";
        return { };
    }
    double a = FindDeterminant(y1, x2, x3) / delta;
    double b = FindDeterminant(x1, y2, x3) / delta;
    double c = FindDeterminant(x1, x2, y3) / delta;

    abc.push_back(a);
    abc.push_back(b);
    abc.push_back(c);

    return abc;
}

 std::vector<QPointF> LogicGate::FindPointsOnTheCurve(QPointF begin, QPointF middle, QPointF end) {
    std::vector<int> abc = Find_abc(begin, middle, end);
    int a = abc[0];
    int b = abc[1];
    int c = abc[2];

    std::vector<QPointF> points;

    for (double i = begin.x(); i < end.x(); i += m_min_dis) {
        points.push_back({i, a*i*i+b*i+c});
    }
    return points;
}

void LogicGate::GetGridPos(QPointF pos) {
    m_pos = pos;
}

void LogicGate::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        QMenu menu;
        QAction* action_1 = menu.addAction("Hello World");
        menu.exec(event->screenPos());
    }
    else {
        setCursor(Qt::ClosedHandCursor);
        QGraphicsItem::mousePressEvent(event);
    }
}

void LogicGate::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF currentPoint = event->scenePos();
    m_pos = ConnectToGrid(currentPoint, m_gap);
    update();
    QGraphicsItem::mousePressEvent(event);
}

void LogicGate::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    setCursor(Qt::CustomCursor);
    QGraphicsItem::mouseReleaseEvent(event);
}

QPointF LogicGate::ConnectToGrid(const QPointF& pos, int gridGap) {
    qreal x = qRound(pos.x() / gridGap) * gridGap;
    qreal y = qRound(pos.y() / gridGap) * gridGap;
    return QPointF { x, y };
}

void LogicGate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setPen(QPen(QColor{ "#777777"}, 1));
}

QRectF LogicGate::boundingRect() const {
    return QRectF(m_pos.x(), m_pos.y(), m_gap, m_gap);
}


