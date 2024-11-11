#ifndef LOGICGATE_H
#define LOGICGATE_H

#include "LogicGate_global.h"

class LOGICGATE_EXPORT LogicGate : public QObject, public QGraphicsItem {
    Q_OBJECT

public:
    LogicGate();
    virtual ~LogicGate() = default;

// public slots:
//     void GetPoint(QPoint point);

protected:
    QPointF m_pos {400, 400};
};

#endif // LOGICGATE_H
