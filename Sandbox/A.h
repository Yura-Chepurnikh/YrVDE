#ifndef A_H
#define A_H

#include <QObject>
#include "./B.h"

class A : public QObject {
    Q_OBJECT
public:
    void Emit_signal();
    void Increment_val();

    int m_val = 10;
signals:
    void A_signal(int value);
};

#endif // A_H
