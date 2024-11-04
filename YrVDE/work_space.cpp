#include "./work_space.h"

int WorkSpace::m_Gap =  0;

WorkSpace::WorkSpace() : QWidget() {
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
    setAttribute(Qt::WA_StyledBackground, true);

    this->setStyleSheet("background-color: #1F1F1F;");

    m_ShowGrid = false;
    m_Gap =  this->height() / 15; // 15 is a random number
    m_MergeDistance = m_Gap / 2;
    setFocusPolicy(Qt::StrongFocus);
    update();
}

void WorkSpace::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_G) {
        m_ShowGrid = !m_ShowGrid;
    }
}

void WorkSpace::paintEvent(QPaintEvent*) {
    if (m_ShowGrid) {
        QPainter painter(this);
        painter.setPen({QColor("#2A2A2A"), 1});

        int work_space_width = this->width();
        int work_space_height = this->height();

        for (int x = 0; x < work_space_width; x += m_Gap) {
            painter.drawLine(x, 0, x, work_space_height);
        }
        for (int y = 0; y < work_space_height; y += m_Gap) {
            painter.drawLine(0, y, work_space_width, y);
        }

        for (int x = 0; x < work_space_width; x += m_Gap) {
            std::vector<QPoint> points;
            for (int y = 0; y < work_space_height; y += m_Gap) {
                points.push_back(QPoint(x, y));
            }
            m_GridPoints.push_back(points);
        }

        painter.setPen({QColor("#2A2A2A"), 3});
        for (int i = 0; i < m_GridPoints.size(); ++i) {
            for (int j = 0; j < m_GridPoints[i].size(); ++j) {
                painter.drawPoint(m_GridPoints[i][j]);
            }
        }
        painter.setPen({Qt::red, 5});
        painter.drawPoint(m_HighLightPoint);

    }
    update();
}

void WorkSpace::mouseMoveEvent(QMouseEvent* event) {
    for (int i = 0; i < m_GridPoints.size(); ++i) {
        for (int j = 0; j < m_GridPoints[i].size(); ++j) {
            if (std::abs(event->pos().x() - m_GridPoints[i][j].x()) < m_MergeDistance &&
                std::abs(event->pos().y() - m_GridPoints[i][j].y()) < m_MergeDistance)
            {
                qDebug() << event->pos() << '\n';
                m_HighLightPoint = m_GridPoints[i][j];
                return;
            }
        }
    }
}

