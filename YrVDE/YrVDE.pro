QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    workspace.cpp

HEADERS += \
    mainwindow.h \
    workspace.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/release/ -lBondingWire
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug/ -lBondingWire
else:unix: LIBS += -L$$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ -lBondingWire

INCLUDEPATH += $$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../BondingWire/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LogicGate/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/release/ -lLogicGate
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LogicGate/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug/ -lLogicGate
else:unix: LIBS += -L$$PWD/../LogicGate/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ -lLogicGate

INCLUDEPATH += $$PWD/../LogicGate/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../LogicGate/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
