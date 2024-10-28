#ifndef EDGE_H
#define EDGE_H

#include <QWidget>
#include <QLine>
#include <QObject>
#include <QPainterPath>
#include <QPainter>
#include <QRect>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>

class Edge : public QWidget {
    Q_OBJECT

public:
    Edge(QWidget* parent = nullptr);

    int count { 0 };
    //using parts = count;

    QPoint point1 {100, 100};
    QPoint point2 {100, 800};

    QColor color { Qt::red };

    //QLine line { 100, 100, 100, 200 };

    QVector<QPoint> points;
    void paintEvent(QPaintEvent* event) override;

public slots:
    void IncreasingThePoints();
};

#endif // EDGE_H
