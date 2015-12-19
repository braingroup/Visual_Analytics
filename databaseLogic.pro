#-------------------------------------------------
#
# Project created by QtCreator 2015-11-14T13:26:59
#
#-------------------------------------------------

QT       += sql
QT       += core

QT       -= gui

TARGET = databaseLogic
TEMPLATE = app

QTPLUGIN += QSQLMYSQL

DEFINES += DATABASELOGIC_LIBRARY

SOURCES += \
    mysqlconnection.cpp \
    main.cpp \
    connectionfabric.cpp

HEADERS += connection.h \
    mysqlconnection.h \
    connectionfabric.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
