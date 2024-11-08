#include "bondingwire.h"

BondingWire::BondingWire()
{
    setAcceptedMouseButtons(Qt::RightButton);
}

void BondingWire::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->drawPath(path());
}

void BondingWire::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        qDebug() << "mousePressEvent !!!" << '\n';

        m_wirePath.moveTo(event->pos());
        setPath(m_wirePath);
        m_lastPos = event->pos();
        m_isDrag = true;
    }
}

void BondingWire::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isDrag && (event->buttons() & Qt::RightButton)) {
        qDebug() << "mouseMoveEvent !!!" << '\n';
        m_wirePath.quadTo(m_lastPos, event->pos());
        setPath(m_wirePath);
        m_lastPos = event->pos();
    }
}

void BondingWire::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        setPath(m_wirePath);
        m_isDrag = false;
    }
}
