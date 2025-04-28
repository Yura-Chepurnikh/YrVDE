#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"

#define PARTS 10

class LOGICGATE_EXPORT LogicGate : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    LogicGate();
    ~LogicGate() = default;
    QPointF ConnectToGrid(const QPointF& pos, int gridGap);

public slots:
    void GetGridGap(int gap);
    void GetGridPos(QPointF pos);

signals:
    void SendCreateWire(LogicGate* gate);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    qreal DistanceToPoints(const QPointF& from, const QPointF& to);

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

    std::vector<QSharedPointer<Input>> CreateInputPoints(QPainterPath path);

    unsigned int m_inputsCount = 2;
    QSharedPointer<Input> m_activeInput;
    QPointF m_pos;
    qreal m_inputsGap, m_gap;
    bool m_isDrag;
    std::vector<QSharedPointer<Input>> m_inputs;
    QSharedPointer<Input> m_output = QSharedPointer<Input>::create(QPointF{1, 1}, LogicState::HIGH_IMPEDANCE_STATE);

    QPainterPath m_backSide;

};

#endif // LOGICGATE_H
