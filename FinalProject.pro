QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CircuitComponent.cpp \
    P5CircuitWindow.cpp \
    P5S1.cpp \
    P5S2.cpp \
    P5S3.cpp \
    P5S4.cpp \
    P5S5.cpp \
    P5S6.cpp \
    P5S7.cpp \
    P6CircuitWindow.cpp \
    P7CircuitWindow.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CircuitComponent.hpp \
    P5CircuitWindow.hpp \
    P5S1.hpp \
    P5S2.hpp \
    P5S3.hpp \
    P5S4.hpp \
    P5S5.hpp \
    P5S6.hpp \
    P5S7.hpp \
    P6CircuitWindow.hpp \
    P7CircuitWindow.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
