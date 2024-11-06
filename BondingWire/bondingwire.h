#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include "BondingWire_global.h"

class BONDINGWIRE_EXPORT BondingWire : public QGraphicsItem {
public:
    BondingWire();

protected:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect() const override;

private:
    bool m_isDrag;
    QPointF m_startPos;
    QPointF m_endPos;
    std::vector<QLineF> m_wires;
};

#endif // BONDINGWIRE_H
