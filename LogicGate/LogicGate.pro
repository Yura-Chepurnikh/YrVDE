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
    input.cpp \
    input_point.cpp \
    logicgate.cpp \
    nand_gate.cpp \
    nor_gate.cpp \
    not_gate.cpp \
    or_gate.cpp \
    output.cpp \
    xnor_gate.cpp \
    xor_gate.cpp

HEADERS += \
    LogicGate_global.h \
    and_gate.h \
    buffer_gate.h \
    input.h \
    input_point.h \
    logicgate.h \
    nand_gate.h \
    nor_gate.h \
    not_gate.h \
    or_gate.h \
    output.h \
    xnor_gate.h \
    xor_gate.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/release/ -lBondingWire
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug/ -lBondingWire
else:unix: LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ -lBondingWire

INCLUDEPATH += $$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BusinessLogic/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/release/ -lBusinessLogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BusinessLogic/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug/ -lBusinessLogic
else:unix: LIBS += -L$$PWD/../BusinessLogic/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ -lBusinessLogic

INCLUDEPATH += $$PWD/../BusinessLogic/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../BusinessLogic/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
