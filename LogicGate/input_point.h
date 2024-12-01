#ifndef INPUT_POINT_H
#define INPUT_POINT_H

#include "../BusinessLogic/GateState.h"
#include <QPointF>

class InputPoint {
public:
    InputPoint(QPointF point, GateState state = GateState::LOGIC_Z);

    QPointF m_point;
    GateState m_state;
};

#endif // INPUT_POINT_H
