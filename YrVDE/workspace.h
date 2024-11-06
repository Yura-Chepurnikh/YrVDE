#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QPoint>
#include <QMouseEvent>

class WorkSpace : public QGraphicsView {
public:
    WorkSpace(QGraphicsScene* scene);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;
    void mouseMoveEvent(QMouseEvent* event) override;

private:
    static int m_gap;
    int m_mergeDistance;
    QPoint m_highlightPoint;
    std::vector<std::vector<QPoint>> m_gridPoints;
};

#endif // WORKSPACE_H
