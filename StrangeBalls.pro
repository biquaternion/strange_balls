#-------------------------------------------------
#
# Project created by QtCreator 2017-03-30T11:57:27
#
#-------------------------------------------------

QT       += core gui concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StrangeBalls
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    ballscene.cpp \
    integrator.cpp \
    ballitem.cpp \
    almanac.cpp

HEADERS  += mainwindow.h \
    ball.h \
    ballscene.h \
    integrator.h \
    ballitem.h \
    almanac.h

FORMS    += mainwindow.ui
