#ifndef INPUT_POINT_H
#define INPUT_POINT_H

#include <QPointF>
#include "../BusinessLogic/gate_state.h"

class InputPoint {
public:
    InputPoint(QPointF point, GateState state = LOGIC_Z);

    QPointF m_point;
    GateState m_state;
};

#endif // INPUT_POINT_H
