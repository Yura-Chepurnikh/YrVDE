#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include "BondingWire_global.h"
#include "../LogicGate/input.h"
#include <utility>

class BONDINGWIRE_EXPORT BondingWire : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    BondingWire();
    ~BondingWire();

public slots:
    void GetGridSize(int size);
    void GetPermissionFromGate(bool isAllowed, QPointF& startPos);

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    QPointF StickToTheGrid(const QPointF& current_pos);
    QRectF boundingRect() const override;

private:
    int m_step;
    bool m_isDrag {false}, m_isAllowedFromGate {false};
    QPointF m_startPos;

    std::pair<QSharedPointer<Input>, QSharedPointer<Input>> m_inputs;
    std::list<std::pair<QSharedPointer<QPointF>, QSharedPointer<QPointF>>> m_path;
};

#endif // BONDINGWIRE_H
