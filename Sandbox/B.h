#ifndef B_H
#define B_H

#include <QObject>

class B : public QObject {
    Q_OBJECT

public slots:
    void B_slot(int value);
};

#endif // B_H
