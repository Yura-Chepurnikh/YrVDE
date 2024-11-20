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

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

    std::vector<QPointF> FindPointsOnTheCurve(QPointF begin, QPointF middle, QPointF end);
    std::vector<int> Find_abc(QPointF begin, QPointF middle, QPointF end);
    double FindDeterminant(double p1, double p2, double p3);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;

    QPointF m_pos {101,200};
    int m_min_dis;
    int m_gap;
    bool m_isDrag;

    std::vector<QPointF> m_inputs;
    QPointF m_output;
};

#endif // LOGICGATE_H
