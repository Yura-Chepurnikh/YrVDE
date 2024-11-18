#ifndef XOR_GATE_H
#define XOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT XORGate : public LogicGate {
Q_OBJECT
public:
    XORGate();
    ~XORGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // XOR_GATE_H
