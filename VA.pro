#-------------------------------------------------
#
# Project created by QtCreator 2015-11-27T01:02:10
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = VA
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
        options_for_graphs.cpp \
        circlegraph.cpp \
        graph.cpp \
        columngraph.cpp \
        functiongraph.cpp \
        drawableobject.cpp \
        graphfabric.cpp \
        graphtype.cpp \
        qcustomplot.cpp \
        graphadapter.cpp \
        queryadapter.cpp \
        queryresult.cpp

HEADERS  += mainwindow.h \
    options_for_graphs.h \
    circlegraph.h \
    graph.h \
    columngraph.h \
    functiongraph.h \
    drawableobject.h \
    graphfabric.h \
    graphtype.h \
    graphfabric.h \
    qcustomplot.h \
    graphadapter.h \
    queryadapter.h \
    queryresult.h

FORMS    += mainwindow.ui \
    options_for_graphs.ui

