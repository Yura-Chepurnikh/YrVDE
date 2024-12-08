#ifndef INPUT_H
#define INPUT_H

#include "./logicgate.h"

class LOGICGATE_EXPORT Input : public LogicGate {
Q_OBJECT

public:
    Input();
    ~Input() override;

protected:
    QSharedPointer<InputPoint> m_input;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const override;
};

#endif // INPUT_H
