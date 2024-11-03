#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>

class WorkSpace : public QWidget {
public:
    WorkSpace();
    void keyPressEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    bool m_ShowGrid;
    static int m_Gap;
};

#endif // WORK_SPACE_H
