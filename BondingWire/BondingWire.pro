QT += core gui widgets

TEMPLATE = lib
DEFINES += BONDINGWIRE_LIBRARY

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bondingwire.cpp

HEADERS += \
    BondingWire_global.h \
    bondingwire.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/./release/ -lBondingWire
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/./debug/ -lBondingWire
else:unix: LIBS += -L$$OUT_PWD/./ -lBondingWire

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/release/ -lBondingWire
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug/ -lBondingWire
else:unix: LIBS += -L$$PWD/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/ -lBondingWire

INCLUDEPATH += $$PWD/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/build/Desktop_Qt_6_7_1_MinGW_64_bit-Debug/debug
