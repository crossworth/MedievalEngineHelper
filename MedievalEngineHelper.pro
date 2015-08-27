#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T19:03:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedievalEngineHelper
TEMPLATE = app


QMAKE_CXXFLAGS += -std=gnu++1y


SOURCES += main.cpp\
        MainWindow.cpp \
    DATFile.cpp

HEADERS  += MainWindow.h \
    Types.h \
    DATFile.h

FORMS    += MainWindow.ui
