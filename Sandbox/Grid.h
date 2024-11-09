#ifndef GRID_H
#define GRID_H

#include <QGraphicsView>
#include <QPaintEvent>
#include <QPainter>

class Grid : public QGraphicsView {
public:
    Grid(QGraphicsScene* scene = nullptr);

    int m_mergeDis = 10;
    std::vector<std::vector<QPointF>> m_gridPoints;
};

#endif // GRID_H
