#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T01:02:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VA
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    options_for_graphs.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    options_for_graphs.h

FORMS    += mainwindow.ui \
    options_for_graphs.ui
