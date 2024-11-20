#ifndef ADD_INPUTS_H
#define ADD_INPUTS_H

#include "LogicGate_global.h"

class LOGICGATE_EXPORT AddInput : public QObject {
    Q_OBJECT

public:
    AddInput();
    ~AddInput() = default;
    std::vector<QPointF> Points();

public slots:
    void GetInputsDistance(int distance);
    void GetFirstCordinate(QPointF first);
    void GetSecondCordinate(QPointF second);

public:

    int m_inputsDistance;
    QPointF m_firstCordinate;
    QPointF m_secondCordinate;
};

#endif // ADD_INPUTS_H
