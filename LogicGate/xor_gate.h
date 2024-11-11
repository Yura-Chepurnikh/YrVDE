#ifndef XOR_GATE_H
#define XOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT XORGate : public LogicGate {
    Q_OBJECT
public:
    XORGate();
    virtual ~XORGate() = default;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // XOR_GATE_H
