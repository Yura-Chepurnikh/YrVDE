#ifndef LOGICGATESYMBOL_H
#define LOGICGATESYMBOL_H

#include <QPainterPath>
#include <QPainter>
#include <QRect>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>

class LogicGateSymbol : public QWidget {
public:
    LogicGateSymbol();
    QRect mrect;

    QPoint dragCursorStartPos;
    QPoint dragWidgetStartPos;
    bool isDragging;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

    bool isCursorPosValid(QMouseEvent* event);

    void paintEvent(QPaintEvent* event) override;
};

#endif // LOGICGATESYMBOL_H
