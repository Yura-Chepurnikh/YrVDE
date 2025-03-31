#ifndef INPUT_H
#define INPUT_H

#include <QPointF>
#include <QObject>
#include "LogicGate_global.h"
#include "../BusinessLogic/logic_state.h"

class Input : public QObject, public QGraphicsItem {
Q_OBJECT

public:
    Input(QPointF pos, LogicState state = LogicState::HIGH_IMPEDANCE_STATE);

    QPointF pos;
    qreal radius {1};
    LogicState state;

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
};

#endif // INPUT_H
