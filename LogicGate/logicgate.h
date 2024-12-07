#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"

class LOGICGATE_EXPORT LogicGate : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    LogicGate();
    ~LogicGate() = default;
    QPointF ConnectToGrid(const QPointF& pos, int gridGap);

public slots:
    void GetGridGap(int gap);
    void GetGridPos(QPointF pos);
    void GetInputPoint(QSharedPointer<InputPoint> point);

signals:
    void SendWire(BondingWire* wire);
    void SendFirstCordinate(QPointF first);
    void SendSecondCordinate(QPointF second);
    void SendInputsDistance(int dis);
    void SendGap(int gap);
    void SendInputsPoints(const std::vector<QSharedPointer<InputPoint>>);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

    std::vector<QSharedPointer<InputPoint>> CreateInputPoints(QPainterPath path);

    bool m_superFlag { false };

    int m_inputsCount = 2;
    QSharedPointer<InputPoint> m_highlightPoint;
    QPointF m_pos {5,5};
    int m_inputsGap;
    int m_gap;
    bool m_isDrag;
    std::vector<QSharedPointer<InputPoint>> m_inputs;
    QSharedPointer<InputPoint> m_output = QSharedPointer<InputPoint>::create(QPointF{1, 1}, GateState::LOGIC_Z);

    QPainterPath m_backSide;

    BondingWire* m_wire;
};

#endif // LOGICGATE_H
