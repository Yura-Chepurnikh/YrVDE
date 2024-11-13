#ifndef AND_GATE_H
#define AND_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT ANDGate : public LogicGate {
    Q_OBJECT
public:
    ANDGate();
    ~ANDGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // AND_GATE_H
