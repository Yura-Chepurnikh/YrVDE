#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"
#include "./add_inputs.h"

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
    void SendFirstCordinate(QPointF first);
    void SendSecondCordinate(QPointF second);
    void SendInputsDistance(int dis);
    void SendPointToWireTrue();
    void SendPointToWireFalse();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

    std::vector<QPointF> CreateInputPoints(QPainterPath path);
    void AddInput();

    bool m_sendPointToWire { false };

    int m_inputsCount = 2;
    QPointF m_highlightPoint;
    QPointF m_pos {101,200};
    int m_inputsGap;
    int m_gap;
    bool m_isDrag;
    std::vector<QPointF> m_inputs;
    QPointF m_output;

    BondingWire* m_wire;
};

#endif // LOGICGATE_H
