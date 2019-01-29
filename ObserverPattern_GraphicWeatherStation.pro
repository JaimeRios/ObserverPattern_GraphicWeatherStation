#-------------------------------------------------
#
# Project created by QtCreator 2019-01-29T15:51:55
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = ObserverPattern_GraphicWeatherStation
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    currentconditionsdisplay.cpp \
    displayelement.cpp \
    forecastdisplay.cpp \
    heatindexdisplay.cpp \
    observer.cpp \
    statisticsdisplay.cpp \
    subject.cpp \
    weatherdata.cpp

HEADERS += \
    currentconditionsdisplay.h \
    displayelement.h \
    forecastdisplay.h \
    heatindexdisplay.h \
    observer.h \
    statisticsdisplay.h \
    subject.h \
    weatherdata.h

FORMS += \
    currentconditionsdisplay.ui \
    forecastdisplay.ui \
    heatindexdisplay.ui \
    statisticsdisplay.ui \
    weatherdata.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
