#ifndef LOGICGATE_GLOBAL_H
#define LOGICGATE_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QtGui/QPainterPath>
#include <QtGui/QPainter>

#if defined(LOGICGATE_LIBRARY)
#define LOGICGATE_EXPORT Q_DECL_EXPORT
#else
#define LOGICGATE_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGICGATE_GLOBAL_H
