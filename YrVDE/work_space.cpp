#include "./work_space.h"

int WorkSpace::m_Gap =  0;

WorkSpace::WorkSpace() : QWidget() {
    m_ShowGrid = false;
    m_Gap =  this->height() / 30; // 30 здесь рандомное число
    setFocusPolicy(Qt::StrongFocus);
}

void WorkSpace::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_G) {
        m_ShowGrid = !m_ShowGrid;
    }
}

void WorkSpace::paintEvent(QPaintEvent*) {
    if (m_ShowGrid) {
        QPainter painter(this);

        int work_space_width = this->width();
        int work_space_height = this->height();

        for (int x = 0; x < work_space_width; x += m_Gap) {
            painter.drawLine(x, 0, x, work_space_height);
        }

        for (int y = 0; y < work_space_height; y += m_Gap) {
            painter.drawLine(0, y, work_space_width, y);
        }
    }
    update();
}

/*
* У нас есть 2 метода, где keyPressEvent проверяет была ли нажата G key
* и в этом случае вызывает метод ShowGrid
*
*
*
*
*
*
*
*
*
*
*
*/
