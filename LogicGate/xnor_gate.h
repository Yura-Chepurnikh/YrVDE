#ifndef XNOR_GATE_H
#define XNOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT XNORGate : public LogicGate {

public:
    XNORGate();
    //virtual ~XNORGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // XNOR_GATE_H
