#ifndef OR_GATE_H
#define OR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT ORGate : public LogicGate {
Q_OBJECT
public:
    ORGate();
    ~ORGate() override;

protected:
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // OR_GATE_H
