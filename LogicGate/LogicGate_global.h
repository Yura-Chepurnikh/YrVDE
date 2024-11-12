#ifndef LOGICGATE_GLOBAL_H
#define LOGICGATE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QtGui/QPainterPath>
#include <QtGui/QPainter>
#include <QPoint>
#include <QCursor>

#if defined(LOGICGATE_LIBRARY)
#define LOGICGATE_EXPORT Q_DECL_EXPORT
#else
#define LOGICGATE_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGICGATE_GLOBAL_H
