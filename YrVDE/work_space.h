#ifndef WORK_SPACE_H
#define WORK_SPACE_H

#include <QWidget>
#include <QPoint>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>

class WorkSpace : public QWidget {
public:
    WorkSpace();
    void keyPressEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    QPoint m_HighLightPoint;

    int m_MergeDistance;
    std::vector<std::vector<QPoint>> m_GridPoints;

    bool m_ShowGrid;
    static int m_Gap;
};

#endif // WORK_SPACE_H
