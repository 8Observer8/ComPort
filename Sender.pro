#-------------------------------------------------
#
# Project created by QtCreator 2014-08-22T10:54:37
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sender
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Sender.cpp

HEADERS  += MainWindow.h \
    Sender.h \
    PortError.h

FORMS    += MainWindow.ui
