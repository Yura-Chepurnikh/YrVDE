#ifndef NOR_GATE_H
#define NOR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT NORGate : public LogicGate {
    Q_OBJECT
public:
    NORGate();
    virtual ~NORGate() = default;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // NOR_GATE_H
