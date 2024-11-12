#ifndef NAND_GATE_H
#define NAND_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT NANDGate : public LogicGate {

public:
    NANDGate();
    //virtual ~NANDGate();


protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

private:

};

#endif // NAND_GATE_H
