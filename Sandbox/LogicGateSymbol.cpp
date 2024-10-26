#include "LogicGateSymbol.h"

LogicGateSymbol::LogicGateSymbol() : QWidget() {
}

void LogicGateSymbol::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    QFont font("Arial", 72);
    mrect.setRect(100, 100, 100, 100);
    painter.setFont(font);
    painter.drawRect(mrect);
    painter.drawText(130, 130, "&");
}

void LogicGateSymbol::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && isCursorPosValid(event)) {
        dragWidgetStartPos = pos();
        dragCursorStartPos = event->pos();
        isDragging = true;
    }
}

bool LogicGateSymbol::isCursorPosValid(QMouseEvent *event){
    if (mrect.contains(event->pos()))
        return true;
    return false;
}

void LogicGateSymbol::mouseMoveEvent(QMouseEvent *event) {
    if (isDragging && (event->buttons() & Qt::LeftButton)) {
        dragWidgetStartPos = dragWidgetStartPos +  event->pos() - dragCursorStartPos;
        move(dragWidgetStartPos);
        //qDebug() << mrect.width();
        qDebug() <<  dragCursorStartPos.x() << " " << dragCursorStartPos.y() << "\t\t" << dragWidgetStartPos.x() << " " << dragWidgetStartPos.y() <<  "\n";
    }
}

void LogicGateSymbol::mouseReleaseEvent(QMouseEvent *event) {
    if (event->buttons()) {
        isDragging = false;
    }
}
