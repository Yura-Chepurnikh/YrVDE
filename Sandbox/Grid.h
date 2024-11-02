#ifndef GRID_H
#define GRID_H

#include <QWidget>
#include <QPaintEvent>
#include <QScreen>
#include <QPainter>

class Grid : public QWidget {
public:
    Grid();

    void paintEvent(QPaintEvent* event) override;
};

#endif // GRID_H
