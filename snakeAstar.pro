#-------------------------------------------------
#
# Project created by QtCreator 2016-10-05T14:21:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snakeAstar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    astar.cpp

HEADERS  += mainwindow.h \
    astar.h

FORMS    += mainwindow.ui
