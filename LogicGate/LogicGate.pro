QT += core widgets gui

TEMPLATE = lib
DEFINES += LOGICGATE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    and_gate.cpp \
    buffer_gate.cpp \
    logicgate.cpp \
    nand_gate.cpp \
    nor_gate.cpp \
    not_gate.cpp \
    or_gate.cpp \
    xnor_gate.cpp \
    xor_gate.cpp

HEADERS += \
    LogicGate_global.h \
    and_gate.h \
    buffer_gate.h \
    logicgate.h \
    nand_gate.h \
    nor_gate.h \
    not_gate.h \
    or_gate.h \
    xnor_gate.h \
    xor_gate.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target