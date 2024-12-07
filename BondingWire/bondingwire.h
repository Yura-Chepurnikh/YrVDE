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
    void GetInputsPoints(std::vector<QSharedPointer<InputPoint>> points);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QPointF ConnectToGrid(const QPointF& pos, int gridGap);
    QRectF boundingRect() const override;

private:
    bool m_flag { false };
    int m_offset;
    bool m_route { false };
    bool m_isDrag = false;
    QPointF m_startPos;
    std::vector<std::vector<QSharedPointer<InputPoint>>> m_allGatePoints;
    QSharedPointer<InputPoint> m_inputsPoints;
    std::vector<QPointF> m_points;
};

#endif // BONDINGWIRE_H
