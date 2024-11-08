#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include "BondingWire_global.h"

class BONDINGWIRE_EXPORT BondingWire : public QGraphicsPathItem {
public:
    BondingWire();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;

private:
    bool m_isDrag;
    QPointF m_lastPos;
    QPainterPath m_wirePath;
};

#endif // BONDINGWIRE_H
