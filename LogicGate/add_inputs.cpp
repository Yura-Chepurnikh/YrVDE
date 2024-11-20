#include "./add_inputs.h"

AddInput::AddInput()
{

}

void AddInput::GetInputsDistance(int distance) {
    m_inputsDistance = distance;
    qDebug() << "GetInputsDistance" << m_inputsDistance;
}

void AddInput::GetFirstCordinate(QPointF first) {
    m_firstCordinate = first;
    qDebug() << "GetFirstCordinate" << m_firstCordinate;
}

void AddInput::GetSecondCordinate(QPointF second) {
    m_secondCordinate = second;
    qDebug() << "GetSecondCordinate" << m_secondCordinate;
}

std::vector<QPointF> AddInput::Points() {
    std::vector<QPointF> points;

    points.push_back({ m_firstCordinate.x(), m_firstCordinate.y() + m_inputsDistance });
    points.push_back({ m_secondCordinate.x(), m_secondCordinate.y() - m_inputsDistance });

    return points;
}
