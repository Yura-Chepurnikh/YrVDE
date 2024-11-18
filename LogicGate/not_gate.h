#ifndef NOT_GATE_H
#define NOT_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT NOTGate : public LogicGate {
Q_OBJECT
public:
    NOTGate();
    ~NOTGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // NOT_GATE_H
