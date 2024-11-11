#ifndef BUFFER_GATE_H
#define BUFFER_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT BUFFERGate : public LogicGate {
public:
    BUFFERGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // BUFFER_GATE_H
