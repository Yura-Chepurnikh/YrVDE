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
    void GetInputPoint(QSharedPointer<Input> point);

signals:
    void SendPermission(bool isAllowed, QPointF& startPos);

    void SendFirstCordinate(QPointF first);
    void SendSecondCordinate(QPointF second);
    void SendInputsDistance(int dis);
    void SendGap(int gap);
    void SendInputsPoints(const std::vector<QSharedPointer<Input>>);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

    std::vector<QSharedPointer<Input>> CreateInputPoints(QPainterPath path);

    bool m_superFlag { false };

    int m_inputsCount = 2;
    QSharedPointer<Input> m_activePoint;
    QPointF m_pos {5,5};
    int m_inputsGap;
    int m_gap;
    bool m_isDrag;
    bool m_isAllowed {false};
    std::vector<QSharedPointer<Input>> m_inputs;
    QSharedPointer<Input> m_output = QSharedPointer<Input>::create(QPointF{1, 1}, LogicState::HIGH_IMPEDANCE_STATE);

    QPainterPath m_backSide;

};

#endif // LOGICGATE_H
