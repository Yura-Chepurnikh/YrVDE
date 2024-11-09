QT  += core gui
QT  += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BondingWire.cpp \
    Edge.cpp \
    Grid.cpp \
    LogicGateSymbol.cpp \
    TrySqlite.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    BondingWire.h \
    Edge.h \
    Grid.h \
    LogicGateSymbol.h \
    TrySqlite.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

QMAKE_LIBDIR += C:/Qt/6.7.1/mingw_64/plugins

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
