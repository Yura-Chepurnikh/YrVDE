#ifndef OR_GATE_H
#define OR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT ORGate : public LogicGate {
public:
    ORGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // OR_GATE_H
