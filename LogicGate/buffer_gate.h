#ifndef BUFFER_GATE_H
#define BUFFER_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT BUFFERGate : public LogicGate {
    Q_OBJECT
public:
    BUFFERGate();
    ~BUFFERGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // BUFFER_GATE_H
