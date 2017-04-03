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
    kinematics.cpp \
    ball.cpp

HEADERS  += mainwindow.h \
    kinematics.h \
    ball.h

FORMS    += mainwindow.ui
