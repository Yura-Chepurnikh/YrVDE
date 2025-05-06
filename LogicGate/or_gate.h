#ifndef OR_GATE_H
#define OR_GATE_H

#include "./logicgate.h"

class LOGICGATE_EXPORT ORGate : public LogicGate {
Q_OBJECT
public:
    ORGate();
    ~ORGate() override;

protected:
    void createBackside(QPainterPath& path) const override;
    void createLateralSides(QPainterPath& path) const;

    void createOutputPort();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // OR_GATE_H
