#include "./Grid.h"

Grid::Grid() : QWidget() { }

void Grid::paintEvent(QPaintEvent* event) {
    QPainter painter(this);

    int width = this->width();
    int height = this->height();

    int offset = height / 20;

    for (int i = 0; i < width; i += offset) {
        painter.drawLine(i, 0, i, height);
    }

    for (int j = 0; j < height; j += offset) {
        painter.drawLine(0, j, width, j);
    }

    update();
}
