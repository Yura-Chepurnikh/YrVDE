#ifndef PIN_H
#define PIN_H

#include "./logicgate.h"
#include "../BusinessLogic/businesslogic.h"

class LOGICGATE_EXPORT Pin : public LogicGate {
    Q_OBJECT

public:
    Pin();
    ~Pin() override;

    void createPin();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
};

#endif // PIN_H
