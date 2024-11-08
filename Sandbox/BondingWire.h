#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include <QMouseEvent>
#include <QGraphicsView>
#include <QGraphicsPathItem>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>

class BondingWire : public QGraphicsItem {
public:
    BondingWire();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QRectF boundingRect() const override;

private:
    bool isDrag = false;
    std::vector<QPointF> m_points;
    std::vector<std::vector<QPointF>> m_all_Points;

};

#endif // BONDINGWIRE_H
