#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"

#define PARTS 10

class LOGICGATE_EXPORT LogicGate : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    LogicGate();
    ~LogicGate() = default;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;
    QRectF boundingRect() const override;

    void hoverMoveEvent(QGraphicsSceneHoverEvent* event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    qreal distanceToPoints(const QPointF& from, const QPointF& to);
    QPointF connectToGrid(const QPointF& pos, int gridGap);

    virtual void createPorts(QPainterPath path);
    virtual void createBackside(QPainterPath& path) const;

public slots:
    void getGridSize(int size);
    void getGridPos(QPointF pos);

signals:
    void createWire(Port* port);
    void sendGateDrag(LogicGate* gate);

public:
    unsigned int m_inputsNumber;
    std::vector<QSharedPointer<Port>> m_inputs;
    QSharedPointer<Port> m_activePort;

    std::vector<QLineF> m_inputWires;

    QSharedPointer<Port> m_output;
    QPointF m_gatePos;
    qreal m_activeRadius, m_gridSize;
    bool m_isDrag;

    QPainterPath m_backSide;
};



#endif // LOGICGATE_H
