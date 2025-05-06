#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include "BondingWire_global.h"
#include "../LogicGate/port.h"
#include "../LogicGate/logicgate.h"

#include <utility>

class BONDINGWIRE_EXPORT BondingWire : public QObject, public QGraphicsItem {
Q_OBJECT
Q_INTERFACES(QGraphicsItem)

public:
    BondingWire();
    ~BondingWire();

public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    QRectF boundingRect() const;
    std::pair<QSharedPointer<Port>, QSharedPointer<Port>> m_path;
};

#endif // BONDINGWIRE_H
