#include "./Edge.h"

Edge::Edge(QWidget* parent) : QWidget(parent)
{
    QPushButton* button = new QPushButton("Add Point", this);


    connect(button, &QPushButton::clicked, this, &Edge::IncreasingThePoints);

}

void Edge::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen(color, 20);

    painter.setPen(pen);
    //painter.drawPoint(point1);
    //painter.drawPoint(point2);

    for (const auto& point : points) {
        painter.drawPoint(point);
    }


    update();
}

void Edge::IncreasingThePoints() {
    int i = 1;
    count++;

    points.clear();

    points.append(point1);
    auto dif = point2.y() - point1.y();
    int dy = dif / count;

    while (i < count) {
        QPoint newPoint;
        newPoint.setY((point1.y() + i * dy));
        newPoint.setX(point1.x());
        points.append(newPoint);
        i++;
    }

    points.append(point2);

    for (const auto& point : points) {
        qDebug() << point << "\n";
    }

    //qDebug() << count << "\n";
    update();
}
