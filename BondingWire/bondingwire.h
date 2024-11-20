#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include "BondingWire_global.h"

class BONDINGWIRE_EXPORT BondingWire : public QObject, public QGraphicsItem {
Q_OBJECT

public:
    BondingWire();
    ~BondingWire();

public slots:
    void GetGridGap(int gap);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QPointF ConnectToGrid(const QPointF& pos, int gridGap);
    QRectF boundingRect() const override;

private:
    int m_offset;
    bool m_isDrag = false;
    QPointF m_startPos;
    std::vector<QPointF> m_points;
};

#endif // BONDINGWIRE_H
