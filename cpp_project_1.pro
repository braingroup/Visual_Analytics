#-------------------------------------------------
#
# Project created by QtCreator 2015-12-02T16:04:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = cpp_project_1
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11



SOURCES += main.cpp\
        mainwindow.cpp \
        circlegraph.cpp \
        graph.cpp \
        columngraph.cpp \
        functiongraph.cpp \
        drawableobject.cpp \
        graphfabric.cpp \
        graphtype.cpp \
        qcustomplot.cpp

HEADERS  += mainwindow.h \
    circlegraph.h \
    graph.h \
    columngraph.h \
    functiongraph.h \
    drawableobject.h \
    graphfabric.h \
    graphtype.h \
    graphfabric.h \
    qcustomplot.h

FORMS    += mainwindow.ui
