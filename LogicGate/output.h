#ifndef OUTPUT_H
#define OUTPUT_H

#include "./logicgate.h"

class LOGICGATE_EXPORT Output : public LogicGate {
    Q_OBJECT

public:
    Output();
    ~Output() override;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
};

#endif // OUTPUT_H
