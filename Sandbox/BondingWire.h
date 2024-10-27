#ifndef BONDINGWIRE_H
#define BONDINGWIRE_H

#include <QPainterPath>
#include <QPainter>
#include <QRect>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class BondingWire : public QWidget {
public:
    BondingWire();

    bool isClicked;
    QPoint startPos;
    QPoint endPos;
    struct BWLine {
        QPoint startPos;
        QPoint endPos;
    };
    QList<BWLine> lines;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

    void paintEvent(QPaintEvent* event);
};

#endif // BONDINGWIRE_H
