#-------------------------------------------------
#
# Project created by QtCreator 2015-08-21T19:03:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedievalEngineHelper
TEMPLATE = app

win32 {

	QMAKE_CXXFLAGS += -std=gnu++1y

}


macosx {

	CONFIG += c++11
	QMAKE_CXXFLAGS_CXX11 = -std=c++14 -stdlib=libc++

}



SOURCES += main.cpp\
        MainWindow.cpp \
    DATFile.cpp

HEADERS  += MainWindow.h \
    Types.h \
    DATFile.h

FORMS    += MainWindow.ui
