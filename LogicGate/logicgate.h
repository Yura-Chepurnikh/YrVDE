#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"

class LOGICGATE_EXPORT LogicGate : public QGraphicsItem {
public:
    LogicGate();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    QPointF m_pos {400, 400};
};

#endif // LOGICGATE_H
