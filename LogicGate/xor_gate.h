#ifndef XOR_GATE_H
#define XOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT XORGate : public LogicGate {

public:
    XORGate();
    //virtual ~XORGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // XOR_GATE_H
