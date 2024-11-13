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

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;

    int m_gap;
    bool m_isDrag;
    QPointF m_pos;
};

#endif // LOGICGATE_H
