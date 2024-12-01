#ifndef LOGICGATE_GLOBAL_H
#define LOGICGATE_GLOBAL_H

#include "./input_point.h"

#include <QtCore/qglobal.h>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QtGui/QPainterPath>
#include <QtGui/QPainter>
#include <QPushButton>
#include <QTransform>
#include <QMenu>
#include <QAction>
#include <QBitmap>
#include <QtWidgets/QGraphicsProxyWidget>
#include <QtWidgets/QGraphicsSceneHoverEvent>
#include <QPoint>
#include <QCursor>
#include <QtWidgets/QCheckBox>
#include <QSharedPointer>

#include "../BondingWire/bondingwire.h"

#if defined(LOGICGATE_LIBRARY)
#define LOGICGATE_EXPORT Q_DECL_EXPORT
#else
#define LOGICGATE_EXPORT Q_DECL_IMPORT
#endif

#endif // LOGICGATE_GLOBAL_H
