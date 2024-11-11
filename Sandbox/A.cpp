#include "./A.h"

void A::Emit_signal() {
    emit A_signal(m_val);
}

void A::Increment_val() {
    ++m_val;
}
