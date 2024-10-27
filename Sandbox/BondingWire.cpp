#include "./BondingWire.h"

BondingWire::BondingWire() { }

void BondingWire::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isClicked = true;
        startPos = event->pos();
    }
}

void BondingWire::mouseMoveEvent(QMouseEvent *event) {
    if (isClicked && (event->buttons() & Qt::LeftButton)) {
        int dx = event->pos().x() - startPos.x();
        int dy= event->pos().y() - startPos.y();

        if (dx > dy) {
            endPos.setY(startPos.y());
            endPos.setX(event->pos().x());
        } else {
            endPos.setX(startPos.x());
            endPos.setY(event->pos().y());
        }
        update();
    }
}

void BondingWire::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isClicked = false;
        lines.append({startPos, endPos});
    }
}

void BondingWire::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 12));

    for (const auto& line : lines) {
        painter.drawLine(line.startPos, line.endPos);
    }

    if (isClicked) {
        painter.drawLine(startPos, endPos);
    }
}
