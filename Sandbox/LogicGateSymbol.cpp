#include "LogicGateSymbol.h"

LogicGateSymbol::LogicGateSymbol() : QWidget() {
    setFixedSize(200, 200);
}

void LogicGateSymbol::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    //painter.setBrush(Qt::blue);
    //painter.setPen(Qt::blue);
    //QFont font("Arial", 72);
    mrect.setRect(100, 100, 100, 100);
    //painter.setFont(font);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRect(mrect);
    QColor col("#FF6A00");
    painter.setPen(QPen(col, 20));
}

void LogicGateSymbol::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        dragWidgetStartPos = pos();
        dragCursorStartPos = event->pos();
        isDragging = true;
    }
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
