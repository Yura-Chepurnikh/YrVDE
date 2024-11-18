#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT XNORGate : public LogicGate {
Q_OBJECT
public:
    XNORGate();
    ~XNORGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // XNOR_GATE_H
