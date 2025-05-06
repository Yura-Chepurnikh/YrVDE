#ifndef PORT_H
#define PORT_H

#include <QPointF>
#include <QObject>
#include "LogicGate_global.h"
#include "../BusinessLogic/logic_state.h"

class Port : public QObject, public QGraphicsItem {
Q_OBJECT

public:
    Port(QPointF pos, LogicState state = LogicState::HIGH_IMPEDANCE_STATE);
    QPointF pos;
    qreal radius {1};
    LogicState state;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // PORT_H
