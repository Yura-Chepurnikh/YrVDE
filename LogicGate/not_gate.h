#ifndef NOT_GATE_H
#define NOT_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT NOTGate : public LogicGate {
public:
    NOTGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // NOT_GATE_H
