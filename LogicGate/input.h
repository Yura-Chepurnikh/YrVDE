#ifndef INPUT_H
#define INPUT_H

#include "./logicgate.h"

class LOGICGATE_EXPORT Input : public LogicGate {
Q_OBJECT

public:
    Input();
    ~Input() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
};

#endif // INPUT_H
