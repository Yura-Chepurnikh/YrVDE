#ifndef PORT_H
#define PORT_H

#include <QPointF>
#include <QObject>
#include "LogicGate_global.h"
#include "../BusinessLogic/logic_state.h"

struct Port : public QObject, public QGraphicsItem {
Q_OBJECT

public:

    Port(QPointF pos = {1, 1}, LogicState state = LogicState::HIGH_IMPEDANCE_STATE);
    QPointF pos;
    qreal radius {1};
    LogicState state;
    static qreal clickableRadius;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // PORT_H
