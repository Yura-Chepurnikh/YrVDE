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



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../BusinessLogic/build/Desktop-Debug/release/ -lBusinessLogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../BusinessLogic/build/Desktop-Debug/debug/ -lBusinessLogic
else:unix: LIBS += -L$$PWD/../BusinessLogic/build/Desktop-Debug/ -lBusinessLogic

INCLUDEPATH += $$PWD/../BusinessLogic/build/Desktop-Debug
DEPENDPATH += $$PWD/../BusinessLogic/build/Desktop-Debug


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../LogicGate/build/Desktop-Debug/release/ -lLogicGate
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../LogicGate/build/Desktop-Debug/debug/ -lLogicGate
else:unix: LIBS += -L$$PWD/../LogicGate/build/Desktop-Debug/ -lLogicGate

INCLUDEPATH += $$PWD/../LogicGate/build/Desktop-Debug
DEPENDPATH += $$PWD/../LogicGate/build/Desktop-Debug
