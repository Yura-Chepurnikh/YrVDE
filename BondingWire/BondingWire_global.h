#ifndef BONDINGWIRE_GLOBAL_H
#define BONDINGWIRE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtWidgets/QGraphicsPathItem>
#include <QtWidgets/QWidget>
#include <QtWidgets/QStyleOptionGraphicsItem>
#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsSceneMouseEvent>
#include <QtCore/QPointF>
#include <QtCore/QLineF>
#include <QtGui/QPainterPath>

#if defined(BONDINGWIRE_LIBRARY)
#define BONDINGWIRE_EXPORT Q_DECL_EXPORT
#else
#define BONDINGWIRE_EXPORT Q_DECL_IMPORT
#endif

#endif // BONDINGWIRE_GLOBAL_H