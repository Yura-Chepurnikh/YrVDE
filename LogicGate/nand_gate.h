#ifndef NAND_GATE_H
#define NAND_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT NANDGate : public LogicGate {
    Q_OBJECT

public:
    NANDGate();
    ~NANDGate() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // NAND_GATE_H
