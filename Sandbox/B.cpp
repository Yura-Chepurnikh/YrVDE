#include "./B.h"
#include <QDebug>

void B::B_slot(int value) {
    qDebug() << "Get the value: " << value << "\n";
}
