#include "./Grid.h"

Grid::Grid(QGraphicsScene* scene) : QGraphicsView(scene)
{
    for (int i = 0; i < 1000; i += 20) {
        std::vector<QPointF> vec;
        for (int j = 0; j < 1000; j += 20) {
            QGraphicsEllipseItem* point = scene->addEllipse(i, j, 1, 1, QPen(Qt::black), QBrush(Qt::black));
            vec.push_back(QPointF(i, j));
        }
        m_gridPoints.push_back(vec);
    }
}
